#pragma once

#include "labs/ExperimentStruct.h"

class Lab4Const : public ExperimentStruct
{
public:
    float L = 0;

    explicit Lab4Const(std::shared_ptr<pl::ExperimentToken>);
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
