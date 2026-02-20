#pragma once

#include <string>
namespace pl 
{

class IRender
{
public:
    virtual void dot(float x, float y) = 0;
    virtual void line(float x1, float y1, float x2, float y2) = 0;
    virtual void circle(float x, float y, float radius) = 0;
    virtual void rectangle(float x1, float y1, float x2, float y2) = 0;
    virtual void text(float x, float y, std::string) = 0;

    IRender(IRender&&) = default;
    IRender& operator=(IRender&&) = default;

    IRender(const IRender&) = delete;
    IRender& operator=(const IRender&) = delete;
};

}
