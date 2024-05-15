#include <stdint.h>
#include <stdio.h>

#include "objects_init.h"
#include "lcd_handler.h"

void move_ball(GameField *field){
    field->ball.x += field->ball.speed_x;
    field->ball.y += field->ball.speed_y;

}

void move_player(GameField *field, int player, int direction){
    if (player == 1){
        if (direction == 1 && field->player1.y > 0){
            field->player1.y -= field->player1.speed;
        }
        else if ((direction == -1) && ((field->player1.y + field->player1.height) < 320)){
            field->player1.y += field->player1.speed;
        }
    }
    else if (player == 2){
        if (direction == 1 && field->player2.y > 0){
            field->player2.y -= field->player2.speed;
        }
        else if ((direction == -1) && ((field->player2.y + field->player2.height) < 320)){
            field->player2.y += field->player2.speed;
        }
    }
}