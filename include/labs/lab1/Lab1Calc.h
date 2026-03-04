#pragma once

#include "labs/ExperimentStruct.h"

class Lab1Calc : public ExperimentStruct
{
public:
    float r = 0, E = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
