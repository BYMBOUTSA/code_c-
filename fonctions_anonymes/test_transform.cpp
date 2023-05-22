#include <iostream>
#include <algorithm>
#include <cstdlib>

void printVecteur(auto v) {
    for (const int x : v) 
        std::cout << x << " ";
    std::cout << std::endl;
}


int main () {

    // Exercice 5
    std::string s = "hello";
    /*std::transform(s.begin(), s.end(), s.begin(), [] (const unsigned char c) {return std::toupper(c);});*/
    //std::cout << s << std::endl;

    // Modification juste du premier caractère 
    std::transform(s.begin(), s.begin() + 1, s.begin(), [] (const unsigned char c) {return std::toupper(c);});
    std::cout << s << std::endl;

    // Exercice 6
    std::string s1 = "abcd----";
    std::transform(s1.begin(), s1.end(), s1.begin() + 4, [] (const unsigned char c) {return std::toupper(c);});
    std::cout << s1 << std::endl;

    // Exercice 7
    std::vector<int> v = {2, 3, 5, 7, 8};
    std::transform(v.begin(), v.end(), v.begin(), [] (const int i) {return i << 1;});
    printVecteur(v);


    return EXIT_SUCCESS;
}