#include "labs/lab4/Lab4.h"
#include "labs/lab4/Lab4Calc.h"
#include "labs/lab4/Lab4Const.h"
#include "labs/lab4/Lab4Error.h"
#include "labs/lab4/Lab4Exp.h"
#include "tokens/lab/LabToken.h"
#include <memory>

Lab4::Lab4(std::shared_ptr<pl::LabToken> token)
{
    for(std::shared_ptr<pl::ExperimentToken> expToken : *token)
    {
        raw.push_back(std::make_shared<Lab4Exp>(expToken));
        calc.push_back(std::make_shared<Lab4Calc>());
        errors.push_back(std::make_shared<Lab4Error>());
    }

    constants = std::make_shared<Lab4Const>((*token)[0]);
}

void Lab4::calculateLab()
{

}
