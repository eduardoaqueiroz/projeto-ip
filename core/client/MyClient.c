#include <client.h>
#include <ACore.h>

ALLEGRO_BITMAP *buffer_janela = NULL;

const short int mapa[LARGURA_MAPA][ALTURA_MAPA] = {{15, 11, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 25},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {16, 12, 23, 24, 23, 24, 23, 24, 31, 38, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {-1, -1, -1, -1, -1, -1, -1, -1, 14, 13, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {-1, -1, -1, -1, -1, -1, -1, -1, 14, 13, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {15, 11, 20, 17, 20, 17, 20, 17, 34, 41, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {16, 12, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 26}};

short int tiroVerif = 0;

Regiao defineRegiao(int x, int y){
    //define a regiao do mapa
    Regiao regiao;

    regiao.x = x - (LARGURA_REGIAO/2);
    regiao.xw = regiao.x + LARGURA_REGIAO;

    regiao.y = y - (ALTURA_REGIAO/2);
    regiao.yh = regiao.y + ALTURA_REGIAO;

    return regiao;
}

int main () {
    //inciializa os modilos do allegro
    if(!coreInit())
        return -1;

    if (!windowInit(LARGURA, ALTURA, "Target Server"))
        return -1;

    if(!inputInit())
        return -1;

    if(!fontInit())
        return -1;

    if(!loadGraphics())
        return -1;

    if(!loadSounds())
        return -1;

    buffer_janela = al_create_bitmap(LARGURA, ALTURA);

    char serverIP[] = "127.0.0.1";

    int id = -1;

    //estabelece conexão com o servidor
    connectToServer(serverIP);
    recvMsgFromServer(&id, WAIT_FOR_IT); //recebe o id do cliente
    printf("id: %d\n", id);

    int sair = 0;
    Pack pack;

    while(!sair){
        //cria uma janela auxiliar e deixa preta
        al_set_target_bitmap(buffer_janela);
        al_clear_to_color(al_map_rgb(47, 47, 47));

        if(recvMsgFromServer(&pack, WAIT_FOR_IT) == sizeof(Pack)) {
            if (pack.jogadores[id].hp == 0)
                break; //perdeu

            Regiao regiao = defineRegiao(pack.jogadores[id].x, pack.jogadores[id].y);

            //renderiza mapa
            for (int i=0; i<LARGURA_REGIAO; i++)
                for (int j=0; j<LARGURA_REGIAO; j++)
                    if (regiao.x + i >= 0 && regiao.y + j >= 0 && regiao.x + i < LARGURA_MAPA && regiao.y + j < ALTURA_MAPA)
                        al_draw_bitmap_region(mapaTiles,
                            mapa[regiao.x + i][regiao.y + j]*TILE, 0,
                            TILE, TILE,
                            TILE * i, TILE * j, 0);

            //renderiza jogadores
            for (int i = 0; i < MAX_JOGADORES; i++)
                if (pack.jogadores[i].hp > 0 && pack.jogadores[i].x >= regiao.x && pack.jogadores[i].x < regiao.xw && pack.jogadores[i].y >= regiao.y && pack.jogadores[i].y < regiao.yh)
                    al_draw_bitmap_region(objects,
                        pack.jogadores[i].tile*TILE, (i+1)*TILE,
                        TILE, TILE,
                        TILE * (pack.jogadores[i].x - regiao.x), TILE * (pack.jogadores[i].y - regiao.y), 0);

            //renderiza tiro
            if (pack.tiro.tile != -1 && pack.tiro.x >= regiao.x && pack.tiro.x < regiao.xw && pack.tiro.y >= regiao.y && pack.tiro.y < regiao.yh){
                al_draw_bitmap_region(objects,
                    pack.tiro.tile*TILE, 7*TILE,
                    TILE, TILE,
                    TILE * (pack.tiro.x - regiao.x), TILE * (pack.tiro.y - regiao.y), 0);
                if (tiroVerif == 0){
                    al_play_sample(somTiro, 0.7, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
                tiroVerif = 1;
            } else
                tiroVerif = 0;

            //renderiza informacoes
            if (pack.jogadores[id].hp == 25){
                //1 coracao
            } else if (pack.jogadores[id].hp == 50) {
                //2 coracoes
            } else if (pack.jogadores[id].hp == 75){
                //3 coracoes
            } else {
                //4 coracoes
            }

        }

        //captura eventos
        while(!al_is_event_queue_empty(eventsQueue)){
                ALLEGRO_EVENT event;
                int tecla = 0;

                //recebe evento do teclado
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

                    //envia evento recebido para o servidor
                    sendMsgToServer(&tecla, sizeof(int));
                } else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    sair = 1;
        }

            //exibe os componentes graficos na janela principal
            al_set_target_bitmap(al_get_backbuffer(main_window));
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
            al_flip_display();
    }

    //finaliza os modulos do allegro
    allegroEnd();

    return 0;
}