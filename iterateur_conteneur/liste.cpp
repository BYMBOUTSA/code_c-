#include <iostream>
#include <forward_list>
#include <list>
#include <cassert>
#include <sstream>

template<typename, T>

class pile : private std::forward_list<T> {
     typedef std::forward_list<T> super;
    public:
        pile() {}
        // initialisation d'une pile au travers d'une liste
        pile(const std::list<T> &l) {
            for (T x : l)
                this->empiler(x);
        }
        bool estVide() const {
            return super::empty();
        }
        T sommet() const {
            return super::front();
        }
        void empiler(const T & x) {
            super::push_front(x);
        }
        void depiler() {
            assert(!this->estVide());
            super::pop_front();
        }
        std::string toString() const {
            std::ostringstream s;
            s << "[";
            for (typename std::forward_list<T>::const_iterator it_v)
        }


};