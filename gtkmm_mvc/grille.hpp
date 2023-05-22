#pragma once
#include <gtkmm.h>

class Grille : public Gtk::DrawingArea {
    private:
        const int largeur = 400;
        const int hauteur = 300;
    public:
        Grille() {
            this->signal_draw().connect(sigc::mem_fun(*this, &Grille::on_draw));
            this->set_size_request(this->largeur, this->hauteur);
        }
        virtual ~Grille() {}
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context> & cr) override {
            // tracer une ligne verte entre les points (10, 10) et (200, 240)
            cr->set_source_rgb(0, 1, 0);
            cr->move_to(10, 10);
            cr->line_to(200, 240);
            cr->stroke();
            // tracer un rectangle rouge en (300, 100) de largeur 40 et hauteur 80
            cr->set_source_rgb(1, 0, 0);
            cr->rectangle(300, 100, 40, 80);
            cr->fill();
            // tracer un cercle bleu en (200, 55) de rayon 30 pixels
            cr->set_source_rgb(0, 0, 1);
            cr->arc(200, 55, 30, 0.0, 2 * M_PI);
            cr->fill();
            return true;
        }
};