#pragma once

#include "labs/ExperimentStruct.h"

class Lab1Calc : public ExperimentStruct
{
public:
    float;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
