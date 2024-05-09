#include <stdint.h>
#include "objects.h"
uint16_t * buffer_init();
void draw_pixel(uint16_t * buffer, int x, int y, uint16_t data);
void draw(uint16_t buffer, unsigned char *parlcd_mem_base);

