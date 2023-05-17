#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

// phím bấm
const int UP = 0;       // Phím mũi tên lên
const int DOWN = 1;     // Phím mũi tên xuống
const int LEFT = 2;     // Phím mũi tên trái
const int RIGHT = 3;    // Phím mũi tên phải

// kiểm tra xem đã thắng game chưa
bool win(int character_and_box[][block],int block)
{
    for (int i=0; i<block; i++)
    {
        for (int j=0; j<block; j++)
        {
            if (character_and_box[i][j]==BOX) return false;
        }
    }
    return true;
}

// kiểm tra xem có thể di chuyển được nhân vật không
bool check_move(int key, int x,int y,int map_sokoban[][block],int character_and_box[][block],int block)
{
    switch(key)
    {
    case UP:
        if (x<=1) return false;
        if ((character_and_box[x-1][y]==NONE)&&(map_sokoban[x-1][y]==NONE||map_sokoban[x-1][y]==LOCATION_CORRECT)) return true;
        else return false;
    case DOWN:
        if (x>=block-2) return false;
        if (character_and_box[x+1][y]==NONE&&(map_sokoban[x+1][y]==NONE||map_sokoban[x+1][y]==LOCATION_CORRECT)) return true;
        else return false;
    case LEFT:
        if (y<=1) return false;
        if (character_and_box[x][y-1]==NONE&&(map_sokoban[x][y-1]==NONE||map_sokoban[x][y-1]==LOCATION_CORRECT)) return true;
        else return false;
    case RIGHT:
        if (y>=block-2) return false;
        if (character_and_box[x][y+1]==NONE&&(map_sokoban[x][y+1]==NONE||map_sokoban[x][y+1]==LOCATION_CORRECT)) return true;
        else return false;
    }
}

// thay đổi vị trí nếu di chuyển được
void change_move(int key, int x,int y,int map_sokoban[][block],int character_and_box[][block],int block)
{
    switch(key)
    {
    case UP:
        character_and_box[x-1][y]=CHARACTER;
        character_and_box[x][y]=NONE;
        break;
    case DOWN:
        character_and_box[x+1][y]=CHARACTER;
        character_and_box[x][y]=NONE;
        break;
    case LEFT:
        character_and_box[x][y-1]=CHARACTER;
        character_and_box[x][y]=NONE;
        break;
    case RIGHT:
        character_and_box[x][y+1]=CHARACTER;
        character_and_box[x][y]=NONE;
        break;
    }
}

// kiểm tra xem có đẩy được thùng không
bool check_push(int key, int x,int y,int map_sokoban[][block],int character_and_box[][block],int block)
{
    bool check=false;
    switch(key)
    {
    case UP:
        if (x<=2) check=false;
        if ((character_and_box[x-1][y] == BOX || character_and_box[x-1][y] == BOX_CORRECT)&&
                (character_and_box[x-2][y] != BOX && character_and_box[x-2][y] != BOX_CORRECT)&&
                ( map_sokoban[x-2][y] == NONE     || map_sokoban[x-2][y] == LOCATION_CORRECT ))
            check=true;
        break;
    case DOWN:
        if (x>=block-3) check=false;
        if ((character_and_box[x+1][y] == BOX || character_and_box[x+1][y] == BOX_CORRECT)&&
                (character_and_box[x+2][y] != BOX && character_and_box[x+2][y] != BOX_CORRECT)&&
                ( map_sokoban[x+2][y] == NONE     || map_sokoban[x+2][y] == LOCATION_CORRECT ))
            check=true;
        break;
    case LEFT:
        if (y<=2) check=false;
        if ((character_and_box[x][y-1] == BOX || character_and_box[x][y-1] == BOX_CORRECT)&&
                (character_and_box[x][y-2] != BOX && character_and_box[x][y-2] != BOX_CORRECT)&&
                ( map_sokoban[x][y-2] == NONE     || map_sokoban[x][y-2] == LOCATION_CORRECT ))
            check=true;
        break;
    case RIGHT:
        if (y>=block-3) check=false;
        if ((character_and_box[x][y+1] == BOX || character_and_box[x][y+1] == BOX_CORRECT)&&
                (character_and_box[x][y+2] != BOX && character_and_box[x][y+2] != BOX_CORRECT)&&
                ( map_sokoban[x][y+2] == NONE     || map_sokoban[x][y+2] == LOCATION_CORRECT ))
            check=true;
        break;
    }
    return check;
}

