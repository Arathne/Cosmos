#include <tests/TestIoWriteController.h>

std::string TestIoWriteController::getName (void) const 
{
    return "TestIoWriteController";
}

TestIoWriteController::TestIoWriteController (void): 
    INVALID_PATH("a9/*!-*s8dyhpk;nd!}{}AS|D"),
    VALID_PATH(TEMP_FILE)
{}

void TestIoWriteController::run (void)
{
    Logger log;

    log.add(write_whenCalledWithInvalidPath_returnsFalse());
    log.add(write_whenCalledWithValidPath_returnsTrue());
    log.add(append_whenCalledWithInvalidPath_returnsFalse());
    log.add(append_whenCalledWithValidPath_returnsTrue());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoWriteController.txt");
}

std::string TestIoWriteController::write_whenCalledWithInvalidPath_returnsFalse (void) 
{
    bool success = IoWriteController::write(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoWriteController::write_whenCalledWithValidPath_returnsTrue() 
{
    bool success = IoWriteController::write(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoWriteController::append_whenCalledWithInvalidPath_returnsFalse() 
{
    bool success = IoWriteController::append(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}

std::string TestIoWriteController::append_whenCalledWithValidPath_returnsTrue()
{
    bool success = IoWriteController::append(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    return output;
}