//
//  main.cpp
//  Task_17
//
//  Created by Hayden Flynn Whiteford on 19/10/2023.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstdlib>
#include <ctime>

int main(int argc, const char * argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Create a window
    SDL_Window* window = SDL_CreateWindow("Background Image Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Load the image using SDL_image
    SDL_Surface* imageSurface = IMG_Load("background.jpg");

    if (imageSurface == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to load image! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Create a texture from the loaded image
    SDL_Texture* backgroundImage = SDL_CreateTextureFromSurface(renderer, imageSurface);

    if (backgroundImage == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Load the combined image that contains all three smaller images
    SDL_Surface* combinedImageSurface = IMG_Load("combined_image.jpg");

    if (combinedImageSurface == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to load combined image! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create a texture from the combined image
    SDL_Texture* combinedImageTexture = SDL_CreateTextureFromSurface(renderer, combinedImageSurface);

    if (combinedImageTexture == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to create texture from combined image! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    
    // Define SDL_Rect structures for each tile
    SDL_Rect tile1Rect = {0, 0, 250, 500}; // Position and dimensions of the first tile (left half)
    SDL_Rect tile2Rect = {250, 0, 250, 250}; // Position and dimensions of the second tile (top right)
    SDL_Rect tile3Rect = {250, 250, 250, 250}; // Position and dimensions of the third tile (bottom right)
    
    //create destination rectangles which we can manipulate the position of
    SDL_Rect tile1RectDest = {std::rand() % 600, std::rand() % 800, 250, 500};
    SDL_Rect tile2RectDest = {std::rand() % 600, std::rand() % 800, 250, 250};
    SDL_Rect tile3RectDest = {std::rand() % 600, std::rand() % 800, 250, 250};
    
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    bool quit = false;
    SDL_Event event;
    bool ShowBackground = true;
    bool ShowTile1 = true;
    bool ShowTile2 = true;
    bool ShowTile3 = true;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_0:
                            //turn off or on background image
                            if (ShowBackground){
                                ShowBackground = false;
                            }
                            else {
                                ShowBackground = true;
                            }
                            break;
                        case SDLK_1:
                            //turn off or on tile
                            if (ShowTile1){
                                ShowTile1 = false;
                            }
                            else {
                                tile1RectDest.x = std::rand() % 600;
                                tile1RectDest.y = std::rand() % 800;
                                ShowTile1 = true;
                            }
                            break;
                        case SDLK_2:
                            //turn off or on tile
                            if (ShowTile2){
                                ShowTile2 = false;
                            }
                            else {
                                tile2RectDest.x = std::rand() % 600;
                                tile2RectDest.y = std::rand() % 800;
                                ShowTile2 = true;
                            }
                            break;
                        case SDLK_3:
                            //turn off or on tile
                            if (ShowTile3){
                                ShowTile3 = false;
                            }
                            else {
                                tile3RectDest.x = std::rand() % 600;
                                tile3RectDest.y = std::rand() % 800;
                                ShowTile3 = true;
                            }
                            break;
                    }
                    break;
            }
        }
        
        SDL_RenderClear(renderer); // Clear the renderer

        // Render the background image
        if (ShowBackground){
            SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);
        }
        if (ShowTile1){
            SDL_RenderCopy(renderer, combinedImageTexture, &tile1Rect, &tile1RectDest);
        }
        if (ShowTile2){
            SDL_RenderCopy(renderer, combinedImageTexture, &tile2Rect, &tile2RectDest);
        }
        if (ShowTile3){
            SDL_RenderCopy(renderer, combinedImageTexture, &tile3Rect, &tile3RectDest);
        }



        // Other rendering code (e.g., game objects) goes here

        SDL_RenderPresent(renderer); // Update the screen
    }
    
    // Cleanup and quit SDL
    
    // Free the surface, as it's no longer needed
    SDL_FreeSurface(imageSurface);
    SDL_DestroyTexture(backgroundImage);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
     
    return 0;
}
