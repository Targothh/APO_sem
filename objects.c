#include <stdint.h>

#include "objects.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

// init green background

void init_background(GameField *field, uint16_t color){
    for (int x = 0; x < field->width; x++){
        for (int y = 0; y < field->height; y++){
            parlcd_write_data(field->parlcd_mem_base, color);
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