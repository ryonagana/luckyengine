#pragma once
#include "Object.h"
#include "Collidible.h"


class Enemy : public Object {



    public:
     int frameactual;
     int framepos;

     uint32_t maxframes;
     uint32_t maxanimation;
     uint32_t time;


     Enemy();
     Collidible Collision;
     Enemy(float pos_x, float pos_y);
     Enemy(const char *filepath, float pos_x, float pos_y);
     void Draw();
     void Update(uint64_t time);
     void Play();
     void Stop();

};
