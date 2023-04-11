#include <iostream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <utility>
#include <fstream>

class Dico  {
    protected:
        //typedef std::map<T> super;
        std::map<std::string, int> dic;
    public:
        void inserer(const std::string m) {
            // si l'élément est trouvé dans m
            /*if (dic.find(elt) != dic.end()) {
                dic[elt]++;
            } else {
                dic[elt] = 1;
            }*/
            this->dic[m] = (this->dic.find(m) == this->dic.end()) ? 1 : (this->dic[m]+1); 
        }

        std::string toString() const {
            std::ostringstream s;
            for (auto x : this->dic)
                s << x.first << " : " << x.second << std::endl;
            return s.str();
        }

        friend std::ostream & operator<<(std::ostream & f, const Dico & d) {
            return f << d.toString();
        }

};


int main (int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Usage : xrf file" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    // ouverture du fichier
    std::ifstream ios(argv[1]);
    // Vérification de la bonne ouverture du fichier
    if (!ios.is_open()) {
        perror(argv[1]);
        std::exit(EXIT_FAILURE);
    }
    // on défini une table pour mémoriser le mot
    Dico table;
    std::string s;
    while (ios >> s)
        table.inserer(s); // on insère le mot dans la table
    ios.close(); // fermeture du fichier
    std::cout << table;

    return EXIT_SUCCESS;
}