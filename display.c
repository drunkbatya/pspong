// Copyright [2022] <drunkbatya>

#include "display.h"

void guInit(unsigned int *list)
{
    sceGuInit();
    sceGuStart(GU_DIRECT, list);
    sceGuDrawBuffer(GU_PSM_8888, (void *)0, BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH, SCR_HEIGHT, (void *)0x88000, BUF_WIDTH);
    sceGuDepthBuffer((void *)0x110000, BUF_WIDTH);
    sceGuOffset(2048 - (SCR_WIDTH / 2), 2048 - (SCR_HEIGHT / 2));
    sceGuViewport(2048, 2048, SCR_WIDTH, SCR_HEIGHT);
    sceGuDepthRange(65535, 0);
    sceGuScissor(0, 0, SCR_WIDTH, SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

void drawRect(uint16_t x, uint16_t y, uint16_t size_x, uint16_t size_y, uint32_t color)
{
    t_dot *points = sceGuGetMemory(5 * sizeof(t_dot));

    points[0].x = x;
    points[0].y = y;
    points[0].z = 0;
    points[1].x = x + size_x;
    points[1].y = y;
    points[1].z = 0;
    points[2].x = x + size_x;
    points[2].y = y + size_y;
    points[2].z = 0;
    points[3].x = x;
    points[3].y = y + size_y;
    points[3].z = 0;
    points[4].x = x;
    points[4].y = y - 1;
    points[4].z = 0;
    sceGuColor(color);
    sceGuDrawArray(GU_LINE_STRIP, GU_VERTEX_16BIT | GU_TRANSFORM_2D, 5, 0, points);
}

void drawRectWidth(uint16_t x, uint16_t y, uint16_t size_x, uint16_t size_y, uint32_t color, uint16_t width)
{
    while (width--)
        drawRect(x + width, y + width, size_x - (width * 2), size_y - (width * 2), color);
}

void drawCircle(uint16_t x, uint16_t y, float radius, uint32_t color)
{
    float real_x;
    t_dot_f *points;

    if (!radius)
        return;
    real_x = -radius;
    points = sceGuGetMemory(((radius * 4) + 1) * sizeof(t_dot_f));
    while (real_x < radius + 1)
    {
        points[(int)(real_x + radius)].x = x + real_x;
        points[(int)(real_x + radius)].y = y + sqrt(pow(radius, 2) - pow(real_x, 2));
        points[(int)(real_x + radius)].z = 0;
        points[(int)(real_x + (radius * 3))].x = x - real_x;
        points[(int)(real_x + (radius * 3))].y = (2 * y) - points[(int)(real_x + radius)].y;
        points[(int)(real_x + (radius * 3))].z = 0;
        real_x++;
    }
    sceGuColor(color);
    sceGuDrawArray(GU_LINE_STRIP, GU_VERTEX_32BITF | GU_TRANSFORM_2D, ((radius * 4) + 1), 0, points);
}

void drawCircleWidth(uint16_t x, uint16_t y, uint16_t radius, uint32_t color, uint16_t width)
{
    while (width--)
        drawCircle(x, y, radius - width, color);
}
