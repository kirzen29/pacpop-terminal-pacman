#include "spatial_matrix.h"

/* Default 21x19 classic arcade layout */
static const char DEFAULT_MAZE[MAZE_ROWS][MAZE_COLS + 1] = {
    "###################",
    "#........#........#",
    "#o##.###.#.###.##o#",
    "#.................#",
    "#.##.#.#####.#.##.#",
    "#....#...#...#....#",
    "####.### # ###.####",
    "   #.#       #.#   ",
    "####.# ##-## #.####",
    "    .  #   #  .    ",
    "####.# ##### #.####",
    "   #.#       #.#   ",
    "####.# ##### #.####",
    "#........#........#",
    "#.##.###.#.###.##.#",
    "#o.#..... .....#.o#",
    "##.#.#.#####.#.#.##",
    "#....#...#...#....#",
    "#.######.#.######.#",
    "#.................#",
    "###################"
};

void init_queue(InputQueue* q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

bool enqueue_input(InputQueue* q, Direction dir) {
    if (q->count >= QUEUE_CAPACITY) return false;
    q->buffer[q->tail] = dir;
    q->tail = (q->tail + 1) % QUEUE_CAPACITY;
    q->count++;
    return true;
}

Direction dequeue_input(InputQueue* q) {
    if (q->count == 0) return DIR_NONE;
    Direction dir = q->buffer[q->head];
    q->head = (q->head + 1) % QUEUE_CAPACITY;
    q->count--;
    return dir;
}

void init_matrix(SpatialMatrix* mat) {
    mat->remaining_pellets = 0;
    for (int r = 0; r < MAZE_ROWS; r++) {
        for (int c = 0; c < MAZE_COLS; c++) {
            mat->grid[r][c] = DEFAULT_MAZE[r][c];
            if (mat->grid[r][c] == '.' || mat->grid[r][c] == 'o') {
                mat->remaining_pellets++;
            }
        }
    }
}

/* O(1) Constant-time spatial collision lookup */
bool is_tile_walkable(const SpatialMatrix* mat, int r, int c) {
    if (r < 0 || r >= MAZE_ROWS || c < 0 || c >= MAZE_COLS) return false;
    char tile = mat->grid[r][c];
    return (tile != '#' && tile != '-');
}
