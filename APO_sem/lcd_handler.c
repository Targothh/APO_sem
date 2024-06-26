#include <stdlib.h>
#include "mzapo_parlcd.h"
#include "font_types.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0

#define HEIGHT 320
#define WIDTH 480

uint16_t * buffer_init(){
    uint16_t * buffer;
    buffer = (uint16_t *) calloc(sizeof(uint16_t), WIDTH * HEIGHT);
    return buffer;
}

void draw_pixel(uint16_t * buffer, int x, int y, uint16_t data){
    buffer[x + WIDTH * y] = data;

}

void draw(uint16_t * buffer, unsigned char *parlcd_mem_base){
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        parlcd_write_data(parlcd_mem_base, buffer[i]);
    }
}

void draw_text(uint16_t * buffer, font_descriptor_t *font, int x, int y, int char_code, int color){
    
    

}