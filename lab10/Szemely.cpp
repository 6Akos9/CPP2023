//
// Created by balaz on 2023. 11. 29..
//

#include "Szemely.h"

Szemely::Szemely(const string &vezetekNev, const string &keresztNev, int szuletesiEv) {
    this->vezetekNev=vezetekNev;
    this->keresztNev=keresztNev;
    this->szuletesiEv=szuletesiEv;
}

void Szemely::print(ostream &n)const {
    n<<this->vezetekNev<<' ';
    n<<this->keresztNev<<' ';
    n<<this->szuletesiEv<<' ';
}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}

