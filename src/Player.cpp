#include  "Player.h"
#include "Global.h"

Player::Player(){

    playerSprite =  al_load_bitmap("data/player.bmp");
    al_convert_mask_to_alpha(playerSprite, al_map_rgb(255,0,255));

    frame = 0;
    animNum = 0;
    PlayerPosition.X = 200.0;
    PlayerPosition.Y = 0.0;
    Gravity = 5.0;
    direction = 1;
    Speed = 1.0;
    keys[0] = keys[1] = keys[2] = keys[3] = keys[4] = false;
    skistate = SKI_SIDESTOP;


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

        PlayerPosition.Y += (Speed + 5) * AbsoluteVal<float>( PlayerPosition.Y + SCREEN_HEIGHT);

    }else {

        float oldpos = PlayerPosition.Y;

        PlayerPosition.Y = oldpos;


    }

    if ( keys[KEY_LEFT] && direction == 3 && skistate == SKI_SIDESTOP){
        PlayerPosition.X -= Speed * AbsoluteVal<float>( PlayerPosition.X + SCREEN_HEIGHT);
    }

       if ( keys[KEY_RIGHT] && direction == 4 && skistate == SKI_SIDESTOP){
        PlayerPosition.X += Speed * AbsoluteVal<float>( PlayerPosition.X + SCREEN_HEIGHT);
    }

    //std::cout << "Direction " << direction;
    //system("cls");
}

void Player::Draw(ALLEGRO_BITMAP *buffer){

    if(direction ==  2){
    al_draw_bitmap_region(playerSprite,64,0,32,32, Cast<int>(PlayerPosition.X) ,Cast<int>(PlayerPosition.Y),NULL);

    }else if(direction == 1) {

        al_draw_bitmap_region(playerSprite,0,0,32,32, Cast<int>(PlayerPosition.X) ,Cast<int>(PlayerPosition.Y),NULL);

    }else if(direction == 3){

        al_draw_bitmap_region(playerSprite,0,0,32,32, Cast<int>(PlayerPosition.X) ,Cast<int>(PlayerPosition.Y),NULL);

    }else if( direction == 4){

        al_draw_bitmap_region(playerSprite,0,0,32,32, Cast<int>(PlayerPosition.X) ,Cast<int>(PlayerPosition.Y),NULL);

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
