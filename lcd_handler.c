#include "objects.h"
#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
uint16_t * buffer_init(GameField *field){
    uint16_t * buffer;
    buffer = calloc(buffer, field ->height * field ->height);
    draw(field, buffer);
}

void draw(GameField *field, uint16_t buffer){
    for(int i; i < field ->height * field ->height; i++){
        parlcd_write_data(field->parlcd_mem_base, buffer+i);
    }
}