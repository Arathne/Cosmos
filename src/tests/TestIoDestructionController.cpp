#include <tests/TestIoDestructionController.h>

std::string TestIoDestructionController::getName (void) const 
{
    return "TestIoDestructionController";
}

void TestIoDestructionController::run (Logger & log)
{
    deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero(log);
    deleteFile_whenCalledWithValidPath_ReturnsZero(log);
    deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse(log);
    deleteDirectory_whenCalledWithValidPath_ReturnsTrue(log);
}

void TestIoDestructionController::deleteFile_whenCalledWithInvalidPath_ReturnsLessThanZero (Logger & log) 
{
    int statusCode = IoDestructionController::deleteFile("lka/?!///!alskjdz");

    std::string result = (statusCode < 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;
    
    log.add(output);
}

void TestIoDestructionController::deleteFile_whenCalledWithValidPath_ReturnsZero (Logger & log)
{
    IoCreationController::createFile(TEMP_FILE);

    int statusCode = IoDestructionController::deleteFile(TEMP_FILE);

    std::string result = (statusCode == 0) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;
    
    log.add(output);
}
        
void TestIoDestructionController::deleteDirectory_whenCalledWithInvalidPath_ReturnsFalse (Logger & log)
{
    bool boolean = IoDestructionController::deleteDirectory("lka/?!///!alskjdz");

    std::string result = (boolean == false) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoDestructionController::deleteDirectory_whenCalledWithValidPath_ReturnsTrue (Logger & log)
{
    std::string path = std::string(DATA_FOLDER) + "/oaikjsd";
    IoCreationController::createDirectory(path);
    bool boolean = IoDestructionController::deleteDirectory(path);

    std::string result = (boolean) ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}