#include <iostream>
#include <cstdlib>
#include <string>
#include <map>


int main () {
    // tableau associatif permet de ranger les élément ni par leur position, ni par leur valeur
    // il permet d'associer à un type clé quelconque une valeur quelconque

    // exemple annuaire
    std::map<std::string, std::string> Repertoire;

    // ajout d'un numéro par l'opérateur []
    Repertoire["Christ"] = "01.42.39.22";

    // on recherche par la fonction find
    auto i = Repertoire.find("alex"); // on recherche la chaîne "alex" dans le repertoire
    if (i != Repertoire.end())
        std::cout << "Numero : " << i->second << std::endl;
    
    // supprimer
    Repertoire.erase("Christ");
    // savoir si une clé existe par count
    if (Repertoire.count("alex") == 0) 
                std::cout << "alex n'est pas connu" << std::endl;

    // on parcourt tout 
    for (std::map<std::string, std::string>::iterator i = Repertoire.begin(); i != Repertoire.end(); i++) {
        std::cout << i->first << "t" << i->second << std::endl; 
    }

    // on peut aussi faire ce parcourt ainsi
    /*for (auto i : Repertoire) {
        std::cout << i->first << "\t" << i->second << std::endl;
    }*/


    return EXIT_SUCCESS;
}