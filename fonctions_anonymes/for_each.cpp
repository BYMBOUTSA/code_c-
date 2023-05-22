#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdlib>

/*void printVecteur(auto v) {
    for_each(v.begin(), v.end(), [](const int x) {std::cout << x << " ";});
    std::cout << std::endl;
}*/

// Procédure permettant de transformer le vecteur d'entier en le multipliant chacun des entiers par 2
/*void printVecteur(auto & v) {
    for_each(v.begin(), v.end(), [](const int x) {std::cout << x * 2 <<  " ";});
    std::cout << std::endl;
}*/

// autre manière de faire la multiplication de chacun des éléments du vecteur * 2 en faisant un décallage à gauche
void printVecteur(auto & v) {
    for_each(v.begin(), v.end(), [](const int x) {std::cout << (x << 1) << " ";});
    std::cout << std::endl;
}

// multiplication par 2 et renvoie la somme des valeurs du vecteur (donne chacune des valaurs des sommes)
/*void printSomme(auto & v) {
    int a = 0;
    for_each(v.begin(), v.end(), [&a](const int i){std::cout << (a += (i * 2)) << " ";});
    std::cout << std::endl;
}*/


// En passant par une classe
class Somme {
    private:
        int sum = 0;
    public:
        Somme(){}
        Somme(const int s) : sum(s) {}
        int getSum() const {
            return this->sum;
        }
        void operator()(int & i) {sum += (i << 1);}
};


int main() {
    std::vector<int> v = {2, 3, 4, 5, 6};
    
    printVecteur(v);
    //printSomme(v);

    // création de l'objet somme
    Somme s;

    //s = for_each(v.begin(), v.end(), s);

    //std::cout << s.getSum() << std::endl;

    // autre manière de calculer la somme des valeurs multiplier par 2 avec capture
    int a=0;
    int n=0;
    for_each(v.begin(),v.end(),[&a,&n,v](const int i){a+=i*2,n++;if(n==v.size()){std::cout<<a<<std::endl;}});

    return EXIT_SUCCESS;
    
}