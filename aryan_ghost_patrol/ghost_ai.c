#include <stdlib.h>
#include "ghost_ai.h"
#include "spatial_matrix.h"

void moveGhost(struct Ghost* g) {
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, -1, 1, 0, 0};
    int opp[5] = {0, 2, 1, 4, 3};

    int validDirs[4];
    int count = 0;

    for (int d = 1; d <= 4; d++) {
        if (d == opp[g->dir]) continue;
        int nx = g->x + dx[d];
        int ny = g->y + dy[d];
        if (isWalkable(ny, nx)) {
            validDirs[count] = d;
            count++;
        }
    }

    if (count > 0) {
        int chosen = validDirs[rand() % count];
        g->dir = chosen;
        g->x += dx[chosen];
        g->y += dy[chosen];
    } else {
        int back = opp[g->dir];
        if (isWalkable(g->y + dy[back], g->x + dx[back])) {
            g->dir = back;
            g->x += dx[back];
            g->y += dy[back];
        }
    }
}
