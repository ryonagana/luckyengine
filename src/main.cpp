#include "main.h"
#include "Global.h"
#include "Player.h"
#include "Fontmanager.h"
#include "Level.h"
#include "Enemy.h"
#include "Snowman.h"
#include "Ramp.h"

ALLEGRO_EVENT_QUEUE *g_queue;
ALLEGRO_DISPLAY *g_display;
ALLEGRO_KEYBOARD_STATE g_kbdstate;
ALLEGRO_BITMAP *g_screen;
ALLEGRO_TIMER *g_timer;

uint64_t ticks;

bool redraw;

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


    if( AllegroInit() < 0 ){
        exit(0);
    }

    bool gamefinished = false;
    redraw =  false;

    Player ski;
    ski.InitPlayer();

    Level teste;
    Snowman  m("data\\snowman.bmp",100.0, 100.0);
    Snowman  snow("data\\snowman.bmp",100.0, 500.0);
    Ramp rampa(192,130);

    snow.startanimation = false;
    snow.repeatanimation = false;




    gFont ff("data\\visitor1.ttf",11);

    teste.open("mapa.txt");

    double oldtime = al_get_time();



    while(!gamefinished){

        ALLEGRO_EVENT ev;



        al_wait_for_event(g_queue, &ev);
        ticks =   al_get_timer_count(g_timer);

        if( ev.type == ALLEGRO_EVENT_TIMER){



        redraw = true;
        debug_print("%f", oldtime);



        if(ski.Collision.Collide(ski, snow)){


            ski.Position.Y =   ski.Position.Y - snow.bound_y;

            snow.Play();

        }



        m.Update();
        m.Play();
        snow.Update();
        ski.Update(ticks);
        rampa.Update(ticks, ski);








        }else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;



         ski.KeyboardUpdate(&ev);


        if(redraw == true && al_event_queue_is_empty(g_queue)){
            redraw = false;

            al_clear_to_color(al_map_rgb(255,255,255));

            ff.drawshadow("V. 0.2.1 - V.S Niketan", al_map_rgb(255,0,0),0,0,0);

            ski.Draw(g_screen);
            rampa.Draw();
            m.Draw(g_screen);
            snow.Draw(g_screen);




            al_flip_display();



        }

    }

    al_destroy_display(g_display);
    al_destroy_timer(g_timer);
    al_destroy_bitmap(g_screen);

    exit(0);



return 0;
}
