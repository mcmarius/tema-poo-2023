#include <iostream>
#include <vector>

class Fir {
private:
    int lungime = 1;
    std::string conector = "USB-C";
    //enum t_conector { USB, RJ45,  } conector;
public:
    //Fir() = default;
    Fir() { std::cout << "constr fără params fir\n"; }
    Fir(int lungime_, const std::string& conector_) : lungime(lungime_),
       conector(conector_) {
        std::cout << "constr de inițializare fir\n";
        //this->lungime = lungime_;
        //this->conector = conector_;
    }
    Fir(const Fir& other) : lungime(other.lungime), conector(other.conector) {
        //lungime = other.lungime;
        //conector = other.conector;
        std::cout << "constr de copiere fir\n";
    }
    Fir& operator=(const Fir& other) {
        lungime = other.lungime;
        conector = other.conector;
        std::cout << "operator= fir\n";
        return *this;
    }
    ~Fir() {
        std::cout << "destructor fir" << lungime
                  << " " << conector << "\n";
    }

    int get_lungime() const { return lungime; }

    const std::string& getConector() const {
        return conector;
    }

    void scurteaza(int x) {
        if(x > 0)
            lungime -= x;
    }
    //void set_lungime(int lungime_) { lungime = lungime_; }
    //void set_conector(std::string conector_) { conector = conector_; }

};

class Echipament {
    //std::vector<Fir> fire;
    Fir fir;
    double masa;
public:
    explicit Echipament(const Fir& fir_) : fir(fir_), masa(1.2) {
        //fir = fir_;
        //fir.operator=(fir_);
        //masa = 1.2;
    }
    Echipament(const Echipament& other) : fir(other.fir),
                                        masa(other.masa) {
        //fir = other.fir;
        //masa = other.masa;
        std::cout << "constructor de copiere echipament\n";
    }
    void monteaza() {
        fir.scurteaza(2);
        masa += 2.3;
    }
};

class Laborator {
    std::vector<Echipament> echipamente;
    std::string cod_sala;
public:
    Laborator(const std::vector<Echipament> &echipamente, const std::string &codSala) : echipamente(echipamente),
                                                                                        cod_sala(codSala) {}

    void setEchipamente(const std::vector<Echipament> &echipamente) {
        Laborator::echipamente = echipamente;
    }

    void setCodSala(const std::string &codSala) {
        cod_sala = codSala;
    }

    const std::vector<Echipament> &getEchipamente() const {
        return echipamente;
    }

    const std::string &getCodSala() const {
        return cod_sala;
    }
};

/*
class T1 {
  int x;
  public:
  T1(int x_) { x= x_; }
};
class T2 {
  int x;
  public:
  explicit T2(int x_) { x= x_; }
};

void f(T1 t) {std::cout << "f t1\n";}
void f(T2 t) {std::cout << "f t2\n";}
*/

int main() {
    // f(T2{1});
    std::cout << "înainte de fir1, fir2\n";
    Fir fir1{2, "USB"}, fir2{3, "RJ45"};
    std::cout << "înainte de fir3\n";
    Fir fir3;
    Fir fir4(30, "VGA");
    //fir3.set_lungime(20);
    //fir3.set_conector("HDMI");
    std::cout << "înainte de echipamente\n";
    Echipament e1{fir1};
    std::cout << "după e1\n";
    Echipament e2{e1}, e3 = e2;
    e1.monteaza();
    // Laborator l1;
    std::cout << fir1.get_lungime() << "\n";
    std::cout << fir2.get_lungime() << "\n";
    std::cout << fir3.get_lungime() << "\n";
    std::cout << fir4.get_lungime() << "\n";
    return 0;
}

