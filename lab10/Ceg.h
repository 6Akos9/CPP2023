//
// Created by balaz on 2023. 12. 01..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H
#include <vector>

#include "Alkalmazott.h"
#include "Manager.h"


class Ceg {
protected:
    vector<Alkalmazott*> alkalmazottak;
public:
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(int id);
    void assignManager(int id, Manager* manager);
    void unassignManager(int id, Manager* manager);
    void print(ostream& os) const;
    void printManagers(ostream& os) const;
};


#endif //CPP_2022_CEG_H
