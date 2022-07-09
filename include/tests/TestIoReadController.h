#ifndef TEST_IO_READ_CONTROLLER
#define TEST_IO_READ_CONTROLLER

#include <controllers/IoReadController.h>
#include <tests/Test.h>

class TestIoReadController : public Test {
    public:
        void run (void);
    
    private:
        /* testing: isDirectory()
         * params: [
                directoryPath: "string with random characters"
            ]
         * expected: false  "not a directory"
        */
        std::string test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse (void);

        /* testing: isDirectory()
         * params: [
                directoryPath: "app folder"
            ]
         * expected: true  "is a directory"
        */
        std::string test_isDirectory_whenCalledWithValidPath_ReturnsTrue (void);
};

#endif