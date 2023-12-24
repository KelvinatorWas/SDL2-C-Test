#include "game.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

SDL_Window* initSDL() {
  // Init
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("ERROR INITING SDL2");
    return NULL;
  }

  // Create Window
  SDL_Window* window = SDL_CreateWindow("SDL2 Template", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    printf("WINDOW couldnt have been made!");
    return NULL;
  }

  return window;
}

void handleEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0){
    if (e.type == SDL_QUIT) {
      exit(0);
    }
  }

}

void updateGame() {
  // update stuff
}

void renderGame(SDL_Renderer* renderer) {
  
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  
  // render stuff here
  

  SDL_RenderPresent(renderer);

}
