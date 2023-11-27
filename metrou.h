//
// Created by marius on 27.11.2023.
//

#ifndef OOP_METROU_H
#define OOP_METROU_H

#include <cmath>
#include "mijloc_de_transport.h"

class metrou : public mijloc_de_transport {
    int nr_paznici{3};
    int statii{4};
private:
    int pret() const override {
        return std::log2(statii) + std::exp(nr_paznici);
    }
};


#endif //OOP_METROU_H
