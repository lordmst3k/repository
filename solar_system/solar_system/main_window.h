#pragma once

#include <SDL.h>
#include <memory>

namespace solar {
  class MainWindow final {
  public:
    MainWindow();
    ~MainWindow();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();

  private:
    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
  };
} // end namespace solar