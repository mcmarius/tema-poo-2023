//
// Created by marius on 27.11.2023.
//

#include "mijloc_de_transport.h"

int mijloc_de_transport::pret() const { return 42; }

mijloc_de_transport::~mijloc_de_transport() {
    std::cout << "destr mijloc\n";
}

std::ostream &operator<<(std::ostream &os, const mijloc_de_transport &tr) {
    os << "mijloc de transport: ";
    tr.print(os);
    os << "\n";
    return os;
}
