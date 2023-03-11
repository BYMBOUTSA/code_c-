#include <iostream>
#include "noeud.hpp"

/*
 * Rôle : renvoie l'élément
*/
int noeud::getElement() const {
    return this->elt;
}

/*
 * Rôle : modifie l'élément
*/
void noeud::setElement(const int e) {
    this->elt = e;
}

/*
 * Rôle : renvoie l'élément suivant
*/
noeud* noeud::getSuivant() const {
    return this->suivant;
}

/*
 * Rôle : modifie l'élément suivant 
*/
void noeud::setSuivant(noeud *n) {
    this->suivant = n;
}