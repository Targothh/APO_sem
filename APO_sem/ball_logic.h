void ball_vec_init(GameField *field);

void reset_ball(GameField *field);

int check_collision(GameField *field, int bounce_count);
void draw_text(uint16_t * buffer, font_descriptor_t *font, int x, int y, int char_code, int color);