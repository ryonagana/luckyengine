#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Global.h"
#include "LevelObject.h"
#include <allegro5/allegro.h>
#include <map>

using namespace std;


class Level {


    public:

        int MapWidth;
        int MapHeight;
        char MapName[32];
        ALLEGRO_BITMAP *levelbuffer;


        void open(const char* filename);
        Level();
        Level(const char* filename);

        vector<LevelObject> LevelObj;

    private:
        ifstream fs;


};


