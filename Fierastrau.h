//
// Created by marius on 30.10.2023.
//

#ifndef OOP_FIERASTRAU_H
#define OOP_FIERASTRAU_H


#include <iostream>

class Fierastrau {
    int zgomot{70};
    // decibeli
    double combustibil{50};
public:
    Fierastrau(int zgomot, double combustibil);

    Fierastrau();

    ~Fierastrau();

    Fierastrau(const Fierastrau &other);

    Fierastrau &operator=(const Fierastrau &other);

    friend std::ostream &operator<<(std::ostream &out, const Fierastrau &fierastrau);
};


#endif //OOP_FIERASTRAU_H
