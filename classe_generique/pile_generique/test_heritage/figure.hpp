#pragma once
#include <iostream>
#include <string>


class figure {

    public:
        virtual ~figure() {
            //std::cout << "Destruction de la figure" << std::endl;
        }
        virtual std::string quiSuisJe() const = 0;
        virtual double surface() const = 0;
        virtual double perimetre() const = 0;
        
        /*friend std::ostream& operator<<(std::ostream& f, const figure & fig) {
            return f << fig.toString();
        }*/

};