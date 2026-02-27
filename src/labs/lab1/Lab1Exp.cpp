
#include "labs/lab1/Lab1Exp.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

Lab1Exp::Lab1Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    U = std::stof((*token)["U"]);
    A = std::stof((*token)["A"]);
    X = std::stof((*token)["X"]);
    Y = std::stof((*token)["Y"]);
}

std::shared_ptr<pl::ExperimentToken> Lab1Exp::getToken() const
{
    pl::ExperimentToken out;

    out.setExperimentData("U", std::to_string(U));
    out.setExperimentData("A", std::to_string(A));
    out.setExperimentData("X", std::to_string(X));
    out.setExperimentData("Y", std::to_string(Y));

    return std::make_shared<pl::ExperimentToken>(out);
}
