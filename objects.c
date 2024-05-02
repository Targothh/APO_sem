#include <stdint.h>

#include "objects.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"


#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

// init green background

void init_background(GameField *field, uint16_t color){
    for (int x = 0; x < field->width; x++){
        for (int y = 0; y < field->height; y++){
            parlcd_write_data(field->parlcd_mem_base, color);
        }
    }
    init_net(field);
}

void init_net(GameField *field){
    for (int x = field->width / 2; x < field->width / 2 + 2; x++){
        for (int y = 0; y < field->height; y++){
            parlcd_write_data(field->parlcd_mem_base, WHITE);
        }
    }
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

void init_ball(GameField *field, int x, int y, int radius, int speed_x, int speed_y){
    field->ball.x = x;
    field->ball.y = y;
    field->ball.radius = radius;
    field->ball.speed_x = speed_x;
    field->ball.speed_y = speed_y;
}

void move_ball(GameField *field){
    field->ball.x += field->ball.speed_x;
    field->ball.y += field->ball.speed_y;
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

void draw_ball(GameField *field){
    for (int x = field->ball.x - field->ball.radius; x < field->ball.x + field->ball.radius; x++){
        for (int y = field->ball.y - field->ball.radius; y < field->ball.y + field->ball.radius; y++){
            parlcd_write_data(field->parlcd_mem_base, WHITE);
        }
    }
}

