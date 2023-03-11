#pragma once
#include <iostream>


class noeud {
  private:
    int elt;
    noeud * suivant;
  public:
    noeud(const int e, noeud *p) : elt(e), suivant(p) {}
    ~noeud() {
      std::cout << "Destruction du noeud" << std::endl;
    }
    int getElement() const;
    void setElement(const int e);
    noeud * getSuivant() const;
    void setSuivant(noeud * n);
};