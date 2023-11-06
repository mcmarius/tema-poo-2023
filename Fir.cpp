//
// Created by marius on 30.10.2023.
//

#include <iostream>
#include "CanalDeComunicare.h"

Fir::Fir() { std::cout << "constr fără params fir\n"; }

Fir::Fir(int lungime_, const std::string &conector_) : lungime(lungime_), conector(conector_) {
    std::cout << "constr de inițializare fir\n";
    //this->lungime = lungime_;
    //this->conector = conector_;
}

Fir::Fir(const Fir &other) : lungime(other.lungime), conector(other.conector) {
    //lungime = other.lungime;
    //conector = other.conector;
    std::cout << "constr de copiere fir\n";
}

Fir &Fir::operator=(const Fir &other) {
    lungime = other.lungime;
    conector = other.conector;
    std::cout << "operator= fir\n";
    return *this;
}

Fir::~Fir() {
    std::cout << "destructor fir" << lungime
              << " " << conector << "\n";
}

int Fir::get_lungime() const { return lungime; }

const std::string &Fir::getConector() const {
    return conector;
}

void Fir::scurteaza(int x) {
    if (x > 0)
        lungime -= x;
}

std::ostream &operator<<(std::ostream &os, const Fir &fir) {
    os << "lungime: " << fir.lungime << " conector: " << fir.conector;
    return os;
}
