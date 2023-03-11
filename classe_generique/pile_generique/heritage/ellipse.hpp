#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "figure.hpp"

class ellipse : public figure {
    protected:
        double prayon;
        double grayon;
    public:
        ellipse(const double p=0, const double g=0) : prayon(p) , grayon(g) {
            assert(p >= 0 && g >= 0);
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

        void setPrayon(const double a) {
            this->prayon = a;
        }

        void setGrayon(const double b) {
            this->grayon = b;
        }

        double perimetre() const override {
            return M_PI*sqrt(2*((this->prayon * this->prayon) + (this->grayon * this->grayon)));
        }

        double surface() const override {
            return (M_PI * prayon * grayon);
        }

        std::string toString() const {
            return "(" + std::to_string(this->prayon) + ", " + std::to_string(this->grayon) + ")";
        }

        std::string quiSuisJe() const override {
            return "une ellipse";
        }

       
};