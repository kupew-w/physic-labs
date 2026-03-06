#pragma once

#include "labs/ExperimentStruct.h"

class Lab4Error : public ExperimentStruct
{
public:
    float R = 0, X = 0, Nu = 0, v = 0;

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
