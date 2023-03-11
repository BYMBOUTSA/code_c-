#include <cstdlib>
#include <iostream>
#include <fstream>
#include "complexe.hpp"


int main () {

    /* complexe c2; // Si on déclare une variable c2 non initialisé (question 4) il y a une erreur car il n' y a pas de valeur
        par default dans le constructeur de la classe.
    */

    // 1ère manière d'initialiser des objets
    /*complexe c1 = complexe ();
    complexe c2 = complexe (4.5);
    complexe c3 = complexe (3.2, 8.9);*/

    // 2nde manière d'initialiser des objets
    /*complexe c1;
    complexe c2(4.5);
    complexe c3(3.2, 8.9);

    //c1.complexe::~complexe(); // appel du destructeur sur l'objet complexe c1 non virtuel
    //c1.~complexe(); // appel du destructeur sur l'objet complexe c1 de façon virtuel
    //c1.~complexe();

    // Affichage des partie réelles et imaginaires de nos complexes
    std::cout << c1.getPreelle() << " " << c1.getPimg() << "i" << std::endl;
    std::cout << c2.getPreelle() << " " << c2.getPimg() << "i" << std::endl;
    std::cout << c3.getPreelle() << " " << c3.getPimg() << "i" << std::endl;

    // Testage de la méthode ecrireComplexe pour afficher les valeurs de c1, c2 et c3 sur la sortie standard
    c1.ecrireComplexe();
    c2.ecrireComplexe();
    c3.ecrireComplexe();

    // Testage des fonctions rho et theta
    std::cout << c1.rho() << std::endl;
    std::cout << c1.theta() << std::endl;
    std::cout << c2.rho() << std::endl;
    std::cout << c2.theta() << std::endl;
    std::cout << c3.rho() << std::endl;
    std::cout << c3.theta() << std::endl;
    
    // Appel de la fonction polComplexe qui est une fonction static
    c1 = complexe::polComplexe(c3.rho(), c3.theta()); // Comme cette fonction ne dépend pas de l'objet
    // en particulier on pourra l'appeler en la préfixant par le nom de la classe
    c1.ecrireComplexe(); // pour afficher de x et de y on appelle notre fonction ecrireComplexe

    // test des différentes opérations
    c1.plus(c2);
    c2.plus(c3);
    c1.moins(c2);
    c3.moins(c2);
    c1.mult(c2);
    c2.mult(c3);
    c1.div(c2);
    c2.div(c3);
    c1.egal(c2);
    c2.egal(c3);
    c1.difference(c2);
    c2.difference(c3);


    // test surcharge des opérateurs
    complexe c4 = c1 + c2;
    c4.ecrireComplexe();
    c4 = c1 - c2;
    c4.ecrireComplexe();
    c4 = c2 * c3;
    c4.ecrireComplexe();
    c4 = c3 / c2;
    c4.ecrireComplexe();
    c4 = c3 == c2;
    c4.ecrireComplexe();
    c4 = c3 != c2;
    c4.ecrireComplexe();*/

    // Partie de fichier
    // Ecriture
    int n;

    std::cin >> n;

    // ouverture du fichier en écriture
    std::ofstream oos("fc");

    // Vérification de l'ouverture du fichier de sortie en écriture
    if (!oos.is_open()) {
        perror("fc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        double pr, pi;
        std::cin >> pr;
        std::cin >> pi;
        // Créer et écrire le complexe dans oos
        complexe c(pr, pi);
        oos.write((char *) &c, sizeof(complexe));
    }
    oos.close();


    // Relecture du fichier
    // ouverture du fichier fc en lecture
    std::ifstream ios("fc");

    if (!ios.is_open()) {
        perror("fc");
        exit(EXIT_FAILURE);
    }

    complexe c;

    while (ios.read((char * ) &c, sizeof(complexe)))
        c.ecrireComplexe();

    // fermeture
    ios.close();

    return EXIT_SUCCESS;
}