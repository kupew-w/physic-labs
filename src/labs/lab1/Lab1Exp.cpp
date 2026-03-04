
#include "labs/lab1/Lab1Exp.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

Lab1Exp::Lab1Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    U = std::stof((*token)["U"]);
    x = std::stof((*token)["x"]);
    y = std::stof((*token)["y"]);
}

std::shared_ptr<pl::ExperimentToken> Lab1Exp::getToken() const
{
    std::shared_ptr<pl::ExperimentToken> out = std::make_shared<pl::ExperimentToken>();

    out->setExperimentData("U", std::to_string(U));
    out->setExperimentData("x", std::to_string(x));
    out->setExperimentData("y", std::to_string(y));

    return out;
}
