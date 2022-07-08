#include <psp2/kernel/processmgr.h>

#include <controllers/IoDestructionController.h>
#include <controllers/IoReadController.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoCreationController.h>

int main () 
{ 
    std::string path = std::string(DATA_FOLDER) + "/random";
    
    IoCreationController::createDirectory(path);

    sceKernelExitProcess(0);
}