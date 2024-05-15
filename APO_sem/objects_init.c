#include <stdint.h>
#include <stdio.h>

#include "objects_init.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "lcd_handler.h"


#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

void init_game(GameField *field, Player *player1, Player *player2, Ball *ball, unsigned char *parlcd_mem_base, uint16_t * buffer){
    field->width = 480;
    field->height = 320;
    field->player1 = *player1;
    field->player2 = *player2;
    field->ball = *ball;
    field->parlcd_mem_base = parlcd_mem_base;
    field->buffer = buffer;
    init_background(field, GREEN);
    init_player(field, 1, 5, 150, 10, 50, 10);
    init_player(field, 2, 470, 150, 10, 50, 10);
    init_ball(field, field->width/2, field->height/2, 20, 3, 3);
}

void init_net(GameField *field){
    for (int x = field->width /2 - 10; x < field->width /2 + 10; x++){
        for (int y = 0; y < field->height; y++){
            draw_pixel(field->buffer, x, y, WHITE);
        }
    }
}

// init black background
void init_background(GameField *field, uint16_t color){
    for (int y = 0; y < field->height; y++){
        for (int x = 0; x < field->width; x++){
            draw_pixel(field->buffer, x, y, BLACK);
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

void init_ball(GameField *field, int x, int y, int size, int speed_x, int speed_y){
    field->ball.x = x;
    field->ball.y = y;
    field->ball.size = size;
    field->ball.speed_x = speed_x;
    field->ball.speed_y = speed_y;
}


