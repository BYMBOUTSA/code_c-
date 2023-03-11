#pragma once
#include <iostream>
#include <vector>
#include "produit.hpp"


class ListeDeCourses {
    protected:
        // mécanisme de polymorphisme
        std::vector<Produit *> listeCourses;
    public:
        ListeDeCourses() {};
        ~ListeDeCourses() {
            for (Produit *p: this->listeCourses)
                delete p;
        }
        void ajouter(Produit * p);
        double prixTotal() const;
};