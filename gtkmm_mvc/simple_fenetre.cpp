#include <gtkmm.h>

// Ce programme crée et fait apparaître une fenêtre graphique
int main (int argc, char * argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    Gtk::Window window;
    // modification de la largeur et de la longueur de la fenêtre
    //window.set_default_size(300, 100);
    return app->run(window);
}