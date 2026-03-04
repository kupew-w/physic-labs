#include "labs/lab1/Lab1Calc.h"
#include <memory>
#include <string>



std::shared_ptr<pl::ExperimentToken> Lab1Calc::getToken() const
{
    std::shared_ptr<pl::ExperimentToken> out = std::make_shared<pl::ExperimentToken>();

    out->setExperimentData("r", std::to_string(r));
    out->setExperimentData("E", std::to_string(E));

    return out;
}
