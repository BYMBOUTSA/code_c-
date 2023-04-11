#include <iostream>
#include <cstdlib>
#include <vector>



// Ecriture de la procédure printD qui affiche de façon descendante sur la sortie standard 
void printD(std::vector<int> v) {
    for (std::vector<int>::iterator it_v = v.end() - 1; it_v >= v.begin(); it_v--) {
        std::cout << *it_v << std::endl;
    }
}

// utilisation de reverse_iterator pour faire ce même parcours descendant, écriture de la procédure printDr
void printDr(std::vector<int> v) {
    for (std::vector<int>::reverse_iterator it_v = v.rbegin(); it_v != v.rend(); it_v++) {
        std::cout << *it_v << std::endl;
    }
}

// procédure printA d'affichage ascendant
void printA(std::vector<int> v) {
    for (std::vector<int>::iterator it_v = v.begin(); it_v != v.end(); it_v++) {
        std::cout << *it_v << std::endl;
    }
}


int main () {

    std::vector<int> v = {2, 6, 8, 9, 10};

    // déclaration d'un itérateur it_v pour un vecteur d'entier
    //std::vector<int>::iterator it_v;

    // Rédéclaration de l'itérateur de type const_iterator
    std::vector<int>::const_iterator it_v; 

    // affichage des valeurs du vecteur par l'intermédiaire de l'itérateur it_v
    for(it_v = v.cbegin(); it_v != v.cend(); it_v++) {
        std::cout << *it_v  << std::endl;
    }

    // à l'aide de l'itérateur modifions la deuxième valeur du tableau
    *(v.begin() + 1) = 7;
    *(v.end()) = 9;
    std::cout << "--------- --------------" << std::endl;
    for (int x : v) {
        std::cout << x  << std::endl;
    }

    std::cout << "--------- --------------" << std::endl;
    // affichage des valeurs de v sur la sortie standard
    printD(v);

    std::cout << "--------- --------------" << std::endl;
    printDr(v);

    std::cout << "--------- --------------" << std::endl;
    // application de la méthode insert sur le vecteur v puis l'afficher
    v.insert(v.begin() + 1, 6, -1);
    printA(v);

    std::cout << "--------- --------------" << std::endl;
    // application de la méthode erase sur le vecteur v puis l'afficher
    v.erase(v.begin() + 2, v.begin() + 4);
    printA(v);


    return EXIT_SUCCESS;
}