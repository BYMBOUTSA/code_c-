#include <iostream>
#include <cstdlib>
#include <cassert>


// version avec un pointeur
/*
* Antécédent a <= b et n > 1
* Rôle : calcule l'aire de la fonction continue f sur l'intervalle [a, b]
* Algorithme méthode des rectangles, n est le nb de rectangles calculés
*/
/*double aire(double a, double b, int n, double (*f)(double)) {
    assert(a <= b);
    double largeurRect = (b - a) / n;
    double x = a + largeurRect / 2;
    double aire = 0;

    for (int i = 1; i <= n; i++)
        // aire = somme()
        aire += largeurRect * f(x);
    return aire;
} */



// version avec le template
template <typename T>
double aire(double a, double b, int n, T f) {
    assert(a <= b);
    double largeurRect = (b - a) / n;
    double x = a + largeurRect / 2;
    double aire = 0;

    for (int i = 1; i <= n; i++)
        // aire = somme()
        aire += largeurRect * f(x);
    return aire;

}

// version avec std::function
/*double aire(double a, double b, int n, std::function<double(double)> f) {
    assert(a <= b);
    double largeurRect = (b - a) / n;
    double x = a + largeurRect / 2;
    double aire = 0;

    for (int i = 1; i <= n; i++)
        // aire = somme()
        aire += largeurRect * f(x);
    return aire;

}*/

// version avec auto
/*double aire(double a, double b, int n, auto f) {
    assert(a <= b);
    double largeurRect = (b - a) / n;
    double x = a + largeurRect / 2;
    double aire = 0;

    for (int i = 1; i <= n; i++)
        // aire = somme()
        aire += largeurRect * f(x);
    return aire;

}*/


int main() {

    // Pour calculer l'aire de cos(x) + x sur l'intervalle [0, pi/2] ou celle de x sur [2, 3]
    double f1(double x) {return cos(x) + x;}
    double f2(double x) {return x;}

    printf("aire = %f \n", aire(0, M_PI/2, 1000, f1));
    printf("aire = %f\n", aire(2, 3, 1000, f2)); 

    return EXIT_SUCCESS;
}
