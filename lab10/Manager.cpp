//
// Created by balaz on 2023. 11. 29..
//

#include "Manager.h"

#include <algorithm>
#include <iostream>

const string Manager::MANAGER_MUNKAKOR = "manager";

Manager::Manager(const string& vezetekNev, const string& keresztNev, int szuletesiEv, const string& munkakor)
        : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor)
{
}

void Manager::addAlkalmazott(Alkalmazott* alkalmazott)
{
    beosztottak.push_back(alkalmazott);
}

void Manager::deleteAlkalmazott(int id)
{
    auto it = find_if(beosztottak.begin(), beosztottak.end(), [id](Alkalmazott* alkalmazott)
    {
        return alkalmazott->getId() == id;
    });
    if (it != beosztottak.end())
    {
        beosztottak.erase(it);
    }
}

int Manager::beosztottakSzama() const
{
    return beosztottak.size();
}

void Manager::print(ostream& os) const
{
    os << "Manager: "<< id << " "<< vezetekNev << " " << keresztNev<< " beosztottjai:"<< endl;
    for (auto const alkalmazott : beosztottak)
    {
        os <<"  "<< *alkalmazott << endl;
    }
}
