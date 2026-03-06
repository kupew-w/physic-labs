#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

class Lab4Exp : public ExperimentStruct
{
public:
    float R = 0, Nu = 0;

    explicit Lab4Exp(std::shared_ptr<pl::ExperimentToken>);
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
