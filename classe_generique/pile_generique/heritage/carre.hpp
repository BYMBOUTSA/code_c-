#pragma once
#include <iostream>
#include <cassert>
#include "rectangle.hpp"
#include "figure.hpp"


class carre : public rectangle {
    private:
        double cote;
    public:
        carre(const double c=0) : rectangle(c, c) {}
        carre(const rectangle &r) : rectangle(r.getLargeur(), r.getLongeur()) {
            assert(r.getLargeur() == r.getLongeur());
        }
        ~carre() {
            std::cout << "Destruction du carré" << std::endl;
        }
        double getCote() const {
            return this->getLargeur();  
        }

        /*void setCote(const double c) {
            this->setLargeur(c);
        }*/

        std::string quiSuisJe() const override {
            return "un carré";
        }

        /*double carre::perimetre() const {
            return (this->cote * 4);
        }

        double surface() const {
            return (this->cote * this->cote);
        }*/

        /*double perimetre() const;
        double surface() const;*/
        // exercice 6
        // modification pour ne plus utiliser les méthodes ci-dessous de la classe mère
        // car sinon on pourra avoir un carre qui a des formes différentes
        //double getLargeur() const = delete; 
        //double getLongueur() const = delete;
        void setLargeur(const int l) = delete;
        void setLongueur(const int L) = delete; 
        
        friend std::ostream& operator<<(std::ostream& f, const carre &c) {
            return f << "carre(" + std::to_string(c.getCote() )+ ")";
        }
};