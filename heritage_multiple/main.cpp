#include <iostream>
#include <cstdlib>
#include "enseignant.hpp"



int main() {
    Enseignant paul("Paul", 50, "Polytech", 5000, "Electronique");

    std::cout << paul.getSpecialite() << std::endl;

    std::cout << paul.getNom() << std::endl;
    //std::cout << paul.getSalaire() << std::end;
    std::cout << paul.getEntreprise() << std::endl;
    std::cout << paul.getAge() << std::endl;
    

    // Pour traiter le cas de l'ambiguîté
    // il suffit de préfixer la méthode getNom() par le Nom de la classe
    // pour spécifier laquelle des méthodes nom qu'on voudrais utiliser
    
    //std::cout << paul.Personne::getNom() << std::endl;
    //std::cout << paul.Salarie::getNom() << std::endl;

    return EXIT_SUCCESS;

}