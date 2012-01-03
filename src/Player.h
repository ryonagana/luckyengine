#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Position.h"
#include "Object.h"
#include "Collidible.h"
#include <cmath>

static const float SpeedModifier[] = {0.5, 1.3, 1.9, 2.3, 3.0 };

enum playerKeys { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};
enum SkiState { SKI_SLIDINGDOWN, SKI_SIDESTOP, SKI_DIAGONAL_L, SKI_DIAGONAL_R   };

class Player : public Object {

    public:

        void InitPlayer();

        Player();
        Vector2<float> PlayerPosition;
        ALLEGRO_BITMAP *playerSprite;
        int animNum;
        int frame;
        float Gravity;
        Collidible Collision;


        uint32_t direction;
        int skistate;



        void Draw(ALLEGRO_BITMAP *buffer);
        void KeyboardUpdate(ALLEGRO_EVENT *ev );


        void Update(uint64_t time);

    private:

    bool keys[4];


};
