#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <cassert>
#include <sstream>


class Dico : public std::map<std::string, int> {
    public:
        // ajouter un mot dans le dictionnaire
        void inserer(const std::string m) {
            // si le mot est trouvé
            (*this)[m] = (this->find(m) == this->end()) ? 1 :((*this)[m] + 1);
        }
        std::string toString() const {
            std::ostringstream s;
            for(auto it_d = this->begin(); it_d != this->end(); it_d++) 
                s << it_d->first << " : " << it_d->second << "\n";
            return s.str();
        }
        friend std::ostream & operator<<(std::ostream & f, const Dico & dic) {
            return f << dic.toString();
        }
};


int main(int argc, char * argv[]) {
    if(argc != 2) {
        std::cerr << "Usage : xrf file" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    // Ouverture du fichier
    std::ifstream ios(argv[1]);
    // Vérification de la bonne ouverture du fichier
    if(!ios.is_open()) {
        perror(argv[1]);
        std::exit(EXIT_FAILURE);
    }
    // on crée une table pour mémoriser le mot
    Dico table;
    std::string s;
    while(ios >> s) 
        table.inserer(s); // on insère le mot
    ios.close(); // on ferme le fichier
    std::cout << table;

    return EXIT_SUCCESS;
}