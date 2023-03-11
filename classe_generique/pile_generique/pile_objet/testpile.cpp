#include <cstdlib>
#include <iostream>
#include "pileChaine.hpp"
#include "pileVector.hpp"
#include "rectangle.hpp"
#include "pile.hpp"


void afficher(const pile<pileVecteur<int>> &p) {
    std::cout << "Je suis " << p.quiSuisJe() << std::endl;
}


int main () {

    pileChainee<int> p;
    std::cout << p.estVide() << std::endl;
    p.empiler(6);
    p.empiler(15);
    std::cout << p.sommet() << std::endl;
    std::cout << p.estVide() << std::endl;
    std::cout << p.sommet() << std::endl;
    p.depiler();
    std::cout << p.sommet() << std::endl;
    std::cout << p << std::endl;
    pileVecteur<int> p1;
    std::cout << p1.estVide() << std::endl;
    p1.empiler(15);
    p1.empiler(7);
    std::cout << p1.sommet() << std::endl;
    std::cout << p1.estVide() << std::endl;
    p1.depiler();
    std::cout << p1.sommet() << std::endl;
    std::cout << p1 << std::endl;

    pileChainee<std::string> pp;
    pp.empiler("hello");

    rectangle r1(2.3 , 1);
    rectangle r2(12.1, 0.43);

    // Utilisation de pileVecteur avec des types différents
    pileVecteur<int> pi;
    pileVecteur<std::string> ps;
    pileVecteur<rectangle> pr;

    pi.empiler(2);
    pi.empiler(4);
    ps.empiler("bonjour");
    ps.empiler("world");
    pr.empiler(r1);
    pr.empiler(r2);

    std::cout << pi.estVide() << std::endl;
    std::cout << ps.estVide() << std::endl;
    std::cout << pr.estVide() << std::endl;
    std::cout << pi.sommet() << std::endl;
    std::cout << ps.sommet() << std::endl;
    std::cout << pr.sommet() << std::endl;

    std::cout << pi << std::endl;
    std::cout << ps << std::endl;
    std::cout << pr << std::endl;

    pi.depiler();
    ps.depiler();
    pr.depiler();

    std::cout << pi << std::endl;
    std::cout << ps << std::endl;
    std::cout << pr << std::endl;

    // Ajout de la déclaration d'une variable ppi qui est une pile d'entier
    pileVecteur<pileVecteur<int>> ppi;
    // on empile sur ppi la pile pi
    ppi.empiler(pi);
    // affichage de la pile ppi sur la sortie standard 
    std::cout << ppi << std::endl;

    // Construction et affichage d'une pileChainee de pileVecteur de int
    pileChainee<pileVecteur<int>> ppr;
    ppr.empiler(pi);
    std::cout << ppr << std::endl;

    // Construction et affichage d'une pileVecteur de pileChainee de std::string
    pileVecteur<pileChainee<std::string>> pps;
    pps.empiler(pp);
    std::cout << pps.sommet() << std::endl;
    afficher(ppi);


    return EXIT_SUCCESS;
}