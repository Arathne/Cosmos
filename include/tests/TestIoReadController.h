#ifndef TEST_IO_READ_CONTROLLER_H
#define TEST_IO_READ_CONTROLLER_H

#include <controllers/IoReadController.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoDestructionController.h>
#include <tests/Test.h>

class TestIoReadController : public Test 
{
    public:
        std::string getName (void) const;
        void run (Logger & log);
    
    private:
        /* testing: isDirectory()
         * params: [
                directoryPath: "string with random characters"
            ]
         * expected: false  "not a directory"
        */
        void isDirectory_whenCalledWithInvalidPath_ReturnsFalse (Logger & log);

        /* testing: isDirectory()
         * params: [
                directoryPath: "app folder"
            ]
         * expected: true  "is a directory"
        */
        void isDirectory_whenCalledWithValidPath_ReturnsTrue (Logger & log);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single word"
        */
        void readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile (Logger & log);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "single line"
        */
        void readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile (Logger & log);

        /* testing: readText()
         * params: [
                filePath: "path to file"
            ]
         * expected: "mulple lines"
        */
        void readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile (Logger & log);

        /* testing: readText()
         * params: [
                filePath: "path that does not exist"
            ]
         * expected: "empty string"
        */
        void readText_whenCalledWithNonExistingFile_ReturnsEmptyString (Logger & log);
};

#endif