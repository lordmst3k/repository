#include "main_window.h"
#include "constants.h"

#include <iostream>
#include <SDL_image.h>

namespace solar {

MainWindow::MainWindow() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError();
    exit(1);
  }

  // Set texture filtering to linear
  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
  }

  // Create window
  window_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window_ == nullptr) {
    std::cout << "Window could not be created. SDL Error: " << SDL_GetError();
    exit(2);
  }

  // Create vsynced renderer for window
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer_ == nullptr) {
    std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError();
    exit(3);
  }

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError();
    exit(4);
  }
}

MainWindow::~MainWindow() {
  // Destroy SDL window	
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

SDL_Window* MainWindow::getWindow() {
  return window_;
}

SDL_Renderer* MainWindow::getRenderer() {
  return renderer_;
}

} // end namespace solar