#include "labs/lab1/Lab1.h"
#include "Calc.h"
#include "labs/lab1/Lab1Calc.h"
#include "labs/lab1/Lab1Const.h"
#include "labs/lab1/Lab1Error.h"
#include "labs/lab1/Lab1Exp.h"
#include "tokens/lab/ExperimentToken.h"
#include "tokens/lab/LabToken.h"
#include <cmath>
#include <memory>
#include <vector>

Lab1::Lab1(std::shared_ptr<pl::LabToken> token)
{
    for(std::shared_ptr<pl::ExperimentToken> expToken : *token)
    {
        raw.push_back(std::make_shared<Lab1Exp>(expToken));
        calc.push_back(std::make_shared<Lab1Calc>());
        errors.push_back(std::make_shared<Lab1Error>());
    }

    constants = std::make_shared<Lab1Const>();
}

void Lab1::calculateLab()
{
    std::vector<double> U;
    std::vector<double> r;
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> E;

    std::shared_ptr<Lab1Exp> rawExp;
    std::shared_ptr<Lab1Calc> calcExp;
    std::shared_ptr<Lab1Error> errorExp;
    std::shared_ptr<Lab1Const> constExp = std::static_pointer_cast<Lab1Const>(constants);

    auto ic = calc.begin();
    auto ie = errors.begin();

    for(std::shared_ptr<ExperimentStruct> exp : raw)
    {
        rawExp = std::static_pointer_cast<Lab1Exp>(exp);

        U.push_back(rawExp->U);
        calcExp->r = sqrt(pow(rawExp->x, 2) + pow(rawExp->y, 2));
        r.push_back(calcExp->r);
        x.push_back(rawExp->x);
        y.push_back(rawExp->y);
    } 
    for(std::shared_ptr<ExperimentStruct> exp : raw)
    {
        rawExp = std::static_pointer_cast<Lab1Exp>(exp);
        calcExp = std::static_pointer_cast<Lab1Calc>(*ic);
        errorExp = std::static_pointer_cast<Lab1Error>(*ie);

        calcExp->E = rawExp->U/calcExp->r;
        E.push_back(calcExp->E);
        
        errorExp->x = Calc::randomMiss(x);
        errorExp->y = Calc::randomMiss(y);

        errorExp->r = sqrt(pow((2 * rawExp->x * errorExp->x) /
                               (2 * sqrt(pow(rawExp->x, 2) + 
                                        pow(rawExp->y, 2))), 2) + 
                           pow((2 * rawExp->y * errorExp->y) /
                               (2 * sqrt(pow(rawExp->x, 2) + 
                                       pow(rawExp->y, 2))), 2));
        errorExp->E = sqrt(pow(1/calcExp->r, 2) + 
                           pow((rawExp->U * errorExp->r)/
                               calcExp->r, 2));
    }

    constExp->phi = Calc::coeffA(U, r);
    //errorExp->phi = abs(Calc::deltaCoeffA(U, Calc::dy(r, )));
 
    
}
