#include "Chestie.h"
#include <sstream>

std::string Chestie::f() const {
    std::ostringstream oss;
    oss << static_cast<int>('1');
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Chestie& chestie) {
    os << chestie.f();
    os << chestie.s << chestie.i;
    return os;
}