

---

# Organizational Chart with Iterators

This project implements a class, `OrgChart`, that represents a hierarchical organizational structure along with various iterators to traverse this structure.

## Overview

The `OrgChart` class models an organizational structure in a hierarchy. The structure can be navigated using different types of iterators that provide level-order, reverse-level-order, and depth (pre-order) traversal.

### Features

- **Level-Order Traversal:** Starts from the top of the organization (e.g., CEO) and moves down horizontally through the various ranks to the most junior object in the organization.
- **Reverse-Level-Order Traversal:** Starts from the most junior levels in the organization and moves up transversely through the ranks until it reaches the top of the organization.
- **Depth (Pre-Order) Traversal:** Similar to the pre-order traversal method on a binary tree, only that our tree is not binary.

## Class Methods

The `OrgChart` class includes the following key methods:

- `add_root(input)`: Places the input at the root of the tree. If there's already a root, it is replaced.
- `add_sub(input1, input2)`: Adds a subordinate to a person or a department already existing in the organizational structure.
- `begin_level_order()`, `end_level_order()`: Return iterators for level-order traversal.
- `begin_reverse_order()`, `end_reverse_order()`: Return iterators for reverse-level-order traversal.
- `begin_preorder()`, `end_preorder()`: Return iterators for pre-order traversal.

## Usage

To compile and run the demo, use the following commands:

```bash
make demo && ./demo
```

To run the tests:

```bash
make test && ./test
```

## Additional Information

The project also includes `make tidy` and `make valgrind` commands for code cleanup and memory leak checks. The main program demonstrates the use of iterators and operators, along with standard library algorithms for creative problem-solving.

---
