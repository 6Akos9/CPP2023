#include <iostream>
#include "SettlementStatisticsImpl.h"

int main() {
    SettlementStatistics * stats = new SettlementStatisticsImpl("telepulesek.csv");

    vector <Settlement> settlements = stats->findSettlementsByCounty("AB");

    for (int i = 0; i < settlements.size(); i++)
    {
        cout << settlements[i].getName() << endl;
    }
    cout << settlements.size() << endl;

    int numSettlements = stats->numSettlements();
    int numCounties = stats->numCounties();
    int numSettlementsByCounty = stats->numSettlementsByCounty("MS");

    cout << endl << endl;
    cout << "Settlements: " << numSettlements << endl;
    cout << "Counties: " << numCounties << endl;
    cout << "Settlements by county (MS): " << numSettlementsByCounty << endl;

    Settlement settlement = stats->findSettlementsByNameAndCounty("Micesti" , "AB");

    cout << endl << settlement.getCounty() << " " <<settlement.getName() << endl;

    Settlement maxPop = stats->maxPopulation();
    Settlement minPop = stats->minPopulation();

    cout << endl << endl ;
    cout << "Max population : " << maxPop.getName() << " " << maxPop.getPopulation() << endl;
    cout << "Min population : " << minPop.getName() << " " << minPop.getPopulation() << endl;

    vector<Settlement> more = stats->findSettlementsByName("Slobozia");

    cout << endl << more.size() << endl;

    delete stats;
    return 0;
}