#include  "Player.h"
#include "Global.h"

void Player::InitPlayer(){

    spr =  al_load_bitmap("data/player.bmp");
    al_convert_mask_to_alpha(spr, al_map_rgb(255,0,255));

    frame = 0;
    animNum = 0;
    PlayerPosition.X = 200.0;
    PlayerPosition.Y = 0.0;
    Gravity = 5.0;
    direction = 1;
    Speed = 1.0;
    keys[0] = keys[1] = keys[2] = keys[3] = keys[4] = false;
    skistate = SKI_SIDESTOP;
    bound_x = 18;
    bound_y = 18;


}

void Player::Update(uint64_t time){


    if(keys[KEY_UP]){

        direction = 1;
        skistate = SKI_SIDESTOP;

    }

    if ( keys[KEY_DOWN]){

        direction =  2;
        skistate = SKI_SLIDINGDOWN;

    }

    if ( keys[KEY_LEFT] ){
        direction = 3;
        skistate = SKI_SIDESTOP;

    }

    if ( keys[KEY_RIGHT]){
        direction = 4;
        skistate = SKI_SIDESTOP;
    }


    //PlayerPosition.Y += Speed * AbsoluteVal<float>( PlayerPosition.Y - SCREEN_HEIGHT);
    if(skistate == SKI_SLIDINGDOWN || skistate == SKI_DIAGONAL_L || skistate == SKI_DIAGONAL_R ) {

        Position.Y += (Speed + 6 ) * AbsoluteVal<float>( Position.Y + SCREEN_HEIGHT / 2);

    }else {

        float oldpos = Position.Y;

        Position.Y = oldpos;


    }

    if( keys[KEY_UP] && direction == 1 && skistate == SKI_SIDESTOP ){

        Position.Y -= Speed * AbsoluteVal<float>( Position.Y - 2);


    }else {

        float oldpos = Position.Y;
        Position.Y = oldpos;

    }

    if ( keys[KEY_LEFT] && direction == 3 && skistate == SKI_SIDESTOP){
        Position.X -= Speed * AbsoluteVal<float>( Position.X + SCREEN_HEIGHT);
    }

       if ( keys[KEY_RIGHT] && direction == 4 && skistate == SKI_SIDESTOP){
        Position.X += Speed * AbsoluteVal<float>( Position.X + SCREEN_HEIGHT);
    }

    //std::cout << "Direction " << direction;
    //system("cls");
}

void Player::Draw(ALLEGRO_BITMAP *buffer){

    if(direction ==  2){
    al_draw_bitmap_region(spr,64,0,32,32, Cast<int>(Position.X) ,Cast<int>(Position.Y),0x0);

    }else if(direction == 1) {

        al_draw_bitmap_region(spr,0,0,32,32, Cast<int>(Position.X) ,Cast<int>(Position.Y),0x0);

    }else if(direction == 3){

        al_draw_bitmap_region(spr,0,0,32,32, Cast<int>(Position.X) ,Cast<int>(Position.Y), ALLEGRO_FLIP_HORIZONTAL );

    }else if( direction == 4){

        al_draw_bitmap_region(spr,0,0,32,32, Cast<int>(Position.X) ,Cast<int>(Position.Y),0x0);

    }

}

void Player::KeyboardUpdate(ALLEGRO_EVENT *ev){


     switch(ev->type){

         case ALLEGRO_EVENT_KEY_UP:
            switch(ev->keyboard.keycode){

                case ALLEGRO_KEY_LEFT:
                    keys[KEY_LEFT] = false;
                    break;

                case ALLEGRO_KEY_UP:
                    keys[KEY_UP] = false;
                    break;

                case ALLEGRO_KEY_DOWN:
                    keys[KEY_DOWN] = false;
                    break;


                case ALLEGRO_KEY_RIGHT:
                    keys[KEY_RIGHT] = false;
                    break;

                }
                break;

            case ALLEGRO_EVENT_KEY_DOWN:

                switch( ev->keyboard.keycode){

                    case ALLEGRO_KEY_LEFT:
                        keys[KEY_LEFT] = true;
                        break;

                    case ALLEGRO_KEY_UP:
                        keys[KEY_UP] = true;
                        break;

                    case ALLEGRO_KEY_DOWN:
                        keys[KEY_DOWN] = true;
                        break;


                    case ALLEGRO_KEY_RIGHT:
                        keys[KEY_RIGHT] = true;
                        break;



                }




     }

}
