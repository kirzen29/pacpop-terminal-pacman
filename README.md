# 🕹️ Terminal Pac-Man: A Data-Structure-Driven Arcade Engine
> **High-Performance Terminal Arcade Engine in C/C++ with Graph-Based AI & Dynamic Heap Telemetry**

[![Course](https://img.shields.io/badge/Course-TCS--302%3A%20Data%20Structures%20with%20C-blue.svg)](#)
[![Team ID](https://img.shields.io/badge/Team%20ID-DSCPP--III--2026--T403-brightgreen.svg)](#)
[![Language](https://img.shields.io/badge/Language-C%20%2F%20C%2B%2B17-orange.svg)](#)
[![Institution](https://img.shields.io/badge/University-Graphic%20Era%20(Deemed%20to%20be%20University)-navy.svg)](#)

---

## 👥 Team: pacpop
* **Pushkal Singh Rathor (Lead)** — Univ ID: `2029079` (Section: ML4)
* **Shourya Sharma** — Univ ID: `2029172` (Section: H)
* **Aryan Gupta** — Univ ID: `2027668` (Section: G)

**Course:** `TCS-302: Data Structures with C` (PBL Phase-I)  
**Department:** Department of Computer Science \& Engineering, Graphic Era (Deemed to be University), Dehradun

---

## 📌 Project Synopsis & Abstract
Commercial game development typically abstracts low-level memory allocation and core search algorithms behind heavy third-party engines. This project designs and implements a high-performance, zero-dependency **Terminal Pac-Man arcade engine** built from scratch in C/C++ for **TCS-302 (Data Structures with C)**.

The system maps core arcade mechanics directly to foundational **Data Structures and Algorithms (DSA)**:
1. **2D Matrix Array:** Instant $O(1)$ spatial coordinate lookups for wall collision detection and pellet eating.
2. **Dynamic Singly Linked List:** Heap-allocated move telemetry and player scoring history without static buffer overflow risks.
3. **Circular FIFO Queue:** Asynchronous input buffering to eliminate dropped keystrokes during high-speed corner turns.
4. **Graph BFS Pathfinding:** Corridor grid conversion into an unweighted graph where Breadth-First Search (BFS) computes optimal shortest paths for multi-mode Ghost AI (*Chase, Scatter, Frightened*).
5. **LIFO Stack:** Game-state snapshot manager for real-time pause, resume, and undo/rewind mechanics.
6. **Disjoint Set Union (DSU / Kruskal's):** Procedural generation of 100% solvable random mazes for advanced stages.

The final outcome is a fully functional, cross-platform terminal arcade game delivering deterministic execution, Valgrind-verified zero memory leaks, and quantitative benchmarks comparing Graph BFS heuristics against stochastic movement models.

---

## 🧠 Data Structure Mapping

| Data Structure | Implementation in `pacpop` | Time / Space Complexity |
| :--- | :--- | :---: |
| **2D Matrix Array** | Spatial grid mapping, wall boundaries, pellet states | $O(1)$ Collision Lookup |
| **Singly Linked List** | Dynamic move history and score telemetry allocated on Heap | $O(1)$ Push / $O(N)$ Space |
| **Circular FIFO Queue** | Input event buffering to prevent dropped keystrokes at corners | $O(1)$ Enqueue / Dequeue |
| **LIFO Stack** | Game-state snapshots for real-time Pause, Resume & Rewind | $O(1)$ Snapshot Push/Pop |
| **Graph & BFS** | Unweighted grid traversal for intelligent shortest-path Ghost AI | $O(V + E)$ Traversal |
| **Disjoint Set Union (DSU)** | Kruskal's algorithm for procedural solvable maze generation | $O(E \log V)$ Generation |

---

## 📜 License
Developed as part of the **Project-Based Learning (PBL)** curriculum at **Graphic Era (Deemed to be University)**.
