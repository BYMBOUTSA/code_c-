#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class MonException {

    public:
        std::string toString() const {
            return "MonException";
        }
        friend std::ostream& operator<<(std::ostream& f, const MonException &e) {
            return f << e.toString();
        }
};

void f() {
    throw 1;
    //throw MonException();
}

void g() {
    try {
        f();
        std::cout << "g : après f()" << std::endl;
    }
    catch (const MonException &e) {
        std::cerr << "Exception : MonException attrapée dans g" << std::endl;
        throw;
    }
    std::cout << "g : après catch" << std::endl;

    
}

// Peut être utiliser pour permettre de finir le programme proprement
// Donc informer qu'on doit fermer toute les ressources par exemple
void finir() {
    std::cerr << "C'est fini, adieu!" << std::endl;
}



int main () {
    std::set_terminate(finir); // transmission du nom de la fonction, car c'est une fonction paramétrique
    try {
        g();
        std::cout << "Main : après g()" << std::endl;
    }
    catch (const  MonException &e) {
        std::cerr << "Exception : MonException attrapée dans main" << std::endl;
    }
    std::cout << "Main : après catch" << std::endl;

    return EXIT_SUCCESS;
}