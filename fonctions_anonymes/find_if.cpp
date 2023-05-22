#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


int main () {
    std::vector<int> v = {2, 3, 5, 7, 8};

    std::vector<int>::iterator pos = v.begin();

    // exo 3
    /*auto i = std::find_if(pos, v.end(), [] (int x) -> bool {return (x & 1) == 0;});
    if (pos != v.end()) 
        std::cout << *pos << std::endl; */
          
    
    // exo 4
    while ((pos = std::find_if(pos, v.end(), [] (int x) {return (x & 1) == 0;})) != v.end())
        std::cout << *pos++ << " ";

    std::cout << std::endl;

    return EXIT_SUCCESS;
}