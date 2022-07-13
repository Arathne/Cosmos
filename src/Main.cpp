#include <psp2/kernel/processmgr.h>
#include <controllers/TestController.h>
#include <controllers/IoCreationController.h>

#include <vitaGL.h>

float colors[] = {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0};
float vertices[] = {100, 100, 0, 150, 100, 0, 100, 150, 0};

int main ()
{ 
    IoCreationController::createDirectory(DATA_FOLDER);

    #ifdef DEVELOPER_MODE
        TestController* tests = new TestController();
        tests -> runAllTests();
        delete tests;
    #endif



    vglInit(0x800000);
	
	// Setting screen clear color
	glClearColor (0.50f, 0.0f, 0.0f, 1.0f);
	
	// Initializing mvp matrix with an orthogonal full screen matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 960, 544, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Main loop
	for (;;){
		// Clearing screen
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Drawing a quad with vertex arrays
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glColorPointer(3, GL_FLOAT, 0, colors);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		
		// datatype
		// num of vertices
		// vertex stride
		// color stride
		// pointer to vertices
		// pointer to colors

		// Performing buffer swap
		vglSwapBuffers(GL_FALSE);
	}
	
	// Terminating graphics device
	vglEnd();














    sceKernelExitProcess(0);
}