//
// Created by balaz on 2023. 11. 29..
//

#include "Manager.h"
#include "algorithm"
const string Manager::MANAGER_MUNKAKOR = "manager";
Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor) : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor)
{}

void Manager::print(ostream &n)const {
    n<<"Manager "<<id<<' '<<vezetekNev<<' '<<keresztNev<<' '<<"beosztottjai:\n";
    for(auto b:beosztottak){
        b->print(n);
    }
}

void Manager::addAlkalmazott(Alkalmazott *beosztott) {
    beosztottak.push_back(beosztott);
}

void Manager::deleteAlkalmazott(int id) {
    auto item = std::find_if(beosztottak.begin(), beosztottak.end(),[id](Alkalmazott*alkalmazott){
        return alkalmazott->getId() == id;
    });
    if (item == beosztottak.end()){
        return;
    }
    beosztottak.erase(item);
}

int Manager::beosztottakSzama() const {
    return beosztottak.size();
}
