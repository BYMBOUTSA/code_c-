#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>


class MonException1 : public std::exception {

    public:
        virtual const char * what() const noexcept override {
            return "MonException1";
        }
        friend std::ostream& operator<<(std::ostream& f, const MonException1 & e) {
            return f << e.what();
        }
};


class MonException2 : public MonException1 {

    public:
        virtual const char * what() const noexcept override {
            return "MonException2";
        }
};



void f() {
    throw MonException1();
}

void g() {
    throw MonException2();
}


int main() {
    try {
        g();
        f();
        g();
    }
    // On doit mettre les exception du particulier au générale donc de l'exception2 à l'exception 1 car il y a l'héritage entre eux
    catch (const MonException2 & e) {
        std::cerr << "Exception 2" << std::endl;
    }
    catch (const MonException1 & e) {
        std::cerr << "Exception 1" << std::endl;
    }
    
    return EXIT_SUCCESS;
}