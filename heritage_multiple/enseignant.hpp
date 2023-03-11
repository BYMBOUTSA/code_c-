#pragma once
#include <iostream>
#include "salarie.hpp"
#include "personne.hpp"


class Enseignant : public Personne, public Salarie {
    protected:
        std::string specialite;
    public:
        Enseignant(const std::string n, const int a, const std::string e, double s, const std::string spe) : Personne(n, a), Salarie(e, s), specialite(spe) {}
        /*~Enseignant() {
            std::cout << "Destruction de l'enseignant" << std::endl;
        }*/
        std::string getSpecialite() const {
            return specialite;
        }
};