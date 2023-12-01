//
// Created by balaz on 2023. 11. 29..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H
#include "Szemely.h"

#include "Szemely.h"

class Alkalmazott : public Szemely{
protected:
    int id;
    string munkakor;
    static int counter;
public:
    Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor);
    virtual void print(ostream &n)const override;

    int getId() const;
};


#endif //CPP_2022_ALKALMAZOTT_H
