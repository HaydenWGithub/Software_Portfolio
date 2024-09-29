//
//  main.cpp
//  Task15Lab
//
//  Created by Hayden Flynn Whiteford on 27/9/2023.
//

#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    
    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    bool quit = false;
    SDL_Event event;
    SDL_Color backgroundColor = {0, 255, 0, 255}; // Initial background color: Green

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            //only ending the loop when the SDL_QUIT event is triggered by closing the window
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_r) {
                    // Change background color to a random color
                    backgroundColor.r = std::rand() % 256;
                    backgroundColor.g = std::rand() % 256;
                    backgroundColor.b = std::rand() % 256;
                }
            }
        }

        // Set the background color
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
        SDL_RenderClear(renderer);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
