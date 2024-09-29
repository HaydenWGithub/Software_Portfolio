//
//  main.cpp
//  Task16
//
//  Created by Hayden Flynn Whiteford on 10/10/2023.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>

const std::string backgroundMusicFile = "background_music.wav";
const std::string soundEffect1File = "sound_effect1.wav";
const std::string soundEffect2File = "sound_effect2.wav";
const std::string soundEffect3File = "sound_effect3.wav";

Mix_Music* backgroundMusic = nullptr;

void playBackgroundMusic() {
    Mix_PlayMusic(backgroundMusic, -1); // -1 means loop indefinitely
}

void pauseBackgroundMusic() {
    if (Mix_PausedMusic() == 1) {
        Mix_ResumeMusic();
    } else {
        Mix_PauseMusic();
    }
}

void playSoundEffect(const std::string& soundFile) {
    Mix_Chunk* soundEffect = Mix_LoadWAV(soundFile.c_str());
    if (soundEffect) {
        Mix_PlayChannel(-1, soundEffect, 0); // -1 means use the first available channel
    } else {
        std::cerr << "Error loading sound effect: " << Mix_GetError() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer initialization failed: " << Mix_GetError() << std::endl;
        return 1;
    }

    backgroundMusic = Mix_LoadMUS(backgroundMusicFile.c_str());
    if (!backgroundMusic) {
        std::cerr << "Error loading background music: " << Mix_GetError() << std::endl;
        return 1;
    }

    std::cout << "Press 0 to play/pause background music" << std::endl;
    std::cout << "Press 1 to play sound effect 1" << std::endl;
    std::cout << "Press 2 to play sound effect 2" << std::endl;
    std::cout << "Press 3 to play sound effect 3" << std::endl;
    std::cout << "Press Q to quit" << std::endl;

    playBackgroundMusic();

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_0:
                            pauseBackgroundMusic();
                            break;
                        case SDLK_1:
                            playSoundEffect(soundEffect1File);
                            break;
                        case SDLK_2:
                            playSoundEffect(soundEffect2File);
                            break;
                        case SDLK_3:
                            playSoundEffect(soundEffect3File);
                            break;
                        case SDLK_q:
                            quit = true;
                            break;
                    }
                    break;
            }
        }
    }

    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
