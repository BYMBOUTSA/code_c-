#pragma once
#include <iostream>
#include "ellipse.hpp"
#include "figure.hpp"

class cercle : public ellipse {
    private:
        double rayon;
    public:
        cercle(const double r=0) : ellipse(r, r) {}
        cercle(const ellipse &e) : ellipse(e.getPrayon(), e.getGrayon()) {
            assert(e.getPrayon() == e.getGrayon());
        }
        
        ~cercle() {
            std::cout << "Destruction du cercle" << std::endl;
        }

        double getRayon() const {
            return this->getPrayon();
        }

        std::string quiSuisJe() const override {
            return "un cercle";
        }
        friend std::ostream& operator<<(std::ostream &f, const cercle& c) {
            return f << "cercle(" << c.getRayon() << ")";
        }
};