#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


class MonException {

    public:
        std::string toString() const {
            return "MonException";
        }
        friend std::ostream& operator<<(std::ostream & f, const MonException & e) {
            return f << e.toString();
        }
};

void p() {
    switch (std::rand() % 4) {
        case 0: throw 1;
        case 1: throw MonException();
        case 2: throw "toto";
        case 3: ;
    }
    std::cout << "Dans p : après le switch" << std::endl;
}


int main () {
    std::srand(std::time(nullptr));

    try {
        p();
    }
    catch (int e) {
        std::cerr << e << std::endl;
    }
    catch (MonException &e) {
        std::cerr << e << std::endl;
    }
    catch(...) {
        std::cerr << "universelle" << std::endl;
    }
    std::cout << "Dans main : après l'appel de p" << std::endl;

    return EXIT_SUCCESS;
}