// thay đổi vị trí nếu đẩy được
void change_push(int key, int x,int y,int map_sokoban[][block],int character_and_box[][block],int block)
{
    switch(key)
    {
    case UP:
        character_and_box[x-1][y]=CHARACTER;
        character_and_box[x][y]=NONE;
        if (map_sokoban[x-2][y]==LOCATION_CORRECT) character_and_box[x-2][y]=BOX_CORRECT;
        else character_and_box[x-2][y]=BOX;
        break;
    case DOWN:
        character_and_box[x+1][y]=CHARACTER;
        character_and_box[x][y]=NONE;
        if (map_sokoban[x+2][y]==LOCATION_CORRECT) character_and_box[x+2][y]=BOX_CORRECT;
        else character_and_box[x+2][y]=BOX;
        break;
    case LEFT:
        character_and_box[x][y-1]=CHARACTER;
        character_and_box[x][y]=NONE;
        if (map_sokoban[x][y-2]==LOCATION_CORRECT) character_and_box[x][y-2]=BOX_CORRECT;
        else character_and_box[x][y-2]=BOX;
        break;
    case RIGHT:
        character_and_box[x][y+1]=CHARACTER;
        character_and_box[x][y]=NONE;
        if (map_sokoban[x][y+2]==LOCATION_CORRECT) character_and_box[x][y+2]=BOX_CORRECT;
        else character_and_box[x][y+2]=BOX;
        break;
    }
}

// lấy vị trí nhân vật
void check_character(int& x, int& y, int character_and_box[][block], int block)
{
    for (int i = 0; i < block; i++)
    {
        for (int j = 0; j < block; j++)
        {
            if (character_and_box[i][j] == CHARACTER)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
}

// xử lí khi nhấn nút menu
void button_menu(int x,int y, int& step)
{
    if (x>=SCREEN_WIDTH-width_block && x<=SCREEN_WIDTH && y>=0 && y<=hight_block)
    {
        step=1;
        //SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, gImage2, nullptr, nullptr);
        SDL_RenderPresent(gRenderer);
    }
}

// xử lí khi nhấn nút chơi lại
void button_restart(int x,int y,int &Map)
{
    if (x>=SCREEN_WIDTH-2*width_block && x<SCREEN_WIDTH-width_block && y>=0 && y<=hight_block)
    {
        read_text(Map,path_map,path_character_and_box);
        read_map(path_map, map_sokoban);
        read_map(path_character_and_box,character_and_box);
        draw_map();
    }
}

// trả về kết quả map
int button_select_map(int x,int y)
{
    int hight=62;
    int width=148;
    if (x>=48 && x<=48+width && y>=111 && y<=111+hight) return 1;
    if (x>=209&& x<=209+width&& y>=111 && y<=111+hight) return 2;
    if (x>=373&& x<=373+width&& y>=111 && y<=111+hight) return 3;
    if (x>=536&& x<=536+width&& y>=111 && y<=111+hight) return 4;
    if (x>=699&& x<=699+width&& y>=111 && y<=111+hight) return 5;
    if (x>=48 && x<= 48+width&& y>=252 && y<=252+hight) return 6;
    if (x>=209&& x<=209+width&& y>=252 && y<=252+hight) return 7;
    if (x>=373&& x<=373+width&& y>=252 && y<=252+hight) return 8;
    if (x>=536&& x<=536+width&& y>=252 && y<=252+hight) return 9;
    if (x>=699&& x<=699+width&& y>=252 && y<=252+hight) return 10;
    if (x>=48 && x<= 48+width&& y>=392 && y<=392+hight) return 11;
    if (x>=209&& x<=209+width&& y>=392 && y<=392+hight) return 12;
    if (x>=373&& x<=373+width&& y>=392 && y<=392+hight) return 13;
    if (x>=536&& x<=536+width&& y>=392 && y<=392+hight) return 14;
    if (x>=699&& x<=699+width&& y>=392 && y<=392+hight) return 15;
    else return 0;
}

// xử lí khi nhấn nút play
void play_button(int x, int y,int& step)
{
// Kiểm tra vị trí chuột và chuyển đổi giữa ảnh 1 và ảnh 2
    if (x > 332 && x < 557 && y > 162 && y < 259)
    {
        step++;
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, gImage2, nullptr, nullptr);
        SDL_RenderPresent(gRenderer);

    }
}

// vẽ màn hình đầu game
void background(SDL_Event e,int& step)   //step=0
{
     if (e.type == SDL_MOUSEBUTTONDOWN)
     {
         int x, y;
        SDL_GetMouseState(&x, &y);
        play_button(x, y,step);
     }
}

// vẽ màn hình chọn map
void choose_map(SDL_Event e,int& step, int &Map)  //step=1
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
     {
        int x,y;
        SDL_GetMouseState(&x, &y);
        Map=button_select_map(x, y);
        if (Map!=0)
        {
            step++;
            read_text(Map,path_map,path_character_and_box);
            read_map(path_map, map_sokoban);
            read_map(path_character_and_box,character_and_box);
            draw_map();
        }
     }
}

