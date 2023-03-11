#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "complexe.hpp"


const complexe complexe::I(0, 1);

/*
* Rôle : renvoie la partie réelle du complexe courant
*/
double complexe::getPreelle () const{
    return this-> preelle;
}

/*
* Rôle : affecter r à la partie réelle du complexe courant
*/
void complexe::setPreelle (const double r) {
    this->preelle = r;
}

/*
* Rôle : renvoie la partie imaginaire du complexe courant
*/
double complexe::getPimg () const {
    return this-> pimg ;
}

/*
* Rôle : affecter i à la partie imaginaire
*/
void complexe::setPimg (const double i) {
    this->pimg = i;
}

/*
* Rôle : convertir l'objet courant sous la forme d'une chaîne de caractères au format (r, i)
*/
std::string complexe::toString () const {
    return "(" + std::to_string(this->preelle) + ", " + std::to_string(this->pimg) + ")";
}

/*
* Rôle : écrire sur la sortie standard le complexe courant
*/
void complexe::ecrireComplexe () {
    std::cout << this->toString() << std::endl;
}

/*
* Rôle : renvoie la norme de l'objet courant à la classe complexe
*/
double complexe::rho () const {
    return sqrt(this->preelle * this->preelle + this->pimg * this->pimg);
}

/*
* Rôle : renvoie l'argument d'un complexe
*/
double complexe::theta () const {
    return atan2(this->pimg , this->preelle); // on utilise atan(y/x) et avec atan2 c'est atan2(y, x)
}

/*
* Rôle : renvoie un objet de type complexe en coordonnées cartésiennes
*/
complexe complexe::polComplexe (const double rho, const double theta) {
    return complexe(rho * cos(theta), rho * sin(theta));
}

/*
* Rôle : effectue la somme de deux complexes
*/
complexe complexe::plus (const complexe & c) const {
    return complexe((this->preelle + c.preelle), (this->pimg + c.pimg)); // comme c est un complexe et qui est passé par reférence
    // donc on peut le modifier et ainsi on peut exploiter sa partie réelle et sa partie imaginaire
}


/*
* Rôle : effectue la soustraction de deux complexes
*/
complexe complexe::moins (const complexe & c) const {
    return complexe((this->preelle + c.preelle), (this->pimg + c.pimg));
}


/*
* Rôle : effectue le produit de deux complexes
*/
complexe complexe::mult (const complexe & c) const {
    return polComplexe((this->preelle * c.preelle), (this->pimg + c.pimg));
}


/*
* Rôle : effectue la division de deux complexes
*/
complexe complexe::div (const complexe & c) const {
    return polComplexe((this->preelle / c.preelle), (this->pimg - c.pimg));
}

/*
* Rôle : teste l'égalité entre l'objet courant et le complexe transmis en paramètre
*/
bool complexe::egal (const complexe & c) const {
    bool received;
    if (this->preelle == c.preelle && this->pimg == c.pimg) {
        received = true;
    } else {
        received = false;
    }
    return received;
}


/*
* Rôle : teste la différence entre l'objet courant et le complexe transmis en paramètre
*/
bool complexe::difference (const complexe & c) const {
    bool received;
    if (this->preelle != c.preelle || this->pimg != c.pimg) {
        received = true;
    }
    else {
        received = false;
    }
    return received;
}


/*
* Rôle : surcharge l'opérateur +
*/
complexe complexe::operator + (const complexe & c) const {
    return this->plus(c);
}

/*
* Rôle : surcharge l'opérateur -
*/
complexe complexe::operator - (const complexe & c) const {
    return this->moins(c);
}

/*
* Rôle : surcharge l'opérateur *
*/
complexe complexe::operator * (const complexe & c) const{
    return this->mult(c);
}

/*
* Rôle : surcharge l'opérateur /
*/
complexe complexe::operator / (const complexe & c) const {
    return this->div(c);
}

/*
* Rôle : surcharge l'opérateur ==
*/
complexe complexe::operator == (const complexe & c) const {
    return this->egal(c);
}

/*
* Rôle : surcharge l'opérateur !=
*/
complexe complexe::operator != (const complexe & c) const {
    return this->difference(c);
}

/*
* Rôle : surcharge de l'opérateur <<
*/
/*std::ofstream& operator<<(std::ofstream &f, const complexe &c) {
    f.write((char *) &c, sizeof(complexe));
    return f;
}*/


/*
* Rôle : surcharge de l'opérateur >>
*/

/*std::ifstream& operator>>(std::ifstream &f, complexe &c) {
    f.read((char *) &c, sizeof(complexe));
    return f;
}*/