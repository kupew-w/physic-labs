#include "graphics/Decart.h"
#include "graphics/Graphic.h"
#include "graphics/IRender.h"
#include "tokens/lab/ExperimentToken.h"
#include "tokens/lab/LabToken.h"
#include <memory>
#include <utility>

pl::Decart::Decart(LabToken& token, std::string x, std::string y, std::unique_ptr<IRender> render) : Graphic(std::move(render))
{
    for(std::shared_ptr<ExperimentToken> expToken : token)
    {
        data.push_back({std::stof((*expToken)[x]), std::stof((*expToken)[y])});
    }
}

void pl::Decart::draw()
{
    
}

void pl::Decart::addData(pl::LabToken& token)
{ }
