#pragma once
#include <iostream>
#include "herbivore.hpp"
#include "carnivore.hpp"


class Omnivore : public Herbivore, public Carnivore {

    public:
        Omnivore(const double kg = 0) : Animal(kg), Herbivore(kg), Carnivore(kg) {}
        virtual void jeMange() const override{
            std::cout << Animal::getRation() << " kilos de viande et d'herbe par jour" << std::endl;
        }

};