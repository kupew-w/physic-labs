#pragma once 

#include "graphics/IRender.h"
#include "tokens/lab/LabToken.h"
#include <memory>
 
namespace pl
{

class IGraphic
{
public:
    IGraphic() = default;

    void setRenderType(std::unique_ptr<IRender>);

    virtual void draw(std::shared_ptr<IRender>) = 0;

    virtual void addData(std::shared_ptr<LabToken>, std::string x, std::string y) = 0;

    IGraphic(IGraphic&&) = default;
    IGraphic& operator=(IGraphic&&) = default;

    IGraphic(const IGraphic&) = delete;
    IGraphic& operator=(const IGraphic&) = delete;

    virtual ~IGraphic() = default;
};

};
