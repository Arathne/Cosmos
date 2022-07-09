#ifndef TEST_IO_WRITE_CONTROLLER_H
#define TEST_IO_WRITE_CONTROLLER_H

#include <tests/Test.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoDestructionController.h>

class TestIoWriteController : public Test 
{
    public:
        TestIoWriteController (void);
        void run (void);
    
    private:
        const std::string INVALID_PATH;
        const std::string VALID_PATH;

        /* testing: write()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "write failed"
        */
        std::string test_write_whenCalledWithInvalidPath_returnsFalse (void);

        /* testing: write()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "write successful"
        */
        std::string test_write_whenCalledWithValidPath_returnsTrue (void);

        /* testing: append()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "append failed"
        */
        std::string test_append_whenCalledWithInvalidPath_returnsFalse (void);

        /* testing: append()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "append successful"
        */
        std::string test_append_whenCalledWithValidPath_returnsTrue (void);
};

#endif