#include "simple_texture.h"
#include "sdl_wrappers.h"

#include <iostream>
#include <SDL_image.h>

namespace solar {
// Deallocates memory
SimpleTexture::~SimpleTexture() {
  free();
}

// Loads image at specified path
bool SimpleTexture::initFromFile(SDL_Renderer* renderer, std::string path) {
  //Get rid of preexisting texture
  free();

  //Load image at specified path
  sdl_wrapper::SDL_Surface_Safe surface(IMG_Load(path.c_str()));
  if (surface.get() == nullptr) {
    std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
    return false;
  }

  //Color key image
  SDL_SetColorKey(surface.get(), SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

  texture_.reset(SDL_CreateTextureFromSurface(renderer, surface.get()));
  if (texture_.get() == nullptr) {
    std::cout << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
    return false;
  }

  width_ = surface->w;
  height_ = surface->h;
}

// Deallocates texture
void SimpleTexture::free() {
  if (texture_.get() != nullptr) {
    texture_.reset(nullptr);
    width_ = 0;
    height_ = 0;
  }
}

// Renders texture at given point
void SimpleTexture::render(SDL_Renderer* renderer) {
  //Render to screen
  SDL_RenderCopy(renderer, texture_.get(), nullptr, nullptr);
}

void SimpleTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
  //Set rendering space and render to screen
  SDL_Rect renderQuad = { x, y, width_, height_ };

  //Set clip rendering dimensions
  if (clip != nullptr) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }

  //Render to screen
  SDL_RenderCopyEx(renderer, texture_.get(), clip, &renderQuad, angle, center, flip);
}

} // end namespace solar