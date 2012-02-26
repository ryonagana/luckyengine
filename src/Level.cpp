#include "Level.h"


Level::Level(){

}

Level::Level(const char* filename){
    open(filename);
}

void Level::open(const char* filename){

   // LevelObj lvobj;
    ifstream level; // init file descriptor  to handle level file
    string tmp; // a temporary string container

    int width, height;  // variable that handles map header  ans stores width and height
    string name; //  variable that stores the name of the map


    level.open(filename); //  open a file

    if(!level.good()){

        cout << "Cannot Open :" << filename << endl;
        /*  if map file not exists gasme throws a FATAL ERROR */

        //allegro_exit();
        file.close();
        exit(0);

    }

    level >> width;  // get firsat column of the file and retrieve width value file
    level >> height; // get the second column and retrieve height vaue from the file

    level >> tmp; //  handle the newline

    while(level.good()){ // check if is file is good and not NULL and not EOF

     char type;  // temporary variable stores type of the file (check line by line)
     float width, height; // temporary variable width and height of the file (check line by line)

     level >> type; // get the first column is type of the object  (char type expected)
     level >> width; // get the second column is the position width of the object (float expected)
     level >> height; // get the third column in the file and return the position height of the object (float expected)

     debug_print("LevelObject: %c %.2f %.2f\n", type, width, height); // jusat a secure print can be hide ifdef DEBUG = 0

     /*
     LevelObj is a vector that stores all objects of the map
     i just push back a new Levelobject (each row is a new instance in the vector)
     and stores for a further  reading and rendering the map
     */

     LevelObj.push_back( LevelObject(type,width,height));




    }

    level.close(); // close file descriptor



    /*
    while(!level.eof() ){

    char type;
    float x,y;

    level >> type >> x >> y;

   debug_print("[LEVEL] %c %.2f %.2f", type, x, y);



    }


    level.close();
    */




    //fp.open(filename);

    /*
    string tmpdata;


    LevelObject lvobj;

    fs.open(filename);

    getline(fs, tmpdata);
    sscanf(tmpdata.c_str(),";%d %d", &MapWidth, &MapHeight);
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
    */



}
