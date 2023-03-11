#include <iostream>
#include <sstream>
#include <cstdlib>


int main () {

    // ostringstream et wostringstream utilisé pour convertir une valeur en chaîne
    // ou construire une chaîne par petit bouts
    
    /*std::ostringstream os; // on définit une ostringstream
    os << 12; // on envoi dans l'ostringstream la valeur 12
    std::string s = os.str(); */ // on recupère la  chaîne representé par 12
    //std::cout << s << std::endl;

    // construction du chaîne par petit bouts
    std::ostringstream os;
    int age = 15;
    os << "Alfred a " << age << " ans"; // on envoie les chaine construite par petits bout dans l'ostringstream
    // on fait comme une concaténation mais avec des types hétérogènes
    std::string s = os.str();
    std::cout << s << std::endl;


    // flux en entrée istringstream et wistringstream
    // convertir une chaîne dans un autre type (entier, etc...) 
    // ou pour extraire des champs d'une chaîne

    /*std::string s1 = "15"; // on met dans une chaîne de caractère le nombre "15"
    std::istringstream f(s1); // on construit un flux de chaîne à partir de cette chaîne
    int i;
    f >> i; // on se sert du flux f pour extraire la représentation de la chaîne s en entier en la mettant dans un entier
    std::cout << i << std::endl;*/

    // extraire des champs d'une chaîne
    std::string s2 = "john paul ringo georges"; // on définit une chaîne s
    std::istringstream f(s2); // on construit un flux de chaîne à partir de la chaîne s
    while(f) { // tant que ce flux est correct
        std::string mot;  // on prend un mot
        f >> mot; // on l'extrait
        std::cout << mot << std::endl;
    }
     
    // extraire des champs d'une chaine et les convertir en entiers
    std::string e = "12 3 4 63 15"; // on met dans une chaîne plusieurs nombre
    std::istringstream d(e); // on construit un flux avec la chaîne e
    while(d) { // tant que ce flux est correct
        int numbers; // on crée un entier pour récupérer les différents entier contenu dans le flux d
        d >> numbers; // on extrait les différentes chaîne dans l'entier numbers en donnant une représentation en entier
        std::cout << numbers << std::endl;
    }




    return EXIT_SUCCESS;
}