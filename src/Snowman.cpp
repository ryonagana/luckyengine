#include "Snowman.h"


Snowman::Snowman(float posx, float posy){

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

}


void Snowman::Update(){


  if(startanimation){
     time--;

    if( (time % 8) == 0 ){

        time = 8;

         framepos++;

        if( (framepos % 5) == 0){


            if(repeatanimation){
                framepos = 0;
            }else{

               int oldframe = framepos;
               framepos = oldframe - 1;

            }

        }



    }


  }




}

void Snowman::Draw(ALLEGRO_BITMAP *buffer){

    if( framepos < 5){  al_draw_bitmap_region(spr, framepos * 32,0,32,32, Position.X , Position.Y ,0x0); }
    else{
        al_draw_bitmap_region(spr, 0,0,32,32, Position.X , Position.Y ,0x0);

        }


}
