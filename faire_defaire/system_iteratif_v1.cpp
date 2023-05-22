#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <forward_list>
#include <cassert>



template <typename T>
class Matrice {
    private:
        const int size = M*N;
        T * mat; // tableau générique d'élément de type T
        int m, n; // ligne et colonne
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

        iterator begin() noexcept {
                return iterator(mat); // on renvoie un itérateur sur mat pour la position de départ
        }

        iterator end() noexcept {
                return iterator(mat + size);
        }

};

void setValue(int v) {
    mat.push_back(v);
}

int addValue() {

}


class command {
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
}

template<typename T>
class setValue : public command {
    private:
        Matrice<T> &mat;
        int ligne, colonne;
        T newval;
        T oldval;
    public:
        setValue(Matrice<T> &m, const T & v) : mat(m),
        ligne(std::srand()% mat.getNbLignes()), 
        colonne(std::srand()% mat.getNbCols()), newval(v) {}
        virtual void execute() override {
            this->oldval = this->mat(this->ligne, this->colonne);
            this->mat(this->ligne, this->colonne) = this->newval;
        }
        virtual void undo() override {
            this->mat(this->ligne, this->colonne) = this->oldval;
        }
};

template<typename T>
class addValue : public command {
    private:
        Matrice<T> &mat;
        T val;
        public:
            addValue(Matrice<T> &m) : mat(m) {}
            virtual void execute() override {
                for(int i = 0; i < mat.getNbLignes(); i++) 
                    for (int j = 0; j < mat.getNbCols(); j++)
                        this->mat(i, j) += this->val;
            }
            virtual void undo() override {
                for(int i = 0; i < mat.getNbLignes(); i++) 
                    for(int j = 0; j < mat.getNbCols(); j++)
                        this->mat(i, j) -= this->val;
            }
};


int main () {

    std::srand(std::time(nullptr));

    std::cout << "-------------- MATRICE 3 * 4 ---------------" << std::endl;
    // on donne le nombre de colonnes et de lignes de notre matrice
    const int M = 3;
    const int N = 4;
    // on intitialise notre matrice avec les paramètres précédent
    Matrice<int> mat(M, N);
    char code;

    command *cmd = nullptr;
    bool undoing_mode = false;

    // affichage de la matrice
    std::cout << mat << "--------------------------"<< std::endl;
    std::cout << "cmd> " << std::endl;

    while(std::cin >> code) {
        if (cmdNormale(code)) {
            switch(code) {
                case 's' : setValue(m, std::rand()%100); break;
                case 'a' : addValue(m, (std::rand()%20 +1)); break;
                case 'q': Quit();
            }
        }   
    }
    else if(code == 'u')



  

  

    

    return EXIT_SUCCESS;
}