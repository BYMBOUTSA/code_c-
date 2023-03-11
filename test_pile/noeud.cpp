#include <iostream>
#include "noeud.hpp"

/*
* Rôle : renvoie la valeur de l'élément
*/
int noeud::getElement() const {
    return this->elt;
}

/*
 * Rôle : modifie la valeur de l'élément 
*/
void noeud::setElement(const int x) {
    this->elt = x;
}

/*
 * Rôle : renvoie la valeur de l'élément suivant 
*/
noeud * noeud::getSuivant() const {
    return this->suivant;
}

/*
 * Rôle : modifie l'élément suivant 
*/
void noeud::setSuivant(noeud *n) {
    this->suivant = n;
}
