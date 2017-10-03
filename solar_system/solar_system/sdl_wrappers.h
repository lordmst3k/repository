#pragma once

#include <SDL.h>

namespace solar {
namespace sdl_wrapper {

// Exception safe wrappers for various SDL classes.
// Each is responsible for managing a single pointer of SDL state.

class SDL_Surface_Safe {
public:
  SDL_Surface_Safe() { ; }
  SDL_Surface_Safe(SDL_Surface* surface) : surface_(surface) { ; }

  ~SDL_Surface_Safe() {
    free();
  }

  SDL_Surface* operator->() {
    return get();
  }
  SDL_Surface* get() { return surface_; }

  void free() {
    if (surface_ != nullptr) {
      SDL_FreeSurface(surface_);
      surface_ = nullptr;
    }
  }

  void reset(SDL_Surface* surface) {
    surface_ = surface;
  }

private:
  SDL_Surface* surface_ = nullptr;
};

class SDL_Texture_Safe {
public:
  SDL_Texture_Safe() { ; }
  SDL_Texture_Safe(SDL_Texture* texture) : texture_(texture) { ; }

  ~SDL_Texture_Safe() {
    free();
  }

  SDL_Texture* operator->() {
    return get();
  }
  SDL_Texture* get() { return texture_; }

  void free() {
    if (texture_ != nullptr) {
      SDL_DestroyTexture(texture_);
      texture_ = nullptr;
    }
  }

  void reset(SDL_Texture* texture) {
    texture_ = texture;
  }

private:
  SDL_Texture* texture_ = nullptr;
};
} // end namespace sdl_wrapper
} // end namespace solar