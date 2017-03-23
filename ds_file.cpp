#include <allegro.h>
#include <stdio.h>
#include <time.h>
#include "ds_header.h"

volatile long ticks=1;
void timerproc()
{
ticks++;
}

void a_init()
{
	allegro_init();
	set_color_depth( 32 );
	set_gfx_mode( GFX_AUTODETECT, 1024, 768, 0, 0 );
	install_timer();
	install_keyboard();
};

void a_deinit()
{
	clear_keybuf();
	allegro_exit();
};

void menu_g()
{
    int mposit;
    BITMAP * bufor01 = NULL;
    bufor01 = create_bitmap( 1024, 768 );
    bufor01=load_bitmap( "bmp/menu1.bmp", NULL );
    button newgame,bestscores,help,endgame;
    //nowa gra
    newgame.x=600;
    newgame.y=60;
    newgame.h=60;
    newgame.w=300;

    //najlepsze wyniki
    bestscores.x=600;
    bestscores.y=170;
    bestscores.h=130;
    bestscores.w=330;

    //pomoc
    help.x=600;
    help.y=350;
    help.h=60;
    help.w=300;

    //wyjdz
    endgame.x=600;
    endgame.y=460;
    endgame.h=60;
    endgame.w=300;

    clear_bitmap( screen );
    blit( bufor01, screen, 0, 0, 0, 0, 1024, 768 );
    mposit=0;
    rect( screen, newgame.x, newgame.y, newgame.x+newgame.w, newgame.y+newgame.h, makecol( 250, 250, 40 ) );
    install_int( timerproc,10 );
    readkey();
    while ( ticks > 0 )
    {
        readkey();
        if ( key[KEY_ENTER] )
            break;
        if ( key[KEY_UP] && mposit > 0 )
        {
            mposit--;
            clear_bitmap( screen );
            blit( bufor01, screen, 0, 0, 0, 0, 1024, 768 );
            if ( mposit == 2 )
            {
                rect(screen, help.x, help.y, help.x+help.w, help.y+help.h, makecol( 250, 250, 40 ));
            }
            else if ( mposit == 1 )
            {
                rect(screen, bestscores.x, bestscores.y, bestscores.x+bestscores.w, bestscores.y+bestscores.h, makecol( 250, 250, 40 ));
            }
            else if ( mposit == 0 )
            {
                 rect(screen, newgame.x, newgame.y, newgame.x+newgame.w, newgame.y+newgame.h, makecol( 250, 250, 40 ));
            }
        }
        if ( key[KEY_DOWN] && mposit < 3 )
        {
            mposit++;
            clear_bitmap( screen );
            blit( bufor01, screen, 0, 0, 0, 0, 1024, 768 );
            if ( mposit == 3 )
            {
                rect(screen, endgame.x, endgame.y, endgame.x+endgame.w, endgame.y+endgame.h, makecol( 250, 250, 40 ));
            }
            else if ( mposit == 2 )
            {
                rect(screen, help.x, help.y, help.x+help.w, help.y+help.h, makecol( 250, 250, 40 ));
            }
            else if ( mposit == 1 )
            {
                 rect(screen, bestscores.x, bestscores.y, bestscores.x+bestscores.w, bestscores.y+bestscores.h, makecol( 250, 250, 40 ));
            }
        }
      ticks--;
    };
    remove_int( timerproc );
    switch( mposit )
    {
        case 0:
        {
           destroy_bitmap( bufor01 );
           menu_p();
           break;
        }
        case 1:
        {
           destroy_bitmap( bufor01 );
           menu_b();
           break;
        }
        case 2:
        {
           destroy_bitmap( bufor01 );
           menu_h();
           break;
        }
        case 3:
        {
           destroy_bitmap( bufor01 );
           exit(0);
           break;
        }
        default:
        {
            //..
            break;
        }
    }
};

