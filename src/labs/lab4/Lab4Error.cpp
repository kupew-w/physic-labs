#include "labs/lab4/Lab4Error.h"

std::shared_ptr<pl::ExperimentToken> Lab4Error::getToken() const
{
    pl::ExperimentToken out;

    out.setExperimentData("R", std::to_string(R));
    out.setExperimentData("X", std::to_string(X));
    out.setExperimentData("v", std::to_string(v));
    out.setExperimentData("Nu", std::to_string(Nu));

    return std::make_shared<pl::ExperimentToken>(out);

}
