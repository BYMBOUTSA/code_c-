#include <iostream>
#include <cstdlib>
#include <forward_list>
#include <sstream>
#include <cassert>

template <int M, int N, typename T>
class Matrice {
    protected:
        int size = M * N;
        T * mat;
    public:
        // constructeur
        Matrice(const T & v = T()) : mat(new T[size]) {
            for(int i = 0; i < this->size; i++)
                this->mat[i] = v;
        }
        // constructeur de copie
        Matrice(const Matrice<M, N, T> & m) {
            // On alloue à la matrice mat un tableau de M*N
            this->mat = new T[m.size];
            // on copie des valeurs
            for(int i = 0; i < this->size; i++) 
                this->mat[i] = m.mat[i]; 
        }
        // destructeur
        ~Matrice() {
            delete [] this->mat;
        }
        // Méthode d'accès et de modification des éléments
        T & get(const int i, const int j) const {
            int index = N * i + j;
            // vérification de l'index 
            assert(index >= 0 && index < this->size);
            return this->mat[index];
        }
        // surcharge de l'opérateur ()
        T & operator()(const int i, const int j) const {
            return this->get(i, j);
        }
        std::string toString() const {
            std::ostringstream s;
            for(int i = 0; i < M; i++) {
                for(int j=0; j < N; j++)
                    s << this->mat[N * i + j] << " ";
                s << "\n";
            }
            return s.str();
        }
        friend std::ostream & operator<<(std::ostream & f, const Matrice<M, N, T> & mat) {
            return f << mat.toString();
        }

        class const_iterator {
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T &;

                // constructeur
                const_iterator(pointer p) : position(p) {}
                // operateurs
                const_iterator & operator++() { // incrémentation prefixe
                    this->position++;
                    return *this;
                }
                const_iterator operator++(int) { // incrémentation postfixe
                    const_iterator i = *this; // on mémorise la position de l'itérateur
                    this->position++; // on modifie la position de l'itérateur
                    return i; // on renvoie la position actuelle de l'itérateur
                }
                bool operator==(const const_iterator & it) const {
                    return this->position == it.position;
                }
                bool operator!=(const const_iterator & it) const {
                    return this->position != it.position;
                }
                reference operator*() const {
                    return *(this->position);
                }
                pointer operator->() const {
                    return this->position;
                }
            private:
                pointer position;
        };

        // méthodes begin() et end()
        const_iterator cbegin() noexcept {
            return const_iterator(this->mat);
        }
        const_iterator cend() noexcept {
            return const_iterator(this->mat + size);
        }

};


int main () {

    const int M = 2;
    const int  N = 2;
    Matrice<M, N, int> m;

    m(0, 0) = 1; m(0, 1) = 2; m(1, 0) = 3; m(1, 1) = 4;
    std::cout << "--> " << m(1, 1) << std::endl;
    std::cout << "------------------------------" << std::endl;

    Matrice<M, N, int>::const_iterator it1 = m.cbegin();
    Matrice<M, N, int>::const_iterator it2(it1);

    it1++;

    std::cout << "*it1 = " << *it1 << " " << std::endl;
    std::cout << "*it2 = " << *it2 << " " << std::endl;
    std::cout << "it2 = " << *it2++ << " " << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "*it2 = " << *it2 << " " << std::endl;
    std::cout << "---------------------------" << std::endl;

    for(Matrice<M, N, int>::const_iterator it = m.cbegin(); it != m.cend(); it++)
        std::cout << *it << std::endl; 

    // oui, on peut l'utiliser
    /*for(auto x : m)
        std::cout << x << std::endl; */

    return EXIT_SUCCESS;
}