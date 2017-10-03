#pragma once

#include <memory>
#include <string>
#include <SDL.h>
#include <SDL_render.h>

#include "sdl_wrappers.h"

namespace solar {
  class SimpleTexture {
  public:
    // Deallocates memory
    ~SimpleTexture();

    // Loads image at specified path
    bool initFromFile(SDL_Renderer* renderer, std::string path);

    // Deallocates texture
    void free();

    // Stetch render texture
    void render(SDL_Renderer* renderer);

    // Renders texture at given point
    void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

  private:

     sdl_wrapper::SDL_Texture_Safe texture_;

    int width_ = 0;
    int height_ = 0;
  };
}