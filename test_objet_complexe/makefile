CFLAGS = -Wall -fconcepts # les options du compilateur
LDFLAGS =  # les options pour l'éditeur de liens

CC = g++ # le compilateur à utiliser

SRC = testcomplexe.cpp complexe.cpp # les fichiers sources
PROG = testcomplexe   # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o    # lien entre les suffixes
all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

testcomplexe.cpp : complexe.hpp 
complexe.cpp : complexe.hpp 


# le lien entre .o et -c
# $< dernière dépendance
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


# pour faire propre
.PHONY: clean
clean:
	rm -f *.o $(PROG)
