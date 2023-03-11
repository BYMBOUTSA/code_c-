#pragma once
#include <iostream>
#include "animal.hpp"


class Herbivore : public virtual Animal {

    public:
        Herbivore(const double kg = 0.0) : Animal(kg) {}
        virtual void jeMange() const override {
            //std::cout << "de l'herbe" << std::endl;
            std::cout << Animal::getRation() << " kilos d'herbe par jour" << std::endl;
        }
};