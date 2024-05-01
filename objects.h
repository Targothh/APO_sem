#include <stdint.h>

typedef struct Player {
    int x;              // Pozice hráče na ose x
    int y;              // Pozice hráče na ose y
    int width;          // Šířka hráče
    int height;         // Výška hráče
    int speed;          // Rychlost pohybu hráče
} Player;

typedef struct Ball {
    int x;              // Pozice míčku na ose x
    int y;              // Pozice míčku na ose y
    int radius;         // Poloměr míčku
    int speed_x;        // Rychlost míčku na ose x
    int speed_y;        // Rychlost míčku na ose y
} Ball;

typedef struct GameField {
    int width;          // Šířka herního pole
    int height;         // Výška herního pole
    Player player1;     // První hráč
    Player player2;     // Druhý hráč
    Ball ball;          // Míček
    uint16_t background_color; // Barva pozadí
    unsigned char *parlcd_mem_base; // Adresa řídicího registru
} GameField;

typedef struct GameState {
    GameField field;    // Aktuální stav herního pole
    int player1_score;  // Skóre prvního hráče
    int player2_score;  // Skóre druhého hráče
    int game_over;      // Indikátor konce hry
} GameState;

void init_background(GameField *field, uint16_t color);

void init_player(GameField *field, int player, int x, int y, int width, int height, int speed);

void init_ball(GameField *field, int x, int y, int radius, int speed_x, int speed_y);

void move_ball(GameField *field);

void move_player(GameField *field, int player, int direction);

void draw_player(GameField *field, int player);