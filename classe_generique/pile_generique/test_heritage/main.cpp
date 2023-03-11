#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "rectangle.hpp"
#include "carre.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"
#include "pileChaine.hpp"
#include "pileVector.hpp"
#include "pile.hpp"


void afficher(const figure * f) {
    std::cout << "Je suis " << f->quiSuisJe() << std::endl;
}

int main () {

    rectangle r1 (2.6, 4.42), r2;
    std::cout << r1.perimetre() << std::endl;
    r1.setLargeur (3.9);

    carre c1 (3.8), c2;
    std::cout << c1.perimetre() << std::endl;
    //c2.setLongueur(2.9); // ce n'est pas normal que çà s'applique
    // mais c'est correct, pour éviter çà il faut supprimer les méthodes
    // getLargeur et getLongueur ainsi que setLargeur et setLongueur
    std::cout << c1 << std::endl;
    std::cout << r1.quiSuisJe() << std::endl;
    std::cout << c1.quiSuisJe() << std::endl;
    // Qu'on a le même type rectangle pour l'objet de type rectangle et celui du carre donc la classe carre à hériter de la 
    // méthode quiSuisJe() de sa super classe rectangle

    /*figure f;
    std::cout << f.quiSuisJe() << std::endl;*/


    rectangle r3 = carre(8);
    //rectangle r4 = cercle(8); // on ne peut pas faire çà car le cercle n'est pas un rectangle particulier
    //carre r4 = rectangle(2.8); // un carre n'est pas un rectangle particulier
    carre r4 = r3; // erreur de conversion de rectangle en carre fais la conversion explicite de rectangle en carre

    rectangle *r = new carre(8);
    afficher(r);
    ellipse *c = new cercle(8);
    afficher(c);
    // Non le résultat obtenu n'est pas satisfaisant, en toute bonne logique on devait obtenir "Je suis un carre" et "Je suis un cercle" ce qu'on alloue de manière dynamique

    std::vector<figure *> vf = {new rectangle(3, 8), new carre(7), new ellipse(2, 3), new cercle(6)};

    for (figure * f: vf) {
        afficher(f);
        std::cout << "de surface " << f->surface() << std::endl;
    }
    // le problème est qu'il n' y a pas de méthode surface dans la classe figure

    pileChainee <int> p;
    p.empiler(15);
    std::cout << p.sommet() << std::endl;
    std::cout << p.estVide() << std::endl;

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
    /*pileVecteur<pileChainee<std::string>> pps;
    pps.empiler(pp);
    std::cout << pps.sommet() << std::endl;
    afficher(ppi);*/


    return EXIT_SUCCESS;
}