#pragma once

class Chestie {
    std::string s;
public:
    friend std::ostream& operator<<(std::ostream& os, const Chestie& chestie);
};