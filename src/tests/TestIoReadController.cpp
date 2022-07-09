#include <tests/TestIoReadController.h>

void TestIoReadController::run (void)
{
    Logger log;
    log.add(test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse());
    log.add(test_isDirectory_whenCalledWithValidPath_ReturnsTrue());
    
    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoReadController.txt");
} 

std::string TestIoReadController::test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse (void) 
{
    bool isDirectory = IoReadController::isDirectory("aks//./0*alskd?!");

    std::string result = isDirectory == false ? "success" : "failed";
    std::string output = result + " :: test_isDirectory_whenCalledWithInvalidPath_ReturnsFalse";

    return output;
}

std::string TestIoReadController::test_isDirectory_whenCalledWithValidPath_ReturnsTrue (void) 
{
    bool isDirectory = IoReadController::isDirectory("ux0:/app");

    std::string result = isDirectory == true ? "success" : "failed";
    std::string output = result + " :: test_isDirectory_whenCalledWithValidPath_ReturnsTrue";

    return output;
}