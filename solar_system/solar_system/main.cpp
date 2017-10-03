/*
main.cpp
copyright Dan Ludwig 2017
*/

#include <memory>

#include "main_window.h"
#include "simple_texture.h"

int main(int argc, char** argv) {
  // Create window
  auto window = std::make_unique<solar::MainWindow>();

  // Create background
  auto background = std::make_unique<solar::SimpleTexture>();
  background->initFromFile(window->getRenderer(), "resources/starfield/starfield1.png");

  bool quit = false;
  while (!quit) {
    // frame timer

    // events
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      //User requests quit
      if (e.type == SDL_QUIT) {
        exit(0);
      }

      //Handle input for the dot
      
    }

    // logic

    // rendering

		// clear screen
    SDL_SetRenderDrawColor(window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window->getRenderer());

    // render background
    background->render(window->getRenderer());

    //Update screen
    SDL_RenderPresent(window->getRenderer());
  }

  return 0;
}