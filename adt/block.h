#include <stdio.h>
#include <stdlib.h>

// #define O_BLOCK {0, 0, 0, 0};

#ifndef BLOCK_H
#define BLOCK_H

typedef enum {
    O_BLOCK, 
    I_BLOCK, 
    S_BLOCK, 
    Z_BLOCK, 
    L_BLOCK, 
    J_BLOCK, 
    T_BLOCK
} BlockType;

typedef struct {
    int shape[4][4];
} BlockShape;

const BlockShape BLOCK_SHAPES[] = {
    [O_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },
    [I_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    [S_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        }
    },
    [Z_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },
    [L_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    [J_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    },
    [T_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        }
    }
};

#endif