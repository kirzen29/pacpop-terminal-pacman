#ifndef GHOST_AI_H
#define GHOST_AI_H

#ifdef __cplusplus
extern "C" {
#endif

struct Ghost {
    int x, y;
    int dir;
    int color;
};

void moveGhost(struct Ghost* g);

#ifdef __cplusplus
}
#endif

#endif
