#ifndef GAME__H_
#define GAME__H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "SDL_Utils.h"
#include "Board.h"


class Game {
public:
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 650;
    const char* WINDOW_TITLE = "2048";

    const char* backgroundImagePath = "bikiniBottom.jpg";
    const char* boardImagePath = "board.jpg";
    const char* imagePath_2 = "2.png";
    const char* imagePath_4 = "4.png";
    const char* imagePath_8 = "8.png";
    const char* imagePath_16 = "16.png";
    const char* imagePath_32 = "32.png";
    const char* imagePath_64 = "64.png";
    const char* imagePath_128 = "128.png";
    const char* imagePath_256 = "256.png";
    const char* imagePath_512 = "512.png";
    const char* imagePath_1024 = "1024.png";
    const char* imagePath_2048 = "2048.png";
    const char* gameOverImagePath = "balloons.png";

    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Music* music;
    Mix_Chunk* win;
    Mix_Chunk* lose;
    Mix_Chunk* merger;

    SDL_Texture* backgroundTxt;
    SDL_Texture* boardTxt;
    SDL_Texture* image_2;
    SDL_Texture* image_4;
    SDL_Texture* image_8;
    SDL_Texture* image_16;
    SDL_Texture* image_32;
    SDL_Texture* image_64;
    SDL_Texture* image_128;
    SDL_Texture* image_256;
    SDL_Texture* image_512;
    SDL_Texture* image_1024;
    SDL_Texture* image_2048;
    SDL_Texture* gameOverTxt;

    Board x;

    SDL_Rect rect;
    SDL_Rect rectb;

    Game(int _w1,int _x,int _y,int _w2 )
    {
        rect.w = _w1;
        rect.h = _w1;
        rectb.x = _x;
        rectb.y = _y;
        rectb.w = _w2;
        rectb.h = _w2;
    };

    void init();

    bool initmusic();

    void clearScreen();

    void render();

    void renderGameOver();

    void destroy();

    void printdata();

    void menu();

};
#endif
