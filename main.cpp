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
    Mix_PlayMusic( game.music, -1 );
    SDL_Event e;
    while(gamerun)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
            {
                if( !game.insideStartButton() ) { }
                else
                {
                    switch( e.type )
                    {
                        case SDL_MOUSEMOTION:
                            break;

                        case SDL_MOUSEBUTTONDOWN:
                            Mix_PlayChannel(-1,game.merger,0);
                            game.render();
                            game.Start(e,gamerun,start);
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

                if(!game.insideExitButton()) {}
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
    game.destroy();
    return 0;
}
