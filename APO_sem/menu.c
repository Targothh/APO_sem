#include "menu.h"

#define WHITE   0xFFFF

void main_menu(menu *menu){
    for (int x = 0; x < menu->width; x++){
        for (int y = 0; y < menu->height; y++){
            parlcd_write_data(menu->parlcd_mem_base, WHITE);
        }
    }
}