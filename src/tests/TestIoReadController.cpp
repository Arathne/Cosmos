#include <tests/TestIoReadController.h>

void TestIoReadController::run (void)
{
    Logger log;
    log.add(test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(test_isDirectory_whenCalledWithValidPath_ReturnsTrue());
    log.add(test_readText_whenCalledToReadFromNonExistingFile_ReturnsEmptyString());
    log.add(test_readText_whenCalledToReadFromExistingFile_ReturnsSingleWordFromFile());
    log.add(test_readText_whenCalledToReadFromExistingFile_ReturnsSingleLineFromFile());
    log.add(test_readText_whenCalledToReadFromExistingFile_ReturnsMultiLineFromFile());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoReadController.txt");
} 

std::string TestIoReadController::test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse (void) 
{
    std::string directoryPath = "a9/*!-*s8dyhpk;nd!}{}AS|D";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == false) ? "success" : "failed";
    std::string output = result + " :: isDirectory_whenCalledWithInvalidPath_ReturnsFalse";

    return output;
}

std::string TestIoReadController::test_isDirectory_whenCalledWithValidPath_ReturnsTrue (void) 
{
    std::string directoryPath = "ux0:/app";
    bool isDirectory = IoReadController::isDirectory(directoryPath);

    std::string result = (isDirectory == true) ? "success" : "failed";
    std::string output = result + " :: isDirectory_whenCalledWithValidPath_ReturnsTrue";

    return output;
}

std::string TestIoReadController::test_readText_whenCalledToReadFromExistingFile_ReturnsSingleWordFromFile (void) 
{
    std::string expectedText = "abcdefg";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: readText_whenCalledToReadFromExistingFile_ReturnsSingleWordFromFile";

    return output;
}

std::string TestIoReadController::test_readText_whenCalledToReadFromExistingFile_ReturnsSingleLineFromFile (void) 
{
    std::string expectedText = "hello world lmao";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: readText_whenCalledToReadFromExistingFile_ReturnsSingleLineFromFile";

    return output;
}

std::string TestIoReadController::test_readText_whenCalledToReadFromExistingFile_ReturnsMultiLineFromFile (void) 
{
    std::string expectedText = "hello world\nplaystation vita\nza warudo";
    IoWriteController::write(TEMP_FILE, expectedText);

    std::string actualText = IoReadController::readText(TEMP_FILE);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: readText_whenCalledToReadFromExistingFile_ReturnsMultiLineFromFile\n";

    return output;
}

std::string TestIoReadController::test_readText_whenCalledToReadFromNonExistingFile_ReturnsEmptyString (void) 
{
    std::string expectedText = "";

    std::string filePath = "a9///*!-*s8dyhpk;nd!}{}AS|D";
    std::string actualText = IoReadController::readText(filePath);

    std::string result = (actualText == expectedText) ? "success" : "failed";
    std::string output = result + " :: readText_whenCalledToReadFromNonExistingFile_ReturnsEmptyString";

    return output;

}