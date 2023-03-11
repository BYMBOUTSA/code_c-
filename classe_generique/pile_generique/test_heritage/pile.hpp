#pragma once
#include <iostream>
#include <string>


template <typename T>

class pile {

    public:
        virtual ~pile() {
            //std::cout << "Destructeur de la pile" << std::endl;
        }
        virtual bool estVide() const = 0;
        virtual void empiler(const T & x) = 0;
        virtual const T sommet() const = 0;
        virtual void depiler() = 0;
        virtual std::string quiSuisJe() const = 0;


};