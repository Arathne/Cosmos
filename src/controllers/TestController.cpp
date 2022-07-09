#include <controllers/TestController.h>

TestController::TestController (void) 
{
    testList_.push_back(new TestIoReadController());
    testList_.push_back(new TestIoWriteController());
}

TestController::~TestController (void) 
{
    for(int i = 0; i < testList_.size(); i++)
    {
        Test* testObj = testList_.at(i);
        delete testObj;
    }
}

 void TestController::runAllTests (void) 
 {
    for(int i = 0; i < testList_.size(); i++)
    {
        Test* testObj = testList_.at(i);
        testObj -> run();
    }
    IoDestructionController::deleteFile(TEMP_FILE);
 }