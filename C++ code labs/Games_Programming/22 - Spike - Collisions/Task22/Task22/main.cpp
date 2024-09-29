//
//  main.cpp
//  Task22
//
//  Created by Hayden Flynn Whiteford on 29/10/2023.
//
#include <SDL2/SDL.h>

class Box {
public:
    int x, y, width, height;
    Box(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    bool intersects(const Box& other) const {
        return x < other.x + other.width && x + width > other.x &&
               y < other.y + other.height && y + height > other.y;
    }
};

class Circle {
public:
    int x, y, radius;
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

    bool intersects(const Circle& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        int distanceSquared = dx * dx + dy * dy;
        int radiiSum = radius + other.radius;
        return distanceSquared < radiiSum * radiiSum;
    }
};

void DrawCircle(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;  // horizontal offset
            int dy = radius - h;  // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}



const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Collision Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Box fixedBox(200, 200, 100, 100);
    Box movingBox(0, 0, 50, 50);

    Circle movingCircle(SCREEN_WIDTH - 30, 0, 30);

    bool quit = false;
    SDL_Event e;
    int counter = 0;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // For simplicity, we'll just move the movingBox and movingCircle diagonally.
        counter++;
        //I've added a simple counter system here, so that we can adjust the speed at which the shapes
        //move. When I added the Circle, everything actually ran slower, so this is somewhat redundant,
        //but still a cool feature.
        if (counter == 1){
            movingBox.x ++;
            movingBox.y ++;

            movingCircle.x --;
            movingCircle.y ++;
            counter = 0;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Draw the fixedBox
        SDL_Rect fixedRect = {fixedBox.x, fixedBox.y, fixedBox.width, fixedBox.height};
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);  // Blue
        SDL_RenderFillRect(renderer, &fixedRect);

        // Draw the movingBox and change color if intersecting
        SDL_Rect movingRect = {movingBox.x, movingBox.y, movingBox.width, movingBox.height};
        if (movingBox.intersects(fixedBox)) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);  // Red for collision
        } else {
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);  // Green otherwise
        }
        SDL_RenderFillRect(renderer, &movingRect);

        // Draw the moving Circle and change color if it intersects
        Circle fixedCircle(400, 200, 50);
        if (movingCircle.intersects(fixedCircle)) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);  // Red for collision
        } else {
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);  // Green otherwise
        }
        DrawCircle(renderer, movingCircle.x, movingCircle.y, movingCircle.radius);

        // Similarly, draw the fixedCircle (you can use a different color if desired).
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);  // Blue for the fixed circle
        DrawCircle(renderer, fixedCircle.x, fixedCircle.y, fixedCircle.radius);


        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

