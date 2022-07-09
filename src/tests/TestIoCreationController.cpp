#include <tests/TestIoCreationController.h>

void TestIoCreationController::run (void)
{
    Logger log;

    log.add(test_createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero());
    log.add(test_createFile_whenCalledWithValidPath_ReturnsZero());
    log.add(test_createDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(test_createDirectory_whenCalledWithValidPath_ReturnsTrue());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoCreationController.txt");
}

std::string TestIoCreationController::test_createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero (void)
{
    int statusCode = IoCreationController::createFile("//asldkma**&^%/1/");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: test_createFile_whenCalledWithInvalidPath_ReturnsIntLessThanZero";

    return output;
}

std::string TestIoCreationController::test_createFile_whenCalledWithValidPath_ReturnsZero (void)
{
    IoDestructionController::deleteFile(TEMP_FILE);
    int statusCode = IoCreationController::createFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: test_createFile_whenCalledWithValidPath_ReturnsZero";

    return output;
}

std::string TestIoCreationController::test_createDirectory_whenCalledWithInvalidPath_ReturnsFalse (void)
{
    bool boolean = IoCreationController::createDirectory("//asldkma**&^%/1/");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: test_createDirectory_whenCalledWithInvalidPath_ReturnsFalse";

    return output;
}

std::string TestIoCreationController::test_createDirectory_whenCalledWithValidPath_ReturnsTrue (void)
{
    std::string directoryPath = std::string(TEST_FOLDER) + "/testCreateDirectory";
    bool boolean = IoCreationController::createDirectory(directoryPath);
    IoDestructionController::deleteDirectory(directoryPath);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: test_createDirectory_whenCalledWithValidPath_ReturnsTrue";

    return output;
}