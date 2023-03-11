#include <cstdlib>
#include <iostream>
#include "pileChaine.hpp"



int main () {
    pileChainee p = pileChainee();
    std::cout << p.estVide() << std::endl;
    p.empiler(6);
    p.empiler(15);
    std::cout << p.sommet() << std::endl;
    std::cout << p.toString() << std::endl;
    std::cout << p.estVide() << std::endl;
    std::cout << p.sommet() << std::endl;
    p.depiler();
    std::cout << p.sommet() << std::endl;
    // Grâce à la surcharge on peut écrire directement les éléments de la pile sur notre ostream
    std::cout << p << std::endl;
    // Création de la pile p1
    pileChainee p1;
    // on empile la valeur 10 dans la pile p1
    p1.empiler(10);
    // on affiche le sommet de la pile
    std::cout << p1.sommet() << std::endl;
    // on déclare la variable p2 de type pileChainee qu'on initialise à p1
    pileChainee p2;
    p2 = p1;
    // on affiche la valeur du sommet de p1, puis celle de p2
    std::cout << p1.sommet() << std::endl;
    std::cout << p2.sommet() << std::endl;
    // on dépile p2
    p2.depiler();
    // on affiche le sommet de p1
    std::cout << p1.sommet() << std::endl; // on a une valeur par défaut car on tente d'accéder à une valeur de sommet
    // qui n'existe pas car la pile est vide, que la pile p1 et p2 représente une seule pile donc en faisant p2 = p1 on 
    // a pas fait une simple copie mais on a fait une affectation donc la pile p1 est exactement la même que p2

    p2.ecrirePile(p1); // qu'on teste avec une transmission par valeur ou par référence on a le même résultat


    return EXIT_SUCCESS;
}
