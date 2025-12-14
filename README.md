This project has been created as part of the 42 curriculum by ***ccavalca***.
# push_swap

## Description
The **push_swap** project is a simple yet highly structured algorithmic challenge: data sorting.

You have at your disposal a set of integer values, 2 stacks (Stack A and Stack B), and a set of instructions to manipulate both stacks. The goal is to write a program in C called `push_swap` that calculates and displays the shortest sequence of instructions needed to sort the given integers in ascending order.

This project focuses on the implementation of sorting algorithms, the concept of complexity (Big O notation), and rigorous memory management in C.

**Objectives:**
* Sorting algorithms.
* Battery of operations on stacks.
* Complexity analysis.
* Algorithm optimization.

## Instructions

### Compilation
To compile the project, clone the repository and run the `make` command in the root directory. This project complies with the 42 Norm and includes a Makefile with the required rules (`NAME`, `all`, `clean`, `fclean`, `re`).
```
bash
git clone <repository_url>
cd push_swap
make
```

### Execution
The program takes a list of integers as arguments.
```
bash
./push_swap <list_of_integers>
```

### Example
```
bash
./push_swap 2 1 3 6 5 8
```

If the arguments are valid, the program outputs a list of operations separated by newlines to sort the stack. If there are errors (non-integers, duplicates, overflow), it displays "Error" on the standard error output.
Operations Reference

The allowed operations are:

    sa (swap a): Swap the first 2 elements at the top of stack a.

    sb (swap b): Swap the first 2 elements at the top of stack b.

    ss: sa and sb at the same time.

    pa (push a): Take the first element at the top of b and put it at the top of a.

    pb (push b): Take the first element at the top of a and put it at the top of b.

    ra (rotate a): Shift up all elements of stack a by 1.

    rb (rotate b): Shift up all elements of stack b by 1.

    rr: ra and rb at the same time.

    rra (reverse rotate a): Shift down all elements of stack a by 1.

    rrb (reverse rotate b): Shift down all elements of stack b by 1.

    rrr: rra and rrb at the same time.

### Resources

> [!TIP]
>**References**
	[Classificação DSA Radix ](https://www-w3schools-com.translate.goog/dsa/dsa_algo_radixsort.php?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc)
	[Radix Sort Algorithm](https://www.interviewcake.com/concept/java/radix-sort)

>[!CAUTION]
>Tasks assisted by AI:

    Concept Explanation: [Used AI to understand the difference between Quick Sort and Radix Sort complexity and organize the logical structure of the project.]

	Productivity: [Used AI to help control the tasks during the implemantation of the project.]

    Debugging: [Used AI to help identify a segmentation fault in the linked list implementation.]

    Documentation: [Used AI to generate a template for this README file.]

    Testing: [Asked AI for edge-case lists of numbers to test the parser.]

Note: All code logic was reviewed and validated manually to ensure compliance with the project rules and standard C library limitations.