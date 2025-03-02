#include "canvas.h"
#include "block.h"

CanvasErrno canvas_initialization(Canvas *canvas) {
    if (canvas == NULL) {
        return CANVAS_ERR_NULL_POINTER;
    }

    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            canvas->canvas[i][j] = 0;
        }
    }

    return CANVAS_SUCCESS;
}


CanvasErrno canvas_draw_canvas(Canvas canvas) {
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            if (canvas.canvas[i][j] == 0) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }

    return CANVAS_SUCCESS;
}

CanvasErrno canvas_add_block(Canvas *canvas, Block block) {
    if (canvas == NULL) {
        return CANVAS_ERR_NULL_POINTER;
    }

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        canvas->canvas[block.position[i][0]][block.position[i][1]] = 1;
    }

    return CANVAS_SUCCESS;
}

BlockErrno block_check_collision_right(Boolean *collide, Block block, Canvas canvas) {
    if (collide == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        if (block.position[i][1] + 1 >= CANVAS_WIDTH) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }

        if (canvas.canvas[block.position[i][0]][block.position[i][1] + 1] == 1) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }
    }

    *collide = FALSE;
    return BLOCK_SUCCESS;
}

BlockErrno block_check_collision_left(Boolean *collide, Block block, Canvas canvas) {
    if (collide == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        if (block.position[i][1] - 1 < 0) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }

        if (canvas.canvas[block.position[i][0]][block.position[i][1] - 1] == 1) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }
    }

    *collide = FALSE;
    return BLOCK_SUCCESS;
}

BlockErrno block_check_collision_down(Boolean *collide, Block block, Canvas canvas) {
    if (collide == NULL) {
        return BLOCK_ERR_NULL_POINTER;
    }

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        if (block.position[i][0] + 1 >= CANVAS_HEIGHT) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }

        if (canvas.canvas[block.position[i][0] + 1][block.position[i][1]] == 1) {
            *collide = TRUE;
            return BLOCK_SUCCESS;
        }
    }

    *collide = FALSE;
    return BLOCK_SUCCESS;
}


// driver
int main() {
    Canvas canvas;
    canvas_initialization(&canvas);
    canvas_draw_canvas(canvas);
    printf("\n");

    Block block = {
        .shape = block_shape(I_BLOCK),
        .position = {
            {0, 0},
            {0, 1},
            {0, 2},
            {0, 3}
        }
    };

    canvas_add_block(&canvas, block);
    canvas_draw_canvas(canvas);

    Boolean collide;
    block_check_collision_right(&collide, block, canvas);
    printf("Collide: %d\n", collide);

    return 0;
}