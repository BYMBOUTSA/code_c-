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
    std::cout << "--->" << mat(1, 1) << std::endl;
    std::cout << mat << std::endl;


    std::cout << "--------------- MATRICE 3 * 3 --------------" << std::endl;
    const int i = 3;
    const int j = 3;

    Matrice<i, j, char> mat1('a');

    //mat1(0, 0, 0) = 2; mat1(0, 0, 1) = 3; mat1(0, 1, 0) = 4; // o,n ne peut pas car on a juste le parcours en i et j

    mat1(1, 2) = 'b'; mat1(2, 2) = 'z'; mat1(2, 1) = 'c';

    std::cout << mat1 << std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    Matrice<i, j, int>mat2;

    mat2(0, 0) = 1; mat2(0, 1) = 2; mat2(1, 2) = 4; mat2(2, 1) = 6;
    std::cout << mat2 << std::endl;


    return EXIT_SUCCESS;
}