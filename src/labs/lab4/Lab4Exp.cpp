#include "labs/lab4/Lab4Exp.h"

Lab4Exp::Lab4Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    R = std::stof((*token)["R"]);
    Nu = std::stof((*token)["Nu"]);
}

std::shared_ptr<pl::ExperimentToken> Lab4Exp::getToken() const
{
    pl::ExperimentToken out;

    out.setExperimentData("R", std::to_string(R));
    out.setExperimentData("Nu", std::to_string(Nu));

    return std::make_shared<pl::ExperimentToken>(out);

}
