#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

class Lab1Exp : public ExperimentStruct
{
public:
    float U, A;
    float X, Y;

    explicit Lab1Exp(std::shared_ptr<pl::ExperimentToken>);
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
