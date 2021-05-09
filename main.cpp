#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "SDL_Utils.h"
#include "Game.h"
#include "Board.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    Game game(120,235,60,530);
    SDL_Event e;
    game.init();
    if ( game.initmusic() ) cout << " yes ";
    else cout << " no ";
    bool gamerun=true;
    game.render();
    while(gamerun)
    {
        if(SDL_WaitEvent(&e) == 0) continue;
        if( e.type == SDL_QUIT )
        {
            gamerun = false;
        }
        if ( e.type == SDL_MOUSEMOTION ) continue;
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE: gamerun=false;break;
                case SDLK_LEFT:
                    if(game.x.checkLeft())
                    {
                        game.x.Left();
                        Mix_PlayChannel(-1,game.merger,0);
                        game.x.init();
                    }
                    break;
                case SDLK_RIGHT:
                    if(game.x.checkRight())
                    {
                        game.x.Right();
                        Mix_PlayChannel(-1,game.merger,0);
                        game.x.init();
                    }
                    break;
                case SDLK_DOWN:
                    if(game.x.checkDown())
                    {
                        game.x.Down();
                        Mix_PlayChannel(-1,game.merger,0);
                        game.x.init();
                    }
                    break;
                case SDLK_UP:
                    if(game.x.checkUp())
                    {
                        game.x.Up();
                        Mix_PlayChannel(-1,game.merger,0);
                        game.x.init();
                    }
                    break;
                }
        }
    game.render();
    game.printdata();
    if( !game.x.checkUp() && !game.x.checkDown() && !game.x.checkRight() && !game.x.checkLeft()) gamerun=false;
    }
    waitUntilKeyPressed();
    game.destroy();
    return 0;
}
