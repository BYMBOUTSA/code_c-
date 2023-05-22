#pragma once
#include <gtkmm.h>

class Damier : public Gtk::DrawingArea {
    private:
        const int largeur = 400;
        const int hauteur = 300;
        const int CoteCase = 80;
        const int m, n;
    public:
        Damier(const int m_, const int n_) : m(m_), n(n_) {
            this->signal_draw().connect(sigc::mem_fun(*this, &Grille::on_draw));
            this->set_size_request(this->largeur, this->hauteur);
        }
        virtual ~Grille() {}
    protected:
        bool on_draw(const Cairo::RefPtr<Cairo::Context> & cr) override {
            cr->set_source_rgb(0, 0, 0);
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    cr->rectangle(j * CoteCase, i * CoteCase, CoteCase, CoteCase);
                    cr->fill();
                    cr->stroke();
                    cr->rectangle(j * CoteCase, i * CoteCase, CoteCase, CoteCase);
                    cr->fill();
                    cr->stroke();
                }
            }
            return true;
        }
};