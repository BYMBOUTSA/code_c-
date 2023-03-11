#pragma once 
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include "pile.hpp"



template <typename T>

class pileVecteur : public pile<T> {
    private:
        std::vector<T> lesElements; // vecteur d'éléments de type T
    public:
     // on a pas besoin de faire le constructeur et le destructeur de l'objet car on utilise le type vector qui est déjà dans le langage
     /*
      * Rôle : renvoie 1 si la pile est vide et 0 si ce n'est pas vide
     */
     bool estVide() const override {
        // première manière de faire
        //return (this->lesElements.size() == 0);
        // second manière en utilisant la méthode empty de vector
        return (this->lesElements.empty());
     }
     /*
      * Rôle : ajouter un élément en sommet de la pile
     */
     void empiler(const T & x) override {
        // on utilise la fonction push_back qui permet d'ajouter un élément à la fin d'un vecteur donc au sommet de la pile
        this->lesElements.push_back(x);
     }
     /*
      * Rôle : renvoie la valeur du sommet de la pile
     */
     const T sommet() const override {
        // on vérifie que la pile des vecteurs n'est pas vide
        assert(!this->estVide());
        // on retourne le sommet de la pile avec la fonction back qui renvoie le dernier élément
        return this->lesElements.back();
     }
     /*
      * Rôle : retirer le sommet de la pile
     */
     void depiler() override {
        // on vérifie que la pile n'est pas vide
        assert(!this->estVide());
        // on retire l'élément qui se trouve en sommet(dernier) de la pile avec la fonction pop_back
        this->lesElements.pop_back();
     }
     /*
      * Rôle : renvoie l'écriture des éléments de la pile en string 
     */
     // comme on redefinit to string à la fin de l'entête on doit mettre override
     std::string toString() const override {
        // on utilise ostringstream pour écrire les caractères dans la chaîne de caractère
        std::ostringstream s;
        // on écrit une chaîne dans la chaîne s
        s << "[ ";
        // on parcourt tous les éléments de la pile de vecteur
        for (unsigned int i = 0; i < this->lesElements.size(); i++) 
            // on écrit tous les éléments dans la chaîne s avec un espace entre eux;
            s << this->lesElements[i] << " ";
        // on ajoute le crochet dans s
        s << "]";
        // on renvoie la chaîne de carcatère crée grâce à la fonction str()
        return s.str();
     }
     /*
      * Rôle : surcharge de l'opérateur << pour tous les élémets de la pile sur un ostream
     */
    
     friend std::ostream& operator<<(std::ostream &f, const pileVecteur &p)  {
        return f << p.toString();
     }

     std::string quiSuisJe() const override {
         return "une pile de vecteur";
     }
};