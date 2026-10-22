#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#include "spatial_matrix.h"
#include "ghost_ai.h"
#include "move_history.h"

using namespace std;

HANDLE hConsole;

void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void gotoXY(int x, int y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hConsole, coord);
}

class PacmanGame {
public:
    int pacX, pacY;
    int pacDir;
    int bufferedDir;
    int score;
    int lives;
    int tickCount;
    bool running;
    struct Ghost ghosts[3];

    PacmanGame() {
        score = 0;
        lives = 3;
        tickCount = 0;
        running = true;
        resetPositions();
        insertMove(pacX, pacY, score);
    }

    // Reset both Pac-Man and Ghosts to safe starting corners when a life is lost
    void resetPositions() {
        pacX = 9;
        pacY = 11;
        pacDir = 0;
        bufferedDir = 0;
        clearQueue();

        ghosts[0] = {1,  1,  4, 12}; // Top-Left (Red)
        ghosts[1] = {17, 1,  3, 13}; // Top-Right (Pink)
        ghosts[2] = {9,  3,  4, 11}; // Top-Center (Cyan)
    }

    void draw() {
        gotoXY(0, 0);
        setColor(11);
        cout << "====================================================\n";
        cout << "   PAC-MAN ENGINE (TCS-302 Data Structures Project) \n";
        cout << "====================================================\n";

        for (int r = 0; r < ROWS; r++) {
            cout << "   ";
            int lastColor = -1;

            for (int c = 0; c < COLS; c++) {
                // 1. Check Pac-Man
                if (r == pacY && c == pacX) {
                    if (lastColor != 14) { setColor(14); lastColor = 14; }
                    cout << "C ";
                    continue;
                }

                // 2. Check Ghosts
                int ghostHere = -1;
                for (int g = 0; g < 3; g++) {
                    if (r == ghosts[g].y && c == ghosts[g].x) {
                        ghostHere = g;
                        break;
                    }
                }
                if (ghostHere != -1) {
                    int gc = ghosts[ghostHere].color;
                    if (lastColor != gc) { setColor(gc); lastColor = gc; }
                    cout << "G ";
                    continue;
                }

                // 3. Draw Maze Tile
                char tile = maze[r][c];
                if (tile == '#') {
                    if (lastColor != 9) { setColor(9); lastColor = 9; }
                    cout << "##";
                } else if (tile == '.') {
                    if (lastColor != 7) { setColor(7); lastColor = 7; }
                    cout << ". ";
                } else if (tile == 'o') {
                    if (lastColor != 14) { setColor(14); lastColor = 14; }
                    cout << "O ";
                } else {
                    cout << "  ";
                }
            }
            cout << "\n";
        }

        // Live Data Structure Status Panel
        setColor(10);
        cout << "----------------------------------------------------\n";
        cout << " Score: " << score << "   |   Lives: " << lives << "   |   Pos: (" << pacY << "," << pacX << ")   \n";

        cout << " [Linked List] Nodes: " << total_steps;
        if (tail != NULL) {
            cout << " | Last Addr: " << tail << "   \n";
        }
        cout << " [FIFO Queue]  Front: " << front << " | Rear: " << rear << "              \n";
        setColor(7);
        cout << "----------------------------------------------------\n";
        cout << " Controls: W/A/S/D or Arrows | T = View Trace | Q = Quit\n";
        cout << "                                                    \n";
    }

    void showTraceReplay() {
        system("cls");
        setColor(14);
        cout << "=== LINKED LIST MOVE HISTORY TRACE (head -> tail) ===\n\n";
        setColor(7);

        struct Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            cout << " Step " << temp->step
                 << " | Pos: (" << temp->y << ", " << temp->x << ")"
                 << " | Score: " << temp->score
                 << " | Heap Addr: " << temp
                 << " | Next: " << temp->next << "\n";
            temp = temp->next;
            count++;
            if (count % 20 == 0) {
                cout << "\n -- Press any key for next page --\n";
                _getch();
            }
        }
        cout << "\n=== End of Linked List. Press any key to resume game ===\n";
        _getch();
        system("cls");
    }

    // Read all pressed keys in the buffer so controls feel instant
    void handleInput() {
        while (_kbhit()) {
            int ch = _getch();
            if (ch == 0 || ch == 224) {
                ch = _getch();
                if (ch == 72) enqueue(1);      // Up
                else if (ch == 80) enqueue(2); // Down
                else if (ch == 75) enqueue(3); // Left
                else if (ch == 77) enqueue(4); // Right
            } else {
                if (ch == 'w' || ch == 'W') enqueue(1);
                else if (ch == 's' || ch == 'S') enqueue(2);
                else if (ch == 'a' || ch == 'A') enqueue(3);
                else if (ch == 'd' || ch == 'D') enqueue(4);
                else if (ch == 't' || ch == 'T') showTraceReplay();
                else if (ch == 'q' || ch == 'Q') running = false;
            }
        }
    }

    bool checkGhostCollision() {
        for (int g = 0; g < 3; g++) {
            if (ghosts[g].x == pacX && ghosts[g].y == pacY) {
                lives--;
                draw();
                gotoXY(3, ROWS + 9);
                setColor(12);
                if (lives > 0) {
                    cout << ">> CAUGHT BY GHOST! Lives Left: " << lives << ". Respawning... <<";
                    Sleep(1000);
                    resetPositions();
                } else {
                    running = false;
                }
                return true;
            }
        }
        return false;
    }

    void update() {
        int dx[5] = {0, 0, 0, -1, 1};
        int dy[5] = {0, -1, 1, 0, 0};

        // Dequeue buffered input
        int qDir = dequeue();
        if (qDir != 0) {
            bufferedDir = qDir;
        }

        // Turn as soon as corner opens up
        if (bufferedDir != 0 && isWalkable(pacY + dy[bufferedDir], pacX + dx[bufferedDir])) {
            pacDir = bufferedDir;
            bufferedDir = 0;
        }

        // 1. Move Pac-Man
        if (pacDir != 0) {
            int nx = pacX + dx[pacDir];
            int ny = pacY + dy[pacDir];

            if (isWalkable(ny, nx)) {
                pacX = nx;
                pacY = ny;

                if (maze[pacY][pacX] == '.') {
                    maze[pacY][pacX] = ' ';
                    score += 10;
                } else if (maze[pacY][pacX] == 'o') {
                    maze[pacY][pacX] = ' ';
                    score += 50;
                }

                insertMove(pacX, pacY, score);
            }
        }

        // Check if Pac-Man walked into a Ghost
        if (checkGhostCollision()) return;

        // 2. Move Ghosts slightly slower than Pac-Man (every 2nd tick) so gameplay is fair & smooth
        tickCount++;
        if (tickCount % 2 == 0) {
            for (int g = 0; g < 3; g++) {
                moveGhost(&ghosts[g]);
            }
            // Check if a Ghost walked into Pac-Man
            if (checkGhostCollision()) return;
        }
    }
};

int main() {
    srand((unsigned int)time(0));

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    system("cls");
    PacmanGame game;

    while (game.running) {
        game.draw();
        game.handleInput();
        game.update();
        Sleep(65); // Fast 65ms tick (~15 FPS) for responsive controls
    }

    system("cls");
    setColor(12);
    cout << "\n   ==========================================\n";
    cout << "          GAME OVER! Final Score: " << game.score << "\n";
    cout << "   ==========================================\n\n";
    setColor(10);
    cout << "   Freeing " << total_steps << " Linked List nodes from heap memory...\n";
    freeList();
    cout << "   Memory freed successfully (0 leaks)!\n\n";
    setColor(7);

    return 0;
}
