#include "labs/lab4/Lab4Const.h"
#include <string>

Lab4Const::Lab4Const(std::shared_ptr<pl::ExperimentToken> token)
{
    L = std::stof((*token)["L"]);
}

std::shared_ptr<pl::ExperimentToken> Lab4Const::getToken() const 
{
    pl::ExperimentToken out;

    out.setExperimentData("L", std::to_string(L));

    return std::make_shared<pl::ExperimentToken>(out);
}
