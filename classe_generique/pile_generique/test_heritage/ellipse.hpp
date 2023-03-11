#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "figure.hpp"

class ellipse : public figure{
    protected:
        double prayon;
        double grayon;
    public:
        ellipse(const double pr=0, const double gr=0) : prayon(pr) , grayon(gr) {
            assert(pr >= 0 && gr >= 0);
        }
        ~ellipse() {
            std::cout << "Destruction de l'ellipse" << std::endl;
        }
        double getPrayon() const {
            return this->prayon;
        }
        double getGrayon() const {
            return this->grayon;
        }
        void setPrayon(const double pr) {
            this->prayon = pr;
        } 
        void setGrayon(const double gr) {
            this->grayon = gr;
        }
        double perimetre() const override{
            return M_PI * sqrt(2 * (this->prayon * this->prayon + this->grayon * this->grayon));
        }
        double surface() const override {
            return M_PI * this->prayon * this->grayon;
        }
        friend std::ostream& operator<<(std::ostream& f, const ellipse & e) {
            return f << "ellipse(" << e.prayon << ", " << e.grayon << ")" << std::endl;
        }
        std::string quiSuisJe() const override {
            return "une ellipse";
        }

};