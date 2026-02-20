
#include "graphics/render/SFMLRender.h"
#include <SFML/Window/VideoMode.hpp>

pl::SFMLRender::SFMLRender()
{
}

pl::SFMLRender::SFMLRender(std::string name)
{
    window.create(sf::VideoMode({800, 600}), name);
}

void pl::SFMLRender::dot(float x, float y)
{

}

void pl::SFMLRender::line(float x1, float y1, float x2, float y2)
{

}

void pl::SFMLRender::circle(float x, float y, float radius)
{

}

void pl::SFMLRender::rectangle(float x1, float y1, float x2, float y2)
{

}

void pl::SFMLRender::text(float x, float y, std::string text)
{

}
