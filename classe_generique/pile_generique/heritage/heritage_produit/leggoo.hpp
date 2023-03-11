#pragma once
#include <iostream>
#include <string>
#include "produit.hpp"


class Leggoo : public Produit {
    protected:
        int age;
    public:
        Leggoo(const double pr, const int a = 6) : Produit(pr), age(a) {};
        int getAge() const;
        void setAge(const int a);
};