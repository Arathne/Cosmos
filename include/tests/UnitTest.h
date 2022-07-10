#ifndef TEST_UNIT_H
#define TEST_UNIT_H

#include <Logger.h>

// templates keep telling me its undefined. rip

class UnitTest
{
    public:
        static void equals (bool expected, bool actual, std::string functionName, Logger & log);
};

#endif