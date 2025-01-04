#include <stdio.h>
#include <stdlib.h>

// #define O_BLOCK {0, 0, 0, 0};

typedef enum BlockType {
    O_BLOCK, 
    I_BLOCK, 
    S_BLOCK, 
    Z_BLOCK, 
    L_BLOCK, 
    J_BLOCK, 
    T_BLOCK
};

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