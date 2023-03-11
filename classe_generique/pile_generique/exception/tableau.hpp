#pragma once
#include <iostream>
#include <initializer_list>
#include <sstream>
#include <string>
#include "IndexException.hpp"
#include "complexe.hpp"

template <int N, typename T>

class tableau {
    private:
        T elem[N];
    public:
        // initialisation des éléments avec une liste
        // valeur de type initialiser_list sont tranmises directement au constructeur
        tableau(const std::initializer_list<T> & l) {
            int i = 0;
            for (T x : l) 
                (*this)[i++] = x;
            //si incomplet, initialisation de tous les autre éléments à T()
            for ( ; i < N; i++)
                  this->elem[i] = T(); 
        }
        // initialiser tous les éléments du tableau à une valeur x avec T() qui est le constructeur par défaut dû tableau
        tableau (const T & x = T()) {
            for (int  i = 0; i < N; i++)
               this->elem[i] = x;
        }
        // constructeur de copie
        tableau (const tableau<N, T> & t) {
            for (int i = 0; i < N ; i++) 
                this->elem[i] = t.elem[i];
        }

        T &operator[] (const int i) {
            if (i < 0) throw IndexUnderFlow(i);
            if (i >= N) throw IndexOverFlow(i);
            // i est un indice valide [1, N-1]
            return this->elem[i];
        }

        int longueur () const {
            return N;
        }

        std::string toString() const {
            std::ostringstream s;
            s << "[";
            for (auto x : this->elem)
                 s << x << " ";
            s << "]";
            return s.str();
        }

        friend std::ostream& operator<<(std::ostream& f, const tableau<N, T> & t) {
            return f << t.toString();
        }
};