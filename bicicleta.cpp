//
// Created by marius on 27.11.2023.
//

#include "bicicleta.h"

int bicicleta::pret() const {
    return 100 + nr_locuri * (nr_spite * 34 + 12);
}

std::shared_ptr<mijloc_de_transport> bicicleta::clone() const {
    return std::make_shared<bicicleta>(*this);
}

void bicicleta::print(std::ostream &os) const {
    os << "nr locuri: " << nr_locuri
       << ", nr spite: " << nr_spite;
}
