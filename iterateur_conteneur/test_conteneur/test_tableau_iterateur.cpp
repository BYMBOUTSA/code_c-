#include <iostream>
#include <cstdlib>
#include <vector>


int main () {

    std::vector<double> v(10);

    // ajoute tous les éléments
    double x = 0.0;
    for (std::vector<double>::iterator i = v.begin(); i != v.end(); i++) {
        x += *i; // *i opérateur de déferencement avec -> pour chercher ce que désigne l'itérateur i
        std::cout << x << std::endl;
    }

    // séparateur
    std::cout << "*----------------*" << std::endl;
    // parcours à l'envers
    std::reverse_iterator j = v.rbegin();
    while(j != v.rend()) {
        x += *j;
        std::cout << x << std::endl;;
        j++;
    }

    // séparateur
    std::cout << "*----------------*" << std::endl;
    // Quelques opérations
    std::vector<std::string> noms;
    // ajoute un élément à la fin (push_back() pour la bibiothèque standard)
    noms.push_back("Angel");
    noms.push_back("David");

    // lit le prémier élément (front())
    std::cout <<  "first element : " << noms.front() << std::endl;

    for (std::vector<std::string>::iterator a = noms.begin(); a != noms.end(); a++) {
        std::string s = *a;
        std::cout << s << std::endl;
    }

    // séparateur
    std::cout << "*----------------*" << std::endl;
    std::reverse_iterator b = noms.rbegin();
    while(b != noms.rend()) {
        std::string s = *b;
        std::cout << s << std::endl;
        b++;
    }

    // lit le dernier élément (back())
    std::cout << "last element : " << noms.back() << std::endl;

    // supression du dernier élément le seul qu'il est possible de supprimer directement dans un tablea avec la fonction pop_back()
    noms.pop_back();
    std::cout << "last element : " << noms.back() <<  " after deleting of the old last element" << std::endl;

    return EXIT_SUCCESS;

}