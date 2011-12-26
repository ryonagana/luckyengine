#include "LevelObject.h"

LevelObject::LevelObject(char object, float x, float y){
    obj_type = object;
    obj_x = x;
    obj_y = y;
}

LevelObject::LevelObject(){

    obj_type = '\0';
    obj_x = 0.0;
    obj_y = 0.0;
    width = 0;
    height = 0;

}
