#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

const int FAILED = -1;

int main() {
  
  bool running = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Error While initing window!!");
    return FAILED;
  }
  
  SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
  
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  
  if (!surface) {
    printf("Error [ Failed to make WINDOW surface]");
    return FAILED;
  }

  printf("Hello World!\n");
  
  SDL_UpdateWindowSurface(window);
  
  while (running) {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) { // Check each event

      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    SDL_UpdateWindowSurface(window);// Update Display
  }

  return 0;
}
