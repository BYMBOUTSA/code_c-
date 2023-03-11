#pragma once
#include <iostream>


class Animal {
    protected:
        double ration;
    public:
        Animal(const double kg) : ration(kg) {}
        virtual ~Animal() {
            std::cout << "Destruction de l'animal" << std::endl;
        }
        double getRation() const {
            return ration;
        }
        virtual void jeMange() const = 0;

};