void menu_p()   //menu wyboru planszy
{
    int mposit;
    BITMAP * bufor02 = NULL;
    bufor02 = create_bitmap( 1024, 768 );
    bufor02 = load_bitmap( "bmp/menu2.bmp",NULL );
    clear_bitmap( screen );
    blit( bufor02, screen, 0, 0, 0, 0, 1024, 768 );
    button plansza1,plansza2,plansza3,plansza4;

    plansza1.x=440;
    plansza1.y=130;
    plansza1.h=40;
    plansza1.w=150;

    plansza2.x=440;
    plansza2.y=200;
    plansza2.h=40;
    plansza2.w=150;

    plansza3.x=440;
    plansza3.y=270;
    plansza3.h=40;
    plansza3.w=150;

    plansza4.x=440;
    plansza4.y=340;
    plansza4.h=40;
    plansza4.w=150;

    mposit=0;
    rect( screen, plansza1.x, plansza1.y, plansza1.x+plansza1.w, plansza1.y+plansza1.h, makecol( 250, 250, 40 ) );
    install_int( timerproc, 10 );
    //readkey();
    while ( ticks > 0 )
    {
        readkey();
        if ( key[KEY_ENTER] )
            break;
        if ( key[KEY_UP] && mposit > 0 )
        {
            mposit--;
            clear_bitmap( screen );
            blit( bufor02, screen, 0, 0, 0, 0, 1024, 768 );
            if ( mposit == 2 )
            {
                 rect( screen, plansza3.x, plansza3.y, plansza3.x+plansza3.w, plansza3.y+plansza3.h, makecol( 250, 250, 40 ) );
            }
            else if ( mposit == 1 )
            {
                 rect( screen, plansza2.x, plansza2.y, plansza2.x+plansza2.w, plansza2.y+plansza2.h, makecol( 250, 250, 40 ) );
            }
            else if ( mposit == 0 )
            {
                rect( screen, plansza1.x, plansza1.y, plansza1.x+plansza1.w, plansza1.y+plansza1.h, makecol( 250, 250, 40 ) );
            }
        }
        if ( key[KEY_DOWN] && mposit < 3 )
        {
            mposit++;
            clear_bitmap( screen );
            blit( bufor02, screen, 0, 0, 0, 0, 1024, 768 );
            if ( mposit == 3 )
            {
                rect( screen, plansza4.x, plansza4.y, plansza4.x+plansza4.w, plansza4.y+plansza4.h, makecol( 250, 250, 40 ) );
            }
            else if ( mposit == 2 )
            {
                rect( screen, plansza3.x, plansza3.y, plansza3.x+plansza3.w, plansza3.y+plansza3.h, makecol( 250, 250, 40 ) );
            }
            else if ( mposit == 1 )
            {
                 rect( screen, plansza2.x, plansza2.y, plansza2.x+plansza2.w, plansza2.y+plansza2.h, makecol( 250, 250, 40 ) );
            }
        }
      ticks--;
    };
    clear_bitmap(screen);
    destroy_bitmap(bufor02);
    game( mposit );
};

void menu_b()   //menu, najlepsze wyniki
{
    int tczasy[4];
    FONT * MyFont;
    PALETTE palette;
    MyFont = load_font("myfont.pcx", palette, NULL);
    BITMAP * bufor03 = NULL;
    bufor03 = create_bitmap( 1024, 768 );
    bufor03=load_bitmap( "bmp/menu3.bmp",NULL );
    FILE * highsc;
    highsc=fopen( "highscores.txt","r" );
    fscanf( highsc,"%d ",&tczasy[0] );
    fscanf( highsc,"%d ",&tczasy[1] );
    fscanf( highsc,"%d ",&tczasy[2] );
    fscanf( highsc,"%d ",&tczasy[3] );
    fclose(highsc);
    clear_bitmap( screen );
    blit( bufor03, screen, 0, 0, 0, 0, 1024, 768 );
    textout_ex( screen, MyFont, "Najlepsze wyniki", 384, 0, makecol( 255, 0, 0 ), - 1 );
    textprintf_ex( screen, MyFont, 384, 100, makecol( 0, 0, 0 ), - 1, "Plansza 1: %d",tczasy[0]);
    textprintf_ex( screen, MyFont, 384, 200, makecol( 0, 0, 0 ), - 1, "Plansza 2: %d",tczasy[1]);
    textprintf_ex( screen, MyFont, 384, 300, makecol( 0, 0, 0 ), - 1, "Plansza 3: %d",tczasy[2]);
    textprintf_ex( screen, MyFont, 384, 400, makecol( 0, 0, 0 ), - 1, "Plansza 4: %d",tczasy[3]);
    while ( !key[KEY_ESC] );
    destroy_bitmap(bufor03);
    menu_g();
};

