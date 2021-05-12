#include "Game.h"
#include "Board.h"
#include<iostream>

void Game::init() {
    initSDL(window, renderer, WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
    music = Mix_LoadMUS( "music.wav" );
    win = Mix_LoadWAV( "win.wav" );
    lose = Mix_LoadWAV( "lose.wav" );
    merger = Mix_LoadWAV( "merge.wav" );

    backgroundTxt = loadTexture(backgroundImagePath, renderer);
    boardTxt = loadTexture(boardImagePath, renderer);
    image_2 = loadTexture(imagePath_2, renderer);
    image_4 = loadTexture(imagePath_4, renderer);
    image_8 = loadTexture(imagePath_8, renderer);
    image_16 = loadTexture(imagePath_16, renderer);
    image_32 = loadTexture(imagePath_32, renderer);
    image_64 = loadTexture(imagePath_64, renderer);
    image_128 = loadTexture(imagePath_128, renderer);
    image_256 = loadTexture(imagePath_256, renderer);
    image_512 = loadTexture(imagePath_512, renderer);
    image_1024 = loadTexture(imagePath_1024, renderer);
    image_2048 = loadTexture(imagePath_2048, renderer);
    StartButton = loadTexture(startPath, renderer);
    HelpButton = loadTexture(helpPath, renderer);
    ExitButton = loadTexture(exitPath ,renderer);
    huongdanTxt = loadTexture(huongdanPath, renderer);
    backTxt = loadTexture(backPath, renderer);
    winTxt = loadTexture(winPath, renderer);
    loseTxt = loadTexture(losePath, renderer);
    newgameTxt = loadTexture(newgamePath, renderer);

    for (int i=1;i<=2;i++)
    {
        x.init();
    }

}

void Game::clearScreen()
{
    SDL_RenderClear(renderer);
}

void Game::render()
{
    clearScreen();
    SDL_RenderCopy( renderer, backgroundTxt, NULL, NULL);

    SDL_RenderCopy( renderer, boardTxt, NULL, &rectb );

    for(int i = 0 ; i < 4 ;i++ )
    {
        for (int j = 0 ; j < 4;j++ )
        {
            rect.x= j*120 + (j+1) * 10 +235;
            rect.y= i*120 + (i+1) *10 +60;
            if(x.board[i][j]==0) continue;
            switch(x.board[i][j]) {
                case 2: SDL_RenderCopy( renderer, image_2, NULL, &rect ); break;
                case 4: SDL_RenderCopy( renderer, image_4, NULL, &rect ); break;
                case 8: SDL_RenderCopy( renderer, image_8, NULL, &rect ); break;
                case 16: SDL_RenderCopy( renderer, image_16, NULL, &rect ); break;
                case 32: SDL_RenderCopy( renderer, image_32, NULL, &rect ); break;
                case 64: SDL_RenderCopy( renderer, image_64, NULL, &rect ); break;
                case 128: SDL_RenderCopy( renderer, image_128, NULL, &rect ); break;
                case 256: SDL_RenderCopy( renderer,image_256, NULL, &rect ); break;
                case 512: SDL_RenderCopy( renderer, image_512, NULL, &rect ); break;
                case 1024: SDL_RenderCopy( renderer, image_1024, NULL, &rect ); break;
                case 2048: SDL_RenderCopy( renderer, image_2048, NULL, &rect ); break;
            }
        }
    }

    SDL_RenderPresent( renderer );
}

void Game::renderGameOver()
{
    clearScreen();
    SDL_RenderCopy( renderer, backgroundTxt, NULL, NULL);
    SDL_RenderCopy( renderer, loseTxt, NULL, &rectLose);
    SDL_RenderCopy( renderer, newgameTxt, NULL, &rectHelp);
    SDL_RenderCopy( renderer, ExitButton, NULL, &rectExit);
    SDL_RenderPresent( renderer );
}

void Game::renderWIN()
{
    clearScreen();
    SDL_RenderCopy( renderer, backgroundTxt, NULL, NULL);
    SDL_RenderCopy( renderer, winTxt, NULL, &rectLose);
    SDL_RenderCopy( renderer, newgameTxt, NULL, &rectHelp);
    SDL_RenderCopy( renderer, ExitButton, NULL, &rectExit);
    SDL_RenderPresent( renderer );
}

void Game::destroy()
{
    SDL_DestroyTexture( boardTxt );
    SDL_DestroyTexture( backgroundTxt );
    SDL_DestroyTexture( image_2 );
    SDL_DestroyTexture( image_4 );
    SDL_DestroyTexture( image_8 );
    SDL_DestroyTexture( image_16 );
    SDL_DestroyTexture( image_32 );
    SDL_DestroyTexture( image_64 );
    SDL_DestroyTexture( image_128 );
    SDL_DestroyTexture( image_256 );
    SDL_DestroyTexture( image_512 );
    SDL_DestroyTexture( image_1024 );
    SDL_DestroyTexture( image_2048 );
    SDL_DestroyTexture( StartButton );
    SDL_DestroyTexture( HelpButton );
    SDL_DestroyTexture( ExitButton );
    SDL_DestroyTexture( huongdanTxt) ;
    SDL_DestroyTexture( backTxt) ;
    SDL_DestroyTexture (winTxt) ;
    SDL_DestroyTexture (loseTxt) ;
    SDL_DestroyTexture (newgameTxt);

    Mix_FreeChunk(win);
    Mix_FreeChunk(lose);
    Mix_FreeChunk(merger);
    win = NULL;
    lose = NULL;
    merger = NULL;
    Mix_FreeMusic(music);
    music = NULL;

    quitSDL(window, renderer);
}

bool Game::initmusic()
{
    bool success = true;
    if( music == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    //Load sound effects
    if( win == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


    if( lose == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


    if( merger == NULL )
    {
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    return success;
}

void Game::menu()
{
    clearScreen();
    SDL_RenderCopy( renderer, backgroundTxt, NULL, NULL);
    SDL_RenderCopy( renderer, StartButton, NULL, &rectStart);
    SDL_RenderCopy( renderer, HelpButton, NULL, &rectHelp);
    SDL_RenderCopy( renderer, ExitButton, NULL, &rectExit);
    SDL_RenderPresent( renderer );
}

bool Game::insideStartButton()
{
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
    return inside;
}

bool Game::insideHelpButton()
{
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
    else if( y < 300 )
    {
        inside = false;
    }
    //Mouse below the button
    else if( y > 350 )
    {
        inside = false;
    }
    return inside;
}

bool Game::insideBackButton()
{
    int x, y;
    SDL_GetMouseState( &x, &y );

    //Check if mouse is in button
    bool inside = true;

    if( x > 100 )
    {
        inside = false;
    }
    //Mouse below the button
    else if( y > 50 )
    {
        inside = false;
    }
    return inside;
}

bool Game::insideExitButton()
{
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
    else if( y < 360 )
    {
        inside = false;
    }
    //Mouse below the button
    else if( y > 410 )
    {
        inside = false;
    }
    return inside;
}

bool Game::checkLose()
{
    if( !x.checkUp() && !x.checkDown() && !x.checkRight() && !x.checkLeft()) return true;
    return false;
}

bool Game::checkWin()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++ )
        {
            if (x.board[i][j] == 2048) return true;
        }
    }
    return false;
}

void Game::Start(SDL_Event e, bool& gamerun, bool& start)
{
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
                    if(x.checkLeft())
                    {
                        x.Left();
                        Mix_PlayChannel(-1,merger,0);
                        x.init();
                    }
                    break;
                case SDLK_RIGHT:
                    if(x.checkRight())
                    {
                        x.Right();
                        Mix_PlayChannel(-1,merger,0);
                        x.init();
                    }
                    break;
                case SDLK_DOWN:
                    if(x.checkDown())
                    {
                        x.Down();
                        Mix_PlayChannel(-1,merger,0);
                        x.init();
                    }
                    break;
                case SDLK_UP:
                    if(x.checkUp())
                    {
                        x.Up();
                        Mix_PlayChannel(-1,merger,0);
                        x.init();
                    }
                    break;
                }
        }
        render();
        if(checkLose())
        {
            gamerun=false;
            start=false;
            Mix_PlayChannel(-1,lose,0);
            renderGameOver();
            bool flag=true;
            while(flag)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {
                        if( !insideHelpButton() ) {}
                        else
                        {
                            switch (e.type)
                            {
                                case SDL_MOUSEMOTION:
                                    break;
                                case SDL_MOUSEBUTTONDOWN:
                                    Mix_PlayChannel(-1,merger,0);
                                    for(int i=0;i<4;i++)
                                    {
                                        for(int j=0;j<4;j++)
                                            x.board[i][j] =0;
                                    }
                                    for(int i=0;i<2;i++)
                                    {
                                        x.init();
                                    }
                                    start=true;
                                    gamerun=true;
                                    flag=false;
                                    Start(e,gamerun,start);
                                    break;
                                case SDL_MOUSEBUTTONUP:
                                    break;
                            }
                        }
                        if(!insideExitButton()) {}
                        else
                        {
                            switch(e.type)
                            {
                                case SDL_MOUSEMOTION:
                                    break;
                                case SDL_MOUSEBUTTONDOWN:
                                    flag = false;
                                    break;
                                case SDL_MOUSEBUTTONUP:
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if(checkWin())
        {
            gamerun=false;
            start=false;
            Mix_PlayChannel(-1,win,0);
            renderWIN();
            bool flag=true;
            while(flag)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {
                        if( !insideHelpButton() ) {}
                        else
                        {
                            switch (e.type)
                            {
                                case SDL_MOUSEMOTION:
                                    break;
                                case SDL_MOUSEBUTTONDOWN:
                                    Mix_PlayChannel(-1,merger,0);
                                    for(int i=0;i<4;i++)
                                    {
                                        for(int j=0;j<4;j++)
                                            x.board[i][j] =0;
                                    }
                                    for(int i=0;i<2;i++)
                                    {
                                        x.init();
                                    }
                                    start=true;
                                    gamerun=true;
                                    flag=false;
                                    Start(e,gamerun,start);
                                    break;
                                case SDL_MOUSEBUTTONUP:
                                    break;
                            }
                        }
                        if(!insideExitButton()) {}
                        else
                        {
                            switch(e.type)
                            {
                                case SDL_MOUSEMOTION:
                                    break;
                                case SDL_MOUSEBUTTONDOWN:
                                    flag = false;
                                    break;
                                case SDL_MOUSEBUTTONUP:
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}

