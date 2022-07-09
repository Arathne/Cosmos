#include <tests/TestIoDestructionController.h>

void TestIoDestructionController::run (void)
{
    Logger log;

    log.add(test_deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero());
    log.add(test_deleteFile_whenCalledWithValidPath_ReturnsZero());
    log.add(test_deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(test_deleteDirectory_whenCalledWithValidPath_ReturnsTrue());

    log.writeToFile(std::string(TEST_FOLDER) + "/IoDestructionController.txt");
}

std::string TestIoDestructionController::test_deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero (void) 
{
    int statusCode = IoDestructionController::deleteFile("lka/?!///!alskjdz");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: test_deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero";
    
    return output;
}

std::string TestIoDestructionController::test_deleteFile_whenCalledWithValidPath_ReturnsZero (void)
{
    IoCreationController::createFile(TEMP_FILE);

    int statusCode = IoDestructionController::deleteFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: test_deleteFile_whenCalledWithValidPath_ReturnsZero";
    
    return output;
}
        
std::string TestIoDestructionController::test_deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse (void)
{
    bool boolean = IoDestructionController::deleteDirectory("lka/?!///!alskjdz");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: test_deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse";

    return output;
}

std::string TestIoDestructionController::test_deleteDirectory_whenCalledWithValidPath_ReturnsTrue (void)
{
    std::string path = std::string(TEST_FOLDER) + "/oaikjsd";
    IoCreationController::createDirectory(path);
    bool boolean = IoDestructionController::deleteDirectory(path);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: test_deleteDirectory_whenCalledWithValidPath_ReturnsTrue";

    return output;
}