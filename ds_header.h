#ifndef DS_HEADER_H_INCLUDED
#define DS_HEADER_H_INCLUDED

#define TILE_0 0        // kafelki po ktorych mozna sie przemieszcac
#define TILE_1 1
#define TILE_2 2
#define TILE_3 3
#define TILE_4 4
#define TILE_5 5
#define TILE_6 6
#define TILE_7 7
#define TILE_8 8
#define TILE_9 9
#define TILE_10 10
#define TILE_11 11
#define TILE_12 12
#define TILE_13 13
#define TILE_14 14
#define TILE_15 15
#define TILE_16 16
#define TILE_AMOUNT 16
#define TILE_SIZE 32

typedef struct button
{
int x,y,w,h;
};

typedef struct person
{
int x,y;
};

void a_init();
void a_deinit();
void menu_g();  //menu gry
void menu_p();  //menu wyboru planszy
void menu_b();  //menu, najlepsze wyniki
void menu_h();  //pomoc, opis sterowania
void game( int n );
#endif // DS_HEADER_H_INCLUDED
