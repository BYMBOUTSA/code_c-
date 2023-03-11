#pragma once
#include <iostream>
#include <cassert>


class Produit {
    protected:
        double prix;
        double tauxReduction = 1.0;
    public:
        Produit(const double pr) : prix(pr) {
            assert(prix >= 0);
        }
        double getPrix() const;
        double getTaux() const;
        void setTaux(const double t);
        virtual std::string toString() const = 0;
        friend std::ostream & operator<<(std::ostream & f, const Produit & p);
};