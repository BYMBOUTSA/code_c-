#include <iostream>
#include <cstdlib>
#include <vector>


// ascendant
void printD(std::vector<int> v) {
    for (std::vector<int>::iterator it_v=v.begin(); it_v!=v.end(); it_v++) {
        std::cout << *it_v << std::endl;
    }
}
// descendant
void printDr(std::vector<int> v) {
    for (std::vector<int>::reverse_iterator it_v=v.rbegin(); it_v!=v.rend(); it_v++) {
        std::cout << *it_v << std::endl;
    }
}

int main() {

    std::vector<int> v = {2, 3, 4, 8, 7};

    // déclaration d'un itérateur d'entier
    std::vector<int>::iterator it_v;

    // affichage de toutes les valeurs entières du vecteur
    /*for (std::vector<int>::iterator it_v=v.begin(); it_v!=v.end(); it_v++) {
        // traitement de l'élément courant *it_v
        std::cout << *it_v << std::endl;
    }*/

    // affichage de toutes les valeurs entières du vecteur en utilisant l'enoncé foreach
    /*for(int x : v) {
        // traitement de l'élément courant *it_v
        std::cout << x << std::endl;
    }*/

    // à l'aide de l'itérateur, modifier la valeur du 2ème élément du vecteur
    //p = v.begin() + 2;
    //*(v.begin() + 2) = 5;
    
    /*for(int x : v) {
        // traitement de l'élément courant *it_v
        std::cout << x << std::endl;
    }*/

    // redéclaration de l'itérateur de type const_iterator
    //std::vector<int>::const_iterator it_v;

    // écriture de la procédure
    printDr(v);
    std::cout << "--------------" << std::endl;

    // application sur le vecteur v de la méthode insert
    v.insert(v.begin() + 1, 6, -1);
    printD(v);
    std::cout << "--------------" << std::endl;
    // suppression des valeurs des positions 3 et 5 dans le vecteur v
    /*v.erase(v.begin() + 3, v.begin() + 5);
    printD(v);*/



    return EXIT_SUCCESS;
}