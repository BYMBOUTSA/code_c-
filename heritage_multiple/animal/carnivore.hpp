#pragma once
#include <iostream>
#include "animal.hpp"


class Carnivore : public virtual Animal {

    public:
        Carnivore(const double kg = 0.0) : Animal(kg) {}
        virtual void jeMange() const override {
            //std::cout << "de la viande" << std::endl;
            std::cout << Animal::getRation() << " kilos de viande par jour" << std::endl;
        }

};