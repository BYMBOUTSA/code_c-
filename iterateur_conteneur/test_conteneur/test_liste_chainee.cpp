#include <iostream>
#include <cstdlib>
#include <list>

int main() {

    // liste chaînée avantages par rapport au tableau ajout / suppresssion à n'importe quel endroit
    // Inconvénients -> occupation mémoire supérieure, pas de gestion par indice
    // Gestion proche du tableau, mais pas d'incide donc il faut utiloiser nécessairement des iterator


    // Ajouter un élément à la fin de la liste
    std::list<std::string> noms;
    noms.push_back("Angel");

    // Ajouter un élément au début de la liste
    noms.push_front("Christ");

    // Affichage du dernier éléments de la liste
    std::cout << noms.back() << std::endl;

    // suppression du premier élément de la liste
    noms.pop_front();

    // Affichage du premier élément de la liste
    std::cout << noms.front() << std::endl;

    // Ajout d'un élément en début de liste
    noms.push_front("Daniel");

    // Affichage de cette élément 
    std::cout << noms.front() << std::endl;

    // Ajout au milieu de la liste
    noms.insert(noms.begin(), 1, "Paul");

    // Parcourt de toute la liste
    for (std::list<std::string>::iterator i = noms.begin(); i != noms.end(); i++) {
        std::cout << *i; // pour désigner le noms qui est dans la liste avec *i
    }

    return EXIT_SUCCESS;
}