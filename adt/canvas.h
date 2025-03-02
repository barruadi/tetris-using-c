#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "block.h"

#ifndef CANVAS_H
#define CANVAS_H

#define CANVAS_WIDTH 10
#define CANVAS_HEIGHT 10

typedef enum {
    CANVAS_SUCCESS = 0,
    CANVAS_ERR_NULL_POINTER = 1,
    CANVAS_ERR_OUT_OF_BOUNDS = 2
} CanvasErrno;

typedef struct {
    int canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
} Canvas;

CanvasErrno canvas_initialization(Canvas *canvas);

CanvasErrno canvas_draw_canvas(Canvas canvas);

// Permanently add block to canvas
CanvasErrno canvas_add_block(Canvas *canvas, Block block);

BlockErrno block_check_collision_right(Boolean *collide, Block block, Canvas canvas);

BlockErrno block_check_collision_left(Boolean *collide, Block block, Canvas canvas);

BlockErrno block_check_collision_down(Boolean *collide, Block block, Canvas canvas);

CanvasErrno canvas_row_full(uint8_t *row, Canvas canvas);

CanvasErrno canvas_clear_row(Canvas *canvas, uint8_t row);

#endif