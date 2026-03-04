#pragma once

#include "labs/ExperimentStruct.h"

class Lab1Const : public ExperimentStruct
{
public:
    float phi = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
