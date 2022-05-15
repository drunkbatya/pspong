// Copyright [2022] <drunkbatya>

#include "exit.h"

static uint8_t exitRequest = 0;

uint8_t running(void)
{
    return (!exitRequest);
}

int exitCallback(int arg1, int arg2, void *common)
{
    exitRequest = 1;
    return (0);
}

int callbackThread(SceSize args, void *argp)
{
    int cbid;

    cbid = sceKernelCreateCallback("Exit Callback", exitCallback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();
    return (0);
}

void setupCallbacks(void)
{
    int thid;

    thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, 0);
    if (thid >= 0)
        sceKernelStartThread(thid, 0, 0);
}
