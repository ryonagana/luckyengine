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

void Enemy::Draw(ALLEGRO_BITMAP *buffer){

al_draw_bitmap_region(spr,0,0,32,32, Position.X , Position.Y ,0x0);


}

void Enemy::Update(uint64_t time){


}
