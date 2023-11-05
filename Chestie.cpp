#include "Chestie.h"
#include <string>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const Chestie& chestie) {
    std::ostringstream oss;
    oss << "abc";
    os << oss.str();
    return os;
}