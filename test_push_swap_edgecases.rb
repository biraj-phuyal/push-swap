#!/usr/bin/env ruby
# test_push_swap_edgecases.rb
#
# Usage:
#   chmod +x test_push_swap_edgecases.rb
#   ./test_push_swap_edgecases.rb
#
# If your checker is an x86 binary on Apple Silicon, run like:
#   CHECKER_CMD="arch -x86_64 ./checker_Mac" ./test_push_swap_edgecases.rb

require 'open3'
require 'json'

PUSH_CMD    = ENV['PUSH_CMD']    || "./push_swap"
CHECKER_CMD = ENV['CHECKER_CMD'] || "./checker_Mac"

def run_push_swap_args(args_array)
  stdout, stderr, status = Open3.capture3(PUSH_CMD, *args_array)
  { out: stdout, err: stderr, status: status.exitstatus || 0 }
end

def run_push_swap_single_arg(arg_string)
  # pass the whole string as a single argv to push_swap (quoted-string case)
  stdout, stderr, status = Open3.capture3(PUSH_CMD, arg_string)
  { out: stdout, err: stderr, status: status.exitstatus || 0 }
end

def run_checker_with_moves(args_array, moves)
  # start checker with same args, write moves to its stdin
  Open3.popen3(CHECKER_CMD, *args_array) do |stdin, stdout, stderr, wait_thr|
    stdin.write(moves)
    stdin.close
    res = stdout.read&.strip
    # prefer checker stdout, but if empty try stderr
    res = res.nil? || res.empty? ? stderr.read&.strip : res
    return { res: res, code: wait_thr.value.exitstatus }
  end
end

def expect_error?(result)
  # treat non-zero exit OR "Error" in stderr/out as an error
  return true if result[:status] != 0
  return true if result[:err] && result[:err].include?("Error")
  return true if result[:out] && result[:out].include?("Error")
  false
end

# Define tests
tests = [
  { name: "no arguments (should not crash)", type: :no_args },
  { name: "single number (no-op)", type: :ok, args: ["42"] },
  { name: "two numbers already sorted", type: :ok, args: ["1","2"] },
  { name: "two numbers reversed", type: :ok, args: ["2","1"] },
  { name: "three numbers (already sorted)", type: :ok, args: ["1","2","3"] },
  { name: "three numbers (reverse sorted)", type: :ok, args: ["3","2","1"] },
  { name: "duplicate numbers -> ERROR", type: :should_error, args: ["1","2","2"] },
  { name: "non-numeric token -> ERROR", type: :should_error, args: ["1","a","3"] },
  { name: "empty token in quoted string -> ERROR", type: :should_error, quoted: true, arg_string: "1  2  3  " }, # double-space can create empty token for some parsers
  { name: "quoted string input (many numbers) -> OK", type: :ok, quoted: true, arg_string: "5 4 3 2 1" },
  { name: "+ and - signs accepted", type: :ok, args: ["-1","+2","3"] },
  { name: "leading zero numbers", type: :ok, args: ["001","2","3"] },
  { name: "INT_MAX boundary accepted", type: :ok, args: ["2147483647","0"] },
  { name: "INT_OVERFLOW -> ERROR", type: :should_error, args: ["2147483648","0"] },
  { name: "INT_MIN boundary accepted", type: :ok, args: ["-2147483648","0"] },
  { name: "INT_UNDERFLOW -> ERROR", type: :should_error, args: ["-2147483649","0"] },
  { name: "very long single quoted string with many spaces (parser robustness)", type: :ok, quoted: true, arg_string: (1..20).to_a.reverse.join(' ') },
  { name: "already sorted long-ish (20 numbers)", type: :ok, args: (1..20).to_a.map(&:to_s) },
  { name: "reverse sorted long-ish (20 numbers)", type: :ok, args: (1..20).to_a.reverse.map(&:to_s) }
]

results = []

puts "Running push_swap edge-case battery (checker: #{CHECKER_CMD.inspect})"
puts "-" * 72

tests.each_with_index do |t,i|
  print "#{i+1}. #{t[:name]} ... "
  case t[:type]
  when :no_args
    stdout, stderr, status = Open3.capture3(PUSH_CMD)
    success = (status.exitstatus == 0) || (status.exitstatus != nil) # we just assert "no crash"
    results << {test: t[:name], ok: success, details: {exit: status.exitstatus, out: stdout, err: stderr}}
    puts success ? "NO CRASH (ok)" : "CRASH/ERR"
  when :should_error
    if t[:quoted]
      r = run_push_swap_single_arg(t[:arg_string])
    else
      r = run_push_swap_args(t[:args])
    end
    ok = expect_error?(r)
    results << {test: t[:name], ok: ok, details: r}
    puts ok ? "ERROR detected (ok)" : "FAILED: no error"
  when :ok
    if t[:quoted]
      r = run_push_swap_single_arg(t[:arg_string])
      args_for_checker = t[:arg_string].split(/\s+/)
    else
      r = run_push_swap_args(t[:args])
      args_for_checker = t[:args]
    end

    if r[:status] < 0
      results << {test: t[:name], ok: false, details: r}
      puts "CRASHED"
      next
    end

    moves = r[:out] || ""
    # If push_swap printed "Error" treat as failure
    if r[:err] && r[:err].include?("Error")
      results << {test: t[:name], ok: false, details: r}
      puts "FAILED (push_swap printed Error)"
      next
    end

    # If no moves produced, it's OK only if already sorted / trivial; still run checker to be sure
    check = run_checker_with_moves(args_for_checker, moves)
    ok = (check[:res] == "OK")
    results << {test: t[:name], ok: ok, details: r.merge({checker: check})}
    puts ok ? "OK (sorted)" : "KO or checker error: #{check[:res].inspect}"
  else
    results << {test: t[:name], ok: false, details: "unknown test type"}
    puts "SKIP (unknown)"
  end
end

puts "\nSummary:"
ok_count = results.count { |r| r[:ok] }
puts "#{ok_count}/#{results.size} tests passed."
results.each do |r|
  puts "- #{r[:test]} : #{r[:ok] ? 'PASS' : 'FAIL'}"
end

# Save failing cases to a file for easier debugging
failed = results.select { |r| !r[:ok] }
if failed.any?
  File.write("push_swap_edgecase_failures.json", JSON.pretty_generate(failed))
  puts "\nDetails for failing tests written to push_swap_edgecase_failures.json"
else
  puts "\nAll edge-case tests passed (according to expectations in this script)."
end
