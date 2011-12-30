#include "Level.h"


Level::Level(){

}

Level::Level(const char* filename){
    open(filename);
}

void Level::open(const char* filename){

    //fp.open(filename);

    string tmpdata;


    LevelObject lvobj;

    fs.open(filename);

    getline(fs, tmpdata);
    sscanf(tmpdata.c_str(),";%d %d", &MapWidth, &MapHeight);
    //cout << lvobj.width << endl;
    //cout << lvobj.height << endl;
    debug_print("Width: %d  Height: %d", lvobj.width , lvobj.height);

    getline(fs, tmpdata);
    sscanf(tmpdata.c_str(),";%s", &MapName);
    //cout << lvobj.name << endl;
    debug_print("Name: %s", MapName);

     getline(fs, tmpdata);








    while(fs.good()){

        getline(fs, tmpdata);
        sscanf(tmpdata.c_str(),"%c %f %f", &lvobj.obj_type, &lvobj.obj_x, &lvobj.obj_y);
        LevelObj.push_back( LevelObject(lvobj.obj_type, lvobj.obj_x, lvobj.obj_y));
        debug_print("[DEBUG:] %f %f", lvobj.obj_x, lvobj.obj_y);


    }


    fs.close();
    debug_print("%f %f", lvobj.obj_x, lvobj.obj_y);


}
