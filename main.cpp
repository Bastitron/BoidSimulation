#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Boid Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 0, 0));

    SDL_UpdateWindowSurface(window);

    SDL_Event event; bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit = event.type == SDL_QUIT;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
