#ifndef TEST_IO_DESTRUCTION_CONTROLLER_H
#define TEST_IO_DESTRUCTION_CONTROLLER_H

#include <controllers/IoCreationController.h>
#include <controllers/IoDestructionController.h>
#include <tests/Test.h>

class TestIoDestructionController : public Test 
{
    public:
        void run (void);

    private:
        std::string test_deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero (void);
        std::string test_deleteFile_whenCalledWithValidPath_ReturnsZero (void);
        
        std::string test_deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse (void);
        std::string test_deleteDirectory_whenCalledWithValidPath_ReturnsTrue (void);
};

#endif