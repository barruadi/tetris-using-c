#include "block.h"

BlockShape block_shape(BlockType type) {
    return BLOCK_SHAPES[type];
}

// BlockType block_random_type() {
//     return rand() % 7;
// }

void print_block(BlockShape block) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", block.shape[i][j]);
        }
        printf("\n");
    }
    printf("%d", block.color);
}

// driver
int main() {
    print_block(block_shape(O_BLOCK));
};