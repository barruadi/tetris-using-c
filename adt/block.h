#include <stdio.h>
#include <stdlib.h>

// #define O_BLOCK {0, 0, 0, 0};

#ifndef BLOCK_H
#define BLOCK_H

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4

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
    uint8_t shape[BLOCK_HEIGHT][BLOCK_WIDTH];
    uint32_t color;
} BlockShape;

typedef struct {
    BlockShape shape;
    uint8_t position[4][2];
} Block;

extern const BlockShape BLOCK_SHAPES[];

BlockShape block_shape(BlockType type);

BlockType block_random_type();

void print_block_shape(BlockShape block);

void print_block_state(Block block);

BlockErrno block_set_position(Block *block, uint8_t position[4][2]);

BlockErrno block_rotate(Block *block);

BlockErrno block_move_left(Block *block);

BlockErrno block_move_right(Block *block);

BlockErrno block_move_down(Block *block);

void block_get_position(Block block);

#endif