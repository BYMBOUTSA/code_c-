#pragma once
#include <iostream>
#include <set>
#include <vector>


class Motlong {
    private:
        std::multiset<char> lettres_tirees; // car on peut tiré une lettre plusieurs foic
        std::vector<char> voyelles; // on prend un vecteur car l'ordre des lettres va compter
        std::vector<char> consonnes;
        char TireLettre(const std::vector<char> & lettres); // on l'a met dans la partie private car elle n'est pas faite pour être appellé par l'utilisateur qui n'a pas accès à un tableau de lettres
    public:
        Motlong();
        // lancé la partie 
        void DebutPartie();
        // renvoyer une voyelle
        char TireVoyelle();
        // renvoyer une consonne
        char TireConsonne();
        bool Teste(std::string mot) const;

};

