#include <tests/TestIoWriteController.h>

std::string TestIoWriteController::getName (void) const 
{
    return "TestIoWriteController";
}

TestIoWriteController::TestIoWriteController (void): 
    INVALID_PATH("a9/*!-*s8dyhpk;nd!}{}AS|D"),
    VALID_PATH(TEMP_FILE)
{}

void TestIoWriteController::run (Logger & log)
{
    write_whenCalledWithInvalidPath_returnsFalse(log);
    write_whenCalledWithValidPath_returnsTrue(log);
    append_whenCalledWithInvalidPath_returnsFalse(log);
    append_whenCalledWithValidPath_returnsTrue(log);
}

void TestIoWriteController::write_whenCalledWithInvalidPath_returnsFalse (Logger & log) 
{
    bool success = IoWriteController::write(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoWriteController::write_whenCalledWithValidPath_returnsTrue (Logger & log) 
{
    bool success = IoWriteController::write(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoWriteController::append_whenCalledWithInvalidPath_returnsFalse (Logger & log) 
{
    bool success = IoWriteController::append(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}

void TestIoWriteController::append_whenCalledWithValidPath_returnsTrue (Logger & log)
{
    bool success = IoWriteController::append(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: " + __FUNCTION__;

    log.add(output);
}