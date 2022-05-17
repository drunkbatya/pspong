// Copyright [2022] <drunkbatya>

#include "main.h"

PSP_MODULE_INFO("Logic Sample", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void)
{
    static unsigned int __attribute__((aligned(16))) list[262144];

    setupCallbacks();
    guInit(list);
    while (running())
    {
        sceGuStart(GU_DIRECT, list);
        sceGuClearColor(0);
        sceGuClear(GU_COLOR_BUFFER_BIT);

        drawField();
        drawRockets(100, 100);
        // drawRectFull(100, 100, 30, 70, RED);
        // drawRectWidth(40, 40, (SCR_WIDTH - 2 - 80), (SCR_HEIGHT - 2 - 80), GREEN, 20);
        // drawCircleWidth(130, 130, 5.5, GREEN, 5);
        // drawCircleWidth(130, 130, 20, RED, 12);
        // drawCircleWidth(130, 130, 60, BLUE, 10);

        sceGuFinish();
        sceGuSync(0, 0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }
    sceGuTerm();
    sceKernelExitGame();
    return (0);
}
