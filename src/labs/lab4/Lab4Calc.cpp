#include "labs/lab4/Lab4Calc.h"

std::shared_ptr<pl::ExperimentToken> Lab4Calc::getToken() const 
{
    pl::ExperimentToken out;

    out.setExperimentData("v", std::to_string(v));
    out.setExperimentData("X", std::to_string(X));

    return std::make_shared<pl::ExperimentToken>(out);
}
