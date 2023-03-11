#include <iostream>
#include <cstdlib>
#include <ctime>

#include "tableau.hpp"
#include "IndexException.hpp"

#define MAX

int main () {
   const int nbElements = 10;
   const int valMax = 1000;

   tableau<nbElements, int> t;
   // initialisation du tableau de façon aléatoire
   std::srand(std::time(nullptr));
   for (int i = 0; i < t.longueur(); i++)
        t[i] = rand() % valMax;
   //afficher le tableau
   std::cout << t << std::endl;

   bool ok = false;
   do {
          int i;
          // lire un indice sur l'E/S
          std::cout << "i = ";
          std::cin >> i;
          try {
               // afficher l'élément t[i]
               std::cout << t[i] << std::endl;
               ok = true;
          }
          catch (IndexException e) {
               std::cerr << e.what() << ", Recommencez." << std::endl;
          }
    
     } while(!ok);
   

     return EXIT_SUCCESS;
}