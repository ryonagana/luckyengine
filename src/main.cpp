#include "main.h"
#include "Global.h"
#include "World.h"




ALLEGRO_EVENT_QUEUE *g_queue;
ALLEGRO_DISPLAY *g_display;
ALLEGRO_KEYBOARD_STATE g_kbdstate;
ALLEGRO_BITMAP *g_screen;
ALLEGRO_TIMER *g_timer;


uint64_t ticks;

bool redraw;

char* getVersion(){

    char ver[127];
    char* str_version  = new char[127];

    switch(ACTUAL_BUILD){

    case BUILD_DEBUG:
        sprintf(ver, "debug ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_RELEASE:
        sprintf(ver, "release ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_ALPHA:
        sprintf(ver, "alpha ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_BETA:
        sprintf(ver, "beta ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_FINAL:
        sprintf(ver, "final ver. %d.%d.%d.%d (unreachable lolol) :)", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_SPECIAL:
        sprintf(ver, "Nightly build ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    }

    strcpy(str_version, ver);

    return str_version;

}

int AllegroInit(){

    if(!al_init()){
        cout << "Fatal Error!";
        return -1;
    }

    if(!al_install_keyboard()){
        cout << "Failed!  installing Keyboard";
        return 0;
    }

    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    g_display = al_create_display(800,760);

    al_get_keyboard_state(&g_kbdstate);
    al_set_target_bitmap(g_screen);
    al_set_target_bitmap(al_get_backbuffer(g_display));

    g_timer = al_create_timer(1.0 / TICKSPERFRAME);
    g_queue = al_create_event_queue();

    al_register_event_source(g_queue, al_get_keyboard_event_source());
    al_register_event_source(g_queue, al_get_display_event_source(g_display));
    al_register_event_source(g_queue, al_get_timer_event_source(g_timer));

    al_start_timer(g_timer);
    al_flip_display();



    return 1;

}



int main(int argc, char* argv[]  ){

    srand(time(NULL));


    if( AllegroInit() < 0 ){
        exit(0);
    }

    bool gamefinished = false;
    redraw =  false;

    World myWorld;

    myWorld.LoadWorld("mapa.cbmap");
    myWorld.Grid = false;


    gFont texto("data\\visitor1.ttf",12);



    while(!gamefinished){

        ALLEGRO_EVENT ev;



        al_wait_for_event(g_queue, &ev);
        ticks =   al_get_timer_count(g_timer);




        if( ev.type == ALLEGRO_EVENT_TIMER){

        redraw = true;


        }else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;






        if(redraw == true && al_event_queue_is_empty(g_queue)){
            redraw = false;

            al_clear_to_color(al_map_rgb(255,255,255));

            texto.draw( getVersion(), al_map_rgb(255,0,0), 0,0,0 );

            myWorld.DrawEnemies(g_display);


            al_flip_display();



        }

    }

    al_destroy_display(g_display);
    al_destroy_timer(g_timer);
    al_destroy_bitmap(g_screen);

    exit(0);



return 0;
}
