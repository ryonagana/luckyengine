#pragma once
#include "Object.h"
#include "Collidible.h"


class Enemy : public Object {



    public:


     Enemy();
     Collidible Collision;
     Enemy(float pos_x, float pos_y);
     Enemy(const char *filepath, float pos_x, float pos_y);
     void Draw(ALLEGRO_BITMAP *buffer);
     void Update(uint64_t time);
     void Play();
     void Stop();

};
