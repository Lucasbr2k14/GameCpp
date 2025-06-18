# Variáveis
.PHONY: clean

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -c -O3
LDFLAGS = -lSDL2 -lSDL2_image -O3
SRCDIR = GameEngine
OBJ = main.o game.o sprite.o player.o vector.o 

# Regra principal
game: $(OBJ)
	$(CXX) -o game $(OBJ) $(LDFLAGS)

# Compilação de objetos
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

game.o: $(SRCDIR)/game.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/game.cpp -o game.o

sprite.o: $(SRCDIR)/sprite.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/sprite.cpp -o sprite.o

player.o: $(SRCDIR)/player.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/player.cpp -o player.o

vector.o: $(SRCDIR)/vector.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/vector.cpp -o vector.o

# Limpeza
clean:
	rm -f *.o