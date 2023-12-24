#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "./game/game.h"

const int FAILED = -1;

void eventLoop (SDL_Event event, bool *running) {
  while (SDL_PollEvent(&event)) { // Check each event

    if (event.type == SDL_QUIT) {
      *running = false;
    }
  }
}

int main() {
  SDL_Window* window = initSDL();

  if (window == NULL) {
    return 1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == NULL) {       
    printf("Error While initializing surface!");
    return 1;
  }

  int quit = 0;

  while (!quit) {
    handleEvents();
    updateGame();
    renderGame(renderer);
    SDL_Delay(16); // Around 60 fps later fix this using time. and implement Delta Time
  }

  // De-init
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
} 