void menu_h()   //pomoc, opis sterowania
{
    FILE *highscores;
    FONT * MyFont;
    PALETTE palette;
    MyFont = load_font("myfont.pcx", palette, NULL);
    BITMAP * bufor04 = NULL;
    bufor04 = create_bitmap( 1024, 768 );
    bufor04=load_bitmap("bmp/menu4.bmp",NULL);
    clear_bitmap( screen );
    blit( bufor04, screen, 0, 0, 0, 0, 1024, 768 );
    textout_ex( screen, MyFont, "Pomoc", 384, 0, makecol( 255, 0, 0 ), - 1 );
    textout_ex( screen, MyFont, "Gracz 1 porusza sie klawiszami WSAD.", 10, 100, makecol( 0, 0, 0 ), - 1 );
    textout_ex( screen, MyFont, "Gracz 2 porusza sie strzalkami.", 10, 200, makecol( 0, 0, 0 ), - 1 );
    textout_ex( screen, MyFont, "Gracze, aby przejsc przez drzwi musza najpierw zdobyc klucz.", 10, 300, makecol( 0, 0, 0 ), - 1 );
    textout_ex( screen, MyFont, "Gracz, ktory spotka sie z duchem wraca w miejsce startowe.", 10, 400, makecol( 0, 0, 0 ), - 1 );
    textout_ex( screen, MyFont, "Wygrywa gracz, ktory pierwszy dotrze do skarbu.", 10, 500, makecol( 0, 0, 0 ), - 1 );
    while (!key[KEY_ESC]);
    destroy_bitmap( bufor04 );
    menu_g();
};

