#pragma once

#include "labs/ExperimentStruct.h"

class Lab4Const : public ExperimentStruct
{
public:

    std::shared_ptr<pl::ExperimentToken> getToken() const override;
};
