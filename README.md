<h1 align="center">🎒 Semester 2 Academic Repository</h1>

<p align="center">
  <code>🔧 C (DSA)</code>&nbsp;&nbsp;<code>🐍 Python</code>&nbsp;&nbsp;<code>📊 Pandas</code>&nbsp;&nbsp;<code>🧠 Data Structures</code>&nbsp;&nbsp;<code>⚡ Algorithms</code>
</p>

---

## About This Repository

This directory documents the academic progress and assignments of **Semester 2**. The coursework focuses heavily on:
1. **Data Structures and Algorithms (DSA)** in **C** — covering arrays, pointers, memory allocation, linked lists (singly, circular, doubly), stacks, queues, sorting algorithms, trees (BST), and graphs.
2. **Python Programming** — spanning fundamental algorithms, basic game dev (Blackjack), object-oriented programming, and an introduction to **Pandas** for Python Data Analysis.

---

## Progress

```
 ██████████████████████████████████████████  100% Coursework Completed
```

**Core concepts covered:** Linked Lists (SLL/DLL/CLL) · Stacks & Queues · Sorting (Quick, Merge, Counting) · Binary Search Trees (BST) · Graph Traversals (BFS & DFS) · Python OOP · Python Pandas for Data Analysis · File I/O in Python

---

## Core Topics Breakdown

> Click any section to view folders and individual source code links.

<details open>
<summary><h3>Phase 1 — Python Fundamentals & Projects <code>python/</code></h3></summary>

Features foundational Python exercises, text file tracking, logic puzzles, object-oriented concepts, and standalone terminal games.

| File / Module | Language | Topic | Key Solution Files |
|:---|:---:|:---|:---|
| **Blackjack Game** | Python | Conditional Logic & State | [blackjack.py](python/blackjack.py) / [blackjack1.py](python/blackjack1.py) |
| **Coffee Machine** | Python | Procedural Simulation | [coffemach.py](python/coffemach.py) |
| **Pandas Data Analysis** | Python / Jupyter | Data Analysis basics | [03-Python-for-Data-Analysis-Pandas/](03-Python-for-Data-Analysis-Pandas) |
| **PDF Generation** | Python | Document formatting | [python/python_pdf_genrerator.py](python/python_pdf_genrerator.py) |
| **File Handling** | Python | Text parsing & extraction | [python/experiment10.1.py](python/experiment10.1.py) to [experiment10.7.py](python/experiment10.7.py) |

</details>

<details open>
<summary><h3>Phase 2 — Arrays, Matrices & Basic Sorting/Searching <code>dsa/</code></h3></summary>

Covers matrix addition/multiplication, dynamic arrays, binary/linear search, and classical sorting algorithms (Insertion, Merge, Quick, Counting).

| File | Language | Technique / Topic | Solution Link |
|:---|:---:|:---|:---:|
| `array_insert.c` | C | Array shifting insertion | [array_insert.c](dsa/array_insert.c) |
| `arr.del.c` | C | Array shifting deletion | [arr.del.c](dsa/arr.del.c) |
| `binarysearch.c` | C | Divide and conquer search ($O(\log n)$) | [binarysearch.c](dsa/binarysearch.c) |
| `linear search.c` | C | Sequential search ($O(n)$) | [linear search.c](dsa/linear search.c) |
| `matadd.c` | C | Element-wise 2D array sum | [matadd.c](dsa/matadd.c) |
| `matmult.c` | C | Nested loop 2D matrix product | [matmult.c](dsa/matmult.c) |
| `insertsort.c` | C | In-place element shifting insertion sort | [insertsort.c](dsa/insertsort.c) |
| `merge,sort.c` | C | Divide-and-conquer recursive sort ($O(n \log n)$) | [merge,sort.c](dsa/merge,sort.c) |
| `quick,sort.c` | C | Partitioning-based recursive sorting ($O(n \log n)$) | [quick,sort.c](dsa/quick,sort.c) |
| `counting,sort.c` | C | Non-comparison frequency array sort ($O(n+k)$) | [counting,sort.c](dsa/counting,sort.c) |

</details>

<details open>
<summary><h3>Phase 3 — Linked List structures (Singly, Circular, Doubly) <code>dsa/</code></h3></summary>

Features dynamic memory node-creation, reference manipulation, circular structures, doubly-linked traversals, and polynomial additions.

