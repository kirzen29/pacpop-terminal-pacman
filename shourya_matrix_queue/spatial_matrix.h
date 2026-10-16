#ifndef SPATIAL_MATRIX_H
#define SPATIAL_MATRIX_H

#include <stdbool.h>

#define MAZE_ROWS 21
#define MAZE_COLS 19
#define QUEUE_CAPACITY 8

/* Cardinal Direction Enum */
typedef enum {
    DIR_NONE  = 0,
    DIR_UP    = 1,
    DIR_LEFT  = 2,
    DIR_DOWN  = 3,
    DIR_RIGHT = 4
} Direction;

/* Circular FIFO Queue for keystroke buffering */
typedef struct InputQueue {
    Direction buffer[QUEUE_CAPACITY];
    int head;
    int tail;
    int count;
} InputQueue;

void init_queue(InputQueue* q);
bool enqueue_input(InputQueue* q, Direction dir);
Direction dequeue_input(InputQueue* q);

/* 2D Spatial Matrix Array */
typedef struct SpatialMatrix {
    char grid[MAZE_ROWS][MAZE_COLS];
    int remaining_pellets;
} SpatialMatrix;

void init_matrix(SpatialMatrix* mat);
bool is_tile_walkable(const SpatialMatrix* mat, int r, int c);

#endif /* SPATIAL_MATRIX_H */
