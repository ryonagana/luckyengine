#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <vector>


class gFont {

    public:

        std::string path;
        int size;

        gFont(std::string fpath, int size){

            font = al_load_ttf_font(fpath.c_str(),size,0);
            path = fpath;

        }

        ALLEGRO_FONT* Font(){
            return font;
        }

        int Size(){
            return size;
        }

        void draw(const char* text, ALLEGRO_COLOR color,  float x, float y, int alignment){

            al_draw_text(font, color, x,y, alignment, text);

        }

        void drawshadow(const char* text, ALLEGRO_COLOR color,  float x, float y, int alignment){

            al_draw_text(font, al_map_rgb(192,192,192) , x + 3,y + 3, alignment, text);
            al_draw_text(font, color, x,y, alignment, text);

        }

        void drawshadowcolor(const char* text, ALLEGRO_COLOR color, ALLEGRO_COLOR shade,  float x, float y, int alignment){

            al_draw_text(font, shade , x + 3,y + 3, alignment, text);
            al_draw_text(font, color, x,y, alignment, text);

        }



        private:
            ALLEGRO_FONT *font;



};

/*
template<class T>
class FontManager {


    public:
        static  T  load_font(std::string fpath, int size ){



        }





};
*/

