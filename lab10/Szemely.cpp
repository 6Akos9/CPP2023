//
// Created by balaz on 2023. 11. 29..
//

#include "Szemely.h"
#include <iostream>
Szemely::Szemely(const string& vezetekNev, const string& keresztNev, int szuletesiEv)
        : vezetekNev(vezetekNev), keresztNev(keresztNev), szuletesiEv(szuletesiEv)
{
}

void Szemely::print(ostream& os) const
{
    os << vezetekNev << " " << keresztNev << " " << szuletesiEv;
}

ostream& operator<<(ostream& os, const Szemely& szemely)
{
    szemely.print(os);
    return os;
}

