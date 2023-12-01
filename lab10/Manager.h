//
// Created by balaz on 2023. 11. 29..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H
#include <vector>
#include "Alkalmazott.h"

class Manager : public Alkalmazott {
private:
    vector<Alkalmazott*>beosztottak;
public:
    Manager(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor);

    virtual void print(ostream &n)const override;
    void addAlkalmazott(Alkalmazott *beosztott);
    void deleteAlkalmazott(int id);
    int beosztottakSzama()const;
    static const string MANAGER_MUNKAKOR ;
};


#endif //CPP_2022_MANAGER_H
