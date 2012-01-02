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
    sscanf(tmpdata.c_str(),";%d %d\n", &MapWidth, &MapHeight);
    //cout << lvobj.width << endl;
    //cout << lvobj.height << endl;
    debug_print("Width: %d  Height: %d\n", lvobj.width , lvobj.height);

    getline(fs, tmpdata);
    sscanf(tmpdata.c_str(),";%s", &MapName);
    //cout << lvobj.name << endl;
    debug_print("Name: %s\n", MapName);

     getline(fs, tmpdata);


    debug_print("Level Size W: %d H:%d", lvobj.width * 32, lvobj.height * 32  );






    while(fs.good()){

        getline(fs, tmpdata);
        sscanf(tmpdata.c_str(),"%c %f %f", &lvobj.obj_type, &lvobj.obj_x, &lvobj.obj_y);
        LevelObj.push_back( LevelObject(lvobj.obj_type, lvobj.obj_x, lvobj.obj_y));
        debug_print("[DEBUG:] %f %f\n", lvobj.obj_x, lvobj.obj_y);


    }


    fs.close();
    debug_print("%f %f", lvobj.obj_x, lvobj.obj_y);


}
