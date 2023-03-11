#include <iostream>
#include "rectangle.hpp"

double rectangle::surface() const {
    return (this->longueur * this->largeur);
}

/*
* Rôle : renvoie vrai si *this<r et faux sinon
*/
bool rectangle::operator<(const rectangle &c) const {
    return this->surface() < c.surface();
}

std::string rectangle::toString() const {
    return "(" + std::to_string(this->largeur) + ", " + std::to_string(this->longueur) + ")";
}

std::ostream& operator<<(std::ostream& f, const rectangle &r) {
    return f << r.toString();
}



