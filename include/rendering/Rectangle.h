#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <glm/glm.hpp>

class Rectangle
{
    public:
        /* constructors */
        Rectangle (void);
        Rectangle (glm::vec3 position);
        Rectangle (glm::vec3 position, glm::vec2 size);
        Rectangle (const Rectangle & rect);

        /* setters and getters */
        void setPosition (float x, float y, float z);
        void setPosition (glm::vec3 position);
        void setPositionX (float x);
        void setPositionY (float y);
        void setPositionZ (float y);

        glm::vec3 getPosition (void) const;
        float getPositionX (void) const;
        float getPositionY (void) const;
        float getPositionZ (void) const;

        void setSize (float h, float w);
        void setSize (glm::vec2 size);
        void setHeight (float x);
        void setWidth (float y);

        glm::vec2 getSize (void) const;
        float getHeight (void) const;
        float getWidth (void) const;
        
        /* operator overloading */
        const Rectangle & operator = (const Rectangle & rect);
        bool operator == (const Rectangle & rect);
        bool operator != (const Rectangle & rect);

    private:
        glm::vec3 position_;
        glm::vec2 size_;
};

#endif