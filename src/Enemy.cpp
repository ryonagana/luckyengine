#include "Enemy.h"

Enemy::Enemy(){

    spr = al_load_bitmap("data\\snowman.bmp");


    Position.X = 0;
    Position.Y = 0x0;


}

void Enemy::Play(){
    startanimation = true;
}

void Enemy::Stop(){
    startanimation = false;
}

Enemy::Enemy(const char *filepath, float pos_x, float pos_y){

    spr = al_load_bitmap(filepath);


    Position.X = pos_x;
    Position.Y = pos_y;



}

void Enemy::Draw(){

al_draw_bitmap_region(spr,framepos * 32,0,32,32, Position.X , Position.Y ,0x0);


}

void Enemy::Update(uint64_t time){
    if(startanimation){
     time--;

    if( (time % 8) == 0 ){

        time = 8;

         framepos++;

        if( (framepos %  maxframes ) == 0){


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
