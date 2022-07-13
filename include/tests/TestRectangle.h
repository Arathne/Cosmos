#ifndef TEST_RECTANGLE_H
#define TEST_RECTANGLE_H

#include <tests/Test.h>
#include <rendering/Rectangle.h>

class TestRectangle : public Test
{
    public:
        std::string getName (void) const;
        void run (Logger & log);

    private:
        /* testing: constructors
         * params: [
                none,
                position, 
                position & size, 
                copy
            ]
         * expected: "attributes should match the values passed in"
        */
        void constructor_argumentWithNone (Logger & log);
        void constructor_argumentWithPositionVector (Logger & log);
        void constructor_argumentWithPositionAndSizeVectors (Logger & log);
        void constructor_argumentWithRectangle (Logger & log);

        /* testing: 'position' setters
         * expected: "attributes should match the values passed in as arguments"
        */
        void setPosition_argumentWithFloats (Logger & log);
        void setPosition_argumentWithVector (Logger & log);
        void setPositionX_argumentWithFloat (Logger & log);
        void setPositionY_argumentWithFloat (Logger & log);  
        void setPositionZ_argumentWithFloat (Logger & log);  

        /* testing: 'position' getters
         * expected: "values received should match attributes passed in the constructor"    -- IS THIS NEEDED
        */
        void getPosition_returnsVector (Logger & log);
        void getPositionX_returnsFloat (Logger & log);
        void getPositionY_returnsFloat (Logger & log);   
        void getPositionZ_returnsFloat (Logger & log);   

        /* testing: 'size' setters and getters
         * expected: "attributes should match the values passed in as arguments"
        */
        void setSize_argumentWithFloats (Logger & log);
        void setSize_argumentWithVector (Logger & log);
        void setHeight_argumentWithFloat (Logger & log);
        void setWidth_argumentWithFloat (Logger & log); 

        /* testing: operator overloading '=='
         * expected: "correctly compare two Rectangle classes to see if they are equal or not"
        */
        void operatorEquals_argumentRectangle_returnsTrueWhenIdentical (Logger & log);
        void operatorEquals_argumentRectangle_returnsFalseWhenDifferent (Logger & log);
        void operatorNotEquals_argumentRectangle_returnsFalseWhenIdentical (Logger & log);
        void operatorNotEquals_argumentRectangle_returnsTrueWhenDifferent (Logger & log);

        /* testing: operator overloading '='
         * expected: "correctly copy values from rhs to lhs"
        */
        void operatorAssignment_argumentRectangle (Logger & log);
};

#endif