| Problem / File | Concept | Target Pointer Strategy | Solution Link |
|:---|:---|:---|:---:|
| `ll.c` | SLL Creation | Sequential node hardcoding and traversal | [ll.c](dsa/ll.c) |
| `insertnode.c` | SLL Insert | Insertion at head, tail, or given indices | [insertnode.c](dsa/insertnode.c) |
| `del ll.c` | SLL Deletion | Pointer updates and memory freeing | [del ll.c](dsa/del ll.c) |
| `ll,rev.c` | SLL Reversal | Three-pointer logic (prev, current, next) | [ll,rev.c](dsa/ll,rev.c) |
| `mid,of,ll.c` | Middle Node | Fast/slow (tortoise and hare) pointer lookup | [mid,of,ll.c](dsa/mid,of,ll.c) |
| `check,cll.c` | Circular SLL | Detects if list is circular via tail->head matching | [check,cll.c](dsa/check,cll.c) |
| `insert.cll.c` | Circular Insert | Head / Tail / Position circular pointer shifting | [insert.cll.c](dsa/insert.cll.c) |
| `insert,any,dll.c`| DLL Insertion | Doubly linked nodes (updating `prev` and `next`) | [insert,any,dll.c](dsa/insert,any,dll.c) |
| `del.any.pt.dll.c`| DLL Deletion | Splices nodes out of DLL updates | [del.any.pt.dll.c](dsa/del.any.pt.dll.c) |
| `add,poly,ll.c` | Polynomial Sum | Custom linked list node addition matching exponents | [add,poly,ll.c](dsa/add,poly,ll.c) |

</details>

<details open>
<summary><h3>Phase 4 — Stacks, Queues, Trees & Graphs <code>dsa/</code></h3></summary>

Covers linear stack/queue abstractions (with arrays and lists), Infix/Postfix/Prefix notation conversion, Binary Search Trees (BST), and Breadth-First / Depth-First search.

| File | Language | Structure / Topic | Solution Link |
|:---|:---:|:---|:---:|
| `stack.c` | C | Array-based LIFO stack | [stack.c](dsa/stack.c) |
| `stack.with.ll.c` | C | Linked list-based LIFO stack | [stack.with.ll.c](dsa/stack.with.ll.c) |
| `stack,in,to,post.c`| C | Infix to Postfix converter using operator precedence | [stack,in,to,post.c](dsa/stack,in,to,post.c) |
| `queue,arr.c` | C | Array-based FIFO queue | [queue,arr.c](dsa/queue,arr.c) |
| `queue,ll.c` | C | Linked list-based FIFO queue | [queue,ll.c](dsa/queue,ll.c) |
| `tree,BST.c` | C | BST insertion, search, and pre/in/post-order traversals | [tree,BST.c](dsa/tree,BST.c) |
| `graph.c` | C | Adjacency list and matrix graph representations | [graph.c](dsa/graph.c) |
| `bfs,graph.c` | C | BFS queue-based traversal on adjacency lists | [bfs,graph.c](dsa/bfs,graph.c) |
| `dfs,grapg.c` | C | DFS recursive stack-based traversal on adjacency lists | [dfs,grapg.c](dsa/dfs,grapg.c) |

</details>

---

## Repository Structure

```
sem2/
│
├── 03-Python-for-Data-Analysis-Pandas/  ← Jupyter notebooks + datasets for data analysis
│
├── dsa/                                 ← Data Structures & Algorithms folder (C)
│   ├── Assignment.1.c to Assignment.10.c
│   ├── tree,BST.c                       ← BST Implementation
│   ├── bfs,graph.c                      ← BFS Algorithm
│   ├── dfs,grapg.c                      ← DFS Algorithm
│   └── ...                              ← Linked Lists, sorting, stack, queue files
│
├── python/                              ← Python source files
│   ├── blackjack.py                     ← Blackjack project
│   ├── experiment1.2.py to experiment10.7.py
│   └── ...                              ← Basic Python scripts
│
├── python exp/                          ← Documents & PDF files containing lab files
│   ├── Anmol_590011794_DSA.pdf          ← Compiled DSA lab report
│   ├── Anmol_590011794_Reportt.pdf      ← Python lab report
│   └── ...
│
├── tracker.pdf                          ← Visual tracking report
└── README.md
```

---

## How to Run

<details>
<summary><b>⚡ Compile and Run C (DSA) Code</b></summary>

For compilation, standard gcc tools are used:
```bash
cd dsa
gcc tree,BST.c -o bst
./bst
```

</details>

<details>
<summary><b>🐍 Run Python and Jupyter Notebooks</b></summary>

For running python scripts:
```bash
cd python
python blackjack.py
```

For Jupyter notebooks (using VS Code or notebook environments):
```bash
jupyter notebook "03-Python-for-Data-Analysis-Pandas/01-Pandas-Overview.ipynb"
```

</details>

---

<p align="center">
  <i>"Bad programmers worry about the code. Good programmers worry about data structures and their relationships." — Linus Torvalds</i>
</p>
