# Push swap

Sorting algorithm project for the 42 curriculum. Write a program that outputs the **shortest possible** sequence of stack operations to sort a list of integers using two stacks (`a`, `b`).

## Requirements
- **Language:** C
- **Compiler:** `cc` with `-Wall -Wextra -Werror`
- **Build:** `make`
- **I/O:**
  - **Input:** space-separated integers as program arguments (duplicates and non-integers are invalid)
  - **Output:** one operation per line; no extra prints
  - **Error handling:** print `Error\n` to `STDERR` and exit for invalid input

## Build
```bash
make         # builds push_swap
make clean   # remove .o
make fclean  # remove .o and binaries
make re      # full rebuild
```

## Usage
```bash
./push_swap 2 1 3 6 5 8    # prints a sequence of operations
./push_swap                 # prints nothing for empty input
./push_swap 1 2 3           # prints nothing (already sorted)
```
Check the result with your checker (if provided) or community tools:
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

## Allowed Operations
- **Swaps:** `sa`, `sb`, `ss`
- **Pushes:** `pa`, `pb`
- **Rotations:** `ra`, `rb`, `rr`
- **Reverse rotations:** `rra`, `rrb`, `rrr`

## Constraints & Goals
- Correctly sort **all** valid inputs
- **Minimize moves** (project scoring is based on move counts for specific `N`)
- Run in **reasonable time** for up to 500 numbers
- Be robust: input parsing, duplicate detection, integer limits, overflow checks

## Typical Targets (subject defaults)
- **N ≤ 3:** ≤ 3 moves
- **N ≤ 5:** usually ≤ 12 moves
- **N = 100:** < ~1100 moves for 84 points
- **N = 500:** < ~7000 moves for 84 points


## Strategy Overview
- **Small sets (≤ 5):** hard‑coded decision trees (minimal sequences using `sa/rra/ra` + push/pop).
- **Indexing/Normalization:** map values to ranks `[0..N-1]` to avoid overflow and ease comparisons.
- **Greedy + Cost Model (popular):**
  - For each element in `b`, compute cost to rotate `a` and `b` to place it optimally.
  - Use combined rotations (`rr`/`rrr`) to reduce total moves.
  - Choose minimal‑cost element each iteration; perform rotation + `pa`.
- **Chunking:** push from `a` to `b` in windows (e.g., 20–50 elements) based on rank; reinsert greedily.
- **LIS + Greedy:** keep a **Longest Increasing Subsequence** in `a`, push non‑LIS elements to `b`, then reinsert in order.
- **Radix (base‑2) for simplicity:** stable and fast `O(N log N)`, excellent for 500 but not always best move count.

## Complexity Notes
- **Greedy/Chunk/LIS:** typically near‑linear time with good move counts
- **Radix:** `~N * bits` passes; predictable performance
- Optimize rotation direction and prefer combined rotations to cut moves

## Testing
- Randomized sets:
  ```bash
  ARG=$(seq -100 100 | shuf -n 100); ./push_swap $ARG | ./checker_linux $ARG #linux
  ARG=$(jot -r 100 -1000 1000); ./push_swap $ARG | ./checker_linux $ARG     # macOS
  ```
- Edge cases: already sorted, reverse sorted, near‑sorted, duplicates (must error), min/max `int`, single element
- Measure:
  ```bash
  for n in 5 100 500; do ARG=$(seq 1 $n | shuf); echo -n "$n: "; ./push_swap $ARG | wc -l; done
  ```
- My test: Using ruby script
  ```bash
  ruby test_push_swap_edgecases.rb
  ruby test_push_swap.rb 100
  ruby test_push_swap.rb 500
  ```

## Error Handling
- Reject duplicates, non‑numeric tokens, and overflows (parse into `long`, range‑check against `INT_MIN..INT_MAX`)
- On any error, write **exactly** `Error\n` to `STDERR` and exit non‑zero
- No memory leaks (free all allocations before exit)

## Notes
- Keep operations atomic and validated; avoid printing anything except the operations.
