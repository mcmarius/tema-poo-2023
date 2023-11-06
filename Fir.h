//
// Created by marius on 30.10.2023.
//

#ifndef OOP_FIR_H
#define OOP_FIR_H

#include <iosfwd>
#include <string>

class Fir {
private:
    int lungime = 1;
    std::string conector = "USB-C";
    //enum t_conector { USB, RJ45,  } conector;
public:
    //Fir() = default;
    Fir();

    Fir(int lungime_, const std::string &conector_);

    Fir(const Fir &other);

    Fir &operator=(const Fir &other);

    ~Fir();

    int get_lungime() const;

    const std::string &getConector() const;

    void scurteaza(int x);

    //void set_lungime(int lungime_) { lungime = lungime_; }
    //void set_conector(std::string conector_) { conector = conector_; }
    friend std::ostream &operator<<(std::ostream &os, const Fir &fir);
};


#endif //OOP_FIR_H
