// Copyright [2022] <drunkbatya>

#ifndef PSPONG_PONG_H_
#define PSPONG_PONG_H_

#include "display.h"
#include "colors.h"

#define FIELD_COLOR RED
#define SEP_COLOR BLUE
#define ROCKET_COLOR GREEN
#define ROCKET_WIDTH 5
#define ROCKET_HEIGHT 40
#define ROCKET_LEFT_X 10
#define ROCKET_RIGHT_X (SCR_WIDTH - ROCKET_LEFT_X)

void drawField(void);
void drawRockets(uint16_t y_left, uint16_t y_right);

#endif  // PSPONG_PONG_H_
