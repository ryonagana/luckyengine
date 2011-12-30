#include "World.h"

World::World(){

    DestroyWorld();

}

void  World::DestroyWorld(){

    if( EnemyList.size() != 0){
        EnemyList.clear();
    }

    if( RampList.size() != 0 ){
        RampList.clear();

    }





}
