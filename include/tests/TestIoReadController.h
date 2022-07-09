#ifndef TEST_IO_READ_CONTROLLER
#define TEST_IO_READ_CONTROLLER

#include <controllers/IoReadController.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoDestructionController.h>
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

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single word"
        */
        std::string test_readText_whenCalledToReadFromExistingFile_ReturnsSingleWordFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single line"
        */
        std::string test_readText_whenCalledToReadFromExistingFile_ReturnsSingleLineFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "mulple lines"
        */
        std::string test_readText_whenCalledToReadFromExistingFile_ReturnsMultiLineFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path that does not exist"
            ]
         * expected: "empty string"
        */
        std::string test_readText_whenCalledToReadFromNonExistingFile_ReturnsEmptyString (void);
};

#endif