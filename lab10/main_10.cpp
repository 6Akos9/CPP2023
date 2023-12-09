#include <iostream>

#include "Ceg.h"

int main() {
    Ceg ceg;
    Alkalmazott alkalmazott1("Kiss", "Jozsef", 1980, "sofor");
    Alkalmazott alkalmazott2("Nagy", "Gabor", 1985, "sofor");
    Alkalmazott alkalmazott3("Kovacs", "Peter", 1987, "sofor");
    Alkalmazott alkalmazott4("Kiss", "Olivia", 1987, "sofor");
    Alkalmazott alkalmazott5("Kiss", "Miklos", 1987, "sofor");
    Manager manager1("Kiss", "Peter", 1987, Manager::MANAGER_MUNKAKOR);
    Manager manager2("Nagy", "Peter", 1987, Manager::MANAGER_MUNKAKOR);
    Manager manager3("Dezsofi", "Peter", 1987, Manager::MANAGER_MUNKAKOR);
    ceg.addAlkalmazott(&alkalmazott1);
    ceg.addAlkalmazott(&alkalmazott2);
    ceg.addAlkalmazott(&alkalmazott3);
    ceg.addAlkalmazott(&alkalmazott4);
    ceg.addAlkalmazott(&alkalmazott5);
    ceg.addAlkalmazott(&manager1);
    ceg.addAlkalmazott(&manager2);
    ceg.addAlkalmazott(&manager3);
    ceg.print(cout);
    cout << endl;
    for (int i = 1; i <= 2; ++i) {
        ceg.assignManager(i, &manager1);
    }
    for (int i = 3; i <= 5; ++i) {
        ceg.assignManager(i, &manager2);
    }
    ceg.printManagers(cout);
    cout << endl;
    ceg.unassignManager(1, &manager1);
    ceg.assignManager(1, &manager3);
    ceg.printManagers(cout);
    cout << endl;
    return 0;
}