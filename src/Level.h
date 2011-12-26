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
        void open(const char* filename);
        Level();

    private:
        ifstream fs;
        vector<LevelObject> LevelObj;

};


