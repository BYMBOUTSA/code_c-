# Variables
GTKMM_CF = `pkg-config gtkmm-3.0 --cflags`
GTKMM_LD = `pkg-config gtkmm-3.0 --libs`
CFLAGS = $(GTKMM_CF) -Wall # les options du compilateur
LDFLAGS = $(GTKMM_LD) # les options pour l’éditeur de liens

# Cible de compilation
all: damier1

damier1 : damier1.cpp
	g++ $(CFLAGS) -o $@ $< $(LDFLAGS)

# Nettoyages
clean:
	rm -f damier1
