#include <tests/TestIoCreationController.h>

std::string TestIoCreationController::getName (void) const 
{
    return "TestIoCreationController";
}

void TestIoCreationController::run (Logger & log)
{
    log.add(createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero());
    log.add(createFile_whenCalledWithValidPath_ReturnsZero());
    log.add(createDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(createDirectory_whenCalledWithValidPath_ReturnsTrue());
}

std::string TestIoCreationController::createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero (void)
{
    int statusCode = IoCreationController::createFile("//asldkma**&^%/1/");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoCreationController::createFile_whenCalledWithValidPath_ReturnsZero (void)
{
    IoDestructionController::deleteFile(TEMP_FILE);
    int statusCode = IoCreationController::createFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoCreationController::createDirectory_whenCalledWithInvalidPath_ReturnsFalse (void)
{
    bool boolean = IoCreationController::createDirectory("//asldkma**&^%/1/");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoCreationController::createDirectory_whenCalledWithValidPath_ReturnsTrue (void)
{
    std::string directoryPath = std::string(DATA_FOLDER) + "/testCreateDirectory";
    bool boolean = IoCreationController::createDirectory(directoryPath);
    IoDestructionController::deleteDirectory(directoryPath);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}