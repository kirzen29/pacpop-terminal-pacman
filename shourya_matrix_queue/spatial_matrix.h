#ifndef SPATIAL_MATRIX_H
#define SPATIAL_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

#define ROWS 15
#define COLS 19
#define MAX_Q 5

extern char maze[ROWS][COLS + 1];
extern int front, rear;

void enqueue(int dir);
int dequeue();
int isWalkable(int r, int c);

#ifdef __cplusplus
}
#endif

#endif