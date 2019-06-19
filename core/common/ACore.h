#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define FPS 40.0
#define IP_MAX_SIZE 100

#define MAX_JOGADORES 4

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

// Estruturas da tela de menu.
ALLEGRO_FONT *titulo;
ALLEGRO_FONT *subtitulo;
ALLEGRO_FONT *info;
ALLEGRO_FONT *infoMaior;

// Estruturas da tela de jogo.
ALLEGRO_SAMPLE *somTiro;
ALLEGRO_BITMAP *objects;
ALLEGRO_BITMAP *menuScreen;
ALLEGRO_BITMAP *mapaTiles;

// Estruturas da tela de opcoes.
ALLEGRO_BITMAP *bg;
ALLEGRO_BITMAP *bgInit;
ALLEGRO_AUDIO_STREAM *somMenu;
ALLEGRO_FONT *somSituacao;
ALLEGRO_FONT *avisoEsc;
ALLEGRO_FONT *interruptor;

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
} PacoteServidor;

typedef struct {
    int tecla;
    int comecou;
} PacoteCliente;


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
bool loadSounds();

//INPUT READING FUNCTION
void readInput(ALLEGRO_EVENT event, char str[], int limit);

#endif
