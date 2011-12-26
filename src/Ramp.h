#include <iostream>
#include <allegro5/allegro.h>
#include "Object.h"
#include "Collidible.h"
#include "Global.h"


using namespace std;


class Ramp : public Object {

    public:
        Ramp();
        Collidible Collision;
        Ramp(float x, float y);
        void Draw();
        void Update(double time, Object &ski);

};
