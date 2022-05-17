// Copyright [2022] <drunkbatya>

#include "pong.h"

void drawField(void)
{
    drawLine(((SCR_WIDTH / 2) - 1), 1, (SCR_WIDTH / 2), (SCR_HEIGHT - 1), SEP_COLOR);
    drawRectWidth(1, 1, (SCR_WIDTH - 2), (SCR_HEIGHT - 2), FIELD_COLOR, 3);
}

static void drawRocket(uint16_t x, uint16_t y)
{
    drawRectFull(x, y, ROCKET_WIDTH, ROCKET_HEIGHT, ROCKET_COLOR);
}

void drawRockets(uint16_t y_left, uint16_t y_right)
{
    drawRocket(ROCKET_LEFT_X, y_left);
    drawRocket(ROCKET_RIGHT_X, y_right);
}

