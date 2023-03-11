#include <iostream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <utility>


class Dico  {
    protected:
        typedef std::map<T> super;
        std::map<std::string, int> dic;
    public:
        void inserer(const std::string m) {
            // si l'élément est trouvé dans m
            /*if (dic.find(elt) != dic.end()) {
                dic[elt]++;
            } else {
                dic[elt] = 1;
            }*/
            this->dic[m] = (this->dic.find(m) == this->dic.end()) ? 1 : this->dic[m]++; 
        }

        std::string toString() const {
            std::ostringstream s;
            for (std::pair<T>::iterator it_d = this->m.begin(); it_d != this->m.end(); it_d++)
                s << it_d.first << " : " << it_d.second << std::endl;
            return s.str();
        }

        friend std::ostream & operator<<(std::ostream & f, const Dico<T> & d) {
            return f << d.toString();
        }

};