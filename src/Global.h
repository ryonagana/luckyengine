#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

#define SCREEN_WIDTH_CENTER SCREEN_WIDTH / 2
#define SCREEN_HEIGHT_CENTER SCREEN_HEIGHT / 2

#define T_ALIGN_CENTER ALLEGRO_ALIGN_CENTRE
#define T_ALIGN_LEFT ALLEGRO_ALIGN_LEFT
#define T_ALIGN_RIGHT ALLEGRO_ALIGN_RIGHT

#define DEBUG true

#define GAME_MAJOR     "0"
#define GAME_MINOR     "0"
#define GAME_VERSION   "2"
#define GAME_REVISION  "0"


const float LogicPerSecond =  120.0f;
const float FramesPerSecond = 60.0f;



#define debug_print(format, ...) do { if (DEBUG) {    printf(format, __VA_ARGS__); } } while (0)


template<class T>
T AbsoluteVal(T Number){

    return (abs(Number) == Number) ? 1 : -1;

}

template<class T>
T Cast(T num){

    return static_cast<T>(num);
}



