//
// Created by balaz on 2023. 11. 29..
//

#include "Alkalmazott.h"
#include <iostream>
int Alkalmazott::counter = 0;

Alkalmazott::Alkalmazott(const string& vezetekNev, const string& keresztNev, int szuletesiEv, const string& munkakor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor)
{
    id = ++counter;
}

void Alkalmazott::print(ostream& os) const
{
    Szemely::print(os);
    os << " " << munkakor;
}

int Alkalmazott::getId() const
{
    return id;
}
