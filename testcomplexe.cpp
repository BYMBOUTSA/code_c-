#include <cstdlib>
#include <iostream>
#include "classe.hpp"


int main() {

    complexe c1;
    complexe c2(4.5);
    complexe c3(3.2, 8.9);
    complexe c4(0.0, -3.9);

    std::cout << c2.getPreelle() << " " << c2.getPimg()  << "i" << std::endl;
    std::cout << c3.getPreelle() << " " << c3.getPimg() <<  "i" << std::endl;
    std::cout << c4.getPreelle() << " " << c4.getPimg() << "i" << std::endl;

    //c3.ecrireComplexe();

    complexe v5 = complexe::polComplexe(c3.rho(), c3.theta());

    // TD5

    int * pi = new int[10];
    complexe * pc = new complexe[5];

    pi[1] = 10;

    // Affichage de sa valeur
    std::cout << pi[2] << std::endl;

    // Affichage de la valeur de pi[8]
    std::cout << pi[8] << std::endl; // Il est à 0 donc par conséquent il a été alloué à 0 lors de l'initialisation de notre tableau

    // Affichage de la valeur de pi[11]
    std::cout << pi[11] << std::endl; // qu'il y a aussi la valeur de pi[11] pendant que cette élément n'existe pas (il y a une erreur de segmentation qui n'est pas pris en compte)

    // Affichage du troisième élément de pc
    pc[2].ecrireComplexe(); // que la partie réelle et imaginaire sont nulles (que l'initialisation ce fait à 0) 

    // oui il est obligatoire car on utilise bien les éléments de notre complexe donc le constructeur par défaut est bien appelé

    complexe **ptpc = new complexe*[10];

    
    // il faut passer par une boucle for
    for (int i = 0; i < 10; i++)
        //std::cout << ptpc[1] << std::endl; 
        ptpc[i] = new complexe();
    
    // Affichage du deuxième 
    (*ptpc[1]).ecrireComplexe(); // On a une Erreur de segmentation normalement quand je le fais sans la boucle for
    

    //complexe * pc0 = new complexe(3.1, 6.56);
    //delete pc0; // oui il est éxécuté

    // Affichage de la partie imaginaire de pc0
    //std::cout << pc0->getPimg() << std::endl; // On a une valeur aléatoire qui s'affiche car il y a des fuites de mémoires
    // dû au fait qu'il n'y a pas de contrôle qui a été effectué.

    // Destruction des éléments du tableau pc
    //delete [] pc; // oui il est éxécuté pour chacun des éléments du tableau

    // Détruisons les éléments du tableau ptpc
    delete [] ptpc; // Non juste pour 6 éléments

    // Insertion des lignes ci-dessous juste avant le return
    complexe c6(1.2, 56.9);
    std::cout << "c6 = " << c6 << std::endl; // Que j'ai bien l'affichage de la partie réelle et imaginaire de mon complexe
    // Qu'on peut maintenant écrire nos complexes directement dans la console sans passer par la méthode ecrireComplexe ou toString
    // Grâce à la surcharge de l'opérateur <<

    std::cin >> c6;
    std::cout << c6;

    return EXIT_SUCCESS;
}