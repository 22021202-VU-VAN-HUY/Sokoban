#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// Cửa sổ SDL
    SDL_Window* gWindow = nullptr;
// Renderer SDL
    SDL_Renderer* gRenderer = nullptr;

//các loạt ảnh
    // Texture của ảnh first_background
    SDL_Texture* gImage1 = nullptr;
    // Texture của ảnh select_map
    SDL_Texture* gImage2 = nullptr;
    SDL_Texture* Image_Win = nullptr;
    SDL_Texture* Image_Map_background = nullptr;
    SDL_Texture* Image_Map_background1 = nullptr;
    SDL_Texture* Image_Tree=nullptr;
    SDL_Texture* Image_Wall=nullptr;
    SDL_Texture* Image_Location_correct=nullptr;
    SDL_Texture* Image_Character;
    SDL_Texture* Image_Box;
    SDL_Texture* Image_Box_correct;
    SDL_Texture* Image_Menu;
    SDL_Texture* Image_Restart;

// các loạt âm thanh
    Mix_Music *gMusic = nullptr;
    Mix_Chunk *gPush  = nullptr;


// Kích thước của cửa sổ
const int SCREEN_WIDTH = 891;
const int SCREEN_HEIGHT = 504;

// Hàm tải ảnh thành texture
SDL_Texture* loadTexture(const std::string& path)
{
    // Surface tạm thời để tải ảnh
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    // Tạo texture từ surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (texture == nullptr)
    {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    // Xóa surface không cần thiết
    SDL_FreeSurface(loadedSurface);

    return texture;
}



bool init()
{
    // Khởi tạo SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Tạo cửa sổ
    gWindow = SDL_CreateWindow("SOKOBAN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Tạo renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    // Thiết lập màu nền cho renderer
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Khởi tạo SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Tải ảnh 1 và ảnh 2 thành texture
    gImage1 = loadTexture("image/first_background.png");
    if (gImage1 == nullptr)
    {
        return false;
    }

    gImage2 = loadTexture("image/seclect_map.png");
    if (gImage2 == nullptr)
    {
        return false;
    }

    Image_Map_background = loadTexture("image/map_background.png");
    if (Image_Map_background == nullptr)
    {
        return false;
    }

    Image_Map_background1 = loadTexture("image/map_background1.png");
    if (Image_Map_background1 == nullptr)
    {
        return false;
    }

    Image_Tree = loadTexture("image/tree.png");
    if (Image_Tree == nullptr)
    {
        return false;
    }

    Image_Wall = loadTexture("image/wall.png");
    if (Image_Wall == nullptr)
    {
        return false;
    }

    Image_Location_correct = loadTexture("image/location_correct.png");
    if (Image_Location_correct == nullptr)
    {
        return false;
    }

    Image_Character  =loadTexture("image/character.png");
    if (Image_Character == nullptr)
    {
        return false;
    }

    Image_Box = loadTexture("image/box.png");
    if (Image_Box == nullptr)
    {
        return false;
    }

    Image_Box_correct = loadTexture("image/box_correct.png");
    if (Image_Box_correct == nullptr)
    {
        return false;
    }

    Image_Win = loadTexture("image/win.png");
    if (Image_Win == nullptr)
    {
        return false;
    }

    Image_Menu = loadTexture("image/menu.png");
    if (Image_Menu == nullptr)
    {
        return false;
    }

    Image_Restart = loadTexture("image/restart.png");
    if (Image_Restart == nullptr)
    {
        return false;
    }

    // âm thanh
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    //SDL_Init(SDL_INIT_AUDIO);
    gMusic = Mix_LoadMUS("image/hihi.mp3");
    if (gMusic == nullptr)
    {
        return false;
    }
    gPush  = Mix_LoadWAV("image/push.mp3");
    if (gPush == nullptr)
    {
        return false;
    }
    return true;
}

void close()
{
// Giải phóng các texture và renderer
    SDL_DestroyTexture(gImage1);
    gImage1 = nullptr;

    SDL_DestroyTexture(gImage2);
    gImage2 = nullptr;

    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    SDL_DestroyTexture(Image_Win);
    Image_Win = nullptr;

    SDL_DestroyTexture(Image_Map_background);
    Image_Map_background = nullptr;

    SDL_DestroyTexture(Image_Map_background1);
    Image_Map_background1 = nullptr;

    SDL_DestroyTexture(Image_Tree);
    Image_Tree=nullptr;

    SDL_DestroyTexture(Image_Wall);
    Image_Wall=nullptr;

    SDL_DestroyTexture(Image_Location_correct);
    Image_Location_correct=nullptr;

    SDL_DestroyTexture(Image_Character);
    Image_Character=nullptr;

    SDL_DestroyTexture(Image_Box);
    Image_Box=nullptr;

    SDL_DestroyTexture(Image_Box_correct);
    Image_Box_correct=nullptr;

    SDL_DestroyTexture(Image_Menu);
    Image_Menu=nullptr;

    SDL_DestroyTexture(Image_Restart);
    Image_Restart=nullptr;


    Mix_FreeMusic( gMusic );
	gMusic = nullptr;

	Mix_FreeChunk( gPush );
	gPush = nullptr;

// Đóng SDL
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


#endif // IMAGE_H_INCLUDED
