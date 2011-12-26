#include "Enemy.h"


class Snowman : public Enemy {

    public:

     int frameactual;
     int framepos;
     uint32_t time;


     Snowman(const char* filename, float posx, float posy);
     void Update();
     void Draw(ALLEGRO_BITMAP *buffer);


};
