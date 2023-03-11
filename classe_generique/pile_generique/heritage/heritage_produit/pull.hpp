#pragma once
#include <iostream>
#include <string>
#include "produit.hpp"


class Pull : public Produit {
    private:
        std::string couleur;
    public:
        Pull(const double & pr, std::string c) : Produit(pr), couleur(c) {};
        std::string getCouleur() const;
        virtual std::string toString() const override {};
};