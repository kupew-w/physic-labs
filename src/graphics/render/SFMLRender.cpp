
#include "graphics/render/SFMLRender.h"
#include "graphics/IRender.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>

void pl::SFMLRender::dot(float x, float y, pl::Color c)
{
    sf::Vertex p({x,y}, tsf(c));
    window.draw(&p, 1, sf::PrimitiveType::Points);
}

void pl::SFMLRender::line(float x1, float y1, float x2, float y2, pl::Color c)
{
    sf::Vertex l[2]
        {
            {{x1, y1}, tsf(c)},
            {{x2, y2}, tsf(c)}
        };

    window.draw(l, 2, sf::PrimitiveType::Lines);
}

void pl::SFMLRender::circle(float x, float y, float radius, pl::Color c)
{

}

void pl::SFMLRender::rectangle(float x1, float y1, float x2, float y2, pl::Color c)
{
    sf::RectangleShape r({x2-x1, y2-y1});

    r.setOutlineColor(tsf(c));
    r.setOutlineThickness(5);
    r.setPosition({x1, y1});

    window.draw(r);
}

void pl::SFMLRender::text(float x, float y, std::string text, pl::Color c)
{

}

sf::Color pl::SFMLRender::tsf(pl::Color c)
{
    return sf::Color(c.r, c.g, c.b, c.a);
}

void pl::SFMLRender::update()
{
    while(const std::optional event = window.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
            window.close();
    }

    window.clear();
    window.display();
}

bool pl::SFMLRender::isOpen()
{
    return window.isOpen();
}
