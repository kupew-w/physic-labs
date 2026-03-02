#pragma once

#include "tokens/lab/ExperimentToken.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace pl
{

class LabToken
{
private:
    std::unordered_map<std::string, std::string> meta;
    std::vector<std::shared_ptr<pl::ExperimentToken>> token;

public:
    void addMeta(std::string k, std::string v);
    void addRow(std::shared_ptr<pl::ExperimentToken>);

    std::shared_ptr<pl::ExperimentToken> operator[](const int i) const;
    int size() const;

    std::unordered_map<std::string, std::string> getMeta() const;
    std::vector<pl::ExperimentToken> getToken() const;

    std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator begin();
    std::vector<std::shared_ptr<pl::ExperimentToken>>::iterator end();
};

};
