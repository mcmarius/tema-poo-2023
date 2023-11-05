#include <iostream>
#include <string>
#include <vector>
#include "Fierastrau.h"
#include "CanalDeComunicare.h"
#include <webview.h>


class Echipament {
    //std::vector<CanalDeComunicare> fire;
    CanalDeComunicare fir;
    double masa;
public:
    friend std::ostream &operator<<(std::ostream &os, const Echipament &echipament) {
        os << "fir: " << echipament.fir << " masa: " << echipament.masa;
        return os;
    }

    Echipament(const CanalDeComunicare &fir_, double masa_) : fir(fir_), masa(masa_) {}

    explicit Echipament(const CanalDeComunicare &fir_) : fir(fir_), masa(1.2) {
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


int main() {
    CanalDeComunicare canal1;
    Fir fir11;
    Wireless wireless1;
    wireless1.get_lungime();
    // CanalDeComunicare &Ref = wireless1;  // nu merge cu moștenire private/protected
    webview_t w = webview_create(0, NULL);
    webview_set_title(w, "Basic Example");
    webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
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

