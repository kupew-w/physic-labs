#include <memory>
#include <stdexcept>
#include <vector>

#include "tokens/lab/LabToken.h"
#include "tokens/lab/ExperimentToken.h"

void pl::LabToken::addMeta(std::string k, std::string v)
{
    meta.emplace(std::move(k), std::move(v));
}

void pl::LabToken::addRow(std::shared_ptr<pl::ExperimentToken> exp)
{ 
    token.push_back(exp); 
}

std::shared_ptr<pl::ExperimentToken> pl::LabToken::operator[](const int i) const
{ 
    if(i < 0 || i >= token.size())
        throw std::out_of_range("LabToken index out of range");

    return token[i]; 
}

int pl::LabToken::size() const
{ return token.size(); }


std::unordered_map<std::string, std::string> pl::LabToken::getMeta() const
{
    return meta;   
}

std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator pl::LabToken::begin()
{ return token.begin();}

std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator pl::LabToken::end()
{ return token.end();}

