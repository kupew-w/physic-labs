#pragma once

#include "labs/LabStruct.h"
#include "tokens/lab/LabToken.h"

class Lab1 : public LabStruct
{
public:
    explicit Lab1(std::shared_ptr<pl::LabToken>);

    void calculateLab() override;
    void calculateData() override;
    void calculateError() override;
};
