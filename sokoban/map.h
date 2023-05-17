#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string path_map;
std::string path_character_and_box;

// định nghĩa số lượng và kích thước các ô trong map
const int block=9;
const int width_block=SCREEN_HEIGHT/block;  //const int width_block=SCREEN_WIDTH/block;
const int hight_block=SCREEN_HEIGHT/block;

int map_sokoban[block][block];
int character_and_box[block][block];

// định nghĩa các ô trong map
const int NONE=0;
const int WALL=1;
const int LOCATION_CORRECT=2;
const int TREE=3;

const int CHARACTER=4;
const int BOX=5;
const int BOX_CORRECT=6;

void read_text(int n,std::string& path_map,std::string& path_character_and_box)
{
    switch (n)
    {
    case 1:
        path_map="map_sokoban/map1.txt";
        path_character_and_box="map_sokoban/map1_character_and_box.txt";
        break;
    case 2:
        path_map="map_sokoban/map2.txt";
        path_character_and_box="map_sokoban/map2_character_and_box.txt";
        break;
    case 3:
        path_map="map_sokoban/map3.txt";
        path_character_and_box="map_sokoban/map3_character_and_box.txt";
        break;
    case 4:
        path_map="map_sokoban/map4.txt";
        path_character_and_box="map_sokoban/map4_character_and_box.txt";
        break;
    case 5:
        path_map="map_sokoban/map5.txt";
        path_character_and_box="map_sokoban/map5_character_and_box.txt";
        break;
    case 6:
        path_map="map_sokoban/map6.txt";
        path_character_and_box="map_sokoban/map6_character_and_box.txt";
        break;
    case 7:
        path_map="map_sokoban/map7.txt";
        path_character_and_box="map_sokoban/map7_character_and_box.txt";
        break;
    case 8:
        path_map="map_sokoban/map8.txt";
        path_character_and_box="map_sokoban/map8_character_and_box.txt";
        break;
    case 9:
        path_map="map_sokoban/map9.txt";
        path_character_and_box="map_sokoban/map9_character_and_box.txt";
        break;
    case 10:
        path_map="map_sokoban/map10.txt";
        path_character_and_box="map_sokoban/map10_character_and_box.txt";
        break;
    case 11:
        path_map="map_sokoban/map11.txt";
        path_character_and_box="map_sokoban/map11_character_and_box.txt";
        break;
    case 12:
        path_map="map_sokoban/map12.txt";
        path_character_and_box="map_sokoban/map12_character_and_box.txt";
        break;
    case 13:
        path_map="map_sokoban/map13.txt";
        path_character_and_box="map_sokoban/map13_character_and_box.txt";
        break;
    case 14:
        path_map="map_sokoban/map14.txt";
        path_character_and_box="map_sokoban/map14_character_and_box.txt";
        break;
    case 15:
        path_map="map_sokoban/map15.txt";
        path_character_and_box="map_sokoban/map15_character_and_box.txt";
        break;
    }
}

void read_map(std::string path,int arraymap[][block])
{
    std::ifstream file_map(path);
    int num;
    while (!file_map.eof())
    {
        for (int i=0; i<block; i++)
        {
            for (int j=0; j<block; j++)
            {
                file_map>>num;
                arraymap[i][j]=num;
            }
        }
    }
}

void draw_menu()
{
    SDL_Rect cellRect;
        cellRect.x = SCREEN_WIDTH-width_block;
        cellRect.y = 0;
        cellRect.w = width_block;
        cellRect.h = hight_block;
    SDL_RenderCopy(gRenderer, Image_Menu, NULL, &cellRect);
    SDL_RenderPresent(gRenderer);
}

void draw_restart()
{
    SDL_Rect cellRect;
        cellRect.x = SCREEN_WIDTH-2*width_block;
        cellRect.y = 0;
        cellRect.w = width_block;
        cellRect.h = hight_block;
    SDL_RenderCopy(gRenderer, Image_Restart, NULL, &cellRect);
    //SDL_RenderPresent(gRenderer);
}

void draw_map()
{
    // Vẽ bản đồ
    //SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, Image_Map_background1, nullptr, nullptr);
    draw_restart();
    draw_menu();
    //SDL_RenderCopy(gRenderer, Image_Map_background, nullptr, nullptr);
    SDL_Rect cellRect;
        cellRect.x = 193;
        cellRect.y = 0;
        cellRect.w = hight_block*block;
        cellRect.h = hight_block*block;
        SDL_RenderCopy(gRenderer, Image_Map_background, NULL, &cellRect);

    //SDL_RenderPresent(gRenderer);
    for (int row = 0; row < block; row++)
    {
        for (int col = 0; col < block; col++)
        {
            SDL_Rect cellRect;
            cellRect.x = col * width_block+193;
            cellRect.y = row * hight_block;
            cellRect.w = width_block;
            cellRect.h = hight_block;

            // Vẽ phần tử tương ứng trong bản đồ
            switch (map_sokoban[row][col])
            {
            case WALL:
                SDL_RenderCopy(gRenderer, Image_Wall, NULL, &cellRect);
                break;
            case TREE:
                SDL_RenderCopy(gRenderer, Image_Tree, NULL, &cellRect);
                break;
            case LOCATION_CORRECT:
                SDL_RenderCopy(gRenderer, Image_Location_correct, NULL, &cellRect);
                break;
            default:
                break;
            }
        }
    }
    //vẽ nhân vật và box
    for (int row = 0; row < block; row++)
    {
        for (int col = 0; col < block; col++)
        {
            SDL_Rect cellRect;
            cellRect.x = col * width_block+193;
            cellRect.y = row * hight_block;
            cellRect.w = width_block;
            cellRect.h = hight_block;

            // Vẽ phần tử tương ứng trong bản đồ
            switch (character_and_box[row][col])
            {
            case CHARACTER:
                SDL_RenderCopy(gRenderer, Image_Character, NULL, &cellRect);
                break;
            case BOX:
                SDL_RenderCopy(gRenderer, Image_Box, NULL, &cellRect);
                break;
            case BOX_CORRECT:
                SDL_RenderCopy(gRenderer, Image_Box_correct, NULL, &cellRect);
                break;
            default:
                break;
            }
        }
    }
    SDL_RenderPresent(gRenderer);
}

#endif // MAP_H_INCLUDED
