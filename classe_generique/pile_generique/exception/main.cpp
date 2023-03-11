#include <iostream>
#include <cstdlib>
#include "tableau.hpp"
#include "complexe.hpp"
#include "IndexException.hpp"



int main () {

    tableau<5, complexe> tc; // un tableau de 5 complexe
    std::cout << tc.longueur() << std::endl;
    tc[0] = complexe(1, 3);
    std::cout << tc[0] << std::endl;
    std::cout << tc << std::endl;
    
    tableau<10, int> ti1 = {3, 8, -9};
    tableau<10, int> ti2;

    ti2 = ti1;
    ti2[5] = 20;
    std::cout << ti1[5] << std::endl;
    std::cout << ti2[5] << std::endl;

    // on déclenche les exception
    int i;
    std::cout << "i = ";
    std::cin >> i;

    try {
        std::cout << tc[i] << std::endl;
    }
    catch (const IndexException & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << tc[-10] << std::endl;


    return EXIT_SUCCESS;
}