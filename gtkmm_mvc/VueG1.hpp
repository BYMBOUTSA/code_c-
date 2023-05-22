#pragma once
#include <gtkmm.h>
#include "damier.hpp"

class VueG : public Gtk::Window {
    private:
        Damier grille;
        Gtk::Button bclose;
        Gtk::Box vbox;

        void close() { Gtk::Window::close(); }

    public:
        VueG(int m, int n) : grille(m, n) {
            set_border_width(10);
            
            // Ajout de la grille et du bouton à la vbox
            vbox.set_orientation(Gtk::ORIENTATION_VERTICAL);
            vbox.pack_start(grille, Gtk::PACK_SHRINK);
            vbox.pack_end(bclose, Gtk::PACK_SHRINK);
            
            add(vbox);
            bclose.set_label("Close");
            bclose.signal_clicked().connect(sigc::mem_fun(*this, &VueG::close));
            show_all_children();
        }
        virtual ~VueG() {}
};
