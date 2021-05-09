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
    bool gamerun=true;
    bool start=true;
    Game game(120,235,60,530);
    game.init();
    game.menu();
    SDL_Event e;
    while(gamerun)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {
                //Get mouse position
                int x, y;
                SDL_GetMouseState( &x, &y );

                //Check if mouse is in button
                bool inside = true;

                //Mouse is left of the button
                if( x < 400 )
                {
                    inside = false;
                }
                //Mouse is right of the button
                else if( x > 600 )
                {
                    inside = false;
                }
                //Mouse above the button
                else if( y < 250 )
                {
                    inside = false;
                }
                //Mouse below the button
                else if( y > 290 )
                {
                    inside = false;
                }

                if( !inside )
                {
                    continue;
                }
                //Mouse is inside button
                else
                {
                    //Set mouse over sprite
                    switch( e.type )
                    {
                        case SDL_MOUSEMOTION:
                            break;

                        case SDL_MOUSEBUTTONDOWN:
                            Mix_PlayChannel(-1,game.merger,0);
                            game.render();
                            while(start)
                            {
                                if(SDL_WaitEvent(&e) == 0) continue;
                                if( e.type == SDL_QUIT )
                                {
                                    start = false;
                                    gamerun = false;
                                }
                                if ( e.type == SDL_MOUSEMOTION ) continue;
                                if (e.type == SDL_KEYDOWN)
                                {
                                    switch (e.key.keysym.sym)
                                        {
                                        case SDLK_ESCAPE: gamerun=false;start=false;break;
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
                            if( !game.x.checkUp() && !game.x.checkDown() && !game.x.checkRight() && !game.x.checkLeft()) {gamerun=false;start=false;}
                            }
                            break;

                        case SDL_MOUSEBUTTONUP:
                        break;
                    }
                }
            }
        }
    }
    waitUntilKeyPressed();
    game.destroy();
    return 0;
}
