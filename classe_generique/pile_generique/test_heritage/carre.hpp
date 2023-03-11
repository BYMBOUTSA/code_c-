#include <iostream>
#include <string>
#include <cassert>
#include "rectangle.hpp"
#include "figure.hpp"


class carre : public rectangle {
    private:
        double cote;
    public:
        carre(const double c=0) : rectangle(c, c) {
            assert(c >= 0);
        }
        // conversion de rectangle en carre
        carre(const rectangle & r) : rectangle(r.getLargeur(), r.getLongueur()) {
            assert(r.getLargeur() == r.getLongueur());
        }
        ~carre() {
            std::cout << "Destruction du carré" << std::endl;
        }

        double getCote() const {
            return this->getLargeur();
        }
        /*void setCote(const double c) {
            this->setLargeur(c);
            this->setLongueur(c);
        }*/
        /*double perimetre() const {
            return (this->cote * 4);
        }
        double surface() const {
            return (this->cote * this->cote);
        }*/
        std::string toString() const {
            return "(" + std::to_string(this->getCote()) + ")";
        }
        friend std::ostream& operator<<(std::ostream& f, const carre & c) {
            return f << c.toString();
        }
        //double getLargeur() const = delete;
        //double getLongueur() const = delete;
        void setLargeur(const double l) = delete;
        void setLongueur(const double L) = delete;
        std::string quiSuisJe() const override {
            return "un carré";
        }


};