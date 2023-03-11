#pragma once
#include <iostream>


class rectangle {
    private:
        double largeur;
        double longueur;
    public:
        rectangle(const double l, const double a) : largeur(l), longueur(a) {}
        double surface() const;
        bool operator<(const rectangle &c) const;
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& f, const rectangle &r);
};