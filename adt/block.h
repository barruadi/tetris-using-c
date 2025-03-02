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

typedef enum {
    BLOCK_SUCCESS = 0,
    BLOCK_ERR_INVALID_TYPE = 1,
    BLOCK_ERR_NULL_POINTER = 2
} BlockErrno;

typedef struct {
    uint8_t shape[4][4];
    uint32_t color;
} BlockShape;

typedef struct {
    BlockShape shape;
    uint8_t position[4][2];
} Block;

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

BlockShape block_shape(BlockType type);

BlockType block_random_type();

// void print_block(BlockShape block);

BlockErrno block_set_position(Block *block, uint8_t position[4][2]);

BlockErrno block_rotate(Block *block);

BlockErrno block_move_left(Block *block);

BlockErrno block_move_right(Block *block);

BlockErrno block_move_down(Block *block);

void block_get_position(Block block);

#endif