#include <iostream>
#include <cstdlib>
#include <exception>


int main() {

    int t[5] = {1, 8, -7};

    std::cout << t[2] << std::endl;

    std::cout << t[3] << std::endl;
    std::cout << t[-1] << std::endl; // indice non controllé nous donne une valeur par defaut
    std::cout << t[-8] << std::endl; // indice non controllé nous donne une valeur par defaut


    return EXIT_SUCCESS;
}