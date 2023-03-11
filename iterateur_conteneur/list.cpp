#include <iostream>
#include <cstdlib>
#include <forward_list>
#include <list>


// écriture de la fonction
template<typename T> void print(std::list<T> l) {
        std::cout << "<";
        for (typename std::list<T>::iterator it_l = l.begin(); it_l != l.end(); it_l++) {
            std::cout << *it_l << " ";
        }
        std::cout << ">" << std::endl;
}

int main () {

    // déclaration de liste d'entier
    std::forward_list<int> lf;
    std::list<int> l;

    // ajout des éléments au début de la liste
    l.push_front(4);
    l.push_front(9);

    // ajout d'un élément à la fin de la liste
    l.push_back(0); 
    //print(l); // <9 4 0 >

    // on définit un itérateur qu'on place au debut de la liste
    std::list<int>::iterator it = l.begin();

    // on insère dans la liste l à la position donnée par l'itérateur it donc begin() + 1 la valeur -1
    l.insert(++it, -1);
    // print(l); <9 -1 4 0 >

    // on retire le premier élément de la liste l
    l.pop_back();
    print(l); //<9 -1 4> 

    // on supprime les éléments qui se trouve dans les position l.begin() et it
    l.erase(l.begin(), it);
    //print(l); //<4 > 

    // on insert -2 à la position l.end()
    l.insert(l.end(), -2);

    print(l); <4 -2 >



    return EXIT_SUCCESS;
}