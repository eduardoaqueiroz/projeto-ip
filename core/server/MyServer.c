#include <server.h>
#include <ACore.h>

Pack pack;

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

int main() {
    //incializa o servidor
    serverInit(MAX_JOGADORES);
    printf("Server is running!\n");
    int sair = 0;

    //incializa os jogadores
    for (int i = 0; i < MAX_JOGADORES; i++){
        pack.jogadores[i].hp = 0;
        pack.jogadores[i].hp = 0;

        switch(i){
            case 0:
                pack.jogadores[i].x = 2;
                pack.jogadores[i].y = 2;
                break;
            case 1:
                pack.jogadores[i].x = 38;
                pack.jogadores[i].y = 38;
                break;
            case 2:
                pack.jogadores[i].x = 38;
                pack.jogadores[i].y = 2;
                break;
            case 3:
                pack.jogadores[i].x = 2;
                pack.jogadores[i].y = 38;
                break;
        }

        pack.jogadores[i].tile = 0;
        pack.jogadores[i].character = i;
    }

    pack.tiro.tile = -1;

    while (!sair) {
        //inicializa o contador de tempo, para trabalhar com framerate
        startTimer();

        //realiza conexao com o cliente
        int id = acceptConnection();
        if (id != NO_CONNECTION){
            sendMsgToClient(&id, sizeof(int), id);
            pack.jogadores[id].hp = 100;

            printf("%d conctou-se\n", id);
        }

        int tecla = 0;

        //recebe mensagem
        struct msg_ret_t chegou = recvMsg(&tecla);
        if (chegou.status == MESSAGE_OK) {
            id = chegou.client_id;

            //insere a posicao dos jogadores numa matriz
            int posJogadores[LARGURA_MAPA][ALTURA_MAPA] = {0};
            for (int i = 0; i < MAX_JOGADORES; i++)
                if (pack.jogadores[i].hp > 0)
                    posJogadores[pack.jogadores[i].x][pack.jogadores[i].y] = i + 1;

            //realiza uma ação a depender da tecla pressionada
            switch (tecla) {
                case 1: //cima
                    if (pack.jogadores[id].y > 0 && mapa[pack.jogadores[id].x][pack.jogadores[id].y-1] < 8 && posJogadores[pack.jogadores[id].x][pack.jogadores[id].y-1] == 0){
                        pack.jogadores[id].y--;
                        pack.jogadores[id].tile = CIMA;
                    }
                    break;
                case 2: //baixo
                    if (pack.jogadores[id].y < ALTURA_MAPA - 1 && mapa[pack.jogadores[id].x][pack.jogadores[id].y+1] < 8 && posJogadores[pack.jogadores[id].x][pack.jogadores[id].y+1] == 0){
                        pack.jogadores[id].y++;
                        pack.jogadores[id].tile = BAIXO;
                    }
                    break;
                case 3: //esquerda
                    if (pack.jogadores[id].x > 0 && mapa[pack.jogadores[id].x-1][pack.jogadores[id].y] < 8 && posJogadores[pack.jogadores[id].x-1][pack.jogadores[id].y] == 0){
                        pack.jogadores[id].x--;
                        pack.jogadores[id].tile = ESQ;
                    }
                    break;
                case 4: //direita
                    if (pack.jogadores[id].x < LARGURA_MAPA && mapa[pack.jogadores[id].x+1][pack.jogadores[id].y] < 8 && posJogadores[pack.jogadores[id].x+1][pack.jogadores[id].y] == 0){
                        pack.jogadores[id].x++;
                        pack.jogadores[id].tile = DIR;
                    }
                    break;
                case 5: //espaço - atira
                    pack.tiro.tile = pack.jogadores[id].tile;
                    pack.tiro.x = pack.jogadores[id].x;
                    pack.tiro.y = pack.jogadores[id].y;

                    FPSLimit();

                    //renderiza (frame a frame) o tiro
                    int alcance = 0;
                    while (alcance++ < 8) {
                        startTimer();

                        if (pack.tiro.tile == CIMA)
                            pack.tiro.y--;
                        else if (pack.tiro.tile == BAIXO)
                            pack.tiro.y++;
                        else if (pack.tiro.tile == ESQ)
                            pack.tiro.x--;
                        else
                            pack.tiro.x++;

                        if (mapa[pack.tiro.x][pack.tiro.y] >= 8)
                            break;
                        else if (posJogadores[pack.tiro.x][pack.tiro.y] != 0){
                            pack.jogadores[posJogadores[pack.tiro.x][pack.tiro.y]-1].hp -= 25;
                            break;
                        }

                        //envia o pacote para todos (contendo a posicao da bala)
                        broadcast(&pack, sizeof(Pack));
                        FPSLimit();
                    }
                    startTimer();

                    pack.tiro.tile = -1;
            }
        }

        //envia o pacote atualizado para todos
        broadcast(&pack, sizeof(Pack));

        //compensa o tempo que falta para o fim do tempo do frame
        FPSLimit();
    }

    //finaliza os modulos do allegro
    allegroEnd();
}