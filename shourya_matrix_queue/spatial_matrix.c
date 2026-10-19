#include "spatial_matrix.h"

char maze[ROWS][COLS + 1] = {
    "###################",
    "#........#........#",
    "#o##.###.#.###.##o#",
    "#.................#",
    "#.##.#.#####.#.##.#",
    "#....#...#...#....#",
    "####.### # ###.####",
    "#........ ........#",
    "####.### # ###.####",
    "#....#...#...#....#",
    "#.##.#.#####.#.##.#",
    "#.................#",
    "#o##.###.#.###.##o#",
    "#........#........#",
    "###################"
};

int q_arr[MAX_Q];
int front = -1, rear = -1;

void enqueue(int dir) {
    if ((rear + 1) % MAX_Q == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_Q;
    q_arr[rear] = dir;
}

int dequeue() {
    if (front == -1) return 0;
    int val = q_arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_Q;
    }
    return val;
}

int isWalkable(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return 0;
    if (maze[r][c] == '#') return 0;
    return 1;
}
