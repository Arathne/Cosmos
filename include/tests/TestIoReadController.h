#ifndef TEST_IO_READ_CONTROLLER_H
#define TEST_IO_READ_CONTROLLER_H

#include <controllers/IoReadController.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoDestructionController.h>
#include <tests/Test.h>

class TestIoReadController : public Test {
    public:
        std::string getName (void) const;
        void run (void);
    
    private:
        /* testing: isDirectory()
         * params: [
                directoryPath: "string with random characters"
            ]
         * expected: false  "not a directory"
        */
        std::string isDirectory_whenCalledWithInvalidPath_ReturnsFalse (void);

        /* testing: isDirectory()
         * params: [
                directoryPath: "app folder"
            ]
         * expected: true  "is a directory"
        */
        std::string isDirectory_whenCalledWithValidPath_ReturnsTrue (void);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single word"
        */
        std::string readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single line"
        */
        std::string readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "mulple lines"
        */
        std::string readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile (void);

        /* testing: readText()
         * params: [
                filePath: "path that does not exist"
            ]
         * expected: "empty string"
        */
        std::string readText_whenCalledWithNonExistingFile_ReturnsEmptyString (void);
};

#endif