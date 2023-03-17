#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <forward_list>
#include <cassert>



template <int M, int N, typename T>
class Matrice {
    private:
        const int size = M*N;
        T * mat; // tableau générique d'élément de type T
    public:
        // le constructeur
        // T c'est une classe donc on appelle le constructeur de la classe T
        Matrice(const T & v=T()) : mat(new T[size]) {
            // on affecte la valeur de v
            for (int i = 0; i < this->size; i++) {
                this->mat[i] = v;
            }
        }
        // constructeur de copie il est appelé à l'initialisation 
        Matrice(const Matrice<M, N, T> &m) {
            // On alloue à la matrice mat un tableau de M*N
            this->mat = new T[m.size];
            // copie les valeurs
            for (int i = 0; i < this->size(); i++) 
                this->mat[i] = m.mat[i];
        }

        // le destructeur
        ~Matrice() {
            delete [] this->mat;
        }

        // on veut transformer m(i, j) en N*i+j
        // renvoie une référence vers mat(i, j)
        T & get(int i, int j) const {
            int index = N * i + j;
            // on verifie que l'index est bien dans les bornes de la matrice
            assert(index >= 0 && index < this->size);
            return mat[index];
        }
        // redéfinition de () pour renvoyer une référence sur l'élément mat(i, j)
        T & operator() (int i, int j) const{
            return this->get(i, j);
        }

        std::string toString() const {
            std::ostringstream s;
            // on parcourt les lignes et colonnes de notre élément mat
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) 
                    s << mat[N * i + j] << " ";
                s << "\n";  
            }
            return s.str();
        }

        friend std::ostream & operator<<(std::ostream & f, const Matrice<M, N, T> & mat) {
            return f << mat.toString();
        }

        class iterator {
            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = T;
                using difference_type = std::ptrdiff_t; // peut faire la différence de deux itérateurs
                using pointer = T*;
                using reference = T&;
                // constructeur de l'iterateur begin et end()
                iterator(pointer p) : position(p) {}
                
                // incrémentation préfixe, ++p
                iterator & operator++() {
                    position++;
                    return *this;
                }

                // incrémentation postfixe, p++, le int c'est pour différencier
                iterator operator++(int) {
                    iterator i = *this; // on mémorise la valeur
                    position++; // on modifie la position
                    return i; // on renvoie l'itérateur
                }

                bool operator==(const iterator & it) {
                    return position == it.position;
                }

                bool operator!=(const iterator & it) {
                    return position != it.position;
                }
                // on renvoie une reférence sur l'élément
                reference operator* () const{
                    return *(position);
                }
                // on renvoie l'adresse de l'élément
                pointer operator->() const {
                    return position;
                }

            private:
                // la position courante
                pointer position;
                

        };
        // Dans la classe Matrice, vous définirez ensuite les méthodes begin et end
        iterator begin() noexcept {
            return iterator(mat); // on renvoie un itérateur sur mat pour la position de départ
        }

        iterator end() noexcept {
            return iterator(mat + size);
        }

};


int main () {

    std::cout << "-------------- MATRICE 2 * 2 ---------------" << std::endl;
    // on donne le nombre de colonnes et de lignes de notre matrice
    const int M = 2;
    const int N = 2;
    // on intitialise notre matrice avec les paramètres précédent
    Matrice<M, N, int> mat;

    // on modifie les valeurs sur certaines lignes et colonnes
    mat(0, 0) = 1; mat(0, 1) = 2;
    mat(1, 0) = 3; mat(1, 1) = 4;


    // affichage de la matrice
    std::cout << "---> " << mat(1, 1) << std::endl;
    std::cout << mat << std::endl;
    std::cout << "--------------------------" << std::endl;

    Matrice<M, N, int>::iterator it1 = mat.begin();
    Matrice<M, N, int>::iterator it2(it1);

    it1++;
    std::cout << "*it1 = " << *it1 << " " << std::endl;
    std::cout << "*it2 = " << *it2 << " " << std::endl;
    std::cout << "*it2 = " << *it2++ << " " << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "*it2 = " << *it2 << " " << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (Matrice<M, N, int>::iterator it = mat.begin(); it != mat.end(); it++) 
        std::cout << *it << " " << std::endl;

    
    /*  Résultat de la simulation
        -------------- MATRICE 2 * 2 ---------------
            ---> 4
            1 2 
            3 4 

        --------------------------
            *it1 = 2 
            *it2 = 1 
            *it2 = 1 
        ---------------------------
            *it2 = 2 
        ---------------------------
            1 
            2 
            3 
            4 
    */
    

    return EXIT_SUCCESS;
}