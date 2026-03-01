#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/lab/LabToken.h"

#include <memory>
#include <vector>

class LabStruct
{
protected:
    std::shared_ptr<ExperimentStruct> constants;
    std::vector<std::shared_ptr<ExperimentStruct>> raw;
    std::vector<std::shared_ptr<ExperimentStruct>> calc;
    std::vector<std::shared_ptr<ExperimentStruct>> errors;

public:
    LabStruct() = default;
    LabStruct(LabStruct&&) = default;
    LabStruct& operator=(LabStruct&&) = default;

    LabStruct(const LabStruct&) = delete;
    LabStruct& operator=(const LabStruct&) = delete;

    ~LabStruct() = default;

    void addExperiment(std::shared_ptr<ExperimentStruct>);

    int getQuantityExperiments();

    virtual void calculateLab() = 0;

    std::shared_ptr<pl::LabToken> getToken() const;
};
