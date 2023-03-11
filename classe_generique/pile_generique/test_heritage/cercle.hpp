#include <iostream>
#include <string>
#include <cassert>
#include "ellipse.hpp"
#include "figure.hpp"

class cercle : public ellipse {

    public:
        cercle(const double r=0) : ellipse(r, r) {
            assert(r >= 0);
        }
        ~cercle() {
            std::cout << "Destructeur du cercle" << std::endl;
        }
        cercle(const ellipse & e) : ellipse(e.getPrayon(), e.getGrayon()) {
            assert(e.getPrayon() == e.getGrayon());
        }
        // On supprime les setteurs de la super-classe
        void setPrayon(const double pr) = delete;
        void setGrayon(const double gr) = delete;
        double getRayon() const {
            return this->getPrayon();
        }
        friend std::ostream& operator<<(std::ostream& f, const cercle & c) {
            return f << "cercle(" << c.getRayon() << ")" << std::endl;
        }
        std::string quiSuisJe() const override {
            return "un cercle";
        }

};