#include <iostream>
#include <cstdlib>
#include <string>
#include "motlong.hpp"


int main () {
    std::cout << "Le mot le plus long !" << std::endl;
    Motlong jeu;

    while (true) {
        std::cout << "voyelle ou consonne ? ";
        char c;
        std::cin >> c;

        if (c == 'v') 
            c = jeu.TireVoyelle();
        else if (c == 'c') 
            c = jeu.TireConsonne();
        else
            break; 
        std::cout << c << std::endl;
    }

    while (true) {
        std::cout << "Proposition : ";
        std::string mot;
        std::cin >> mot;
        if (jeu.Teste(mot))
            break;
        else 
            std::cout << "Incorrect" << std::endl;
    }
    

    std::cout << "au revoir" << std::endl;


    return EXIT_SUCCESS;
}