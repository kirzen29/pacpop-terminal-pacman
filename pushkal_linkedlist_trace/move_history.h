#ifndef MOVE_HISTORY_H
#define MOVE_HISTORY_H

#ifdef __cplusplus
extern "C" {
#endif

struct Node {
    int step;
    int x, y;
    int score;
    struct Node* next;
};

extern struct Node* head;
extern struct Node* tail;
extern int total_steps;

void insertMove(int x, int y, int sc);
void freeList();

#ifdef __cplusplus
}
#endif

#endif
