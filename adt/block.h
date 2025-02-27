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
    int color;
} BlockShape;

const BlockShape BLOCK_SHAPES[] = {
    [O_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [I_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [S_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [Z_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [L_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [J_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    },
    [T_BLOCK] = {
        .shape = {
            {0, 0, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0}
        },
        .color = 0x00FF00
    }
};

#endif