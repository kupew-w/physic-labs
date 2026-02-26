
#include "graphics/Scene.h"
#include "graphics/IGraphic.h"
#include <memory>

void pl::Scene::add(std::unique_ptr<IGraphic> g)
{
    graphics.push_back(std::move(g));
}

void pl::Scene::draw()
{
    while(render->isOpen())
    {
        render->processEvent();
        render->clear();

        for(auto& g : graphics)
        {
            g->draw(render);
        }
        render->display();
    }
}
