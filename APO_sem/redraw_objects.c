#include <stdint.h>
#include <stdio.h>

#include "objects_init.h"
#include "lcd_handler.h"


#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0



void draw_player(GameField *field, int player){
    if (player == 1){
        for (int x = field->player1.x; x < field->player1.x + field->player1.width; x++){
            for (int y = field->player1.y; y < field->player1.y + field->player1.height; y++){
                draw_pixel(field->buffer, x, y, WHITE);
            }
        }
    }
    else if (player == 2){
        for (int x = field->player2.x; x < field->player2.x + field->player2.width; x++){
            for (int y = field->player2.y; y < field->player2.y + field->player2.height; y++){
                draw_pixel(field->buffer, x, y, WHITE);
            }
        }
    }
}

void draw_ball(GameField *field){
    for (int x = field->ball.x; x < field->ball.x + field->ball.size; x++){
        for (int y = field->ball.y; y < field->ball.y + field->ball.size; y++){
            draw_pixel(field->buffer, x, y, RED);
        }
    }
}



void clear_player(GameField *field, int player){
    if (player == 1){
        for (int x = field->player1.x; x < field->player1.x + field->player1.width; x++){
            for (int y = field->player1.y; y < field->player1.y + field->player1.height; y++){
                draw_pixel(field->buffer, x, y, BLACK);
            }
        }
    }
    else if (player == 2){
        for (int x = field->player2.x; x < field->player2.x + field->player2.width; x++){
            for (int y = field->player2.y; y < field->player2.y + field->player2.height; y++){
                draw_pixel(field->buffer, x, y, BLACK);
            }
        }
    }
}

void clear_ball(GameField *field){
    for (int x = field->ball.x; x < field->ball.x + field->ball.size; x++){
        for (int y = field->ball.y; y < field->ball.y + field->ball.size; y++){
            draw_pixel(field->buffer, x, y, BLACK);
        }
    }
}