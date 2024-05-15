#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"
#include "objects_init.h"
#include "knob_handler.h"
#include "move_objects.h"

uint8_t check_red_knob(GameField *field, unsigned char *spiled_base, uint8_t red_curr){
    uint8_t red_new = *(spiled_base + SPILED_REG_KNOBS_8BIT_o + 2);
    int red_diff = ((int)red_new - (int)red_curr + 255) % 255;
    if (red_diff == 0){
        return red_curr;
    }
    if (red_diff > 127){
        // move right
        move_player(field, 1, 1);
    } else if (red_diff < 127){
        // move left
        move_player(field, 1, -1);
    }
    return red_new;
}


uint8_t check_blue_knob(GameField *field, unsigned char *spiled_base, uint8_t blue_curr){
    uint8_t blue_new = *(spiled_base + SPILED_REG_KNOBS_8BIT_o);
    int blue_diff = ((int)blue_new - (int)blue_curr + 255) % 255;
    if (blue_diff == 0){
        return blue_curr;
    }
    if (blue_diff > 127){
        // move right
        move_player(field, 2, 1);
    } else if (blue_diff < 127){
        // move left
        move_player(field, 2, -1);
    } else{
        return blue_curr;
    }
    return blue_new;
}

