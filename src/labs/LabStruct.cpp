#include "labs/LabStruct.h"
#include "labs/ExperimentStruct.h"
#include "tokens/lab/ExperimentToken.h"
#include <memory>

int LabStruct::getQuantityExperiments() 
{ return raw.size(); }

void LabStruct::addExperiment(std::shared_ptr<ExperimentStruct> e)
{ raw.push_back(e); }

std::shared_ptr<pl::LabToken> LabStruct::getToken() const
{
    pl::LabToken out;


    for(int i = 0; i < raw.size(); ++i)
    {
        pl::ExperimentToken token; 

        token.addExperimentData(constants->getToken());
        token.addExperimentData(raw[i]->getToken());
        token.addExperimentData(calc[i]->getToken());
        token.addExperimentData(errors[i]->getToken());

        out.addRow(token);
    }

    return std::make_shared<pl::LabToken>(out);
}
