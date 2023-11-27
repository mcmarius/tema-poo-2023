//
// Created by marius on 27.11.2023.
//

#ifndef OOP_BICICLETA_H
#define OOP_BICICLETA_H


#include <ostream>
#include "mijloc_de_transport.h"

class bicicleta : public mijloc_de_transport {
    int nr_spite{100};
    int nr_locuri{1};
public:
    int pret() const override;

    std::shared_ptr<mijloc_de_transport> clone() const override;

private:
    void print(std::ostream &ostream) const override;
};


#endif //OOP_BICICLETA_H
