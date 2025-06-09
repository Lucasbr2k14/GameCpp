make:
	g++ main.cpp -o game \
	GameEngine/game.cpp \
	GameEngine/vector.cpp \
	GameEngine/player.cpp \
	-lSDL2 -lSDL2_image