# 🕹️ pacpop: Terminal Pac-Man Arcade Engine
> **Data-Structure-Driven Retro Arcade Engine with Graph-Based AI & Dynamic Heap Telemetry**

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
**Department:** Department of Computer Science & Engineering, Graphic Era (Deemed to be University), Dehradun

---

## 📌 Project Overview
Commercial game engines hide low-level memory allocation and search heuristics behind pre-built abstractions. **pacpop** is a high-performance, zero-dependency terminal arcade engine written from scratch in C/C++ to demonstrate how foundational **Data Structures and Algorithms (DSA)** power real-time games.

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

## 🚀 Key Features
- **Zero Third-Party Dependencies:** Pure C/C++ standard runtime with native ANSI terminal control.
- **Instant $O(1)$ Collision Detection:** Matrix coordinate lookups with zero latency.
- **Dynamic Memory Safety:** Custom heap-allocated linked lists with Valgrind-verified leak prevention.
- **Responsive Input Buffer:** Smooth corner turning through asynchronous circular queue buffering.
- **Intelligent Enemy Pathfinding:** Graph-based BFS search replacing stochastic random-walk algorithms.

---

## 🛠️ Build & Run Instructions

### Prerequisites
* GCC / G++ (supporting C++17 or C11)
* CMake (optional, $\ge 3.10$)

### Compilation (Single Command)
```bash
# Compile with g++
g++ -std=c++17 -O2 main.cpp -o pacman

# Run the game
./pacman
```

### Controls
* `W` : Move Up
* `A` : Move Left
* `S` : Move Down
* `D` : Move Right
* `P` : Pause / Snapshot
* `Q` : Quit Game

---

## 📂 Project Structure
```
pacpop-terminal-pacman/
├── CMakeLists.txt        # CMake build configuration
├── README.md             # Project documentation
├── main.cpp              # Core game loop & engine entry point
├── include/
│   ├── Engine.hpp        # Game engine loop & state machine
│   ├── Maze.hpp          # 2D Array spatial collision matrix
│   ├── MoveList.hpp      # Custom Singly Linked List telemetry
│   ├── InputQueue.hpp    # Circular FIFO queue input buffer
│   └── GhostAI.hpp       # Graph BFS shortest-path solver
└── docs/
    ├── report.pdf        # PBL Phase-I Project Proposal Report
    └── presentation.pdf  # PBL Phase-I Beamer Presentation
```

---

## 📜 License
Developed as part of the **Project-Based Learning (PBL)** curriculum at **Graphic Era (Deemed to be University)**.
