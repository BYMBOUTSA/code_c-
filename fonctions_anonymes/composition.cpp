#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <functional>

// version avec double
 /*std::function<double(double)> 
    compose(std::function<double(double)> f, std::function<double(double)> g) {
        return [f, g] (double x) {return g(f(x));};
    }*/


// version avec auto
template<typename F, typename G>
auto compose(F f, G g) {
    return [f, g](auto x) {return g(f(x));};
}

// Ecriture d'une fonction qui permet de composer n fois une même fonction
/*template<typename F>
auto composeN(F f, int n) {
    if (n == 0)
        return [f](auto x) { return x; };
    else
        return [f, n](auto x) { return compose(f, composeN(f, n - 1))(x); };
}*/


int main () {

    // teste version avec double
    /*auto gof = compose([] (double x) { return x + 1;}, [](double x) { return cos(x);});

    std::cout << gof(3) << std::endl;
    std::cout << compose([] (double x) {return x * x;}, [](double x){return x + 2;})(4);
    std::cout << std::endl; */

    // teste version avec auto
    auto gof = compose([](int * t) {return *t;}, [](double x){return x * x;});
    int t [] = {3, 4, 5};
    std::cout << gof(t) << std::endl;

    auto square = [](int x) {return x * x;};
    auto cube = [](int x) {return x * x * x;};

    auto square4Times = composeN(square, 4); 
    std::cout << square4Times(2) << std::endl; // 256

    auto cube3Times = composeN(cube, 3);
    std::cout << cube3Times(2) << std::endl; // 64

    return EXIT_SUCCESS;
}


