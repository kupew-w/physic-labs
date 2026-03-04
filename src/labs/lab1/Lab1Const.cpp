#include "labs/lab1/Lab1Const.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

std::shared_ptr<pl::ExperimentToken> Lab1Const::getToken() const 
{
    std::shared_ptr<pl::ExperimentToken> out = std::make_shared<pl::ExperimentToken>();

    out->setExperimentData("phi", std::to_string(phi));

    return out;
}
