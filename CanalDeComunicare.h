//
// Created by marius on 30.10.2023.
//

#ifndef OOP_CANALDECOMUNICARE_H
#define OOP_CANALDECOMUNICARE_H

#include <iosfwd>
#include <string>

class CanalDeComunicare {
private:
    int lungime = 1;
    std::string conector = "USB-C";
    //enum t_conector { USB, RJ45,  } conector;
public:
//    CanalDeComunicare() = default;
    CanalDeComunicare();

    CanalDeComunicare(int lungime_, const std::string &conector_);

    CanalDeComunicare(const CanalDeComunicare &other);

    CanalDeComunicare &operator=(const CanalDeComunicare &other);

    ~CanalDeComunicare();

    int get_lungime() const;

    const std::string &getConector() const;

    void scurteaza(int x);

    //void set_lungime(int lungime_) { lungime = lungime_; }
    //void set_conector(std::string conector_) { conector = conector_; }
    friend std::ostream &operator<<(std::ostream &os, const CanalDeComunicare &fir);
};

class Fir : public CanalDeComunicare {
    using CanalDeComunicare::CanalDeComunicare;
};

//class FibraOptica : CanalDeComunicare {};
class Wireless : public CanalDeComunicare {
};


#endif //OOP_CANALDECOMUNICARE_H
