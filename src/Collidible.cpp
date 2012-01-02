#include "Collidible.h"
#include "Enemy.h"


Collidible::Collidible(){

}

bool Collidible::Collide(Object &a, Object &b){

    if( ( a.Position.X >  (b.Position.X - b.bound_x))  &&
        ( a.Position.X < (b.Position.X +  b.bound_x))  &&
        ( a.Position.Y > (b.Position.Y - b.bound_y ))  &&
        ( a.Position.Y < (b.Position.Y + b.bound_y ))) {

            return true;

        }

return false;
}

bool Collidible::EnemyCollide(Object &a, Enemy* &b){


    if( ( a.Position.X >  (b->Position.X - b->bound_x))  &&
        ( a.Position.X < (b->Position.X +  b->bound_x))  &&
        ( a.Position.Y > (b->Position.Y - b->bound_y ))  &&
        ( a.Position.Y < (b->Position.Y + b->bound_y ))) {

            return true;

        }

        return false;


}
