#include <iostream>

using namespace std;

class LevelObject {

    public:

        char obj_type;
        float obj_x,obj_y;

        char name[32];
        int width, height;

        LevelObject(char object, float x, float y);
        LevelObject();




};
