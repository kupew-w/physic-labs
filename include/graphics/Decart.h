#pragma once

#include "graphics/IGraphic.h"
#include "graphics/IRender.h"
#include "tokens/lab/LabToken.h"
#include <memory>
#include <vector>

namespace pl 
{

class Decart : public IGraphic
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
    Decart(std::shared_ptr<LabToken>, std::string x, std::string y);
    
    void draw(std::shared_ptr<IRender>) override;
    void addData(std::shared_ptr<LabToken>, std::string x, std::string y) override;
};

}
