CFLAGS = -Wall -fconcepts # les options du compilateur
LDFLAGS =  # les options pour l'éditeur de liens

CC = g++ # le compilateur à utiliser

SRC = fctgen.cpp rectangle.cpp # les fichiers sources
PROG = fctgen   # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o    # lien entre les suffixes
all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

fctgen.cpp : rectangle.hpp 
rectangle.cpp : rectangle.hpp 


# le lien entre .o et -c
# $< dernière dépendance
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


# pour faire propre
.PHONY: clean
clean:
	rm -f *.o $(PROG)
