#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

SDL_Window* initSDL();

void handleEvents();
void updateGame();
void renderGame(SDL_Renderer* renderer);

#endif

