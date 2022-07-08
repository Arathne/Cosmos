#ifndef TEST_H
#define TEST_H

#include <Logger.h>

class Test {
    public:
        virtual ~Test (void) {}

        /* @name: run
         * @description: runs tests associated with the class 
         * @params: []
         * @return: none
        */
        virtual void run (void) = 0;
};

#endif