//
// Created by balaz on 2023. 11. 29..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H
#include <vector>

#include "Alkalmazott.h"


class Manager: public Alkalmazott {
protected:
    vector<Alkalmazott*> beosztottak;
public:
    const static string MANAGER_MUNKAKOR;
    Manager(const string& vezetekNev, const string& keresztNev, int szuletesiEv, const string& munkakor);
    void addAlkalmazott(Alkalmazott* alkalmazott);
    void deleteAlkalmazott(int id);
    int beosztottakSzama() const;
    void print(ostream& os) const override;
};


#endif //CPP_2022_MANAGER_H
