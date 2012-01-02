#pragma once
#include <iostream>
#include <allegro5/allegro5.h>
#include "Object.h"


using namespace std;

class Object;
class Enemy;

class Collidible {

    public:
        Collidible();
        bool Collide(Object &a, Object &b );
        bool EnemyCollide(Object &a, Enemy* &b);

};
