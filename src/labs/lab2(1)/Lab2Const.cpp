#include "labs/lab2(1)/Lab2Const.h"

std::shared_ptr<pl::ExperimentToken> Lab2Const::getToken() const 
{
    pl::ExperimentToken out;

    out.setExperimentData("Ri", std::to_string(Ri));

    return std::make_shared<pl::ExperimentToken>(out);
}
