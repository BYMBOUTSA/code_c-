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
        virtual std::string toString() const = 0;
        
        // liaison dynamique pour pouvoir écrire la bonne figure sur la console
        friend std::ostream& operator<<(std::ostream& f, const figure & fig) {
            return f << fig.toString();
        }
};