// xử lí trò chơi
void play_game(SDL_Event e,int &step,int &Map)  // step=2
{
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x;int y;
        SDL_GetMouseState(&x, &y);
        button_menu(x,y,step);
        button_restart(x,y,Map);
    }
    else if( e.type == SDL_KEYDOWN )
    {
        int x,y;
        check_character(x,y,character_and_box,block);
        //SDL_RenderClear(gRenderer);

        //Select surfaces based on key press
        switch( e.key.keysym.sym )
        {
        case SDLK_UP:
            if (check_move(UP,x,y,map_sokoban,character_and_box,block))
            {
                change_move(UP,x,y,map_sokoban,character_and_box,block);
                draw_map();
            }
            else if (check_push(UP,x,y,map_sokoban,character_and_box,block))
            {
                change_push(UP,x,y,map_sokoban,character_and_box,block);
                draw_map();
                Mix_PlayChannel( -1, gPush, 0 );
            }
            break;
        case SDLK_DOWN:
            if (check_move(DOWN,x,y,map_sokoban,character_and_box,block))
            {
                change_move(DOWN,x,y,map_sokoban,character_and_box,block);
                draw_map();
            }
            else if (check_push(DOWN,x,y,map_sokoban,character_and_box,block))
            {
                change_push(DOWN,x,y,map_sokoban,character_and_box,block);
                draw_map();
                Mix_PlayChannel( -1, gPush, 0 );
            }
            break;
        case SDLK_LEFT:
            if (check_move(LEFT,x,y,map_sokoban,character_and_box,block))
            {
                change_move(LEFT,x,y,map_sokoban,character_and_box,block);
                draw_map();
            }
            else if (check_push(LEFT,x,y,map_sokoban,character_and_box,block))
            {
                change_push(LEFT,x,y,map_sokoban,character_and_box,block);
                draw_map();
                Mix_PlayChannel( -1, gPush, 0 );
            }
            break;
        case SDLK_RIGHT:
            if (check_move(RIGHT,x,y,map_sokoban,character_and_box,block))
            {
                change_move(RIGHT,x,y,map_sokoban,character_and_box,block);
                draw_map();
            }
            else if (check_push(RIGHT,x,y,map_sokoban,character_and_box,block))
            {
                change_push(RIGHT,x,y,map_sokoban,character_and_box,block);
                draw_map();
                Mix_PlayChannel( -1, gPush, 0 );
            }
            break;
        default:
            break;
        }
        if (win(character_and_box,block))
        {
            step++;
        }
    }
}

// xử lí nếu thắng game
void win_game(SDL_Event e,int &step,int &Map)
{
    //SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, Image_Win, nullptr, nullptr);
    //SDL_RenderPresent(gRenderer);
    draw_menu();
    std::cout<<2;
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x;int y;
        SDL_GetMouseState(&x, &y);
        button_menu(x,y,step);
        Map=0;
    }
}


#endif // PLAY_H_INCLUDED
