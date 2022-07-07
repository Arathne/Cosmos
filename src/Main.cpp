#include <psp2/kernel/processmgr.h>

#include <controllers/IoController.h>
#include <tests/TestIoController.h>

int main () 
{
    IoController::createDirectory(DATA_FOLDER);

    IoController::deleteDirectory(TEST_FOLDER);
    //IoController::createDirectory(TEST_FOLDER);

    TestIoController test;
    test.run();

    sceKernelExitProcess(0);
}