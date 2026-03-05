#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

class Lab1Exp : public ExperimentStruct
{
public:
    float R = 0, X = 0, Nu = 0;

    explicit Lab1Exp(std::shared_ptr<pl::ExperimentToken>);
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
