#pragma once

#include "labs/LabStruct.h"
<<<<<<< HEAD:include/factories/LabFactory.h
#include "tokens/lab/LabToken.h"
=======
#include "tokens/LabToken.h"
#include <memory>

>>>>>>> lab2(1):include/LabFactory.h
enum class LabType 
{
    LAB1,   
    LAB2,
    LAB3,
    LAB4,
    LAB5
};

class LabFactory
{
public:
    static std::shared_ptr<LabStruct> create(const LabType, std::shared_ptr<pl::LabToken>) noexcept(false);
};
