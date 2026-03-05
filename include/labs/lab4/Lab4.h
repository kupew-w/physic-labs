#pragma once

#include "labs/LabStruct.h"
#include "tokens/lab/LabToken.h"

class Lab4 : public LabStruct
{
public:
    explicit Lab4(std::shared_ptr<pl::LabToken>);

    void calculateLab() override;
};
