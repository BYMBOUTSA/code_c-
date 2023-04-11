#include <iostream>
#include <cstdlib>
#include <set>


int main () {
    // ensemble collection non ordonné (set)
    // avantage recherche d'un élément est plus rapide par rapport aux listes et aux tableaux
    // avec cdes éléments homogènes tous du même type
    // avec la variante set les éléments ne peuvent être présent qu'une seul fois
    // multiset les éléments peuvent être présent une ou plusieur fois
    // on ne peut pas mettre dans un set des éléments qui ne possède pas un opérateur <
    
    std::set<char> lettres; // On crée l'ensemble qu'on appelle lettre
    // On prend toute les lettres de A à Z 
    for (char c = 'A'; c <= 'Z'; c++) 
        lettres.insert(c); // on les insert dans l'ensemble lettres
        
    /*for (std::set<char>::iterator i = lettres.begin(); i != lettres.end(); i++) {
        std::cout << *i << std::endl;
    }*/

    std::set<char> voyelles; // on crée un ensemble voyelle
    // on insert chacune des voyelles
    voyelles.insert('A');
    voyelles.insert('E');
    voyelles.insert('I');
    voyelles.insert('O');
    voyelles.insert('U');
    voyelles.insert('Y');

    // On se sert des deux ensembles précédent pour déduire l'ensemble de consonnes
    std::set<char> consonnes; // ensemble de consonnes
    // on parcourt l'ensemble des lettres
    for (char c : lettres) {
        // si la lettres c n'est pas dans l'ensemble des voyelles alors c'est une consonnes
        if (voyelles.count(c) == 0)
            consonnes.insert(c); // on insert la lettre dans c

    }

    char lettre; std::cout << "Veuillez entrer une lettre : "; std::cin >> lettre;
    // si count pour les consonnes ne renvoie pas 0 alors c'est une consonne
    if (consonnes.count(lettre) != 0)
        std::cout << "Consonne" << std::endl;
    else if(voyelles.count(lettre))
        std::cout << "Voyelle" << std::endl;
    else 
        std::cout << "Pas une lettre" << std::endl;;

   
    
    return EXIT_SUCCESS;
}