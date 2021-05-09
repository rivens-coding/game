#ifndef SDL_UTILS__H_
#define SDL_UTILS__H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
             const char* WINDOW_TITLE, int SCREEN_WIDTH, int SCREEN_HEIGHT );
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
SDL_Texture* loadTexture( string path, SDL_Renderer* renderer );



#endif // SDL_UTILS__H_
