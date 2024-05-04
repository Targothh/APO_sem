
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
#include "objects.h"

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

  init_game(&field, &player1, &player2, &ball, parlcd_mem_base);

  // while(1){
  //   uint32_t knob_rgb = *(volatile uint32_t*)(spiled_base + SPILED_REG_KNOBS_8BIT_o);
  //   uint16_t rgb565 = ((knob_rgb & 0xff) >> 3) | ((knob_rgb >> 5) & (0x3f << 5)) | ((knob_rgb >> 16) & (0x1f << (11)));
  //   *(volatile uint32_t*)(spiled_base + SPILED_REG_LED_LINE_o ) = knob_rgb;
  //   printf("0x%08x\n", ((knob_rgb >> 16) & (0x1f << (11))));
  //   parlcd_write_cmd(parlcd_mem_base, 0x2c);
  //   for (int i = 0; i < 480 * 320; i++){
  //     parlcd_write_data(parlcd_mem_base, rgb565);
  //   }
  // }

  // led_state = 0xff;

  // for(int i = 0; i <1000; i++){
  //   *(volatile uint32_t*)(spiled_base + SPILED_REG_LED_LINE_o) = 0xaa5500ff;
  //   sleep(1);
  //   led_state = (led_state << 1) | ((led_state >> 31) & 1);
  // }

  // /* Serialize execution of applications */

  // /* Try to acquire lock the first */
  // if (serialize_lock(1) <= 0) {
  //   printf("System is occupied\n");

  //   if (1) {
  //     printf("Waitting\n");
  //     /* Wait till application holding lock releases it or exits */
  //     serialize_lock(0);
  //   }
  // }

  // printf("Hello world\n");

  // sleep(4);

  // printf("Goodbye world\n");

  // /* Release the lock */
  // serialize_unlock();

  return 0;
}
