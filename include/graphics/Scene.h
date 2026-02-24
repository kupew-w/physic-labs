#pragma once

#include "graphics/IGraphic.h"
#include "graphics/IRender.h"
#include <memory>
#include <vector>

namespace pl 
{

class Scene
{
private:
    std::vector<std::unique_ptr<IGraphic>> graphics;

public:
    std::shared_ptr<IRender> render;

    void add(std::unique_ptr<IGraphic>);
    void draw();
};

}
