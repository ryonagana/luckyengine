#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Position.h"
#include <cmath>

class Player {

    public:

        Player();
        Player(int initX, int initY);

        enum playerKeys { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};
        enum SkiState { SKI_SLIDINGDOWN, SKI_SIDESTOP, SKI_DIAGONAL_L, SKI_DIAGONAL_R   };

        Position<float> PlayerPosition;
        ALLEGRO_BITMAP *playerSprite;
        int animNum;
        int frame;
        float Gravity;
        float Speed;

        uint32_t direction;
        int skistate;



        void Draw(ALLEGRO_BITMAP *buffer);
        void Update();
        void KeyboardUpdate(ALLEGRO_EVENT *ev );
        void Update(uint64_t time);

    private:

    bool keys[4];


};
