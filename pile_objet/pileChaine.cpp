#include <iostream>
#include <string>
#include <cassert>
#include "pileChaine.hpp"


/*
 * Rôle : renvoie 0 si la pile n'est pas vide et 1 si c'est le cas 
*/
bool pileChainee::estVide() const {
    return (this->sp == nullptr);
}

/*
 * Rôle : ajouter les éléments dans la pile
*/
void pileChainee::empiler(const int e) {
    // on crée un noeud avec un entier et un lien et on positionne le pointeur
    // sur ce noeud pour le mettre en sommet de pile
    noeud *p = new noeud(e, this->sp);
    // Je mets le noeud dans la pile
    this->sp = p;
}

/*
 * Rôle : renvoie l'entier qui est le sommet de la pile
*/
int pileChainee::sommet() const {
    // on vérifie que la pile n'est pas vide
    assert(!this->estVide());
    // retourne l'élement qui est au sommet de la pile
    return this->sp->getElement();
}

/*
* Rôle : retirer le sommet de la pile
*/
void pileChainee::depiler() {
    // on vérifie que la pile ne soit pas vide
    assert(!this->estVide());
    // on crée un pointeur qu'on positionne au sommet de la pile
    noeud *p = this->sp;
    // on déplace le pointeur courant sur le noeud suivant
    this->sp = (this->sp)->getSuivant();
    // on retire le noeud pointer par p qui est notre sommet de pile
    delete p;
}

/*
 * Rôle : supprimer tous les éléments de la pile
*/
void pileChainee::detruire(noeud *n) {
   // tant que le pointeur n'est pas sur nullptr
   while (n != nullptr) {
    // on crée un pointeur qu'on met sur le noeud suivant
    noeud *p = n->getSuivant();
    // on supprime le noeud précédent
    delete n;
    // on positionne les pointeurs sur le même noeud
    n = p;
   }  
}


/*
 * Rôle : écriture des éléments de la pile sous la forme d'une chaîne de caractère
*/
std::string pileChainee::toString() const {
   // on crée une chaîne s
   std::string s = "[";
   // on crée un pointeur qu'on met au sommet de la pile
   noeud *n = this->sp;
   // tant que le pointeur n'est pas sur nullptr
   while (n != nullptr) {
    // on concatène la chaîne s avec l'élément qui est tranformé en chaîne avec un espace en plus
    s += std::to_string(n->getElement()) + " ";
    // on positionne le pointeur n sur le noeud suivant afin de continuer la concaténation
    n = n->getSuivant();
   }
   return s + "]";
}

/*
 * Rôle : surcharger l'opérateur << de façon à pouvoir écrire tous les éléments d'une pile sur une ostream
*/
std::ostream& operator<<(std::ostream& f, const pileChainee &p) {
    return f << p.toString();
}

/*
 * Rôle : renvoie la duplication de l'objet courant dans une autre pile
*/
noeud * pileChainee::dupliquer(noeud *n) {
    // si le pointeur n pointe sur nullptr
    if (n == nullptr) return nullptr;
    // si le pointeur ne pointe pas sur nullptr
    // on crée un pointeur p qui pointe sur le noeud suivant qui est dupliquer
    noeud * p = dupliquer(n->getSuivant());
    // on retourne le nouveau noeud avec l'élément et le pointeur p
    return new noeud(n->getElement(), p);
}

pileChainee & pileChainee::operator=(const pileChainee &p) {
    std::cout << "Affectation de la copie de la pile" << std::endl;
    this->sp = dupliquer(p.sp);
    return *this;
}

/*
 * Rôle : écrire sur la sortie standard le contenu d'une pile p passé en paramètre
*/
void pileChainee::ecrirePile(const pileChainee &p) {
        std::cout << p.toString() << std::endl;
}