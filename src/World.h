#include <iostream>
#include <allegro5/allegro.h>
#include <vector>

#include "Player.h"
#include "Fontmanager.h"
#include "Level.h"
#include "Enemy.h"
#include "Snowman.h"
#include "Ramp.h"


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

        void Input(ALLEGRO_EVENT *ev);
        void Update();
        void Draw();
        void Collision();

    private:
        double SeedEnemies(double val);


};
