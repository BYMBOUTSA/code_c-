#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std ;

//Help me

class Dico{

    private :
        map<string,int> m ;
    
    public :
        //Dico(){}
        //Dico(map<string,int> m1) : m(m1){}

    public :

        string toString() const{
            ostringstream ss ;
            ss << "-> " ;
            for(auto x : this->m)
                ss <<x.first << " : " <<x.second << endl ;
            
            return ss.str() ;
        }

        void inserer (const string s){
            /*int n = count (m.begin(),m.end(),s) ;
            m[s] = n ;*/
            if (m.find(s) != m.end()) {
                m[s]++;
            } else {
                m[s] = 1;
            }
        }

};


int main (int argc , char* argv[]){

    if(argc != 2){
        perror("pas de ficher en entrée") ;
        return EXIT_FAILURE ;
    }

    ifstream fin (argv[1]) ;
    string word ;
    Dico elt ;

    if(!fin.is_open()){
        perror(argv[1]) ;
        return EXIT_FAILURE ;
    }

    while(fin >>word){
        elt.inserer(word) ;
    }
    fin.close() ;
    
    cout << elt.toString()<< endl ;
    return EXIT_SUCCESS ;

}