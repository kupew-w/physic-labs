#pragma once

#include "labs/ExperimentStruct.h"

class Lab1Error : public ExperimentStruct
{
public:
    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
