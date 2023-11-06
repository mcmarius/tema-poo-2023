//
// Created by marius on 30.10.2023.
//

#include "Fierastrau.h"

Fierastrau::Fierastrau(int zgomot, double combustibil) : zgomot(zgomot), combustibil(combustibil) {}

Fierastrau::Fierastrau() {
    std::cout << "constr implicit fierastrau\n";
}

Fierastrau::~Fierastrau() {
    std::cout << "destr fierastrau\n";
}

Fierastrau::Fierastrau(const Fierastrau &other) : zgomot(other.zgomot), combustibil(other.combustibil) {
    std::cout << "cc fierastrau\n";
}

Fierastrau &Fierastrau::operator=(const Fierastrau &other) {
    this->zgomot = other.zgomot;
    this->combustibil = other.combustibil;
    std::cout << "op= fierastrau\n";
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fierastrau &fierastrau) {
    out << "Fierastrau: {"
        << fierastrau.zgomot << " " << fierastrau.combustibil
        << "}\n";
    return out;
}

