
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

#define T_ALIGN_CENTER ALLEGRO_ALIGN_CENTRE
#define T_ALIGN_LEFT ALLEGRO_ALIGN_LEFT
#define T_ALIGN_RIGHT ALLEGRO_ALIGN_RIGHT

template<class T>
T AbsoluteVal(T Number){

    return (abs(Number) == Number) ? 1 : -1;

}

template<class T>
T Cast(T num){

    return static_cast<T>(num);
}
