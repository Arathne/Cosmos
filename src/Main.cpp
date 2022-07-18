#include <psp2/kernel/processmgr.h>
#include <controllers/TestController.h>
#include <controllers/IoCreationController.h>

#include <vitaGL.h>
#include <rendering/Triangle.h>
#include <rendering/Renderer.h>
#include <rendering/Color.h>

int main ()
{ 
    IoCreationController::createDirectory(DATA_FOLDER);

    #ifdef DEVELOPER_MODE
        TestController* tests = new TestController();
        tests -> runAllTests();
        delete tests;
    #endif



    vglInit(0x800000);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -3, 3, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Triangle triangle(Color(0, 255, 0));
	Renderer renderer;

	renderer.setClearColor(Color(0,0,0));

	for (;;){
		renderer.clear();
		renderer.draw(triangle);
		renderer.swap();
	}
	
	vglEnd();

    sceKernelExitProcess(0);
}