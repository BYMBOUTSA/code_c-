#include <iostream>
#include <cassert>
#include "pileChainee.hpp"
#include "noeud.hpp"


/*
 * Rôle :  renvoie true si la pile est vide sinon false
*/
bool pileChainee::estVide() const {
    // retourne true si la pile est vide et false si la pile n'est pas vide
    return this->sp == nullptr;
}

/*
*   Rôle : ajouter un élément sur la pile courante
*/
void pileChainee::empiler(const int x) {
    // création d'un noeud qu'on alloue à l'entier x
    noeud *p = new noeud(x, this->sp);
    // on le place au sommet de la pile
    this->sp = p;
}

/*
 *  Rôle : renvoie l'entier correspondant au sommet de la pile courante 
*/
int pileChainee::sommet() const {
    // on vérifie si la pile est vide ou pas
    assert(!this->estVide());
    // on retourne la valeur de l'élément
    return (this->sp)->getElement();
}

/*
 *  Rôle : retirer le sommet de la pile courante 
*/
void pileChainee::depiler() {
    // on vérifie si la pile est vide ou pas
    assert(!this->estVide());
    // on crée un pointeur p qu'on met sur le sommet de la pile
    noeud *p = this->sp;
    // on déplace le pointeur sp vers le noeud suivant
    this->sp = (this->sp)->getSuivant();
    // on retire le noeud contenant le pointeur p
    delete p;
}

/*
 *  Rôle : supprime tous les éléments de la pile 
*/
void pileChainee::detruire(noeud *n) {
    // on vérifie que la pile est vide ou pas
    assert(!this->estVide());
    // tant que le pointeur sur noeud n'est pas sur nullptr
    while (n != nullptr) {
        // on crée un pointeur sur noeud qu'on met à l'élément suivant
        noeud *p = n->getSuivant();
        // on retire le noeud précédent
        delete n;
        // on met 
        n = p;
    }
}

/*
 * Rôle :  renvoie la représentation de l'objet courant sous 
 * la forme d'une string
*/
std::string pileChainee::toString() const {
    // on initialise une string
    std::string s = "[";
    // on crée un pointeur sur l'élément courant (sommet de la pile)
    noeud *n = this->sp;
    // tant que le pointeur sur n ne pointe pas sur nullptr
    while (n != nullptr) {
        // on concatene la chaine s avec la valeur en string du sommet de la pile avec en plus un espace
        s += std::to_string(n->getElement()) + " ";
        // on positionne le pointeur n sur le noeud suivant
        n = n->getSuivant();
    }
    // on retourne la chaîne s concatene à un crochet fermé
    return s + "]";
}

/*
*   Rôle : écrire tous les éléments de la pile sur un ostream
*/
std::ostream& operator<<(std::ostream& f, const pileChainee &p) {
    return f << p.toString();
}

/*
 * Rôle :  créer une copie de p
*/
noeud* pileChainee::dupliquer(noeud *n) {
    // si le pointeur sur le noeud n est sur nullptr
    if (n == nullptr) return nullptr;
    // on crée un pointeur qui pointe sur l'élément suivant
    noeud *p = dupliquer(n->getSuivant());
    // retourne l'allocation 
    return new noeud(n->getElement(), p);    
}


/*
* Rôle : surcharge de l'opérateur = pour permettre de faire la copie d'une pile dans l'autre
*/
pileChainee& pileChainee::operator=(const pileChainee &p) {
    // on met dans le pointeur sur le noeud courant la duplication de p
    this->sp = dupliquer(p.sp);
    return *this;
}