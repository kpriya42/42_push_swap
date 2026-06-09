*This project has been created as part of the 42 curriculum by kri-, meqian.*

# push_swap

## Description

`push_swap` is a 42 School algorithm project. The goal is to sort a list of unique integers using two stacks, named `a` and `b`, and a limited set of stack operations. The program receives integers as command-line arguments and prints the smallest practical sequence of operations needed to sort stack `a` in ascending order.

The challenge is not only to produce a correct sort, but also to minimize the number of operations. This implementation uses several strategies depending on the size and disorder of the input:

- direct small-size sorting for 2 to 5 numbers;
- insertion-based sorting for low-disorder inputs;
- chunk-based sorting for medium-disorder inputs;
- binary radix sorting for high-disorder or large inputs;
- an adaptive mode that chooses a strategy automatically.

The project also includes argument validation, index normalization, operation counting, and an optional benchmark mode.

## Rules and Available Operations

Only the following operations are allowed:

| Operation | Description |
| --- | --- |
| `sa` | Swap the first two elements of stack `a`. |
| `sb` | Swap the first two elements of stack `b`. |
| `ss` | Perform `sa` and `sb` at the same time. |
| `pa` | Push the first element of stack `b` to stack `a`. |
| `pb` | Push the first element of stack `a` to stack `b`. |
| `ra` | Rotate stack `a` upward. |
| `rb` | Rotate stack `b` upward. |
| `rr` | Perform `ra` and `rb` at the same time. |
| `rra` | Reverse rotate stack `a`. |
| `rrb` | Reverse rotate stack `b`. |
| `rrr` | Perform `rra` and `rrb` at the same time. |

## Project Structure

```text
.
├── include/
│   └── push_swap.h
├── libft/
│   ├── Makefile
│   └── *.c / *.h
├── src/
│   ├── algo_simple.c
│   ├── algo_medium.c
│   ├── algo_complex.c
│   ├── bench_output.c
│   ├── check_args.c
│   ├── clean_args.c
│   ├── init_stack.c
│   ├── main.c
│   ├── operation_*.c
│   ├── push_swap.c
│   └── push_swap_utils_*.c
└── Makefile
```

## Instructions

### Compilation

Compile the project from the repository root:

```bash
make
```

This builds the `push_swap` executable and links it with `libft`.

Available Makefile rules:

```bash
make        # Compile push_swap
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Rebuild from scratch
```

### Execution

Run the program with a list of unique integers:

```bash
./push_swap 3 2 1
```

Expected output example:

```text
sa
rra
```

The exact sequence may differ depending on the selected strategy, but it must sort the stack correctly.

The program also supports quoted input:

```bash
./push_swap "3 2 1 6 5 8"
```

### Checking the Result

When using the official Linux checker:

```bash
ARG="3 2 1 6 5 8"
./push_swap $ARG | ./checker_linux $ARG
```

Expected result:

```text
OK
```

### Error Handling

The program prints `Error` to standard error when the input is invalid, for example:

- non-numeric arguments;
- duplicated integers;
- values outside the signed integer range;
- empty or whitespace-only arguments.

Examples:

```bash
./push_swap 1 2 2
# Error

./push_swap 1 abc 3
# Error

./push_swap 2147483648
# Error
```

## Optional Flags

This implementation supports optional strategy flags:

```bash
./push_swap --simple  5 1 4 2 3
./push_swap --medium  5 1 4 2 3
./push_swap --complex 5 1 4 2 3
./push_swap --adaptive 5 1 4 2 3
```

If no strategy flag is provided, adaptive mode is used by default.

Benchmark mode prints diagnostic information to standard error:

```bash
./push_swap --bench 5 1 4 2 3
```

The benchmark output includes the measured disorder, selected strategy, total operation count, and per-operation counts.

## Algorithm Explanation and Justification

### 1. Index Normalization

Before sorting, each integer is assigned an index based on its rank in the sorted order. For example:

```text
values:  40  -3  12
indexes:  2   0   1
```

This normalization is useful because the algorithms can compare compact indexes instead of raw integer values. It also makes radix sorting possible, since radix works naturally on non-negative integer ranks.

Justification:

- handles negative numbers without special radix cases;
- avoids overflow-prone arithmetic on original values;
- converts the problem into sorting values from `0` to `n - 1`.

### 2. Small Sort: 2 to 5 Elements

For very small inputs, the program uses direct logic instead of a general sorting algorithm.

- For 2 elements, it swaps if necessary.
- For 3 elements, it places the maximum element correctly using `ra` or `rra`, then applies `sa` if needed.
- For 4 or 5 elements, it pushes the smallest elements to stack `b`, sorts the remaining 3 elements, then pushes the saved elements back to stack `a`.

Justification:

Small inputs have predictable optimal or near-optimal patterns. A general-purpose algorithm would create unnecessary operations, while direct handling keeps the move count low and the implementation simple.

### 3. Insertion-Based Sort: Low-Disorder Inputs

The insertion-based strategy is used for inputs that are already close to sorted.

