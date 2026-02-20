#pragma once

#include "graphics/Graphic.h"
#include "graphics/IRender.h"
#include "tokens/lab/LabToken.h"
#include <vector>

namespace pl 
{

class Decart : Graphic
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
    Decart(IRender&&);
    Decart(LabToken&, IRender&&);
};

}
