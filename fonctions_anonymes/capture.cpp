#include <iostream>
#include <cstdlib>
#include <algorithm>


int main () {

    int n = 10;
    std::function<int(int)> f = [n] (int x){return n * x;};
    std::cout << f(3) << std::endl;


    return EXIT_SUCCESS;
}