#ifndef TEST_H
#define TEST_H

#include <Logger.h>

class Test {
    public:
        virtual ~Test (void) {}
        virtual void run (void) = 0;
};

#endif