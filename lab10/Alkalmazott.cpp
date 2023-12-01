//
// Created by balaz on 2023. 11. 29..
//

#include "Alkalmazott.h"
int Alkalmazott::counter = 0;
Alkalmazott::Alkalmazott(const string &vezetekNev, const string &keresztNev, int szuletesiEv, const string &munkakor)
        : Szemely(vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor),id(++counter) {

}

void Alkalmazott::print(ostream &n)const  {
    Szemely::print(n);
    n<<munkakor<<' ';
}

int Alkalmazott::getId() const {
    return id;
}
