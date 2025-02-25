//
//  main.cpp
//  chords
//
//  Created by Shaunak Ghosh on 05/12/2024.
//

#include <iostream>
#include <unistd.h>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// generate key size and copy to renderer
void draw_key(SDL_Renderer *renderer, SDL_Texture *key, int x, int y) {
    SDL_Rect key_size = {x, y, 40, 40};
    SDL_RenderCopy(renderer, key, NULL, &key_size);
}

int main() {
    // init SDL
    SDL_Init(SDL_INIT_VIDEO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    // window and renderer
    bool running = true;
    const char *title = "Hello, World!";
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    int w = 800;
    int h = 400;
    
    SDL_Window *window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderClear(renderer);
    
    // music
    Mix_Chunk *Cma7 = Mix_LoadWAV("Cma7.wav");
    Mix_Chunk *Cm7 = Mix_LoadWAV("Cm7.wav");
    Mix_Chunk *Dma7 = Mix_LoadWAV("Dma7.wav");
    Mix_Chunk *Dm7 = Mix_LoadWAV("Dm7.wav");
    Mix_Chunk *Ema7 = Mix_LoadWAV("Ema7.wav");
    Mix_Chunk *Em7 = Mix_LoadWAV("Em7.wav");
    Mix_Chunk *Fma7 = Mix_LoadWAV("Fma7.wav");
    Mix_Chunk *Fm7 = Mix_LoadWAV("Fm7.wav");
    Mix_Chunk *C3 = Mix_LoadWAV("C3.wav");
    Mix_Chunk *D3 = Mix_LoadWAV("D3.wav");
    Mix_Chunk *E3 = Mix_LoadWAV("E3.wav");
    Mix_Chunk *F3 = Mix_LoadWAV("F3.wav");
    Mix_Chunk *C4 = Mix_LoadWAV("C4.wav");
    Mix_Chunk *D4 = Mix_LoadWAV("D4.wav");
    Mix_Chunk *E4 = Mix_LoadWAV("E4.wav");
    Mix_Chunk *F4 = Mix_LoadWAV("F4.wav");
    
    // textures
    SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("background.bmp"));
    SDL_Texture *key_empty = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_empty.bmp"));
    SDL_Texture *key_a_empty = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_a_empty.bmp"));
    SDL_Texture *key_j_empty = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_j_empty.bmp"));
    SDL_Texture *key_left_clicked = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_left_clicked.bmp"));
    SDL_Texture *key_right_clicked = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_right_clicked.bmp"));
    SDL_Texture *key_a_clicked = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_a_clicked.bmp"));
    SDL_Texture *key_j_clicked = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("key_j_clicked.bmp"));
    
    // background
    SDL_RenderCopy(renderer, background, NULL, NULL);
    
    // left keys
    draw_key(renderer, key_a_empty, 100, 225);
    draw_key(renderer, key_empty, 139, 225);
    draw_key(renderer, key_empty, 178, 225);
    draw_key(renderer, key_empty, 217, 225);
    draw_key(renderer, key_empty, 119, 186);
    draw_key(renderer, key_empty, 158, 186);
    draw_key(renderer, key_empty, 197, 186);
    draw_key(renderer, key_empty, 236, 186);
    
    // right keys
    draw_key(renderer, key_empty, 660, 225);
    draw_key(renderer, key_empty, 621, 225);
    draw_key(renderer, key_empty, 582, 225);
    draw_key(renderer, key_j_empty, 543, 225);
    draw_key(renderer, key_empty, 641, 186);
    draw_key(renderer, key_empty, 602, 186);
    draw_key(renderer, key_empty, 563, 186);
    draw_key(renderer, key_empty, 524, 186);
    SDL_RenderPresent(renderer);
    
    SDL_RaiseWindow(window);
    
    // event handling
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
            // TODO: play multiple sounds at the same time
            // keyboard presses
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    // left
                    case SDLK_a: Mix_PlayChannel(-1, Cma7, 0); SDL_Log("A key pressed!"); break;
                    case SDLK_w: Mix_PlayChannel(-1, Cm7, 0); SDL_Log("W key pressed!"); break;
                    case SDLK_s: Mix_PlayChannel(-1, Dma7, 0); SDL_Log("S key pressed!"); break;
                    case SDLK_e: Mix_PlayChannel(-1, Dm7, 0); SDL_Log("E key pressed!"); break;
                    case SDLK_d: Mix_PlayChannel(-1, Ema7, 0); SDL_Log("D key pressed!"); break;
                    case SDLK_r: Mix_PlayChannel(-1, Em7, 0); SDL_Log("R key pressed!"); break;
                    case SDLK_f: Mix_PlayChannel(-1, Fma7, 0); SDL_Log("F key pressed"); break;
                    case SDLK_t: Mix_PlayChannel(-1, Fm7, 0); SDL_Log("T key pressed"); break;
                    // right
                    case SDLK_j: Mix_PlayChannel(-1, C3, 0); SDL_Log("J key pressed"); break;
                    case SDLK_k: Mix_PlayChannel(-1, D3, 0); SDL_Log("K key pressed"); break;
                    case SDLK_l: Mix_PlayChannel(-1, E3, 0); SDL_Log("L key pressed"); break;
                    case SDLK_SEMICOLON: Mix_PlayChannel(-1, F3, 0); SDL_Log("; key pressed"); break;
                    case SDLK_u: Mix_PlayChannel(-1, C4, 0); SDL_Log("U key pressed"); break;
                    case SDLK_i: Mix_PlayChannel(-1, D4, 0); SDL_Log("I key pressed"); break;
                    case SDLK_o: Mix_PlayChannel(-1, E4, 0); SDL_Log("O key pressed"); break;
                    case SDLK_p: Mix_PlayChannel(-1, F4, 0); SDL_Log("P key pressed"); break;
                }
            }
        }
    }
    
    // cleanup
    Mix_FreeChunk(Cma7);
    Mix_FreeChunk(Cm7);
    Mix_FreeChunk(Dma7);
    Mix_FreeChunk(Dm7);
    Mix_FreeChunk(Ema7);
    Mix_FreeChunk(Em7);
    Mix_FreeChunk(Fma7);
    Mix_FreeChunk(Fm7);
    
    Mix_FreeChunk(C3);
    Mix_FreeChunk(C4);
    Mix_FreeChunk(D3);
    Mix_FreeChunk(D4);
    Mix_FreeChunk(E3);
    Mix_FreeChunk(E4);
    Mix_FreeChunk(F3);
    Mix_FreeChunk(F4);
    
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(key_empty);
    SDL_DestroyTexture(key_a_empty);
    SDL_DestroyTexture(key_j_empty);
    SDL_DestroyTexture(key_left_clicked);
    SDL_DestroyTexture(key_right_clicked);
    SDL_DestroyTexture(key_a_clicked);
    SDL_DestroyTexture(key_j_clicked);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
