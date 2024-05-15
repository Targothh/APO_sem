#include "objects.h"

void ball_vec_init(GameField *field){
    field -> ball.speed_x = rand() %10 > 10 ? -10 : 10;
    field -> ball.speed_y = rand() %20 - 10;
}

void reset_ball(GameField *field){
    field->ball.x =  field->width/2;
    field->ball.y =  field->height/2;
    ball_vec_init(field);
}



void check_collision(GameField *field){
    if((field -> ball.y + field -> height) < 0){
        field -> ball.speed_y = field -> ball.speed_y * -1;
    } else if((field -> ball.y + field -> height) > 320){
        field -> ball.speed_y = field -> ball.speed_y * -1;
    }

    if((field -> ball.y + field -> width) > 480 || (field -> ball.y + field -> width) < 0){
        reset_ball(&field);
    }

}