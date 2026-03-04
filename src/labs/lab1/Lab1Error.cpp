#include "labs/lab1/Lab1Error.h"

std::shared_ptr<pl::ExperimentToken> Lab1Error::getToken() const 
{
    std::shared_ptr<pl::ExperimentToken> out = std::make_shared<pl::ExperimentToken>();

    out->setExperimentData("x", std::to_string(x));
    out->setExperimentData("y", std::to_string(y));
    out->setExperimentData("r", std::to_string(r));
    out->setExperimentData("E", std::to_string(E));
    out->setExperimentData("phi", std::to_string(phi));

    return out;
}
