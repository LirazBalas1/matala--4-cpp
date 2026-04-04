# K-ary Tree with STL-Compatible Iterators

A generic, template-based k-ary tree implementation in C++ with multiple traversal iterators and SFML visualization.

## Overview

This project implements a container representing a k-ary tree (a tree where each node has at most k children). The tree is generic -- it supports keys of any type (numbers, strings, custom classes). By default, k=2 (binary tree).

## Features

- **Generic Template Design** -- Works with any key type via C++ templates
- **Configurable Arity** -- Binary tree by default, supports any k value
- **6 Traversal Iterators:**

| Iterator | Description | Scope |
|----------|-------------|-------|
| Pre-Order | Root, Left, Right | Binary trees (falls back to DFS for k>2) |
| Post-Order | Left, Right, Root | Binary trees (falls back to DFS for k>2) |
| In-Order | Left, Root, Right | Binary trees (falls back to DFS for k>2) |
| BFS | Breadth-first (level-order) | All k-ary trees |
| DFS | Depth-first traversal | All k-ary trees |
| Heap | Converts binary tree to min-heap | Binary trees |

- **SFML Visualization** -- Graphical rendering of tree structure

## API

```cpp
Tree<int> tree;                    // Binary tree (k=2)
Tree<string, 3> tree3;             // Ternary tree (k=3)

tree.add_root(node);               // Set root node
tree.add_sub_node(parent, child);  // Add child to parent

// Traversal iterators
for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) { ... }
for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) { ... }
for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) { ... }
auto heap_it = tree.myHeap();      // Min-heap conversion
```

## Build and Run

```bash
git clone https://github.com/LirazBalas1/kary-tree-iterators-cpp.git
cd kary-tree-iterators-cpp
make
./tree
make test   # Run tests
```

## Requirements

- C++11 or higher
- SFML library (for visualization)
- doctest (for testing)
