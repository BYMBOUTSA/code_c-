#include <iostream>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <forward_list>
#include <list>
#include <stack>

template <typename T>

class pile : private std::forward_list<T> {
        protected:
            // pour utiliser super à la place de std::forward_list
            typedef std::forward_list<T> super;
        public:
            pile() {}
            // constructeur pour initialiser une pile avec une liste passé en paramètre
            pile(const std::list<T> l) {
                for (T x : l) 
                    this->empiler(x);
            }
            // on empile l'élément x au début de la liste
            void empiler(const T & x) {
                super::push_front(x);
            }
            // on retire l'élément qui se trouve au début de la liste
            void depiler() {
                // pour vérifier que la liste n'est pas vide
                assert(!this->empty());
                super::pop_front();
            }
            // on affiche l'élément au sommet de la pile ici le premier élément de la liste
            T sommet() const {
                return super::front();
            }
            // on teste pour avoir l'état de la pile
            bool estVide() const {
                return super::empty();
            }

            std::string toString() const {
                std::ostringstream s;
                s << "[";
                for (typename std::forward_list<T>::const_iterator it_l = super::cbegin(); it_l != super::cend(); it_l++) 
                //  la même chose avec le (for each) for (T x : *this) s << x << " ";
                    s << *it_l << " ";
                s << "]";
                return s.str();
            }
            friend std::ostream & operator<<(std::ostream & f, const pile<T> & p) {
                return f << p.toString();
            }

};


int main () {

    std::cout << "--------------- PILE -----------------" << std::endl;

    // on crée une pile de double
    pile<double> p;
    p.empiler(2.5);
    p.empiler(3.8);
    p.empiler(5.2);

    // on affiche le sommet de la pile
    std::cout << p.sommet() << std::endl;
    // on affiche chacun des éléments présent dans la pile p
    std::cout << p << std::endl;

    // on crée une pile de liste d'entier
    pile<int> p1({2, 6, 8});
    // on empile la valeur 10 en sommet de la pile
    p1.empiler(10);
    // affichage du sommet de la pile et de tous les éléments de la pile de liste
    std::cout << p1.sommet() << std::endl;
    std::cout << p1 << std::endl;


    std::cout << "--------------- STACK ----------------" << std::endl;

    std::stack<double> ps;
    ps.push(2.5);
    ps.push(3.8);
    ps.push(5.2);

    // on affiche le sommet de la pile (stack) et tous ses éléments
    std::cout << ps.top() << std::endl;
    
    while(!ps.empty()) {
        std::cout << ps.top() << " "; // on affiche le sommet de la pile
        ps.pop(); // suppression du sommet de la pile
    }

    std::stack<int> ps1({2, 6, 8});
    // on empile 10 en sommet de la pile de liste
    ps1.push(10);
    // affichage du sommet de la pile et de tous les éléments de la pile de liste
    std::cout << ps1.top() << std::endl;
    
    // tant que la pile de liste n'est pas vide
    while(!ps1.empty()) {
        std::cout << ps1.top() << " "; // on affiche le sommet de la pile
        ps1.pop(); // on retire le sommet de la pile
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}