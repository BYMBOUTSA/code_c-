#include <iostream>
#include <string>
#include "produit.hpp"


double Produit::getPrix() const {
    return this->prix * getTaux();
}

double Produit::getTaux() const {
    return this->tauxReduction;
}

void Produit::setTaux(const double t) {
    this->tauxReduction = t;
}


// le mécanisme qui a lieu là c'est la liaison dynamique
std::ostream & operator<<(std::ostream & f, const Produit & p) {
    return f << p.toString();
}