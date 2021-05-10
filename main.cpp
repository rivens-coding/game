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
                if( !game.insideStartButton() )
                {
                    //continue;
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

                if( !game.insideHelpButton() )
                {
                    //continue;
                }
                else
                {
                    switch (e.type)
                    {
                        case SDL_MOUSEMOTION:
                            break;

                        case SDL_MOUSEBUTTONDOWN:
                        {
                            Mix_PlayChannel(-1,game.merger,0);
                            SDL_RenderCopy( game.renderer, game.backgroundTxt, NULL, NULL);
                            SDL_RenderCopy( game.renderer, game.huongdanTxt, NULL, NULL);
                            SDL_RenderCopy( game.renderer, game.backTxt, NULL, &game.rectBack);
                            SDL_RenderPresent(game.renderer);
                            bool flag = true;
                            while(flag)
                            {
                                while( SDL_PollEvent( &e ) != 0 )
                                {
                                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                                    {
                                        if( !game.insideBackButton() )
                                        {
                                            //continue;
                                        }
                                        //Mouse is inside button
                                        else
                                        {
                                            switch (e.type)
                                            {
                                                case SDL_MOUSEMOTION:
                                                    break;
                                                case SDL_MOUSEBUTTONDOWN:
                                                    Mix_PlayChannel(-1,game.merger,0);
                                                    game.menu();
                                                    flag=false;
                                                    break;
                                                case SDL_MOUSEBUTTONUP:
                                                    break;
                                            }
                                        }
                                    }
                                }
                            }
                            continue;
                        }
                        case SDL_MOUSEBUTTONUP:
                            break;
                    }
                }

                if(!game.insideExitButton())
                {

                }
                else
                {
                    switch (e.type)
                    {
                        case SDL_MOUSEMOTION:
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            Mix_PlayChannel(-1,game.merger,0);
                            gamerun=false;
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
