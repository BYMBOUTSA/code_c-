#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/messagedialog.h>
#include <vector>
#include <string>

class Vue : public Gtk::Window {
    private:
        Gtk::Box box;
        Gtk::Button bPermut, bclose;
        //Gtk::Button b;
        Gtk::Image img;

        const string gtkImg = "GTK.png";
        const string gnomeImg = "pied.png";

        void close() {Gtk::Window::close();}
        /*void action() {
            Gtk::MessageDialog dialog(*this, "Information");
            dialog.set_secondary_text("Button clicked");
            dialog.run();
        }*/
        // méthode permuter
        void permuter() {
           static bool toggle = true;
           this->img.set(toggle ? gnomeImg : gtkImg);
           toggle = !toggle;
        }

    public:
        Vue() : box(Gtk::ORIENTATION_VERTICAL), bclose("Close"), bPermut("Permuter"), img(gtkImg) {
            box.pack_start(img);
            box.pack_start(bPermut);
            box.pack_start(bclose);
            add(box);
            show_all_children();

            // Connect signals
            //b.signal_clicked().connect(sigc::mem_fun(*this, &Vue::action));
            //bclose.signal_clicked().connect(sigc::mem_fun(*this, &Vue::close));
            // en remplaçant par une fonction anonyme
            bclose.signal_clicked().connect([this]() {
                this->close();
            });
            bPermut.signal_clicked().connect([this]() {this->permuter();});

        }

        // le destructeur
        virtual ~Vue() {}
};
