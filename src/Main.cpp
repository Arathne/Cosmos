#include <psp2/kernel/processmgr.h>
#include <controllers/TestController.h>

#include <controllers/IoCreationController.h>

int main ()
{ 
    IoCreationController::createDirectory(DATA_FOLDER);

    #ifdef DEVELOPER_MODE
        IoCreationController::createDirectory(TEST_FOLDER);
        TestController* tests = new TestController();
        tests -> runAllTests();
        delete tests;
    #endif

    sceKernelExitProcess(0);
}