#include <psp2/kernel/processmgr.h>
#include <controllers/TestController.h>

int main ()
{ 
    #ifdef DEVELOPER_MODE
        TestController* tests = new TestController();
        tests -> runAllTests();
        delete tests;
    #endif

    sceKernelExitProcess(0);
}