#include "Snowman.h"


Snowman::Snowman(float posx, float posy) : Enemy() {

    spr = al_load_bitmap("data\\snowman.bmp");
    al_convert_mask_to_alpha(spr, al_map_rgb(255,0,255));
    frameactual = 0;
    framepos = 0;
    maxtime = 15;


    Position.X = posx;
    Position.Y = posy;
    bound_x = 10;
    bound_y = 5;

    repeatanimation = false;
    startanimation = false;
    alive = false;
    maxframes = 5;
    time = 8;

}


Snowman::Snowman(int id, float posx, float posy){

    spr = al_load_bitmap("data\\snowman.bmp");
    al_convert_mask_to_alpha(spr, al_map_rgb(255,0,255));
    frameactual = 0;
    framepos = 0;
    time = 5;


    Position.X = posx;
    Position.Y = posy;
    bound_x = 10;
    bound_y = 5;

    repeatanimation = false;
    alive = false;
    isCollidible = true;

}


void Snowman::Update(){



    debug_print("Frame: %d\n", framepos);


    return Enemy::Update(0);
}

void Snowman::Draw(){

    Enemy::Draw();
}

void Snowman::CollisionWith(Object &a, Enemy* &enemy){

    Enemy::CollideWith(a, enemy);

}


