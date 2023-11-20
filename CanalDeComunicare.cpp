//
// Created by marius on 30.10.2023.
//

#include <iostream>
#include "CanalDeComunicare.h"

CanalDeComunicare::CanalDeComunicare() { std::cout << "constr fără params fir\n"; }

CanalDeComunicare::CanalDeComunicare(int lungime_, const std::string &conector_) : lungime(lungime_),
                                                                                   conector(conector_) {
    std::cout << "constr de inițializare fir\n";
    //this->lungime = lungime_;
    //this->conector = conector_;
}

CanalDeComunicare::CanalDeComunicare(const CanalDeComunicare &other) : lungime(other.lungime),
                                                                       conector(other.conector) {
    // lungime = other.lungime;
    //conector = other.conector;
    std::cout << "constr de copiere fir\n";
}

CanalDeComunicare &CanalDeComunicare::operator=(const CanalDeComunicare &other) {
    lungime = other.lungime;
    conector = other.conector;
    std::cout << "operator= fir\n";
    return *this;
}

CanalDeComunicare::~CanalDeComunicare() {
    std::cout << "destructor fir" << lungime
              << " " << conector << "\n";
}

int CanalDeComunicare::get_lungime() const { return lungime; }

const std::string &CanalDeComunicare::getConector() const {
    return conector;
}

void CanalDeComunicare::scurteaza(int x) {
    if (x > 0)
        lungime -= x;
}

std::ostream &operator<<(std::ostream &os, const CanalDeComunicare &fir) {
    os << "lungime: " << fir.lungime << " conector: " << fir.conector;
    return os;
}
