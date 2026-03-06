#pragma once

#include "labs/ExperimentStruct.h"

class Lab4Calc : public ExperimentStruct
{
public:
    float v = 0, X = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
