#pragma once
#include <iostream>
#include <cassert>
#include "figure.hpp"

class rectangle : public figure {
    protected:
        double largeur;
        double longueur;
    public:
        rectangle(const double l=0, const double L=0) : largeur(l), longueur(L) {
            assert(l >= 0 && L >= 0);
        }
        ~rectangle() {
            std::cout << "Destruction du rectangle" << std::endl;
        }
        double getLargeur() const {
            return this->largeur;
        }

        double getLongeur() const {
            return this->longueur;
        }

        void setLargeur(const double l) {
            this->largeur = l;
        }

        void setLongueur(const double L) {
            this->longueur = L;
        }

        double perimetre() const {
            return (this->longueur + this->largeur) * 2;
        }

        double surface() const {
            return (this->longueur * this->largeur);
        }

        /*
        * Rôle : renvoie vrai si *this<r et faux sinon
        */
        bool operator<(const rectangle &c) const {
            return this->surface() < c.surface();
        }

        std::string toString() const {
            return "(" + std::to_string(this->largeur) + ", " + std::to_string(this->longueur) + ")";
        }

        friend std::ostream& operator<<(std::ostream& f, const rectangle &r) {
            return f << r.toString();
        }

        std::string quiSuisJe() const {
            return  "un rectangle";
        }
        
};