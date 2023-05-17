#include "image.h"
#include "map.h"
#include "play.h"



int main(int argc, char* args[])
{
// Khởi tạo SDL và tải ảnh
    if (!init())
    {
        std::cerr << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }
    //màn hình khởi tạo
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, gImage1, nullptr, nullptr);
    SDL_RenderPresent(gRenderer);

    SDL_Event e;
    // Vòng lặp chính

    bool quit = false;
    int Map=0;
    int step=0;
    Mix_PlayMusic( gMusic, -1 );
    while (!quit||Mix_PlayingMusic())
    {
        while (SDL_PollEvent(&e) != 0 )
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                Mix_HaltMusic();

            }
            else
            {
                if (step==0) background(e,step);
                else if (step==1) choose_map(e,step,Map);
                else if (step==2) play_game(e,step,Map);
                else win_game(e,step,Map);
            }
        }
    }
    // Đóng SDL
    close();

    return 0;
}
