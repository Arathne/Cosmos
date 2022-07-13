#include <rendering/Rectangle.h>

Rectangle::Rectangle (void):
    position_(glm::vec3(0, 0, 0)),
    size_(glm::vec2(0, 0))
{}


Rectangle::Rectangle (glm::vec3 position):
    position_(position),
    size_(glm::vec2(0, 0))
{}

Rectangle::Rectangle (glm::vec3 position, glm::vec2 size):
    position_(position),
    size_(size)
{}

Rectangle::Rectangle (const Rectangle & rect):
    position_(rect.position_),
    size_(rect.size_)
{}

void Rectangle::setPosition (float x, float y, float z)
{
    position_ = glm::vec3(x, y, z);
}

void Rectangle::setPosition (glm::vec3 position)
{
    position_ = position;
}

void Rectangle::setPositionX (float x)
{
    position_.x = x;
}

void Rectangle::setPositionY (float y)
{
    position_.y = y;
}

void Rectangle::setPositionZ (float z)
{
    position_.z = z;
}

glm::vec3 Rectangle::getPosition (void) const
{
    return position_;
}

float Rectangle::getPositionX (void) const
{
    return position_.x;
}

float Rectangle::getPositionY (void) const
{
    return position_.y;
}

float Rectangle::getPositionZ (void) const
{
    return position_.z;
}

void Rectangle::setSize (float h, float w)
{
    size_ = glm::vec2(h, w);
}

void Rectangle::setSize (glm::vec2 size)
{
    size_ = size;
}

void Rectangle::setHeight (float x)
{
    size_.x = x;
}

void Rectangle::setWidth (float y)
{
    size_.y = y;
}

glm::vec2 Rectangle::getSize (void) const
{
    return size_;
}

float Rectangle::getHeight (void) const
{
    return size_.x;
}

float Rectangle::getWidth (void) const
{
    return size_.y;
}
        
const Rectangle & Rectangle::operator = (const Rectangle & rhs)
{
    if (&rhs != &(*this))
	{
        position_ = rhs.position_;
        size_ = rhs.size_;
    }

    return *this;
}

bool Rectangle::operator == (const Rectangle & rhs) 
{
    if (&rhs == &(*this))
        return true;

    if (position_ != rhs.position_)
        return false;

    if (size_ != rhs.size_)
        return false;

    return true;
}

bool Rectangle::operator != (const Rectangle & rhs) 
{
    return !(*this == rhs);
}