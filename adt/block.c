#include "block.h"

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

BlockShape block_shape(BlockType type) {
    return BLOCK_SHAPES[type];
}

BlockType block_random_type() {
    return rand() % 7;
}

void print_block_shape(BlockShape block) {
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            printf("%d ", block.shape[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", block.color);
}

void print_block_state(Block block) {
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            printf("%d ", block.shape.shape[i][j]);
        }
        printf("\n");
    }
}

BlockErrno block_set_position(Block *block, uint8_t position[4][2]) {
    if (block == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        block->position[i][0] = position[i][0];
        block->position[i][1] = position[i][1];
    }

    return BLOCK_SUCCESS;
}

BlockErrno block_rotate(Block *block) {
    if (block == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    // Rotate positions
    uint8_t new_position[4][2];
    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        new_position[i][0] = block->position[i][1];
        new_position[i][1] = 3 - block->position[i][0];
    }

    // Rotate shape array
    uint8_t new_shape[BLOCK_HEIGHT][BLOCK_WIDTH];
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            new_shape[j][3-i] = block->shape.shape[i][j];
        }
    }
    
    // Update shape array
    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            block->shape.shape[i][j] = new_shape[i][j];
        }
    }

    return block_set_position(block, new_position);
}

BlockErrno block_move_left(Block *block) {
    if (block == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        block->position[i][1]--;
    }

    return BLOCK_SUCCESS;
}

BlockErrno block_move_right(Block *block) {
    if (block == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        block->position[i][1]++;
    }

    return BLOCK_SUCCESS;
}

BlockErrno block_move_down(Block *block) {
    if (block == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        block->position[i][0]++;
    }

    return BLOCK_SUCCESS;
}

void block_get_position(Block block) {
    for (uint8_t i = 0; i < BLOCK_HEIGHT; i++) {
        printf("(%d, %d)\n", block.position[i][0], block.position[i][1]);
    }
}

// // driver
// int main() {
//     print_block_shape(block_shape(I_BLOCK));
//     Block block = {
//         .shape = block_shape(I_BLOCK),
//         .position = {
//             {0, 0},
//             {0, 1},
//             {0, 2},
//             {0, 3}
//         }
//     };
//     print_block_state(block);
//     block_rotate(&block);
//     block_get_position(block);
//     print_block_state(block);
//     return 0;
// };