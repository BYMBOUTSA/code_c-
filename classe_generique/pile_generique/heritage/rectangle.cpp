#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "figure.hpp"


double rectangle::getLargeur() const {
    return this->largeur;
}

double rectangle::getLongeur() const {
    return this->longueur;
}

void rectangle::setLargeur(const double l) {
    this->largeur = l;
}

void rectangle::setLongueur(const double L) {
    this->longueur = L;
}

double rectangle::perimetre() const {
    return (this->longueur + this->largeur) * 2;
}

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

std::string rectangle::quiSuisJe() const {
    return  "un rectangle";
}