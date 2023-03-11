#include <iostream>
#include <cstdlib>
#include "rectangle.hpp"
#include "carre.hpp"
#include "ellipse.hpp"
#include "cercle.hpp"
#include "figure.hpp"
#include  <vector>


void afficher(const figure *f) {
    std::cout << "Je suis " << f->quiSuisJe() << std::endl;
}


int main () {

    rectangle r1 (2.6, 4.42), r2;

    std::cout << r1.perimetre() << std::endl;
    r1.setLargeur(3.9);

    carre c1 (3.8), c2;

    std::cout << c1.perimetre() << std::endl;

    //c2.setLargeur(2.9);
    std::cout << c2.getLargeur() << std::endl;
    // oui le constructeur de la classe carre est d'abord appliqué ensuite c'est le cas de celui 
    // de la classe rectangle
    //c2.setLongueur(3.5);
    std::cout << c2.getLongeur() << std::endl;
    // ou la méthode setLongueur() s'applique bien sur un objet de type carre, oui c'est normal
    // car le carré est un rectangle particulier ayant la longueur égal à la largeur, mais ce n'est pas correct

    std::cout << r1.quiSuisJe() << std::endl;
    //std::cout << c1.quiSuisJe() << std::endl;
    // Qu'il affiche toujours que c'est un rectangle dans les deux cas

    // Déclaration d'une variable f de type figure
    /*figure f;
    std::cout << f.quiSuisJe() << std::endl;*/

    // polymorphisme
    rectangle r3 = carre(8); // possible car le carré est un rectangle particulier
    //rectangle r4 = cercle(8); // error: car le cercle n'est pas rectangle particulier
    //carre c3 = rectangle(2, 8); // error : car le rectangle n'est pas un carré particulier
    //carre c3 = r3; // error car r3 est un rectangle il faut faire une conversion explicite
    // il faut créer le constructeur de copie
    //carre c3 = (carre *) r3;

    // Liaison dynamique
    rectangle * r = new carre(8);
    afficher(r);
    ellipse * c = new cercle(8);
    afficher(c);

    cercle e (3);
    std::cout << e << std::endl;


    // Le résultat obtenu n'est pas satisfaisant, on devait avoir "Je suis un rectangle", 
    // et le second je suis un ellipse

    // Déclaration de la variable vf de type vecteur de figure et ajoutons 
    // dans ce vecteur plusieurs rectangles, carrés, ellipse et cercles
    std::vector<figure *>  vf = {new rectangle(3, 1), new carre(18), new ellipse(4, 2), new cercle(3)};

    // à l'exercice 20 on a un problème car la méthode surface n'existe pas dans la figure
    // parcours du vecteur vf
    for (figure *f : vf) {
        afficher(f);
        std::cout << "de surface " << f->surface() << std::endl;
    }


    return EXIT_SUCCESS;
}