#include "Enemy.h"
#include "Global.h"


class ObjTree : public Enemy {

    public:
        ObjTree();
        ObjTree(float posx, float posy);
        void Update();
        void Draw();
        void CollisionWith(Object &a, Enemy* &enemy);

};
