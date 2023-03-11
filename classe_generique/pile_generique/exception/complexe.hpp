#pragma once

#include <string>
#include <iostream>
#include <string>
#include <cmath>


class complexe {
    private:
        double preelle;
        double pimg;
    public:
        static const complexe I;

        /*complexe (const double r, const double i) {
            this->preelle = r;
            this->pimg = i;
        }
        complexe () {} // par default*/
        complexe (const double r=0.0, const double i=0.0) : preelle(r), pimg(i) {}
        ~ complexe () {
            //std::cout << "Je suis le destructeur complexes !" << std::endl;
        }
        double getPreelle () const; // on le met en const car il ne fait pas de modification de la partie réelle de notre complexe
        void setPreelle (const double r);
        double getPimg () const;
        void setPimg (const double i);
        std::string toString () const;
        void ecrireComplexe ();
        double rho () const;
        double theta () const;
        static complexe polComplexe (const double rho, const double theta);
        complexe plus (const complexe & c) const;
        complexe moins (const complexe & c) const;
        complexe mult (const complexe & c) const;
        complexe div (const complexe & c) const;
        bool egal (const complexe & c) const;
        bool difference (const complexe & c) const;
        complexe operator + (const complexe & c) const;
        complexe operator - (const complexe & c) const;
        complexe operator * (const complexe & c) const;
        complexe operator / (const complexe & c) const;
        complexe operator == (const complexe & c) const;
        complexe operator != (const complexe & c) const;
        friend std::ostream &operator<<(std::ostream &f, const complexe &c);
        //friend std::ifstream &operator>>(std::ifstream &f, complexe &c);
};