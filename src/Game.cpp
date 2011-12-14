#include "Game.h"


Game::Game(){


    Width = 800;
    Height = 600;
    Bpp = 32;
    Title = "Default Window";
    isFullScreen = false;




    Start();
    InitWindow(800,600,32,"Default Window");
    SetTimer(60);
    InitEvents();

}

Game::Game(int width, int height, int bpp, std::string title, bool fullscreen){

    Width = width;
    Height = height;
    Bpp = bpp;
    Title = Title;
    isFullScreen = fullscreen ? true : false;

    Start();
    InitWindow(width,height,bpp,title);
    SetTimer(60);
    InitEvents();
    isAppFinished = false;


}

Game::~Game(){

    al_destroy_bitmap(g_screen);
    al_destroy_event_queue(g_queue);

}


void Game::InitWindow(int width, int height, int bpp, std::string title){

    if(isFullScreen){

        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    }else{

        al_set_new_display_flags(ALLEGRO_WINDOWED);

    }


    g_display = al_create_display(Width, Height);
    g_queue = al_create_event_queue();

}

void Game::Start(){

    if(!al_init()){

        std::cout << "Cannot Init Allegro Fatal Error!" << std::endl;
        exit(0);

    }

    if(!al_install_keyboard()){
       std::cout << "Fatal Error: Cannot Init keyboard" << std::endl;

    }

    /* if(al_init_font_addon() != -1){
      std::cout << "Cannot Initialize Font Add-on, May Occur Errors or Crash while running" << std::endl;
    }
    */

    al_init_font_addon();

}

int Game::W(){
    return Width;
}

void Game::W(int val){
   Width = val;
}

int Game::H(){
    return Height;
}

void Game::H(int val){
    Height = val;
}

int Game::Pallete(){
    return Bpp;
}

void Game::Pallete(int bpp){
    Bpp = bpp;
}

std::string Game::WindowCaption(){
    return Title;
}

void Game::WindowCaption(std::string str){

    Title = str;

}

void Game::SetTimer(int ticks){
    g_timer = al_create_timer(1.0 / ticks);
}

void Game::InitEvents(void){





    al_register_event_source(g_queue, al_get_keyboard_event_source());
    al_register_event_source(g_queue, al_get_display_event_source(g_display));
    al_register_event_source(g_queue, al_get_timer_event_source(g_timer));

    al_start_timer(g_timer);


}

bool Game::AppFinished(){
    return isAppFinished;
}

void Game::AppFinished(bool val){
    isAppFinished = val;
}



