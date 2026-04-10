*This project has been created as part of the 42 curriculum by roblomba*

---

# Push_Swap

## Description

Push_swap is a sorting algorithm project that orders a list of integers using two stacks (A and B) and a limited set of operations. The goal is to sort numbers with the **minimum number of moves possible**.

## Feature List
- Supports integers from INT_MIN to INT_MAX
- Accepts input in multiple formats
- Validates input and handles errors gracefully
- Implements 11 different operations
- Uses optimized Turk algorithm (< 700 moves for 100 numbers)

---

## Instructions

### Compilation

```bash
make          # Compile the program
make clean    # Remove .o files
make fclean   # Remove all generated files
make re       # Recompile from scratch
```

## Usage Examples

```bash
./push_swap 3 2 1              # Separate numbers
./push_swap "5 2 7 1 9"        # Space-separated string
./push_swap "3 2" 1 "5 4"      # Mixed format
```

**Output:** Prints operations needed to sort (one per line). No output if already sorted.

### Error Handling

Outputs "Error" if:
- Arguments are not valid integers
- Duplicates exist  
- Integer overflow (> INT_MAX or < INT_MIN)
- No arguments provided

---

## Resources

### References
- YouTube walkthroughs on push_swap, stack-based sorting, and rotation strategies
- Medium articles on greedy insertion sorting and rotation cost optimization

### The Turk Algorithm

This project implements an optimized insertion-based approach:

1. **Push Phase:** Move all but 3 elements from A to B
2. **Sort Phase:** Sort the remaining 3 in A (hardcoded optimal solution)
3. **Insertion Phase:** Reinsert elements from B to A, always choosing the "cheapest" (fewest rotations)
4. **Finalize:** Rotate minimum to the top

### AI Usage

Assistance from AI tools was used for:
- Explaining complex functions (swap, push, Turk algorithm, cost calculations)
- Spotting logical errors in rotation/cost handling
- Drafting documentation and comments
- Suggesting minor optimizations for dual rotations and cost logic

---

## Operations

| Operation | Effect |
|-----------|--------|
| `sa`, `sb`, `ss` | Swap first 2 elements |
| `pa`, `pb` | Push top from B→A (or A→B) |
| `ra`, `rb`, `rr` | Rotate up (last→first) |
| `rra`, `rrb`, `rrr` | Rotate down (first→last) |

---

## Performance

- **100 numbers:** ~600-800 moves
- **500 numbers:** ~4500-5500 moves
- **Time complexity:** O(n²) average case
- **Space complexity:** O(n)

---

## Technical Choices

- **Two stacks (A/B):** Enables simultaneous rotations (rr/rrr) and cheaper insertions
- **Doubly linked list nodes:** Fast head/tail access and reverse rotations
- **Greedy insertion:** Always move the cheapest element back to A to minimize total moves

---


## Testing

```bash
# Verify sorting
./push_swap 3 2 1 | ./checker_linux 3 2 1   # Output: OK

# Performance test (100 numbers)
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l
