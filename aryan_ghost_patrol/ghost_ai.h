#ifndef GHOST_AI_H
#define GHOST_AI_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "spatial_matrix.h"

typedef struct Ghost {
    int x;
    int y;
    Direction current_dir;
    COLORREF color;
    const char* name;
} Ghost;

/* Phase-I: 2D Matrix Intersection Patrol (Interface hook reserved for Phase-II BFS) */
Direction choose_ghost_direction(const Ghost* g, const SpatialMatrix* mat);

#endif /* GHOST_AI_H */
