CFLAGS = -Wall -fconcepts # les options du compilateur
LDFLAGS =  # les options pour l'éditeur de liens

CC = g++ # le compilateur à utiliser

SRC = testPileChainee.cpp pileChainee.cpp noeud.cpp # les fichiers sources
PROG = testPileChainee   # nom de l'exécutable
OBJS = $(SRC:.cpp=.o) # les .o qui en découlent
.SUFFIXES: .cpp .o    # lien entre les suffixes
all: $(PROG)

# étapes de compilation et d'édition de liens
# $@ la cible $^ toutes les dépendances
$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

testPileChainee.cpp : pileChainee.hpp noeud.hpp
pileChainee.cpp : pileChainee.hpp 
noeud.cpp : noeud.hpp 


# le lien entre .o et -c
# $< dernière dépendance
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


# pour faire propre
.PHONY: clean
clean:
	rm -f *.o $(PROG)
