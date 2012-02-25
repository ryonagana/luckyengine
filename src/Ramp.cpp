#include "Ramp.h"


Ramp::Ramp(){

    spr = al_load_bitmap("data//ramp.bmp");
    Position.X = 0;
    Position.Y = 0;
    bound_x = 32;
    bound_y = 120;

}

Ramp::Ramp(float x, float y){

    spr = al_load_bitmap("data//ramp.bmp");

    if(spr != NULL){

        al_convert_mask_to_alpha(spr, al_map_rgb(255,0,255));

    }
    Position.X = x;
    Position.Y = y;

}

void Ramp::Draw(){


    al_draw_bitmap_region(spr,0,0,32,32, Position.X ,Position.Y,0x0);


}


void Ramp::Update(double time,  Object &ski){


     if( Collision.Collide((*this), ski ) ){

        ski.Position.Y += (ski.Speed * 6.5) * AbsoluteVal<float>( ski.Position.Y + 50);

    }


}
