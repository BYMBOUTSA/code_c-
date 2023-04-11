#include <iostream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <fstream>
#include <utility>

class Dico {
    protected:
        std::map<std::string, int> dic;
    public:
        // ajouter un mot dans le dictionnaire
        void inserer(const std::string m) {
            // si le mot est dans le dictionnaire
            this->dic[m] = (this->dic.find(m) == this->dic.end()) ? 1 : (this->dic[m]+1);
        }
        std::string toString() const {
            std::ostringstream s;
            for(auto it_d = this->dic.begin(); it_d != this->dic.end(); it_d++) 
                s << it_d->first << " : " << it_d->second << "\n";
            return s.str();
        }
        // On surcharge l'opérateur <<
        friend std::ostream & operator<<(std::ostream & f, const Dico & dic) {
                return f << dic.toString();
        }
};


int main(int argc, char * argv[]) {
    if(argc != 2) {
        std::cerr << "Usage : xref file" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    //Ouverture du fichier
    std::ifstream ios(argv[1]);
    // Vérification de la bonne ouverture du fichier
    if(!ios.is_open()) {
        perror(argv[1]);
        std::exit(EXIT_FAILURE);
    }
    // On crée une table pour mémoriser le mot
    Dico table;
    std::string s;
    while(ios >> s)
        table.inserer(s); // on insère le mot dans la table
    ios.close(); // fermeture du fichier
    std::cout << table; // on affiche le contenu de la table

    return EXIT_SUCCESS;
}




// la classe Dico heritière de std:map 
/*#include <iostream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <fstream>
#include <utility>

class Dico : public std::map<std::string, int> {
    public:
        // ajouter un mot dans le dictionnaire
        void inserer(const std::string m) {
            // si le mot est dans le dictionnaire
            (*this)[m] = (this->find(m) == this->end()) ? 1 : ((*this)[m] + 1);
        }
        std::string toString() const {
            std::ostringstream s;
            for(auto it_d = this->begin(); it_d != this->end(); it_d++) 
                s << it_d->first << " : " << it_d->second << "\n";
            return s.str();
        }
        // On surcharge l'opérateur <<
        friend std::ostream & operator<<(std::ostream & f, const Dico & dic) {
                return f << dic.toString();
        }
};


int main(int argc, char * argv[]) {
    if(argc != 2) {
        std::cerr << "Usage : xref file" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    //Ouverture du fichier
    std::ifstream ios(argv[1]);
    // Vérification de la bonne ouverture du fichier
    if(!ios.is_open()) {
        perror(argv[1]);
        std::exit(EXIT_FAILURE);
    }
    // On crée une table pour mémoriser le mot
    Dico table;
    std::string s;
    while(ios >> s)
        table.inserer(s); // on insère le mot dans la table
    ios.close(); // fermeture du fichier
    std::cout << table; // on affiche le contenu de la table

    return EXIT_SUCCESS;
} */