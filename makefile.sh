#!/bin/bash







g++ -g  src/main.cpp src/Game.cpp  src/Global.cpp src/Level.cpp  src/Object.cpp src/Enemy.cpp src/Snowman.cpp src/Player.cpp src/Position.cpp src/Ramp.cpp src/LevelObject.cpp src/Collidible.cpp -L/usr/lib -lallegro -lallegro_font -lallegro_image -lallegro_ttf -lallegro_main -lallegro -lallegro_primitives -lGL

./a.out



