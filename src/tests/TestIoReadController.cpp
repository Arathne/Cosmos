#include <tests/TestIoReadController.h>

std::string TestIoReadController::getName (void) const 
{
    return "TestIoReadController";
}

void TestIoReadController::run (void)
{
    Logger log;
    
    log.add(isDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(isDirectory_whenCalledWithValidPath_ReturnsTrue());
    log.add(readText_whenCalledWithNonExistingFile_ReturnsEmptyString());
    log.add(readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile());
    log.add(readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile());
    log.add(readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoReadController.txt");
} 

std::string TestIoReadController::isDirectory_whenCalledWithInvalidPath_ReturnsFalse (void) 
{
    std::string directoryPath = "a9/*!-*s8dyhpk;nd!}{}AS|D";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoReadController::isDirectory_whenCalledWithValidPath_ReturnsTrue (void) 
{
    std::string directoryPath = "ux0:/app";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == true) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoReadController::readText_whenCalledWithExistingFile_ReturnsSingleWordFromFile (void) 
{
    std::string expectedText = "abcdefg";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoReadController::readText_whenCalledWithExistingFile_ReturnsSingleLineFromFile (void) 
{
    std::string expectedText = "hello world lmao";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoReadController::readText_whenCalledWithExistingFile_ReturnsMultiLineFromFile (void) 
{
    std::string expectedText = "hello world\nplaystation vita\nza warudo";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoReadController::readText_whenCalledWithNonExistingFile_ReturnsEmptyString (void) 
{
    std::string expectedText = "";

    std::string filePath = "a9///*!-*s8dyhpk;nd!}{}AS|D";
    std::string actualText = IoReadController::readText(filePath);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;

}