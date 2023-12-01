#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"


int main() {
    Szemely *s = new Szemely("a", "b", 1988);
    Szemely *a = new Alkalmazott("a", "c", 1970, "f");
    Szemely *m = new Manager("c", "D", 1896, "mgr");
    s->print(cout);
    a->print(cout);
    m->print(cout);
    return 0;
}