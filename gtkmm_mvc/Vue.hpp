#pragma once
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/messagedialog.h>

class Vue : public Gtk::Window {
    private:
        Gtk::Box box;
        Gtk::Button bclose;
        Gtk::Button b;
        Gtk::Image img;

        void close() {Gtk::Window::close();}
        void action() {
            Gtk::MessageDialog dialog(*this, "Information");
            dialog.set_secondary_text("Button clicked");
            dialog.run();
        }
       
        

    public:
        Vue() : box(Gtk::ORIENTATION_VERTICAL), bclose("Close"), b("Permuter"), img("GTK.png") {
            box.pack_start(img);
            box.pack_start(b);
            box.pack_start(bclose);
            add(box);
            show_all_children();

            // Connect signals
            b.signal_clicked().connect(sigc::mem_fun(*this, &Vue::action));
            bclose.signal_clicked().connect(sigc::mem_fun(*this, &Vue::close));
            // en remplaçant par une fonction anonyme
            bclose.signal_clicked().connect([this]() {
                this->close();
            });

        }
        // le destructeur
        virtual ~Vue() {}
}; 