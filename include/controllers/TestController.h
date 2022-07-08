#ifndef TEST_CONTROLLER_H
#define TEST_CONTROLLER_H

#include <tests/Test.h>
#include <vector>

#include <tests/TestIoReadController.h>

class TestController {
    public:
        TestController (void);
        ~TestController (void);

        /* @name: runAllTests
         * @description: runs all tests
         * @params: []
         * @return: none
        */
        void runAllTests (void);

    private:
        std::vector<Test*> testList_;
};

#endif