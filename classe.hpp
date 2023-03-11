#pragma once

#include <iostream>
#include <string>


class complexe {
    private:
        double preelle, pimg;
    public:
        static const complexe I;

        complexe(const double r = 0.0, const double i=0.0) : preelle(r), pimg(i) {
            //this->preelle = r;
            //this->pimg = i;
        }

        ~complexe() {
            std::cout << "Je détruis un complexe" << std::endl;
        }
        double getPreelle() const;
        void setPreelle(const double r);
        double getPimg() const;
        void setPimg(const double i);
        std::string toString() const;
        void ecrireComplexe();
        double rho() const;
        double theta() const;
        static complexe polComplexe(const double rho, const double theta);
        complexe plus(const complexe & c) const;
        friend std::ostream & operator<< (std::ostream& f, const complexe &c);
        friend std::istream& operator>>(std::istream& f, complexe &c);
};