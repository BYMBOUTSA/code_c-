#pragma once

#include <iostream>
#include <cassert>
#include <sstream>

template <int M, int N, typename T>
class Matrice {

private:
  const int size = M*N;
  T *mat; // tableau générique d'éléments de type T
public:  
  // le constructeur
  Matrice(const T& v=T()) : mat(new T[size]) {
    // affecter la valeur v
    for(int i=0 ; i<this->size ; i++)
      this->mat[i]=v;
  }

  // le constructeur de copie
  Matrice(const Matrice<M,N,T> &m) {
    this->mat = new T[m.size];
    // copie les valeurs
    for(int i=0 ; i<this->size ; i++)
      this->mat[i]=m.mat[i];
  }
  
  // le destructeur
  ~Matrice() {
    delete [] this->mat;
  }

  // Rôle : renvoie une référence sur l'élément mat[i][j]
  T &get(const int i, const int j) const {
    assert(i>=0 and i<M and j>=0 and j<N); 
    int index = N*i+j;
    return this->mat[index];
  }
  
  // Rôle : redéfinition de () pour renvoyer une référence sur
  // l'élément mat[i][j]
  T &operator() (const int i, const int j) const {
    return this->get(i,j);
  }

  // Rôle : renvoie la représentation de l'objet courant sous forme d'une std::string
  std::string toString() const {
    std::ostringstream s;
    for (int i=0; i<M; i++) {
      for (int j=0; j<N; j++)
	s << this->mat[N*i+j] << " ";
      //s << (*this)(i,j) << " ";
      //
      s << "\n";
    }
    return s.str();
  }

  friend std::ostream& operator<<(std::ostream &f, const Matrice &m) {
    return f << m.toString();
  }
};
  

  
