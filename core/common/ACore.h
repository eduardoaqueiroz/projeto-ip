#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define FPS 40.0
#define IP_MAX_SIZE 100

#define MAX_JOGADORES 6

#define LARGURA 768
#define ALTURA 512

#define LARGURA_MAPA 40
#define ALTURA_MAPA 40

#define LARGURA_REGIAO 24
#define ALTURA_REGIAO 16

#define TILE 32
#define CIMA 2
#define BAIXO 1
#define DIR 0
#define ESQ 3

double startingTime;

ALLEGRO_DISPLAY *main_window;
ALLEGRO_EVENT_QUEUE *eventsQueue;

//FONT AND BITMAP POINTERS
ALLEGRO_FONT *ubuntu;
ALLEGRO_FONT *start;

ALLEGRO_BITMAP *objects;
ALLEGRO_BITMAP *characters;
ALLEGRO_BITMAP *menuScreen;
//========================
//========================

//STRUCTS
typedef struct {
    int hp;
    int x;
    int y;
    int tile;
    int character;
} Jogador;

typedef struct {
    int x;
    int y;
    int tile;
} Tiro;

typedef struct {
    int x;
    int y;
    int xw;
    int yh;
} Regiao;

typedef struct {
    Jogador jogadores[MAX_JOGADORES];
    Tiro tiro;
} Pack;


//MAIN ALLEGRO FUNCTIONS
bool coreInit();
bool windowInit(int W, int H, char title[]);
bool inputInit();
void allegroEnd();

//FPS CONTROL FUNCTIONS
void startTimer();
double getTimer();
void FPSLimit();

//RESOURCE LOADING FUNCTIONS
bool loadGraphics();
bool fontInit();

//INPUT READING FUNCTION
void readInput(ALLEGRO_EVENT event, char str[], int limit);

#endif
