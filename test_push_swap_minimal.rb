#!/usr/bin/env ruby
# Usage:
#   ruby test_push_swap_minimal.rb
#   or, if your checker needs Rosetta:
#   CHECKER_CMD="arch -x86_64 ./checker_Mac" ruby test_push_swap_minimal.rb

require 'set'

# Commands (change if needed)
PUSH_CMD    = ENV['PUSH_CMD']    || "./push_swap"
CHECKER_CMD = ENV['CHECKER_CMD'] || "./checker_Mac"

def gen_unique_numbers(count, range_min = -1_000_000, range_max = 1_000_000)
  s = Set.new
  s << rand(range_min..range_max) while s.size < count
  s.to_a.shuffle
end

def run_case(count)
  nums = gen_unique_numbers(count)
  args = nums.join(' ')
  puts "\n--- Running test for #{count} numbers ---"
  puts "Sample (first 20): #{nums.first(20).join(' ')}#{' ...' if nums.size > 20}"

  # Run push_swap and capture moves
  print "Running push_swap..."
  moves = %x(#{PUSH_CMD} #{args})
  ops = moves.lines.count
  puts " done (#{ops} ops)"

  # Feed moves to checker
  checker_res = nil
  IO.popen("#{CHECKER_CMD} #{args}", "r+") do |chk|
    chk.write moves
    chk.close_write
    checker_res = chk.read&.strip
  end

  puts "Checker result: #{checker_res}"
  puts "Operations: #{ops}"
  return { count: count, checker: checker_res, ops: ops }
end

# run tests
res100 = run_case(100)
res500 = run_case(500)

# Minimal validation combos (use strict "under" as requested)
combo1 = (res100[:ops] < 1100) && (res500[:ops] < 8500)
combo2 = (res100[:ops] < 700)  && (res500[:ops] < 11500)
combo3 = (res100[:ops] < 1300) && (res500[:ops] < 5500)

ok100 = res100[:checker] == "OK"
ok500 = res500[:checker] == "OK"

puts "\n=== Summary ==="
puts "100 numbers: checker=#{res100[:checker]}  ops=#{res100[:ops]}"
puts "500 numbers: checker=#{res500[:checker]}  ops=#{res500[:ops]}"

if !ok100 || !ok500
  puts "\n❌ FAIL: checker did not return OK for one or both tests."
  puts "Make sure your push_swap output contains only valid moves and sorts correctly."
else
  passed = []
  passed << "Combo 1 (100<1100 & 500<8500)"  if combo1
  passed << "Combo 2 (100<700  & 500<11500)" if combo2
  passed << "Combo 3 (100<1300 & 500<5500)"  if combo3

  if passed.any?
    puts "\n✅ Minimal requirement PASSED!"
    puts "Matching combinations:"
    passed.each { |c| puts "  - #{c}" }
  else
    puts "\n⚠️ Minimal requirement NOT met."
    puts "None of the three required combinations were satisfied."
  end
end
