#pragma once

#include "labs/ExperimentStruct.h"

class Lab2Const : public ExperimentStruct
{
public:
    float Ri = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
