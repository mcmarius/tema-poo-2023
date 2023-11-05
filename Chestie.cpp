#include "Chestie.h"
#include <string>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const Chestie& chestie) {
    os << chestie.s;
    return os;
}