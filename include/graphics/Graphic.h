#pragma once 

#include "graphics/IRender.h"
#include "tokens/lab/LabToken.h"
#include <memory>
 
namespace pl
{

class Graphic
{
private:
    std::unique_ptr<IRender> render;

public:
    Graphic(std::unique_ptr<IRender> render) : render(std::move(render))  {}

    void setRenderType(std::unique_ptr<IRender>);

    virtual void draw() = 0;

    virtual void addData(LabToken&) = 0;

    Graphic(Graphic&&) = default;
    Graphic& operator=(Graphic&&) = default;

    Graphic(const Graphic&) = delete;
    Graphic& operator=(const Graphic&) = delete;

    virtual ~Graphic() = default;
};

};
