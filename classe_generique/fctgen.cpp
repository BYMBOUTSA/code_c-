#include <iostream>
#include "rectangle.hpp"

template <typename T>
const T & minimum(const T &x, const T &y) {
    return x < y ? x : y;
}

int main () {
    int a, b;
    std::cout << "a : ";
    std::cin >> a;
     std::cout << "b : ";
    std::cin >> b;
    std::cout << minimum(a, b) << std::endl;

    double c = 3.4, d = 6.5;
    std::cout << minimum(c, d) << std::endl;

    std::string s = "Bonjour";
    std::string s1 = "Bonne";

    std::cout << minimum(s, s1) << std::endl;

    // affichage du minimum d'un entier et d'un réel
    //int e = 5; double f = 4.5;
    //std::cout << minimum(e, f) << std::endl; // template argument deduction/substitution failed car on a pas les mêmes types

    // Régler le problème précédent
    std::cout << minimum<double>(5.7, 13) << std::endl; // ici on a bien 5.7 comme minimum
    std::cout << minimum<int>(5.7, 13) << std::endl; // ici on va avoir 5 comme minimum car on castre le 5.7 en int

    // déclaration de r1 et r2 de type rectangle
    rectangle r1(2.3 , 1);
    rectangle r2(12.1, 0.43);
    std::cout << minimum(r1, r2) << std::endl; // on a une erreur car on veut écrire un type rectangle sur la sortie, il faut le surcharger l'opérateur <<
    // Après avoir fait la surcharge de l'opérateur << on se rend compte que sa marche mieux

    /*const auto minimum(const auto &x, const auto &y) {
        return x < y ? x : y;
    }*/


    return EXIT_SUCCESS;
}