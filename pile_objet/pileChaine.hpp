#include <iostream>
#include "noeud.hpp"


class pileChainee {
  private:
   noeud * sp;
   void detruire(noeud *n);
   noeud * dupliquer(noeud * n);
  public:
    pileChainee() : sp(nullptr) {}
    pileChainee(const pileChainee &p) {
      this->sp = dupliquer(p.sp);
    }
    ~pileChainee() {
      std::cout << "Destruction de la pile" << std::endl;
      this->detruire(this->sp);
    }
    bool estVide() const;
    void empiler(const int e);
    int sommet() const;
    void depiler();
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& f, const pileChainee &p);
    pileChainee & operator=(const pileChainee &p);
    void ecrirePile(const pileChainee &p);
};