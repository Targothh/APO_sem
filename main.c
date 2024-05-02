
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

  for (int i = 0; i < 480; i++) {
    for (int j = 0; j < 320; j++) {
      parlcd_write_data(parlcd_mem_base, GREEN);
    }
  }

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
