#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cassert>


template <int M, int N, typename T>
class Matrice {
    protected:
        int size = M * N;
        T * mat;
    public:
        //constructeur
        Matrice(const T & v = T()) : mat(new T[size]) {
            for(int i = 0; i < this->size; i++)
                this->mat[i] = v;
        }
        // constructeur de copie
        Matrice(const Matrice<M, N, T> & m) {
            this->mat = new T[m.size]; // on alloue une matrice de taille M*N
            // copie les valeurs
            for(int i = 0; i < this->size; i++) 
                this->mat[i] = m.mat[i]; 
        }
        // le destructeur
        ~Matrice() {
            delete [] this->mat;
        }
        // méthodes d'accès et de modification des éléments
        T & get(const int i, const int j) const {
            int index = N * i + j;
            // on vérifie que l'index soit bien valide
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
                for(int j = 0; j < N; j++)
                    s << this->mat[N * i + j] << " ";
                s << "\n";
            }
            return s.str();
        }
        friend std::ostream & operator<<(std::ostream & f, const Matrice<M, N, T> & mat) {
            return f << mat.toString();
        }

};

int main() {
    std::cout << "------------- MATRICE 2*2 ----------------" << std::endl;
    const int M = 2;
    const int N = 2;
    Matrice<M, N, int> mat;

    mat(0, 0) = 1; mat(0, 1) = 4; mat(1, 0) = 6; mat(1, 1) = 8;
    std::cout << "--> " << mat(1, 0) << std::endl;
    std::cout << mat << std::endl;

    std::cout << "------------- MATRICE 3*3 ---------------" << std::endl;
    const int i = 3;
    const int j = 3;
    Matrice<i, j, char> mat1('a');

    mat1(1, 2) = 'b'; mat1(2, 0) = 'e'; mat1(2, 1) = 'r'; mat1(2, 2) = 't';
    std::cout << "--> " << mat1(2, 1) << std::endl;
    std::cout << mat1 << std::endl;

    std::cout << "-----------------------------" << std::endl;
    Matrice<i, j, double> mat2;
    mat2(1, 2) = 2.5; mat2(2, 0) = 1.6; mat2(2, 1) = 2.9; mat2(2, 2) = 5.2;
    std::cout << "--> " << mat2(2, 1) << std::endl;
    std::cout << mat2 << std::endl;


    return EXIT_SUCCESS;
}