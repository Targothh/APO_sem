
#define _POSIX_C_SOURCE 200112L

#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "serialize_lock.h"
#include "objects_init.h"
#include "lcd_handler.h"
#include "knob_handler.h"
#include "redraw_objects.h"
#include "move_objects.h"
#include "ball_logic.h"

int main(int argc, char *argv[])
{

  /* Initialize the LCD */
  unsigned char *parlcd_mem_base;
  parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  if (parlcd_mem_base == NULL) {
    return 1;
  }

  unsigned char *spiled_base;
  spiled_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
  if (spiled_base == NULL) {
    return 1;
  }

  GameField field;
  Ball ball;
  Player player1;
  Player player2;
  int bounce_count = 0;
  uint16_t *buffer;

  buffer = buffer_init();
  init_game(&field, &player1, &player2, &ball, parlcd_mem_base, buffer);

  uint8_t red_curr = *(spiled_base + SPILED_REG_KNOBS_8BIT_o + 2);
  uint8_t blue_curr = *(spiled_base + SPILED_REG_KNOBS_8BIT_o);

  ball_vec_init(&field);

  while(1){
    init_background(&field, BLACK);
    clear_player(&field, 1);
    clear_player(&field,2);

    uint8_t red_old = red_curr;
    uint8_t blue_old = blue_curr;

    red_curr = check_red_knob(&field, spiled_base, red_old);
    blue_curr = check_blue_knob(&field, spiled_base, blue_old);

    draw_player(&field, 1);
    draw_player(&field, 2);

    bounce_count = check_collision(&field, bounce_count);
    clear_ball(&field);
    move_ball(&field);
    draw_ball(&field);
    draw(buffer, parlcd_mem_base);
    sleep(0.5);
  }

  return 0;
}
