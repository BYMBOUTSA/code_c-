#pragma once
#include <iostream>
#include <string>
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
        double getLongueur() const {
            return this->longueur;
        }
        void setLargeur(const int l) {
            this->largeur = l;
        }
        void setLongueur(const int L) {
            this->longueur = L;
        }
        double perimetre() const override {
            return (largeur + longueur) * 2;
        }
        double surface() const override {
            return (largeur * longueur);
        }
        std::string toString() const {
            return "(" + std::to_string(largeur) + " , " + std::to_string(longueur) + ")";
        }
        friend std::ostream& operator<<(std::ostream& f, const rectangle &r) {
            return f << r.toString();
        }

        std::string quiSuisJe() const override {
            return "un rectangle";
        }


};