#include <gtkmm.h>
#include "grille.hpp"

class VueG : public Gtk::Window {
    public:
        VueG() {
            set_title("Grille");
            set_default_size(500, 400);

            Gtk::Box * pBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
            add(*pBox);

            Grille grille;
            pBox->pack_start(grille, Gtk::PACK_EXPAND_WIDGET);

            show_all_children();
        }
};