//
// Created by balaz on 2023. 12. 13..
//

#include "SettlementStatisticsImpl.h"
#include <fstream>
#include <sstream>
#include <algorithm>

int SettlementStatisticsImpl::numSettlements() const
{
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const
{
    int counter = 0;
    for (auto it = settlements.begin(); it != settlements.end(); it = settlements.upper_bound(it->first))
    {
        ++counter;
    }
    return counter;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const
{
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const
{
    vector<Settlement> result;

    for( auto  it = settlements.lower_bound(county) ; it != settlements.upper_bound(county); ++it)
    {
        result.push_back(it->second);
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const
{
    for(auto it = settlements.lower_bound(county) ; it != settlements.upper_bound(county); ++it)
    {
        if(it->second.getName() == name)
        {
            return it->second;
        }
    }
    throw runtime_error("Settlement not found");
}

Settlement SettlementStatisticsImpl::maxPopulation() const
{
    // hazi
    return max_element(settlements.begin(), settlements.end(), [](const auto& a, const auto& b) {
        return a.second.getPopulation() < b.second.getPopulation();
    })->second;
}

Settlement SettlementStatisticsImpl::minPopulation() const
{
    auto it = min_element(settlements.begin(), settlements.end(), [](const auto& a, const auto& b) {
        return a.second.getPopulation() < b.second.getPopulation();
    });

    if(it == settlements.end())
    {
        throw runtime_error("Settlement not found");
    }
    return it->second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name)
{
    vector<Settlement> result;
    for(auto & [key, value] : settlements)
    {
        if(value.getName() == name)
        {
            result.push_back(value);
        }
    }
    return result;
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string& filename)
{
    ifstream file(filename);
    if(!file)
    {
        throw runtime_error("Cannot open file");
    }

    string line;

    getline(file, line);
    while(getline(file, line))
    {
        stringstream ss(line);

        string name,code,population;

        getline(ss, name, ',');
        getline(ss, code, ',');
        getline(ss, population);

        if(population == "")
        {
            population = "0";
        }

        //cout << '"'<< population <<  '"' << endl;
        settlements.insert(pair(code , Settlement(name, code, stoi(population))));

    }
}
