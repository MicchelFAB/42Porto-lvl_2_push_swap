# 42Porto-lvl_2_push_swap

## Core of the Project

The `push_swap` project is a sorting algorithm project that involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack with the fewest number of moves possible. The project is part of the 42 Network curriculum and is designed to test your understanding of algorithms, data structures, and optimization techniques.

## Limitation of Moves

In the `push_swap` project, you are limited to a specific set of operations to manipulate the stack. These operations are:

- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: Swap the first two elements of both stacks A and B.
- `pa`: Push the top element of stack B onto stack A.
- `pb`: Push the top element of stack A onto stack B.
- `ra`: Rotate stack A upwards (the first element becomes the last).
- `rb`: Rotate stack B upwards (the first element becomes the last).
- `rr`: Rotate both stacks A and B upwards.
- `rra`: Reverse rotate stack A (the last element becomes the first).
- `rrb`: Reverse rotate stack B (the last element becomes the first).
- `rrr`: Reverse rotate both stacks A and B.

The challenge is to use these operations efficiently to sort the stack with the minimum number of moves.

## Algorithm Used

In this project, I used a custom algorithm that combines elements of the Quick Sort and Merge Sort algorithms. The algorithm works by dividing the stack into smaller sub-stacks, sorting them individually, and then merging them back together. This approach allows for efficient sorting with a limited number of moves.

### Why My Algorithm is Better than TURK and RADIX

The TURK and RADIX algorithms are popular sorting algorithms, but they have some limitations when it comes to sorting stacks with a limited set of operations. My custom algorithm is better because:

1. It takes advantage of the specific operations available in the `push_swap` project, allowing for more efficient sorting.
2. It minimizes the number of moves required to sort the stack, which is the primary goal of the project.
3. It is more adaptable to different stack sizes and configurations, making it a more versatile solution.

## Usage

To use the `push_swap` program, compile the source code and run the executable with a list of integers as arguments. For example:

```sh
make
./push_swap 3 2 5 1 4
```

The program will output a sequence of operations that will sort the stack.

## Bonus: Checker

The bonus part of the project involves creating a checker program that verifies whether a given sequence of operations correctly sorts the stack. The checker complements the mandatory part of the project by providing a way to validate the correctness of the sorting algorithm.

The checker program reads a sequence of operations from the standard input and applies them to the stack. It then checks if the stack is sorted correctly and outputs "OK" if it is, or "KO" if it is not. This helps ensure that the sorting algorithm works as intended and provides a useful tool for debugging and testing.

## Usage

To use the `checker` program, compile the source code and run the executable with a list of integers as arguments. Then, provide a sequence of operations through standard input. For example:

```sh
make bonus
./checker 3 2 5 1 4
```

Then, input the operations:

```sh
pb
pb
sa
pa
pa
```

The program will output "OK" if the stack is sorted correctly, or "KO" if it is not.

## References

- This project was inspired by the `push_swap` repository by `mcombeau`. You can find it [here](https://github.com/mcombeau/push_swap).
- I also used a tester that I forked from [Push-Swap-Tester](https://github.com/MicchelFAB/Push-Swap-Tester).

