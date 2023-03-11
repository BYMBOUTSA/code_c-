#pragma once
#include <iostream>


class Personne {
    protected:
        std::string nom;
        int age;
    public:
        Personne(const std::string n, const int a) : nom(n), age(a) {}
        /*~Personne() {
            std::cout << "Destruction de la personne" << std::endl;
        }*/
        std::string getNom() const {
            return nom;
        }
        int getAge() const {
            return age;
        }

};