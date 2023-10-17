#include <iostream>
#include <string>
#include <vector>

class Fierastrau {
    int zgomot{70};
    // decibeli
    double combustibil{50};
public:
    Fierastrau(int zgomot, double combustibil) : zgomot(zgomot), combustibil(combustibil) {}
    Fierastrau() {
        std::cout << "constr implicit fierastrau\n";
    }
    ~Fierastrau() {
        std::cout << "destr fierastrau\n";
    }
    Fierastrau(const Fierastrau& other) : zgomot(other.zgomot), combustibil(other.combustibil) {
        std::cout << "cc fierastrau\n";
    }
    Fierastrau& operator=(const Fierastrau& other) {
        this->zgomot = other.zgomot;
        this->combustibil = other.combustibil;
        std::cout << "op= fierastrau\n";
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, const Fierastrau& fierastrau);
};

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
    friend std::ostream &operator<<(std::ostream &os, const Fir &fir) {
        os << "lungime: " << fir.lungime << " conector: " << fir.conector;
        return os;
    }
};

class Echipament {
    //std::vector<Fir> fire;
    Fir fir;
    double masa;
public:
    friend std::ostream &operator<<(std::ostream &os, const Echipament &echipament) {
        os << "fir: " << echipament.fir << " masa: " << echipament.masa;
        return os;
    }

    Echipament(const Fir &fir_, double masa_) : fir(fir_), masa(masa_) {}

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
    Echipament& operator=(const Echipament& other) {
        fir = other.fir;
        masa = other.masa;
        std::cout << "operator= echipament\n";
        return *this;
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
    friend std::ostream &operator<<(std::ostream &os, const Laborator &laborator) {
        os << "Echipamente:\n";
        for(const auto& echipament : laborator.echipamente)
            os << "\tEchipament: " << echipament << " cod_sala: " << laborator.cod_sala << "\n";
        return os;
    }

    Laborator(const std::vector<Echipament> &echipamente_, const std::string &codSala) : echipamente(echipamente_),
                                                                                         cod_sala(codSala) {}

    void setEchipamente(const std::vector<Echipament> &echipamente_) {
        Laborator::echipamente = echipamente_;
    }

    void setCodSala(const std::string &codSala) {
        cod_sala = codSala;
    }

//    const std::vector<Echipament> &getEchipamente() const {
//        return echipamente;
//    }

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

class Duba {
    Fierastrau f;
};

//void operator>>(std::istream& in, Fierastrau& fierastrau) {}

std::ostream& operator<<(std::ostream& out, const Fierastrau& fierastrau) {
    out << "Fierastrau: {"
        << fierastrau.zgomot << " " << fierastrau.combustibil
        << "}\n";
    return out;
}

int main() {
    Fierastrau f1, f2{10, 20}, f3{100, 200};
    Fierastrau f4{f2};
    std::cout << f4;
    f2 = f3;
    std::cout << f2;
//    f1 = f2 = f3;
//    f1.operator=(f2.operator=(f3));
//    std::cout << f1 << f2;
    // std::cout.operator<<(f1); // nu se poate
//    operator<<(operator<<(std::cout, f1), f2);
//    return 0;
    Duba duba;
    std::vector<Duba> dube;
    dube.push_back(duba);
//    std::cout << duba;
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
    e3.monteaza();
    Laborator l1{{e1, e2}, "119"};
    std::cout << l1.getCodSala() << " " << "\n";
    l1.setCodSala("119!");
    l1.setEchipamente({e1, e2, e3});
    std::cout << "-------------------------------------------\n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cout << l1;
    std::cout << "-------------------------------------------\n\n";
    std::cout << "-------------------------------------------\n\n";
    std::cout << fir1.get_lungime() << " " << fir1.getConector() << "\n";
    std::cout << fir2.get_lungime() << "\n";
    std::cout << fir3.get_lungime() << "\n";
    std::cout << fir4.get_lungime() << "\n";
    return 0;
}

