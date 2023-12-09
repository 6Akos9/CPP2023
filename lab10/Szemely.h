//
// Created by balaz on 2023. 11. 29..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H
#include <string>
using namespace std;
class Szemely
{
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv = 0;
public:
    Szemely(const string& vezetekNev, const string& keresztNev, int szuletesiEv);
    virtual void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Szemely& szemely);
};


#endif //CPP_2022_SZEMELY_H
