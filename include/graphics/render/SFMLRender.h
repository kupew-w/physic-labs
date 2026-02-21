#pragma once

#include "graphics/IRender.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace pl 
{

class SFMLRender : public IRender
{
private:
    sf::RenderWindow window;   

    sf::Color tsf(Color);

public:
    explicit SFMLRender() : window(sf::VideoMode({800, 600}), "graphic") {}
    explicit SFMLRender(std::string name) : window(sf::VideoMode({800, 600}), name) {}

    void dot(float x, float y, pl::Color color) override;
    void line(float x1, float y1, float x2, float y2, pl::Color color) override;
    void circle(float x, float y, float radius, pl::Color color) override;
    void rectangle(float x1, float y1, float x2, float y2, pl::Color color) override;
    void text(float x, float y, std::string, pl::Color color) override;

    void update() override;
    bool isOpen() override;
};

}
