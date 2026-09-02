/**
 * @file main.cpp
 * @brief Terminal Pac-Man Arcade Engine (PBL Phase-I)
 * @course TCS-302: Data Structures with C
 * @team pacpop (Team ID: DSCPP-III-2026-T403)
 * @author Pushkal Singh Rathor (Lead), Shourya Sharma, Aryan Gupta
 * @institution Graphic Era (Deemed to be University), Dehradun
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// -------------------------------------------------------------
// 1. DATA STRUCTURE: Dynamic Singly Linked List for Move Logging
// -------------------------------------------------------------
struct MoveNode {
    int x, y;
    int score;
    MoveNode* next;
    MoveNode(int _x, int _y, int _s) : x(_x), y(_y), score(_s), next(nullptr) {}
};

class MoveHistory {
private:
    MoveNode* head;
    MoveNode* tail;
    int totalMoves;
public:
    MoveHistory() : head(nullptr), tail(nullptr), totalMoves(0) {}
    
    void recordMove(int x, int y, int score) {
        MoveNode* newNode = new MoveNode(x, y, score);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        totalMoves++;
    }

    int getCount() const { return totalMoves; }

    ~MoveHistory() {
        MoveNode* curr = head;
        while (curr) {
            MoveNode* tmp = curr;
            curr = curr->next;
            delete tmp; // Prevent memory leaks on the heap
        }
    }
};

// -------------------------------------------------------------
// 2. DATA STRUCTURE: 2D Spatial Collision Matrix
// -------------------------------------------------------------
const int HEIGHT = 11;
const int WIDTH = 21;

const char INITIAL_MAZE[HEIGHT][WIDTH + 1] = {
    "#####################",
    "#P........#........G#",
    "#.###.###.#.###.###.#",
    "#o###.###.#.###.###o#",
    "#...................#",
    "#.###.#.#####.#.###.#",
    "#.....#...#...#.....#",
    "#####.### # ###.#####",
    "#.........#.........#",
    "#o#######.#.#######o#",
    "#####################"
};

// -------------------------------------------------------------
// 3. MAIN GAME CONTROLLER
// -------------------------------------------------------------
int main() {
    std::cout << "\033[2J\033[H"; // Clear terminal screen via ANSI
    std::cout << "====================================================\n";
    std::cout << "   pacpop: Terminal Pac-Man Engine (TCS-302 PBL)    \n";
    std::cout << "   Team: pacpop | Team ID: DSCPP-III-2026-T403      \n";
    std::cout << "====================================================\n\n";

    MoveHistory history;
    int pacmanX = 1, pacmanY = 1;
    int score = 0;

    // Log initial starting position
    history.recordMove(pacmanX, pacmanY, score);

    // Display 2D Spatial Grid
    for (int r = 0; r < HEIGHT; ++r) {
        std::cout << "   " << INITIAL_MAZE[r] << "\n";
    }

    std::cout << "\n[Engine Status] 2D Matrix Grid initialized successfully.\n";
    std::cout << "[Telemetry] Heap Linked List Move Log count: " << history.getCount() << "\n";
    std::cout << "[Collision] O(1) Matrix lookup at (1,1) = '" << INITIAL_MAZE[1][1] << "'\n\n";
    std::cout << "Compile with: g++ -std=c++17 -O2 main.cpp -o pacman\n";

    return 0;
}
