#include <tests/TestIoReadController.h>

std::string TestIoReadController::getName (void) const 
{
    return "TestIoReadController";
}

void TestIoReadController::run (Logger & log)
{
    isDirectory_whenCalledWithInvalidPath_ReturnsFalse(log);
    isDirectory_whenCalledWithValidPath_ReturnsTrue(log);
    readText_whenCalledWithNonExistingFile_ReturnsEmptyString(log);
    readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile(log);
    readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile(log);
    readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile(log);
} 

void TestIoReadController::isDirectory_whenCalledWithInvalidPath_ReturnsFalse (Logger & log) 
{
    std::string directoryPath = "a9/*!-*s8dyhpk;nd!}{}AS|D";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoReadController::isDirectory_whenCalledWithValidPath_ReturnsTrue (Logger & log) 
{
    std::string directoryPath = "ux0:/app";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == true) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoReadController::readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile (Logger & log) 
{
    std::string expectedText = "abcdefg";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoReadController::readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile (Logger & log) 
{
    std::string expectedText = "hello world lmao";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoReadController::readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile (Logger & log) 
{
    std::string expectedText = "hello world\nplaystation vita\nza warudo";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoReadController::readText_whenCalledWithNonExistingFile_ReturnsEmptyString (Logger & log) 
{
    std::string expectedText = "";

    std::string filePath = "a9///*!-*s8dyhpk;nd!}{}AS|D";
    std::string actualText = IoReadController::readText(filePath);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);

}