#include "Tree.h"

ObjTree::ObjTree() : Enemy() {

}

ObjTree::ObjTree(float posx, float posy) : Enemy() {

    spr = al_load_bitmap("data//tree.bmp");
    al_convert_mask_to_alpha(spr, al_map_rgb(255,0,255));
    frameactual = 0;
    framepos  = 0;
    maxframes  = 1;
    maxtime = 8;
    startanimation = false;
    repeatanimation = false;
    Position.X = posx;
    Position.Y = posy;






}


void ObjTree::Draw(){
    Enemy::Draw();
}

void ObjTree::Update(){

    Enemy::Update(0);
}
