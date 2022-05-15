
#include "pong.h"

PSP_MODULE_INFO("Logic Sample", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(int argc, char* argv[])
{
    static unsigned int __attribute__((aligned(16))) list[262144];

	setupCallbacks();
    guInit(list);
	while(running())
	{
		sceGuStart(GU_DIRECT,list);
		sceGuClearColor(0);
		sceGuClear(GU_COLOR_BUFFER_BIT);

		sceGuFinish();
		sceGuSync(0,0);
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
	sceGuTerm();
	sceKernelExitGame();
	return (0);
}
