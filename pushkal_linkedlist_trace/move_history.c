#include <stdlib.h>
#include "move_history.h"

struct Node* head = NULL;
struct Node* tail = NULL;
int total_steps = 0;

void insertMove(int x, int y, int sc) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;

    total_steps++;
    newNode->step = total_steps;
    newNode->x = x;
    newNode->y = y;
    newNode->score = sc;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void freeList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
    tail = NULL;
    total_steps = 0;
}
