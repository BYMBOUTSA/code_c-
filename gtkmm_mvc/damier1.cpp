#include <gtkmm/application.h>
#include "VueG.hpp"

int main (int argc, char * argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    VueG vue;
    return app->run(vue);
}


