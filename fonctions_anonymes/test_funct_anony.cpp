#include <iostream>
#include <cstdlib>
#include <functional>
#include <cassert>
#include <cmath>


int main () {

    //[] (double x, double y) {return x + y};

    // 1ère méthode en spécifiant le type
    /*std::function<double(double, double)> f1 = [](double x, double y) -> double {return x + y;};
    std::function<double(double)> f2 = [] (double x) {
        assert(x >= 0);
        return sqrt(x);
    };
    std::function<void()> f3 = []  () {
        std::cout << "n= ";
        int n;
        std::cin >> n;
        std::cout << n * n << std::endl;
    };*/

    // 2nde méthode avec auto
    auto f1 = [] (double x, double y) -> double {return x + y;};
    auto f2 = [] (double x) {assert(x >= 0); return sqrt(x);};
    auto f3 = [] () {
        std::cout << "n = ";
        int n;
        std::cin >> n;
        std::cout << n * n << std::endl;
    };

    std::cout << f1(3.4, -9.76) << std::endl;
    std::cout << f2(9.0) << std::endl;
    f3();

    return EXIT_SUCCESS;
}