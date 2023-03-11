#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "motlong.hpp"



Motlong::Motlong() {
    // Ajout des différentes voyelles
    voyelles.push_back('A');
    voyelles.push_back('O');
    voyelles.push_back('E');
    voyelles.push_back('U');
    voyelles.push_back('I');
    voyelles.push_back('Y');

    // on parcout tous les éléments
    for (char c = 'A'; c <= 'Z'; c++) {
        if(std::find(voyelles.begin(), voyelles.end(), c) == voyelles.end()) {
            consonnes.push_back(c); // si il ne le trouve pas dans les voyelles alors c'est une consonne
        }
    }
}


void Motlong::DebutPartie() {
    lettres_tirees.clear(); // on vide le tableau au départ
}


char Motlong::TireConsonne() {
    return TireLettre(consonnes);
}

char Motlong::TireVoyelle() {
    return TireLettre(voyelles); // on appelle la méthode TireLettre avec le tableau de voyelles
}

// Fonction permettant de factoriser le code de TireVoyelle() et de TireConsonne() qui se repétais
char Motlong::TireLettre(const std::vector<char> & lettres) {
    int i = std::rand() % lettres.size(); 
    char c = lettres[i]; // on prend le caractère
    lettres_tirees.insert(c); // ajout du caractère aux lettres tirées
    return c;
}


bool Motlong::Teste(std::string mot) const {
    std::multiset<char> lettres;
    for (char c : mot) // pour chaque caractères de mot je l'ajoute dans mon multiset
        lettres.insert(c);
    bool ok = true;
    for (char lettre : lettres) {
        if (lettres.count(lettre) > lettres_tirees.count(lettre)) {
            ok = false;
            break;
        }
    }
    return ok;
}