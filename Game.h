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

    const char* backgroundImagePath = "background.png";
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
    const char* startPath = "start.png";
    const char* helpPath = "help.png";
    const char* exitPath = "exit.png";
    const char* huongdanPath = "huongdan.png";
    const char* backPath = "back.png" ;
    const char* winPath = "win.png";
    const char* losePath = "lose.png";
    const char* newgamePath = "Newgame.png";

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
    SDL_Texture* StartButton;
    SDL_Texture* HelpButton;
    SDL_Texture* ExitButton;
    SDL_Texture* huongdanTxt;
    SDL_Texture* backTxt;
    SDL_Texture* winTxt;
    SDL_Texture* loseTxt;
    SDL_Texture* newgameTxt;

    Board x;

    SDL_Rect rect;
    SDL_Rect rectb;
    SDL_Rect rectStart;
    SDL_Rect rectHelp;
    SDL_Rect rectExit;
    SDL_Rect rectBack;
    SDL_Rect rectLose;

    Game(int _w1,int _x,int _y,int _w2 )
    {
        rect.w = _w1;
        rect.h = _w1;
        rectb.x = _x;
        rectb.y = _y;
        rectb.w = _w2;
        rectb.h = _w2;

        rectStart.x=400;
        rectStart.y=240;
        rectStart.w=200;
        rectStart.h=50;

        rectHelp.x=400;
        rectHelp.y=300;
        rectHelp.w=200;
        rectHelp.h=50;

        rectExit.x=400;
        rectExit.y=360;
        rectExit.w=200;
        rectExit.h=50;

        rectBack.x=0;
        rectBack.y=0;
        rectBack.w=100;
        rectBack.h=50;

        rectLose.x=0;
        rectLose.y=100;
        rectLose.w=1000;
        rectLose.h=200;
    };

    void init();

    bool initmusic();

    void clearScreen();

    void render();

    void renderGameOver();

    void renderWIN();

    void destroy();

    void printdata();

    void menu();

    bool insideStartButton();

    bool insideHelpButton();

    bool insideExitButton();

    bool insideBackButton();

    bool checkLose();

    bool checkWin();

    void Start(SDL_Event e, bool& gamerun, bool& start);

};
#endif
