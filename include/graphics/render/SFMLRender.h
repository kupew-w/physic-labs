#pragma once

#include "graphics/IRender.h"
#include <SFML/Window.hpp>

namespace pl 
{

class SFMLRender : IRender
{
private:
    const sf::Window window;   

public:
    explicit SFMLRender();

    void dot(float x, float y) override;
    void line(float x1, float y1, float x2, float y2) override;
    void circle(float x, float y, float radius) override;
    void rectangle(float x1, float y1, float x2, float y2) override;
    void text(float x, float y, std::string) override;

};

}
