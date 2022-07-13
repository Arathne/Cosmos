#include <tests/TestRectangle.h>

std::string TestRectangle::getName (void) const
{
    return "TestRectangle";
}

void TestRectangle::run (Logger & log)
{
    TestRectangle::constructor_argumentWithNone (log);
    TestRectangle::constructor_argumentWithPositionVector (log);
    TestRectangle::constructor_argumentWithPositionAndSizeVectors (log);
    TestRectangle::constructor_argumentWithRectangle (log);
    TestRectangle::setPosition_argumentWithFloats (log);
    TestRectangle::setPosition_argumentWithVector (log);
    TestRectangle::setPositionX_argumentWithFloat (log);
    TestRectangle::setPositionY_argumentWithFloat (log);  
    TestRectangle::setPositionZ_argumentWithFloat (log);  
    TestRectangle::getPosition_returnsVector (log);
    TestRectangle::getPositionX_returnsFloat (log);
    TestRectangle::getPositionY_returnsFloat (log);   
    TestRectangle::getPositionZ_returnsFloat (log);   
    TestRectangle::setSize_argumentWithFloats (log);
    TestRectangle::setSize_argumentWithVector (log);
    TestRectangle::setHeight_argumentWithFloat (log);
    TestRectangle::setWidth_argumentWithFloat (log); 
    TestRectangle::operatorEquals_argumentRectangle_returnsTrueWhenIdentical (log);
    TestRectangle::operatorEquals_argumentRectangle_returnsFalseWhenDifferent (log);
    TestRectangle::operatorNotEquals_argumentRectangle_returnsFalseWhenIdentical (log);
    TestRectangle::operatorNotEquals_argumentRectangle_returnsTrueWhenDifferent (log);
    TestRectangle::operatorAssignment_argumentRectangle (log);
}


