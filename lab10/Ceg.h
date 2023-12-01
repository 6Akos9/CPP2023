//
// Created by balaz on 2023. 12. 01..
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H
#include <vector>
#include "Szemely.h"

class Ceg {
private:
    vector<Szemely *> szemelyLista;
public:
    explicit Ceg(const string &vezetekNev, const string &keresztNev);
};


#endif //CPP_2022_CEG_H
