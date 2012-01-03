#include "Enemy.h"
#include "Global.h"

class Snowman : public Enemy {

    public:


     uint32_t time;


     Snowman(float posx, float posy);
     Snowman(int id, float posx, float posy);
     void Update();
     void Draw();
     void CollisionWith(Object &a, Enemy* &enemy);



};
