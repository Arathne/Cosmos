#include <tests/TestIoCreationController.h>

std::string TestIoCreationController::getName (void) const 
{
    return "TestIoCreationController";
}

void TestIoCreationController::run (Logger & log)
{
    createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero(log);
    createFile_whenCalledWithValidPath_ReturnsZero(log);
    createDirectory_whenCalledWithInvalidPath_ReturnsFalse(log);
    createDirectory_whenCalledWithValidPath_ReturnsTrue(log);
}

void TestIoCreationController::createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero (Logger & log)
{
    int statusCode = IoCreationController::createFile("//asldkma**&^%/1/");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoCreationController::createFile_whenCalledWithValidPath_ReturnsZero (Logger & log)
{
    IoDestructionController::deleteFile(TEMP_FILE);
    int statusCode = IoCreationController::createFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoCreationController::createDirectory_whenCalledWithInvalidPath_ReturnsFalse (Logger & log)
{
    bool boolean = IoCreationController::createDirectory("//asldkma**&^%/1/");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoCreationController::createDirectory_whenCalledWithValidPath_ReturnsTrue (Logger & log)
{
    std::string directoryPath = std::string(DATA_FOLDER) + "/testCreateDirectory";
    bool boolean = IoCreationController::createDirectory(directoryPath);
    IoDestructionController::deleteDirectory(directoryPath);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}