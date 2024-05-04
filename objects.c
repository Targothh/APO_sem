#include <stdint.h>

#include "objects.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"


#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0


void init_net(GameField *field){
    for (int x = field->width / 2; x < field->width / 2 + 2; x++){
        for (int y = 0; y < field->height; y++){
            parlcd_write_data(field->parlcd_mem_base, WHITE);
        }
    }
}

// init green background
void init_background(GameField *field, uint16_t color){
    for (int x = 0; x < field->width; x++){
        for (int y = 0; y < field->height; y++){
            parlcd_write_data(field->parlcd_mem_base, color);
        }
    }
    init_net(field);
}

void init_player(GameField *field, int player, int x, int y, int width, int height, int speed){
    if (player == 1){
        field->player1.x = x;
        field->player1.y = y;
        field->player1.width = width;
        field->player1.height = height;
        field->player1.speed = speed;
    }
    else if (player == 2){
        field->player2.x = x;
        field->player2.y = y;
        field->player2.width = width;
        field->player2.height = height;
        field->player2.speed = speed;
    }
}

void init_ball(GameField *field, int x, int y, int size, int speed){
    field->ball.x = x;
    field->ball.y = y;
    field->ball.size = size;
    field->ball.speed = speed;
}





void init_game(GameField *field, Player *player1, Player *player2, Ball *ball, unsigned char *parlcd_mem_base){
    field->width = 480;
    field->height = 320;
    field->player1 = *player1;
    field->player2 = *player2;
    field->ball = *ball;
    field->parlcd_mem_base = parlcd_mem_base;
    init_background(field, GREEN);
    init_player(field, 1, 0, 150, 5, 20, 10);
    init_player(field, 2, 475, 150, 5, 20, 10);
    init_ball(field, 6, 160, 4, 10);
}





void move_ball(GameField *field){
    field->ball.x += field->ball.speed;
    field->ball.y += field->ball.speed;

}

void move_player(GameField *field, int player, int direction){
    if (player == 1){
        if (direction == 1){
            field->player1.y -= field->player1.speed;
        }
        else if (direction == -1){
            field->player1.y += field->player1.speed;
        }
    }
    else if (player == 2){
        if (direction == 1){
            field->player2.y -= field->player2.speed;
        }
        else if (direction == -1){
            field->player2.y += field->player2.speed;
        }
    }
}

void draw_player(GameField *field, int player){
    if (player == 1){
        for (int x = field->player1.x; x < field->player1.x + field->player1.width; x++){
            for (int y = field->player1.y; y < field->player1.y + field->player1.height; y++){
                parlcd_write_data(field->parlcd_mem_base, WHITE);
            }
        }
    }
    else if (player == 2){
        for (int x = field->player2.x; x < field->player2.x + field->player2.width; x++){
            for (int y = field->player2.y; y < field->player2.y + field->player2.height; y++){
                parlcd_write_data(field->parlcd_mem_base, WHITE);
            }
        }
    }
}

void clear_player(GameField *field, int player){
    if (player == 1){
        for (int x = field->player1.x; x < field->player1.x + field->player1.width; x++){
            for (int y = field->player1.y; y < field->player1.y + field->player1.height; y++){
                parlcd_write_data(field->parlcd_mem_base, GREEN);
            }
        }
    }
    else if (player == 2){
        for (int x = field->player2.x; x < field->player2.x + field->player2.width; x++){
            for (int y = field->player2.y; y < field->player2.y + field->player2.height; y++){
                parlcd_write_data(field->parlcd_mem_base, GREEN);
            }
        }
    }
}

void draw_ball(GameField *field){
    for (int x = field->ball.x; x < field->ball.x + field->ball.size; x++){
        for (int y = field->ball.y; y < field->ball.y + field->ball.size; y++){
            parlcd_write_data(field->parlcd_mem_base, WHITE);
        }
    }
}

