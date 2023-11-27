#include <list>
#include <string>
#include <iostream>
#include <memory>
#include <cmath>
#include "mijloc_de_transport.h"
#include "bicicleta.h"


class autobuz : public mijloc_de_transport {
    int nr_roti{6};
    std::string tip_combustibil;
    int nr_locuri{100};

    void print(std::ostream &os) const override {
        os << nr_roti << " " << tip_combustibil << " " << nr_locuri << "\n";
    }
public:
    int pret() const override {
        float multiplier_combustibil = 1;
        if (tip_combustibil == "gpl")
            multiplier_combustibil = 2.5;
        return (nr_roti * 123 + nr_locuri * 321) * multiplier_combustibil;
    }

    ~autobuz() override {
        std::cout << "destr autobuz\n";
    }

    std::shared_ptr<mijloc_de_transport> clone() const override {
        return std::make_shared<autobuz>(*this);
    }
    // virtual autobuz* clone() const = 0;
    // tip covariant
};

class tramvai : public mijloc_de_transport {
    int nr_usi{10};
    int nr_burdufuri{2};

    void print(std::ostream &os) const override {
        os << nr_usi << " " << nr_burdufuri << "\n";
    }

public:
    int pret() const override {
        return 777 * (nr_usi / nr_burdufuri);
    }

    ~tramvai() override {
        std::cout << "destr tramvai\n";
    }

    std::shared_ptr<mijloc_de_transport> clone() const override {
        return std::make_shared<tramvai>(*this);
    }
};


class traseu {
    int id{};
    std::list<std::shared_ptr<mijloc_de_transport>> mijloace;
public:
    int pret_total() const {
        int suma = 0;
        for (const auto &mijloc: mijloace)
            suma += mijloc->pret();
        return suma;
    }

    void add(const mijloc_de_transport &mij) {
        mijloace.push_back(mij.clone());
    }

    traseu() = default;

    traseu(const traseu &other) {
        for (const auto &mijloc: other.mijloace) {
            // if pe tip sau multe dynamic_cast-uri din aceeași ierarhie ==> GREȘIT
            mijloace.push_back(mijloc->clone());
        }
    }

    friend void swap(traseu &t1, traseu &t2) {
        using std::swap;  // enables ADL (argument depenedent lookup)
        swap(t1.id, t2.id);
        swap(t1.mijloace, t2.mijloace);
    }

    traseu &operator=(traseu other) {
        if (this == &other)
            return *this;
        swap(*this, other);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const traseu &tr) {
        os << "traseu:\n";
        for (const auto &mijloc: tr.mijloace)
            os << *mijloc;
        return os;
    }
};

[[maybe_unused]] void test1() {
    mijloc_de_transport *tr;
    autobuz a1;
    tramvai t1;
    std::cout << a1.pret() << " " << t1.pret() << "\n";
    tr = &a1;
    std::cout << tr->pret() << "\n";
    tr = &t1;
    std::cout << tr->pret() << "\n";
    mijloc_de_transport &ref = a1;
    std::cout << ref.pret() << "\n";
    ref = t1;
    std::cout << ref.pret() << "\n";

}

void adauga(traseu &tr) {
    autobuz a1;
    tramvai t1;
    tr.add(a1);
    tr.add(t1);
    tr.add(bicicleta{});
}

int main() {
    traseu traseu1;
    adauga(traseu1);
    std::cout << "total: " << traseu1.pret_total() << "\n";

    traseu traseu2{traseu1};
    traseu traseu3 = traseu1;
    traseu2 = traseu3;
    //traseu2.operator=(traseu3);
    std::cout << traseu1 << traseu2;
    return 0;
}
