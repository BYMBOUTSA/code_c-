#pragma once
#include <iostream>
#include <cassert>
#include "figure.hpp"


class rectangle : public figure{
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
        double getLargeur() const;
        double getLongeur() const;
        void setLargeur(const double l);
        void setLongueur(const double L);
        double perimetre() const override;
        double surface() const override;
        bool operator<(const rectangle &c) const;
        std::string toString() const override;
        friend std::ostream& operator<<(std::ostream& f, const rectangle &r);
        std::string quiSuisJe() const override;
        
};