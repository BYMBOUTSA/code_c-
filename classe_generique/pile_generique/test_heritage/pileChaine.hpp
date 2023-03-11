#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include "pile.hpp"



template <typename T> 


class noeud {
  private:
    T elt;
    noeud<T> *suivant;
  public:
    noeud(const T e, noeud<T> *s) : elt(e), suivant(s) {}
    ~noeud() {
      std::cout << "Destruction du noeud" << std::endl;
    }
    
    T getElement() const {
      return this->elt;
    }

    void setElement(const T x) {
      this->elt = x;
    }

    noeud<T>* getSuivant() const {
      return this->suivant;
    }

    void setSuivant(noeud<T> *e) {
      this->suivant = e;
    }

};

template <typename T> 

class pileChainee : public pile<T> {
    private:
        noeud<T> *sp;
        void detruire(noeud<T> * p) {
          while(p != nullptr) {
              noeud<T> *q = p->getSuivant();
              delete p;
              p = q;
          }
        }

        std::string toString() const  {
          std::string s = "[";
          noeud<T> *n = this->sp;
          while(n != nullptr) {
              s += std::to_string(n->getElement()) + " ";
              n = n->getSuivant();
          }
          return s + "]";
        }

        noeud<T>* dupliquer(noeud<T> * n) {
          if (n == nullptr) 
              return nullptr;
          noeud<T> *p = dupliquer(n->getSuivant());
          return new noeud<T>(n->getElement(), p);
        }
    public:
      pileChainee() : sp(nullptr) {}
      pileChainee(const pileChainee &p) {
        this->sp = dupliquer(p.sp);
      }
      ~pileChainee() {
        std::cout << "Destruction de la pile" << std::endl;
        this->detruire(this->sp);
      }

      bool estVide() const override {
        return this->sp == nullptr;
      }

      /*
      * Rôle : empiler l'entier x en sommet de la pile courante
      */
      void empiler(const T & x) override {
          noeud<T> *p = new noeud<T>(x, this->sp);
          this->sp = p;
      }

      /*
      * Rôle : renvoie l'entier en sommet de la pile
      */
      const T sommet() const override {
          assert(!this->estVide());
          return (this->sp)->getElement();
      }

      /*
      * Rôle : dépiler l'entier en sommet de la pile
      */
      void depiler()  {
          assert(!this->estVide());
          noeud<T> *p = this->sp;
          this->sp = (this->sp)->getSuivant();
          // on détruit le noeud
          delete p;
      }


      friend std::ostream& operator<<(std::ostream& f, const pileChainee & p) {
          return f << p.toString();
      }

      std::string quiSuisJe() const override {
          return "une pile chainée";
      }

};



