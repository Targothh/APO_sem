#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"
#include "objects.h"

// player 1 - blue
// player 2 - red


void handle_direction(int diff, GameField *field, int player){
    clear_player(field, player);

    if (diff > 127){
        // move right
        move_player(field, player, 1);
    }
    else if (diff < 127){
        // move left
        move_player(field, player, -1);
    }
    
    draw_player(field, player);
}

void handle_knobs(GameField *field){
    unsigned char *spiled_base;
    spiled_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
    if(spiled_base == NULL) {
        return;
    }

    uint32_t blue_init = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o);
    // uint32_t green_init = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o + 1);
    uint32_t red_init = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o + 2);

    while(1){
        uint32_t blue_new = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o);   
        // uint32_t green_new = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o + 1);
        uint32_t red_new = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o + 2);

        int blue_diff = ((int)blue_new - (int)blue_init + 255) % 255;
        // int green_diff = ((int)green_new - (int)green_init + 255) % 255;
        int red_diff = ((int)red_new - (int)red_init + 255) % 255;

        handle_direction(blue_diff, field, 1);
        // handle_direction(green_diff, field);
        handle_direction(red_diff, field, 2);

        blue_init = blue_new;
        // green_init = green_new;
        red_init = red_new;

        sleep(5);
    }
}
