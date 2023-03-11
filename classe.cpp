#include <cmath>
#include <iostream>

#include "classe.hpp"

const complexe complexe::I(0, 1);

double complexe::getPreelle() const {
    return this->preelle;
}

void complexe::setPreelle(const double r) {
    this->preelle = r;
}

double complexe::getPimg() const {
    return this->pimg;
}

void complexe::setPimg(const double i) {
    this->pimg = i;
}

std::string complexe::toString() const {
    return "(" + std::to_string(this->preelle) + "," + std::to_string(this->pimg) + ")";
}

void complexe::ecrireComplexe() {
    std::cout << this->toString() << std::endl;
}

double complexe::rho() const {
    return sqrt(this->preelle*this->preelle + this->pimg * this->pimg);
}

double complexe::theta() const {
    return atan2(this->pimg , this->preelle);
}

complexe complexe::polComplexe(const double rho, const double theta) {
    return complexe(rho*cos(theta), rho*sin(theta));
}

complexe complexe::plus(const complexe & c) const {
    return complexe(this->preelle + c.preelle, this->pimg + c.pimg);
}

std::ostream& operator<<(std::ostream& f, const complexe &c) {
    return f << c.toString();
}

std::istream& operator>>(std::istream& f, complexe &c) {
    double a, b;
    //char e;
    f >> a >> b;
    complexe d(a, b);
    c = d;
    return f;
}