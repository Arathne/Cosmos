#ifndef TEST_IO_CREATION_CONTROLLER_H
#define TEST_IO_CREATION_CONTROLLER_H

#include <tests/Test.h>
#include <controllers/IoCreationController.h>
#include <controllers/IoDestructionController.h>

class TestIoCreationController  : public Test
{
    public:
        void run (void);

    private:
        /* testing: createFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: int  <0  "failed to create new file"
        */
        std::string test_createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero (void);

        /* testing: createFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: int  0  "successfully created new file"
        */
        std::string test_createFile_whenCalledWithValidPath_ReturnsZero (void);

        /* testing: createDirectory()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "failed to create new directory"
        */
        std::string test_createDirectory_whenCalledWithInvalidPath_ReturnsFalse (void);

        /* testing: createDirectory()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully created new directory"
        */
        std::string test_createDirectory_whenCalledWithValidPath_ReturnsTrue (void);
};

#endif