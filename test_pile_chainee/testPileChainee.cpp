#include <iostream>
#include "pileChainee.hpp"
#include <cstdlib>


int main () {
    pileChainee p = pileChainee();
    std::cout << p.estVide() << std::endl;
    p.empiler(6);
    p.empiler(15);
    std::cout << p.sommet() << std::endl;
    std::cout << p.estVide() << std::endl;
    std::cout << p.sommet() << std::endl;
    p.depiler();
    std::cout << p.sommet() << std::endl;

    std::cout << p << std::endl;

    /*p.empiler(10);
    p.empiler(7);
    std::cout << p.sommet() << std::endl;
    std::cout << p.estVide() << std::endl;
    std::cout << p << std::endl;*/

    // constructeur de copie
    pileChainee p1 = pileChainee();
    // empiler la valeur 10 en sommet de votre pile
    p1.empiler(10);
    // affichage du sommet de la pile
    std::cout << p1.sommet() << std::endl;
    // déclaration de la variable p2 initialisée à p1
    pileChainee p2;
    p2 = p1;
    // affichage de la valeur du sommet de p2
    std::cout << p2.sommet() << std::endl;
    // appliquer la méthode dépiler sur p2
    p2.depiler();
    // affichage de la valeur du sommet de p1
    std::cout << p1.sommet() << std::endl; // qu'il y a une valeur par défaut car on essaie d'afficher à une pile vide (sans élément)
    //std::cout << p2.sommet() << std::endl; // on a bien l'assertion qui s'effectue car il n' y a plus 
    // d'élément dans la pile p1, et p2
    // on a bien retiré le sommet de la pile p1, en retirant le sommet de la pile p2
    // etant donné que la pile p1 et p2 sont identique donc en dépilant le sommet de p2 on fait de même pour p1
    
    return EXIT_SUCCESS;
}