The idea is similar to insertion sort, adapted to the two-stack `push_swap` model:

1. Move elements from stack `a` to stack `b`.
2. Keep stack `b` in a useful circular order.
3. Find the correct insertion position for each value.
4. Rotate stack `b` using the shortest path before pushing.
5. Push everything back to stack `a`.

The implementation uses helpers such as `find_min_node`, `find_max_node`, `get_node_pos`, and `rotate_to_top` to determine where an element belongs and whether `rb` or `rrb` is cheaper.

Justification:

Insertion-based sorting performs well when the input is nearly sorted because only a limited number of elements need significant movement. For low-disorder data, this can produce fewer operations than radix sorting, which always performs several full passes over the stack.

Complexity:

- approximate time complexity: `O(n²)`;
- practical advantage: good operation count on nearly sorted input.

### 4. Chunk-Based Sort: Medium-Disorder Inputs

The medium strategy divides the indexed values into chunks. The chunk size is chosen around the square root of the input size.

The algorithm works in two main phases:

1. Move elements from stack `a` to stack `b` chunk by chunk.
2. Repeatedly bring the maximum element of stack `b` to the top and push it back to stack `a`.

Because the largest remaining element is always pushed back first, stack `a` is rebuilt in sorted order.

Justification:

Chunk sorting is a compromise between insertion sorting and radix sorting. It reduces the search space by grouping values, which avoids the heavy cost of pure insertion sort on more random inputs, while often producing fewer operations than radix for medium-sized or moderately disordered inputs.

Complexity:

- approximate practical complexity: `O(n√n)`;
- useful for medium-disorder inputs where insertion sort becomes expensive but radix may still be too mechanical.

### 5. Radix-Based Sort: High-Disorder or Large Inputs

The complex strategy uses a binary radix sort on normalized indexes.

For each bit position, from least significant to most significant:

1. Inspect the bit of the index at the top of stack `a`.
2. If the bit is `1`, rotate stack `a` using `ra`.
3. If the bit is `0`, push the element to stack `b` using `pb`.
4. After one full pass, push everything from `b` back to `a` using `pa`.

After all required bits have been processed, stack `a` is sorted.

Justification:

Radix sort is deterministic and reliable for large or highly disordered inputs. Its operation count is predictable because it depends mainly on the number of elements and the number of bits required to represent the largest index.

Complexity:

- approximate time complexity: `O(n log n)` for binary index radix;
- predictable and stable performance on random large inputs;
- avoids the worst-case behavior of insertion-based approaches.

### 6. Adaptive Strategy

Adaptive mode chooses the algorithm based on the size and disorder of the input.

The disorder score is computed by counting inverted pairs:

```text
for each pair (i, j), where i appears before j:
    if value[i] > value[j], count it as a disorder pair

disorder = disorder_pairs / total_pairs
```

The current thresholds are:

| Condition | Strategy |
| --- | --- |
| `size <= 5` | Small direct sort |
| `disorder < 0.2` | Insertion-based sort |
| `disorder > 0.5` | Radix-based sort |
| `disorder >= 0.2 and =< 0.5` | Chunk-based sort |

Justification:

No single sorting strategy is best for every input. Adaptive selection allows the program to use the strengths of each algorithm:

- small sort for tiny inputs;
- insertion sort for nearly sorted data;
- chunk sort for moderate disorder;
- radix sort for highly disordered data.

This design prioritizes practical operation count while keeping the code modular and testable.

## Testing Examples

Generate random arguments and test with the checker:

```bash
ARG=$(seq -100 100 | shuf | head -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
```

Count the number of operations:

```bash
ARG="5 1 4 2 3"
./push_swap $ARG | wc -l
```

Use benchmark mode:

```bash
./push_swap --bench $ARG >/dev/null
```

## Technical Choices

- **Language:** C
- **Build system:** Makefile
- **Data structure:** doubly linked list stack
- **Utility library:** custom `libft`
- **Sorting model:** two-stack constrained sorting
- **Validation:** strict integer parsing, duplicate detection, and whitespace checks

A doubly linked list was selected because stack operations such as push, rotate, and reverse rotate can be implemented naturally by relinking nodes instead of shifting array elements.

## Resources

Classic references and useful learning materials:

- 42 School `push_swap` subject PDF
- 42 School `libft` project documentation
- GNU Make Manual: <https://www.gnu.org/software/make/manual/>
- C reference documentation: <https://en.cppreference.com/w/c>
- Radix sort explanation: <https://www.geeksforgeeks.org/radix-sort/>
- Insertion sort explanation: <https://www.geeksforgeeks.org/insertion-sort-algorithm/>
- Stack data structure overview: <https://www.geeksforgeeks.org/stack-data-structure/>
- Algorithm complexity overview: <https://www.bigocheatsheet.com/>

### AI Usage

AI was used to help prepare and improve this README.

AI was also used to understand algorithmic complexity and various sorting algorithms

## Notes

This project follows the 42 School style and norm requirements.
