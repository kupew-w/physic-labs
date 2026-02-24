#include "graphics/Decart.h"
#include "graphics/IRender.h"
#include "tokens/lab/ExperimentToken.h"
#include "tokens/lab/LabToken.h"
#include <memory>

pl::Decart::Decart(LabToken& token, std::string x, std::string y)
{
    for(std::shared_ptr<ExperimentToken> expToken : token)
    {
        data.push_back({std::stof((*expToken)[x]), std::stof((*expToken)[y])});
    }
}

void pl::Decart::draw(std::shared_ptr<IRender>)
{
    
}

void pl::Decart::addData(pl::LabToken& token, std::string x, std::string y)
{ }
