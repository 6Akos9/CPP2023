//
// Created by balaz on 2023. 12. 01..
//

#include "Ceg.h"

#include <algorithm>
#include <iostream>

void Ceg::addAlkalmazott(Alkalmazott* alkalmazott)
{
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::deleteAlkalmazott(int id)
{
    auto it = find_if(alkalmazottak.begin(), alkalmazottak.end(), [id](Alkalmazott* alkalmazott)
    {
        return alkalmazott->getId() == id;
    });
    for (Alkalmazott * alkalmazott : alkalmazottak)
    {
        auto* manager = dynamic_cast<Manager*>(alkalmazott);
        if (manager != nullptr)
        {
            manager->deleteAlkalmazott(id);
        }
    }
    if (it != alkalmazottak.end())
    {
        alkalmazottak.erase(it);
    }
}

void Ceg::assignManager(int id, Manager* manager)
{
    auto it = find_if(alkalmazottak.begin(), alkalmazottak.end(), [id](Alkalmazott* alkalmazott)
    {
        return alkalmazott->getId() == id;
    });
    if(it != alkalmazottak.end())
    {
        manager->addAlkalmazott(*it);
    }
}

void Ceg::unassignManager(int id, Manager* manager)
{
    auto it = find_if(alkalmazottak.begin(), alkalmazottak.end(), [id](Alkalmazott* alkalmazott)
    {
        return alkalmazott->getId() == id;
    });
    if(it != alkalmazottak.end())
    {
        manager->deleteAlkalmazott(id);
    }
}

void Ceg::print(ostream& os) const
{
    for (auto const alkalmazott : alkalmazottak)
    {
        os << *alkalmazott << endl;
    }
}

void Ceg::printManagers(ostream& os) const
{
    for (auto const alkalmazott : alkalmazottak)
    {
        auto* manager = dynamic_cast<Manager*>(alkalmazott);
        if (manager != nullptr)
        {
            os << *manager << endl;
        }
    }
}
