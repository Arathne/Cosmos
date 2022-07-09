#include <tests/TestIoWriteController.h>

TestIoWriteController::TestIoWriteController (void): 
    INVALID_PATH("a9/*!-*s8dyhpk;nd!}{}AS|D"),
    VALID_PATH(TEMP_FILE)
{}

void TestIoWriteController::run (void)
{
    Logger log;

    log.add(test_write_whenCalledWithInvalidPath_returnsFalse());
    log.add(test_write_whenCalledWithValidPath_returnsTrue());
    log.add(test_append_whenCalledWithInvalidPath_returnsFalse());
    log.add(test_append_whenCalledWithValidPath_returnsTrue());

    log.writeToFile(std::string(TEST_FOLDER) + "/TestIoWriteController.txt");
}

std::string TestIoWriteController::test_write_whenCalledWithInvalidPath_returnsFalse (void) 
{
    bool success = IoWriteController::write(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: write_whenCalledWithInvalidPath_returnsFalse";

    return output;
}

std::string TestIoWriteController::test_write_whenCalledWithValidPath_returnsTrue() 
{
    bool success = IoWriteController::write(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: write_whenCalledWithValidPath_returnsTrue";

    return output;
}

std::string TestIoWriteController::test_append_whenCalledWithInvalidPath_returnsFalse() 
{
    bool success = IoWriteController::append(INVALID_PATH, "");

    std::string result = success == false ? "success" : "failed";
    std::string output = result + " :: append_whenCalledWithInvalidPath_returnsFalse";

    return output;
}

std::string TestIoWriteController::test_append_whenCalledWithValidPath_returnsTrue()
{
    bool success = IoWriteController::append(VALID_PATH, "");

    std::string result = success ? "success" : "failed";
    std::string output = result + " :: append_whenCalledWithValidPath_returnsTrue";

    return output;
}