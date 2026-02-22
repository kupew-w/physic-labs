#pragma once

#include "graphics/Graphic.h"
#include "graphics/IRender.h"
#include "tokens/lab/LabToken.h"
#include <memory>
#include <vector>

namespace pl 
{

class Decart : public Graphic
{
private:

    struct Data
    {
        float x;
        float y;
    };

    std::vector<Data> data;
    float xStep, yStep;

public:
    Decart(std::unique_ptr<IRender> render) : Graphic(std::move(render)) {}
    Decart(LabToken&, std::string x, std::string y, std::unique_ptr<IRender>);
    
    void draw() override;
    void addData(LabToken&) override;
};

}
