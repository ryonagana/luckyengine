#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>

#include "Player.h"
#include "FontManager.h"
#include "Level.h"

#include "Snowman.h"
#include "Ramp.h"
#include "Tree.h"


using namespace std;

int const MAX_ENEMIES = 90;
int const MAX_RAMPS = 35;



class World {



    public:

        World();
        void DestroyWorld();
        void LoadWorld(const char *worldname);

        Player SkiPlayer;
        vector<Enemy*> EnemyList;
        vector<Ramp>  RampList;
        Level gameLevel;

        bool Grid;

        void Input(ALLEGRO_EVENT *ev);
        void Update();
        void Draw(ALLEGRO_DISPLAY *dsp);
        void Collision();
        void DrawEnemies(ALLEGRO_DISPLAY *display);

    private:

        void CreateLevel(const char*  levelfilepath);
        void CreateGrid(Level &thelevel);





};
