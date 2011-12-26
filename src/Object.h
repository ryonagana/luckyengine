#pragma once
#include <allegro5/allegro.h>
#include "Position.h"
#include "Collidible.h"
#include <iostream>

using namespace std;



class Object {


    public:
        bool startanimation;
        bool repeatanimation;
        int width, height;
        ALLEGRO_BITMAP *spr;
        float Speed;


        Vector2<float> Position;

        int bound_x;
        int bound_y;

        char type;

        Object();

        virtual void Draw() { return; }
        virtual void Update() { return; }
        virtual void Play() { return; }
        virtual void Stop() { return;  }
};
