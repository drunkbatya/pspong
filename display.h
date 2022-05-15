
#ifndef PSPONG_DISPLAY_H_
#define PSPONG_DISPLAY_H_

#include <pspgu.h>
#include <pspdisplay.h>

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)

// need flag GU_COLOR_8888
typedef struct s_color_dot
{
    uint32_t color;
    uint16_t x;
    uint16_t y;
    uint16_t z;
} t_color_dot;

// need external color set by sceGuColor(color uint32_t hex code);
typedef struct s_dot
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
} t_dot;

void guInit(unsigned int *list);

#endif  // PSPONG_DISPLAY_H_