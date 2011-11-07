#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>



class Game {

    public:
    ALLEGRO_TIMER *g_timer;
    ALLEGRO_DISPLAY *g_display;
    ALLEGRO_EVENT_QUEUE *g_queue;
    ALLEGRO_BITMAP *g_screen;

    int W();
    void W(int val);

    int H();
    void H(int val);

    int Pallete();
    void Pallete(int bpp);

    std::string WindowCaption(); // return as string
    //char WindowCaption(); // return as C-String
    void WindowCaption(std::string str);


    void SetTimer(int ticks);




    Game();
    Game(int width, int height, int bpp, std::string title, bool fullscreen);
    ~Game();

    private:
    void Start(void);
    void InitWindow(int width, int height, int bpp, std::string title);

    void InitEvents(void);

    int Width;
    int Height;
    int Bpp;
    bool isFullScreen;
    std::string Title;




};
