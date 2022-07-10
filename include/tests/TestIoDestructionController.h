#ifndef TEST_IO_DESTRUCTION_CONTROLLER_H
#define TEST_IO_DESTRUCTION_CONTROLLER_H

#include <controllers/IoCreationController.h>
#include <controllers/IoDestructionController.h>
#include <tests/Test.h>

class TestIoDestructionController : public Test 
{
    public:
        std::string getName (void) const;
        void run (Logger & log);

    private:
        /* testing: deleteFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: true  "failed to delete file"
        */
        std::string deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero (void);

        /* testing: deleteFile()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully deleted file"
        */
        std::string deleteFile_whenCalledWithValidPath_ReturnsZero (void);

        /* testing: deleteDirectory()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "failed to delete directory"
        */
        std::string deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse (void);

        /* testing: deleteDirectory()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully deleted directory"
        */
        std::string deleteDirectory_whenCalledWithValidPath_ReturnsTrue (void);
};

#endif