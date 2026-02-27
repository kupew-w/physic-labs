#include "labs/LabStruct.h"
#include "labs/ExperimentStruct.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

int LabStruct::getQuantityExperiments() 
{ return experiments.size(); }

void LabStruct::addExperiment(std::shared_ptr<ExperimentStruct> e)
{ experiments.push_back(e); }

void LabStruct::addCalc(std::shared_ptr<ExperimentStruct> e)
{ calculate.push_back(e); }

void LabStruct::addError(std::shared_ptr<ExperimentStruct> e)
{ errors.push_back(e); }

std::shared_ptr<pl::LabToken> LabStruct::getToken() const
{
    pl::LabToken out;


    auto exp = experiments.begin();
    auto calc = calculate.begin();
    auto error = errors.begin();

    while(exp != experiments.end())
    {
        pl::ExperimentToken token; 

        token.addExperimentData((*exp)->getToken());
        token.addExperimentData((*calc)->getToken());
        token.addExperimentData((*error)->getToken());

        ++exp;
        ++calc;
        ++error;

        out.addRow(token);
    }

    return std::make_shared<pl::LabToken>(out);
}
