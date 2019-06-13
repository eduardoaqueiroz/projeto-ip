#include <client.h>
#include <ACore.h>

#define TILE 32

typedef struct {
    int id;
    int hp;
    int x;
    int y;
    int tile;
    int character;
} Jogador;

typedef struct {
    Jogador jogadores[6];
    int qtdJogadores;
} Pack;

short int mapa[20][20] = {{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int main () {
    if(!coreInit())
        return -1;

    if (!windowInit(640, 640, "Target Server"))
        return -1;

    if(!inputInit())
        return -1;

    if(!fontInit())
        return -1;

    if(!loadGraphics())
        return -1;

    char serverIP[] = "127.0.0.1";

    int id = -1;

    connectToServer(serverIP);
    recvMsgFromServer(&id, WAIT_FOR_IT);
    printf("id: %d\n", id);

    int sair = 0;
    Pack pack, packAux;

    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++){
            al_draw_bitmap_region(objects,
                mapa[i][j]*TILE, 2*TILE,
                TILE, TILE,
                TILE * i, TILE * j, 0);
        }
    }

    if (recvMsgFromServer(&pack, WAIT_FOR_IT) == sizeof(Pack)) {
        for (int i = 0; i < pack.qtdJogadores; i++){
            Jogador jogador = pack.jogadores[i];
            al_draw_bitmap_region(objects,
                    pack.jogadores[i].tile*TILE, 5*TILE,
                    TILE, TILE,
                    TILE*pack.jogadores[i].x, TILE*pack.jogadores[i].y, 0);
        }
    } else
        return -1;

    al_flip_display();

    while(!sair){
        startTimer();

        packAux = pack;
        if(recvMsgFromServer(&pack, WAIT_FOR_IT) == sizeof(Pack)) {
            int mudou = 0;
            for (int i = 0; i < pack.qtdJogadores && i < packAux.qtdJogadores; i++){
                printf("%d %d\n", pack.jogadores[i].x, pack.jogadores[i].y);
                if (packAux.jogadores[i].x != pack.jogadores[i].x || packAux.jogadores[i].y != pack.jogadores[i].y){
                    al_draw_bitmap_region(objects,
                        mapa[packAux.jogadores[i].x][packAux.jogadores[i].y]*TILE, 2*TILE,
                        TILE, TILE,
                        TILE * packAux.jogadores[i].x, TILE * packAux.jogadores[i].y, 0);

                    al_draw_bitmap_region(objects,
                        pack.jogadores[i].tile*TILE, 5*TILE,
                        TILE, TILE,
                        TILE * pack.jogadores[i].x, TILE * pack.jogadores[i].y, 0);

                    mudou = 1;
                }
            }

            if (mudou)
                al_flip_display();
        }

        while(!al_is_event_queue_empty(eventsQueue)){
                ALLEGRO_EVENT event;
                int tecla = 0;
                al_wait_for_event(eventsQueue, &event);
                if(event.type == ALLEGRO_EVENT_KEY_CHAR){
                    if(event.keyboard.keycode == ALLEGRO_KEY_UP)
                        tecla = 1;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                        tecla = 2;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                        tecla = 3;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                        tecla = 4;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
                        tecla = 5;

                    sendMsgToServer(&tecla, sizeof(int));
                } else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                    sair = 1;
                }
        }

        //FPSLimit();
    }

    allegroEnd();

    return 0;
}