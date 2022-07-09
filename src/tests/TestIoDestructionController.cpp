#include <tests/TestIoDestructionController.h>

std::string TestIoDestructionController::getName (void) const 
{
    return "TestIoDestructionController";
}

void TestIoDestructionController::run (void)
{
    Logger log;

    log.add(deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero());
    log.add(deleteFile_whenCalledWithValidPath_ReturnsZero());
    log.add(deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(deleteDirectory_whenCalledWithValidPath_ReturnsTrue());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoDestructionController.txt");
}

std::string TestIoDestructionController::deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero (void) 
{
    int statusCode = IoDestructionController::deleteFile("lka/?!///!alskjdz");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;
    
    return output;
}

std::string TestIoDestructionController::deleteFile_whenCalledWithValidPath_ReturnsZero (void)
{
    IoCreationController::createFile(TEMP_FILE);

    int statusCode = IoDestructionController::deleteFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;
    
    return output;
}
        
std::string TestIoDestructionController::deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse (void)
{
    bool boolean = IoDestructionController::deleteDirectory("lka/?!///!alskjdz");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoDestructionController::deleteDirectory_whenCalledWithValidPath_ReturnsTrue (void)
{
    std::string path = std::string(TEST_FOLDER) + "/oaikjsd";
    IoCreationController::createDirectory(path);
    bool boolean = IoDestructionController::deleteDirectory(path);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}