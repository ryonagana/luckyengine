#include "World.h"

World::World(){

    DestroyWorld();

}

void World::CreateGrid(Level &thelevel){

    for(int i = 0; i < thelevel.MapHeight; ++i){
        for(int j = 0; j< thelevel.MapWidth; ++j ){

            al_draw_line(0, i * 32 , thelevel.MapWidth * 32  , i * 32, al_map_rgb(255,0,0),1.0);

            al_draw_line( (i * 32), thelevel.MapHeight * 32, (i*32), 0, al_map_rgb(255,0,0),1.0);



        }

    }


}

void World::LoadWorld(const char* worldname){

    string mapname(worldname);
    size_t found_str;

    found_str = mapname.find(".txt");
    if ( found_str != string::npos){
        CreateLevel(worldname);
        debug_print("Level TXT Loaded: %s  ", mapname.c_str());
    }
    found_str = mapname.find(".cbmap");
    if ( found_str != string::npos){
        CreateLevel(worldname);
        debug_print("Level CBMAP Loaded: %s  ", mapname.c_str());
    }

    found_str = mapname.find(".map");
    if ( found_str != string::npos){
        CreateLevel(worldname);
        debug_print("Level MAP Loaded: %s  ", mapname.c_str());
    }

    found_str = mapname.find(".level");
    if ( found_str != string::npos){
        CreateLevel(worldname);
        debug_print("Level LEVEL Loaded: %s  ", mapname.c_str());
    }


}

void World::CreateLevel(const char *levelfilemap){


    gameLevel.open(levelfilemap);
    vector<LevelObject>::iterator levelItem;
    Enemy* enemy;
    //gameLevel.levelbuffer = al_create_bitmap(gameLevel.MapWidth * 32, gameLevel.MapHeight * 32);



    for(levelItem  =  gameLevel.LevelObj.begin(); levelItem < gameLevel.LevelObj.end(); ++levelItem){

        if(levelItem->obj_x <= gameLevel.MapWidth || levelItem->obj_y <= gameLevel.MapHeight){

        switch(levelItem->obj_type){

        case 's': // create a Snowman!

            enemy = new Snowman(levelItem->obj_x, levelItem->obj_y);
            enemy->alive = true;
            EnemyList.push_back (enemy);
            break;

        case 't': // create tree

            enemy = new ObjTree(levelItem->obj_x, levelItem->obj_y);
            enemy->alive = true;
            EnemyList.push_back(enemy);
            break;

        }





    }
}


}

void World::Collision(){


    for(uint32_t i = 0; i <  EnemyList.size(); i++ ){

        if( EnemyList.at(i)->CollideWith(SkiPlayer, EnemyList.at(i))  ){

             EnemyList.at(i)->Play();
        }

    }


}

void World::DrawEnemies(ALLEGRO_DISPLAY *display){


    for(uint32_t i = 0; i < EnemyList.size(); i++){

        if(EnemyList.at(i)->alive){

        //al_set_target_bitmap(gameLevel.levelbuffer);

        if(Grid) CreateGrid(gameLevel);


        EnemyList.at(i)->Draw();
        //al_set_target_bitmap( al_get_backbuffer(display));
        //al_draw_bitmap(gameLevel.levelbuffer, 0 , 0 ,0);



        }

    }

}


void World::Draw(ALLEGRO_DISPLAY *dsp){

    SkiPlayer.Draw( al_get_backbuffer(dsp));

}

void World::Input(ALLEGRO_EVENT *ev){

    SkiPlayer.KeyboardUpdate(ev);


}

void World::Update(){

    SkiPlayer.Update(0);

    for(uint32_t i = 0; i < EnemyList.size(); i++){

        EnemyList.at(i)->Update(0);

    }

    Collision();

}


void  World::DestroyWorld(){

    if( EnemyList.size() != 0){
        EnemyList.clear();
    }else  if( RampList.size() != 0 ){
        RampList.clear();

    }





}
