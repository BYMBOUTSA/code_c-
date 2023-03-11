#include <iostream>
#include <cstdlib>
#include "animal.hpp"
#include "herbivore.hpp"
#include "carnivore.hpp"
#include "omnivore.hpp"


int main () {

    /*Animal e;
    Herbivore mouton;
    Carnivore lion;
  
    std::cout << "Je mange ";
    mouton.jeMange();
    std::cout << "et moi, je mange ";
    lion.jeMange();*/

    //Omnivore kangourou;
    /*std::cout << "Je mange ";
    kangourou.Herbivore::jeMange();
    std::cout << "et ";
    kangourou.Carnivore::jeMange();
    std::cout << std::endl;*/

    /*std::cout << "Je mange ";
    kangourou.jeMange();
    std::cout << std::endl;*/

    // on a bien une ambiguité 
    // dû au fait que la classe Omnivore est 
    // hérite de la méthode getRation() qui est présente dans c'est deux classe mère
    /*Omnivore ours;

    std::cout << ours.getRation() << std::endl; */

    Animal * faune[] = {new Omnivore(10), new Herbivore(60), new Carnivore(7)};
    for (Animal * a : faune) {
        std::cout << "Je mange "; a->jeMange(); std::cout << std::endl;
    }


    return EXIT_SUCCESS;
}