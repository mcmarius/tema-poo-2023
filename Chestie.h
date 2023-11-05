#pragma once

#include <string>

class Chestie {
    std::string s;
public:
    // std::string f() const;
    friend std::ostream& operator<<(std::ostream& os, const Chestie& chestie);
};