void TestRectangle::constructor_argumentWithNone (Logger & log)
{
    glm::vec3 expectedPosition = glm::vec3(0,0,0);
    glm::vec2 expectedSize = glm::vec2(0,0);

    Rectangle rect;
    glm::vec3 actualPosition = rect.getPosition();
    glm::vec2 actualSize = rect.getSize();

    bool result = (expectedPosition == actualPosition) && (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::constructor_argumentWithPositionVector (Logger & log)
{
    glm::vec3 expectedPosition = glm::vec3(1,2,3);
    glm::vec2 expectedSize = glm::vec2(0,0);

    Rectangle rect(expectedPosition);
    glm::vec3 actualPosition = rect.getPosition();
    glm::vec2 actualSize = rect.getSize();

    bool result = (expectedPosition == actualPosition) && (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::constructor_argumentWithPositionAndSizeVectors (Logger & log)
{
    glm::vec3 expectedPosition = glm::vec3(1,2,3);
    glm::vec2 expectedSize = glm::vec2(4,5);

    Rectangle rect(expectedPosition, expectedSize);
    glm::vec3 actualPosition = rect.getPosition();
    glm::vec2 actualSize = rect.getSize();

    bool result = (expectedPosition == actualPosition) && (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::constructor_argumentWithRectangle (Logger & log)
{
    glm::vec3 expectedPosition = glm::vec3(1,2,3);
    glm::vec2 expectedSize = glm::vec2(4,5);
    Rectangle* rect1 = new Rectangle(expectedPosition, expectedSize);

    Rectangle rect2(*rect1);
    delete rect1; // making sure it is not a hollow copy

    glm::vec3 actualPosition = rect2.getPosition();
    glm::vec2 actualSize = rect2.getSize();

    bool result = (expectedPosition == actualPosition) && (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setPosition_argumentWithFloats (Logger & log)
{
    glm::vec3 expected = glm::vec3(1,2,3);
    Rectangle rect;

    rect.setPosition(1,2,3);
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setPosition_argumentWithVector (Logger & log)
{
    glm::vec3 expected = glm::vec3(1,2,3);
    Rectangle rect;

    rect.setPosition(expected);
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setPositionX_argumentWithFloat (Logger & log)
{
    glm::vec3 expected = glm::vec3(1,0,0);
    Rectangle rect;

    rect.setPositionX(1);
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setPositionY_argumentWithFloat (Logger & log)
{
    glm::vec3 expected = glm::vec3(0,1,0);
    Rectangle rect;

    rect.setPositionY(1);
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setPositionZ_argumentWithFloat (Logger & log)
{
    glm::vec3 expected = glm::vec3(0,0,1);
    Rectangle rect;

    rect.setPositionZ(1);
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}  

void TestRectangle::getPosition_returnsVector (Logger & log)
{
    glm::vec3 expected = glm::vec3(1,2,3);
    Rectangle rect(expected);

    rect.getPosition();
    glm::vec3 actual = rect.getPosition();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::getPositionX_returnsFloat (Logger & log)
{
    float expected = 1.0f;
    Rectangle rect(glm::vec3(1, 0, 0));

    float actual = rect.getPositionX();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::getPositionY_returnsFloat (Logger & log)
{
    float expected = 1.0f;
    Rectangle rect(glm::vec3(0, 1, 0));

    float actual = rect.getPositionY();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::getPositionZ_returnsFloat (Logger & log)
{
    float expected = 1.0f;
    Rectangle rect(glm::vec3(0, 0, 1));

    float actual = rect.getPositionZ();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}   

void TestRectangle::setSize_argumentWithFloats (Logger & log)
{
    glm::vec2 expectedSize = glm::vec2(1, 2);
    Rectangle rect;

    rect.setSize(1, 2);
    glm::vec2 actualSize = rect.getSize();

    bool result = (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setSize_argumentWithVector (Logger & log)
{
    glm::vec2 expectedSize = glm::vec2(1, 2);
    Rectangle rect;

    rect.setSize(expectedSize);
    glm::vec2 actualSize = rect.getSize();

    bool result = (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setHeight_argumentWithFloat (Logger & log)
{
    float expectedHeight = 1.0f;

    Rectangle rect;
    rect.setHeight(1.0f);
    float actualHeight = rect.getHeight();

    bool result = (expectedHeight == actualHeight);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::setWidth_argumentWithFloat (Logger & log)
{
    float expectedWidth = 1.0f;

    Rectangle rect;
    rect.setWidth(1.0f);
    float actualWidth = rect.getWidth();

    bool result = (expectedWidth == actualWidth);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::operatorEquals_argumentRectangle_returnsTrueWhenIdentical (Logger & log) 
{
    Rectangle rect1(glm::vec3(1,2,3));
    Rectangle rect2(glm::vec3(1,2,3));

    bool result = (rect1 == rect2);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::operatorEquals_argumentRectangle_returnsFalseWhenDifferent (Logger & log)
{
    Rectangle rect1(glm::vec3(1,2,3));
    Rectangle rect2(glm::vec3(3,2,1));

    bool result = (rect1 == rect2);
    UnitTest::equals(false, result, __FUNCTION__, log);
}

void TestRectangle::operatorNotEquals_argumentRectangle_returnsFalseWhenIdentical (Logger & log)
{
    Rectangle rect1(glm::vec3(1,2,3));
    Rectangle rect2(glm::vec3(1,2,3));

    bool result = (rect1 != rect2);
    UnitTest::equals(false, result, __FUNCTION__, log);
}

void TestRectangle::operatorNotEquals_argumentRectangle_returnsTrueWhenDifferent (Logger & log)
{
    Rectangle rect1(glm::vec3(1,2,3));
    Rectangle rect2(glm::vec3(3,2,1));

    bool result = (rect1 != rect2);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestRectangle::operatorAssignment_argumentRectangle (Logger & log)
{
    glm::vec3 expectedPosition = glm::vec3(3,2,1);
    glm::vec2 expectedSize = glm::vec2(4,5);

    Rectangle* rect1 = new Rectangle(expectedPosition, expectedSize);
    Rectangle rect2 = *rect1;
    delete rect1;

    glm::vec3 actualPosition = rect2.getPosition();
    glm::vec2 actualSize = rect2.getSize();

    bool result = (expectedPosition == actualPosition) && (expectedSize == actualSize);
    UnitTest::equals(true, result, __FUNCTION__, log);
}