void game( int n ) //jedynym argumentem jest numer planszy na ktorej bedzie toczyla sie rozgrywka
{
    FILE *file; //tworzenie plikow
    FILE *highscores;
    FONT * MyFont; //utworzenie czcionki
    PALETTE palette;
    MyFont = load_font("myfont.pcx", palette, NULL); // zaladowanie czcionki
    int frame,t,m1,m2,sp1,sp2,sp3,ghvect,flagend,keyvis,wintime;
    int tczasy[4];
    frame = 0;
    keyvis=1;
    sp1=sp2=3; // predkosc gracz
    sp3=5;     // predkosc ducha
    ghvect=1;  //kierunek ruchu ducha
    flagend=0;
    person pla1,pla2,gh1,key1,chest1,st1,st2,door1,door2;
    BITMAP * bufor05 = NULL;
    BITMAP * mapa = NULL;
    BITMAP* player1=NULL;
    BITMAP* player2=NULL;
    BITMAP* anim1=NULL;
    BITMAP* anim2=NULL;
    BITMAP* ghost1=NULL;
    BITMAP* ghostanim1=NULL;
    BITMAP *tilegfx[TILE_AMOUNT]; //tablica malych bitmap
    mapa = create_bitmap( 1024, 768 );
    tilegfx[0]=load_bitmap( "bmp/tiles/tile00.bmp",NULL );
    tilegfx[1]=load_bitmap( "bmp/tiles/tile01.bmp",NULL );
    tilegfx[2]=load_bitmap( "bmp/tiles/tile02.bmp",NULL );
    tilegfx[3]=load_bitmap( "bmp/tiles/tile03.bmp",NULL );
    tilegfx[4]=load_bitmap( "bmp/tiles/tile04.bmp",NULL );
    tilegfx[5]=load_bitmap( "bmp/tiles/tile05.bmp",NULL );
    tilegfx[6]=load_bitmap( "bmp/tiles/tile06.bmp",NULL );
    tilegfx[7]=load_bitmap( "bmp/tiles/tile07.bmp",NULL );
    tilegfx[8]=load_bitmap( "bmp/tiles/tile08.bmp",NULL );
    tilegfx[9]=load_bitmap( "bmp/tiles/tile09.bmp",NULL );
    tilegfx[10]=load_bitmap( "bmp/tiles/tile10.bmp",NULL );
    tilegfx[11]=load_bitmap( "bmp/tiles/tile11.bmp",NULL );
    tilegfx[12]=load_bitmap( "bmp/tiles/tile12.bmp",NULL );
    tilegfx[13]=load_bitmap( "bmp/tiles/tile13.bmp",NULL );
    tilegfx[14]=load_bitmap( "bmp/tiles/tile14.bmp",NULL );
    tilegfx[15]=load_bitmap( "bmp/tiles/tile15.bmp",NULL );
    switch ( n ) //otwierzamy odpowiednia mape
    {
        case 0:
        {
             file=fopen( "maps/mapa-001.txt","r" );
            break;
        }
        case 1:
        {
             file=fopen( "maps/mapa-002.txt","r" );
            break;
        }
        case 2:
        {
             file=fopen( "maps/mapa-003.txt","r" );
            break;
        }
        case 3:
        {
             file=fopen( "maps/mapa-004.txt","r" );
            break;
        }
        default:
        {
            break;
        }
    };
    int tab[32][24];
    for ( int i=0; i<24; i++ )     //wczytywanie mapy z pliku
        for ( int a=0; a<32; a++ )
        {
            fscanf( file,"%d ",&t );
            tab[a][i]=t;
        };
    fscanf( file,"%d ",&pla1.x ); //wczytywanie wspolrzednych startowych graczy i obiektow
    fscanf( file,"%d ",&pla1.y );
    fscanf( file,"%d ",&pla2.x );
    fscanf( file,"%d ",&pla2.y );
    st1.x=pla1.x;
    st1.y=pla1.y;
    st2.x=pla2.x;
    st2.y=pla2.y;
    fscanf( file,"%d ",&gh1.x );
    fscanf( file,"%d ",&gh1.y );
    fscanf( file,"%d ",&key1.x );
    fscanf( file,"%d ",&key1.y );
    fscanf( file,"%d ",&chest1.x );
    fscanf( file,"%d ",&chest1.y );
    fscanf( file,"%d ",&door1.x );
    fscanf( file,"%d ",&door1.y );
    fscanf( file,"%d ",&door2.x );
    fscanf( file,"%d ",&door2.y );
    for( int i=0; i<24; i++ )   //rysowanie mapy
        for( int a=0; a<32; a++ )
        draw_sprite( mapa,tilegfx[tab[a][i]],0+32*a,0+32*i );
    tab[door1.x][door1.y]=1;
    tab[door2.x][door2.y]=1;
    anim1 = create_bitmap( TILE_SIZE, TILE_SIZE );
    anim2 = create_bitmap( TILE_SIZE, TILE_SIZE );
    ghostanim1 = create_bitmap( TILE_SIZE, TILE_SIZE );
    player1 = load_bitmap( "bmp/person001.bmp",NULL );
    player2 = load_bitmap( "bmp/person002.bmp",NULL );
    ghost1 = load_bitmap( "bmp/ghost001.bmp",NULL );
    blit( player1, anim1, 32, 0, 0, 0, TILE_SIZE, TILE_SIZE );
    blit( player2, anim2, 32, 0, 0, 0, TILE_SIZE, TILE_SIZE );
    blit( ghost1,ghostanim1, 0, 32, 0, 0, TILE_SIZE, TILE_SIZE );
    bufor05 = create_video_bitmap( 1024, 768 );
    install_int( timerproc, 60 );
    blit( mapa, bufor05, 0, 0, 0, 0, 1024, 768 );
    draw_sprite( bufor05, tilegfx[8], door1.x*32, door1.y*32);
    draw_sprite( bufor05, tilegfx[8], door2.x*32, door2.y*32);
    draw_sprite( bufor05, anim1, pla1.x, pla1.y);
    draw_sprite( bufor05, anim2, pla2.x, pla2.y);
    draw_sprite( bufor05, ghostanim1, gh1.x, gh1.y);
    draw_sprite( bufor05, tilegfx[14], chest1.x, chest1.y);
    draw_sprite( bufor05, tilegfx[13], key1.x, key1.y);
    blit( bufor05, screen, 0, 0, 0, 0, 1024, 768 );
    int startTime = clock(); //poczatek mierzenia czasu
    while ( !key[KEY_ESC] && flagend==0 )
    {
        while ( ticks > 0 && flagend==0 )
        {
            if ( key[ KEY_LEFT ] ) // poruszanie sie graczy (gracz 2 w lewo)
            {

                pla2.x=pla2.x-(1*sp2); //zmiana wspolrzednej
                m1=(pla2.x)/32; // obliczanie pola na ktorym gracz sie znajdzie po ruchu
                m2=(pla2.y)/32;
                if( tab[m1][m2] == 0 ) //jesli nie ma tam mury to wykonujemy ruch
                {
                if ( frame < 10 ) //kopiujemy do bitmapy gracza odpowiednia klatke ruchu
                    blit( player2, anim2, 0, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                else if ( frame >= 10 && frame < 20 )
                    blit( player2, anim2, 32, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                else if( frame >= 20 && frame < 30 )
                    blit( player2, anim2, 64, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla2.x=pla2.x+(1*sp2); //w przeciwnym przypadku cofamy ruch gracza
            }

            if ( key[ KEY_RIGHT ] )
            {
                pla2.x=pla2.x+(1*sp2);
                m1=(pla2.x+32)/32;
                m2=(pla2.y)/32;
                if( tab[m1][m2] == 0 )
                {
                if ( frame < 10 )
                    blit( player2, anim2, 0, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                else if ( frame >= 10 && frame < 20 )
                    blit( player2, anim2, 32, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                else if( frame >= 20 && frame < 30 )
                    blit( player2, anim2, 64, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla2.x=pla2.x-(1*sp2);
            }

            if ( key[ KEY_UP ] )
            {
                pla2.y=pla2.y-(1*sp2);
                m1=(pla2.x)/32;
                m2=(pla2.y)/32;
                if( tab[m1][m2]== 0 )
                {
                if ( frame < 10 )
                    blit( player2, anim2, 0, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                else if ( frame >= 10 && frame < 20 )
                    blit( player2, anim2, 32, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                else if( frame >= 20 && frame < 30 )
                    blit( player2, anim2, 64, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla2.y=pla2.y+(1*sp2);
            }

            if ( key[ KEY_DOWN ] )
            {
                pla2.y=pla2.y+(1*sp2);
                m1=(pla2.x)/32;
                m2=(pla2.y+32)/32;
                if( tab[m1][m2]== 0 )
                {
                    if ( frame < 10 )
                        blit( player2, anim2, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( player2, anim2, 32, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( player2, anim2, 64, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla2.y=pla2.y-(1*sp2);
            }

            if ( key[ KEY_A ] )
            {
                pla1.x--;
                m1=(pla1.x)/32;
                m2=(pla1.y)/32;
                if( tab[m1][m2]== 0 )
                {
                    if ( frame < 10 )
                        blit( player1, anim1, 0, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( player1, anim1, 32, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( player1, anim1, 64, 64, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla1.x++;

            }

            if ( key[ KEY_D ] )
            {
                pla1.x++;
                m1=(pla1.x+32)/32;
                m2=(pla1.y)/32;
                if( tab[m1][m2]== 0 )
                {
                    if ( frame < 10 )
                        blit( player1, anim1, 0, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( player1, anim1, 32, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( player1, anim1, 64, 96, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla1.x--;
            }

            if (key[ KEY_W ] )
            {
                pla1.y--;
                m1=(pla1.x)/32;
                m2=(pla1.y)/32;
                if( tab[m1][m2]== 0 )
                {
                    if ( frame < 10 )
                        blit( player1, anim1, 0, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( player1, anim1, 32, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( player1, anim1, 64, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla1.y++;
            }

            if ( key[ KEY_S ] )
            {
                pla1.y++;
                m1=(pla1.x)/32;
                m2=(pla1.y+32)/32;
                if( tab[m1][m2]== 0)
                {
                    if ( frame < 10 )
                        blit( player1, anim1, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( player1, anim1, 32, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( player1, anim1, 64, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                }
                else
                pla1.y--;
            }

            if ( key[ KEY_ESC ])
                break;

            gh1.x = gh1.x+(1*sp3)*ghvect;
            m1 =( gh1.x + 32 )/32;
            m2 =( gh1.y )/32;
            if( tab[m1][m2] == 0 )
            {
                if( ghvect > 0)
                {
                    if ( frame < 10 )
                        blit( ghost1, ghostanim1, 0, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( ghost1, ghostanim1, 32, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( ghost1, ghostanim1, 64, 32, 0, 0, TILE_SIZE, TILE_SIZE );
                    }
                else
                {
                    if ( frame < 10 )
                        blit( ghost1, ghostanim1, 0, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if ( frame >= 10 && frame < 20 )
                        blit( ghost1, ghostanim1, 32, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    else if( frame >= 20 && frame < 30 )
                        blit( ghost1, ghostanim1, 64, 0, 0, 0, TILE_SIZE, TILE_SIZE );
                    }
            }
            else
            {
                gh1.x = gh1.x-(1*sp3)*ghvect;
                ghvect*=-1;
            }
            acquire_bitmap( bufor05 );
            blit( mapa, bufor05, 0, 0, 0, 0, 1024, 768 ); //kopiujemy mape do bufora
            draw_sprite( bufor05, anim1, pla1.x, pla1.y); //rysujemy obiekty na buforze
            draw_sprite( bufor05, anim2, pla2.x, pla2.y);
            draw_sprite( bufor05, ghostanim1, gh1.x, gh1.y);
            if ( keyvis )
            {
                draw_sprite( bufor05, tilegfx[13], key1.x, key1.y);
                draw_sprite( bufor05, tilegfx[8], door1.x*32, door1.y*32);
                draw_sprite( bufor05, tilegfx[8], door2.x*32, door2.y*32);
            }
            draw_sprite( bufor05, tilegfx[14], chest1.x, chest1.y);
            textprintf_ex( bufor05, MyFont, 384, 0, makecol( 0, 0, 0 ), - 1, "Czas gry: %d sekund",( clock() - startTime ) / CLOCKS_PER_SEC );
            blit( bufor05, screen, 0, 0, 0, 0, 1024, 768 ); //kopiujemy bufor na ekran
            release_bitmap( bufor05 ); //wyswietlamy

            ticks--;
            frame++;
            if ( frame > 30)
                frame=0;
            clear_keybuf();
            if( ((pla1.x-gh1.x < 16) && (pla1.x-gh1.x > -16)) && ((pla1.y-gh1.y < 16) && (pla1.y-gh1.y > -16)) )
            {
                pla1.x=st1.x; //gracz 1 jest za blisko ducha, wraca do pozycji startowej
                pla1.y=st1.y;
            }
            if( ((pla2.x-gh1.x < 16) && (pla2.x-gh1.x > -16)) && ((pla2.y-gh1.y < 16) && (pla2.y-gh1.y > -16)) )
            {
                pla2.x=st2.x;
                pla2.y=st2.y;
            }
            if( ((pla1.x-chest1.x < 16) && (pla1.x-chest1.x > -16)) && ((pla1.y-chest1.y < 16) && (pla1.y-chest1.y > -16)) )
            {
                flagend = 1;    //jesli gracz 1 znalazl skarb
                wintime = ( clock() - startTime ) / CLOCKS_PER_SEC; //czas zwyciezcy
                textout_ex( screen, MyFont, "Wygral gracz 1", 384, 384, makecol( 255, 0, 0 ), - 1 );
                highscores=fopen( "highscores.txt","r" ); //wczytywanie rekordow
                fscanf( highscores,"%d ",&tczasy[0] );
                fscanf( highscores,"%d ",&tczasy[1] );
                fscanf( highscores,"%d ",&tczasy[2] );
                fscanf( highscores,"%d ",&tczasy[3] );
                fclose(highscores);
                if (tczasy[n] > wintime) //jesli wynik lepszy od rekordu
                {
                    FILE *highscores1;
                    highscores1=fopen( "highscores.txt","w" );
                    tczasy[n]=wintime;
                    for( int i=0; i<4; ++i)
                        fprintf(highscores1,"%d\n",tczasy[i]);
                    fclose(highscores1);
                }
            }
            if( ((pla2.x-chest1.x < 16) && (pla2.x-chest1.x > -16)) && ((pla2.y-chest1.y < 16) && (pla2.y-chest1.y > -16)) )
            {
                flagend = 1;
                wintime = ( clock() - startTime ) / CLOCKS_PER_SEC;
                textout_ex( screen, MyFont, "Wygral gracz 2", 384, 384, makecol( 255, 0, 0 ), - 1 );
                highscores=fopen( "highscores.txt","r" );
                fscanf( highscores,"%d ",&tczasy[0] );
                fscanf( highscores,"%d ",&tczasy[1] );
                fscanf( highscores,"%d ",&tczasy[2] );
                fscanf( highscores,"%d ",&tczasy[3] );
                fclose(highscores);
                if (tczasy[n] > wintime)
                {
                    FILE *highscores1;
                    highscores1=fopen( "highscores.txt","w" );
                    tczasy[n]=wintime;
                    for( int i=0; i<4; ++i)
                        fprintf(highscores1,"%d\n",tczasy[i]);
                    fclose(highscores1);
                }
            }
            if( ((pla1.x-key1.x < 16) && (pla1.x-key1.x > -16)) && ((pla1.y-key1.y < 16) && (pla1.y-key1.y > -16)) )
            {
                keyvis=0; //gracz 1 zdobyl klucz
                tab[door1.x][door1.y]=0;
                tab[door2.x][door2.y]=0;
            }
            if( ((pla2.x-key1.x < 16) && (pla2.x-key1.x > -16)) && ((pla2.y-key1.y < 16) && (pla2.y-key1.y > -16)) )
            {
                keyvis=0; //gracz 2 zdobyl klucz
                tab[door1.x][door1.y]=0;
                tab[door2.x][door2.y]=0;
            }
        }
    }
    destroy_bitmap( player1 ); //usun bitmapy z pamieci
    destroy_bitmap( player2 );
    destroy_bitmap( anim1 );
    destroy_bitmap( anim2 );
    destroy_bitmap( ghost1 );
    destroy_bitmap( ghostanim1 );
    destroy_bitmap( mapa );
    destroy_bitmap( bufor05 );
    for(int i=0; i<15;++i)
        destroy_bitmap( tilegfx[i] );
    fclose( file );           //zamknj plik
    clear_bitmap( screen );   // wyczysc ekran
    menu_b();   //otworz menu z najlepszymi wynikami
};
