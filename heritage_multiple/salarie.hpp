#pragma once
#include <iostream>

class Salarie {
    protected:
        std::string entreprise;
        //std::string nom;
        double salaire;
    public:
        Salarie(const std::string e, const double s) : entreprise(e), salaire(s) {}
        /*~Salarie() {
            std::cout << "Destruction du Salarié" << std::endl;
        }*/
        std::string getEntreprise() const {
            return entreprise;
        }
        /*std::string getNom() const {
            return nom;
        }*/
        double getSalaire() const {
            return salaire;
        }

};