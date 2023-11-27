//
// Created by marius on 27.11.2023.
//

#ifndef OOP_MIJLOC_DE_TRANSPORT_H
#define OOP_MIJLOC_DE_TRANSPORT_H


#include <ostream>
#include <iostream>
#include <memory>

class mijloc_de_transport {
    //std::string nume;
    virtual void print(std::ostream &) const {}

public:
    virtual int pret() const = 0;

    virtual ~mijloc_de_transport();

    virtual std::shared_ptr<mijloc_de_transport> clone() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const mijloc_de_transport &tr);
};


#endif //OOP_MIJLOC_DE_TRANSPORT_H
