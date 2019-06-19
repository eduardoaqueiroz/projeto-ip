#include <server.h>
#include <ACore.h>

const short int mapa[LARGURA_MAPA][ALTURA_MAPA] = {{15, 11, 20, 17, 20, 17, 20, 17, 20, 25, 15, 11, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 17, 20, 25},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 27, 14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 10, 2, 10, 27, 14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 10, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 10, 2, 10, 3, 10, 2, 27, 14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 46, 21, 30, 39, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 45, 34, 41, 4, 2, 4, 3, 4, 2, 10, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 10, 27, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 10, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 46, 21, 30, 39, 4, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 27, -1, 14, 13, 3, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {16, 12, 23, 24, 23, 24, 23, 24, 31, 38, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 27, -1, 14, 13, 4, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {-1, -1, -1, -1, -1, -1, -1, -1, 14, 13, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 45, 20, 33, 42, 3, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {-1, -1, -1, -1, -1, -1, -1, -1, 14, 13, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {15, 11, 20, 17, 20, 17, 20, 17, 34, 41, 4, 2, 10, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 10, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 9, 4, 2, 10, 2, 27, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 46, 21, 30, 39, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 46, 21, 30, 39, 4, 2, 4, 3, 4, 2, 10, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 27, -1, 14, 13, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 27, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 10, 2, 4, 2, 4, 3, 4, 2, 27, -1, 14, 13, 4, 2, 4, 3, 4, 2, 4, 9, 4, 2, 4, 45, 20, 33, 42, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 45, 20, 33, 42, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 10, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13,10, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 4, 2, 4, 2, 4, 3, 46, 21, 30, 39, 4, 3, 4, 2, 4, 3, 4, 2, 46, 21, 30, 39, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 27, -1, 14, 13, 2, 4, 3, 4, 2, 4, 3, 4, 27, -1, 14, 13, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 4, 2, 10, 2, 4, 3, 27, -1, 14, 13, 4, 3, 4, 2, 4, 3, 4, 2, 27, -1, 14, 13, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 45, 20, 33, 42, 2, 4, 3, 4, 2, 4, 3, 4, 45, 20, 33, 42, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 10, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 10, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 9, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 9, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 46, 21, 24, 21, 24, 21, 30, 39, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 10, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 27, -1, -1, -1, -1, -1, 14, 13, 2, 4, 27},
                        {14, 13, 2, 4, 27, -1, 14, 13, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 27, -1, -1,  -1, -1, -1, 14, 13, 4, 2, 27},
                        {14, 13, 4, 2, 27, -1, 14, 13, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 10, 3, 4, 2, 4, 45, 20, 19, 20, 19, 20, 33, 42, 2, 4, 27},
                        {14, 13, 2, 4, 45, 20, 33, 42, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 27},
                        {14, 13, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 2, 4, 3, 4, 2, 4, 3, 4, 2, 4, 2, 4, 2, 4, 2, 4, 3, 4, 2, 4, 27},
                        {16, 12, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 24, 21, 26}};

int main() {
    //incializa o servidor
    serverInit(MAX_JOGADORES);
    printf("Server is running!\n");
    int sair = 0;

    PacoteServidor pacoteServidor;
    PacoteCliente pacoteCliente;
    int comecou = 0;

    //incializa os jogadores
    for (int i = 0; i < MAX_JOGADORES; i++){
        pacoteServidor.jogadores[i].hp = 0;
        pacoteServidor.jogadores[i].hp = 0;

        switch(i){
            case 0:
                pacoteServidor.jogadores[i].x = 2;
                pacoteServidor.jogadores[i].y = 2;
                break;
            case 1:
                pacoteServidor.jogadores[i].x = 38;
                pacoteServidor.jogadores[i].y = 38;
                break;
            case 2:
                pacoteServidor.jogadores[i].x = 38;
                pacoteServidor.jogadores[i].y = 2;
                break;
            case 3:
                pacoteServidor.jogadores[i].x = 2;
                pacoteServidor.jogadores[i].y = 38;
                break;
        }

        pacoteServidor.jogadores[i].tile = 0;
        pacoteServidor.jogadores[i].character = i;
    }

    pacoteServidor.jogadores[0].tile = -1;

    pacoteServidor.tiro.tile = -1;

    while (!sair) {
        //inicializa o contador de tempo, para trabalhar com framerate
        startTimer();

        //realiza conexao com o cliente
        int id = acceptConnection();
        if (id != NO_CONNECTION){
            sendMsgToClient(&id, sizeof(int), id);
            pacoteServidor.jogadores[id].hp = 100;

            printf("%d conctou-se\n", id);
        }

        //recebe mensagem
        struct msg_ret_t chegou = recvMsg(&pacoteCliente);
        if (chegou.status == MESSAGE_OK) {
            if (!comecou) {
                if (pacoteCliente.comecou == 1) {
                    pacoteServidor.jogadores[0].tile = 0;
                    comecou = 1;
                    broadcast(&pacoteServidor, sizeof(PacoteServidor));
                }
            } else {
                id = chegou.client_id;
                //insere a posicao dos jogadores numa matriz
                int posJogadores[LARGURA_MAPA][ALTURA_MAPA] = {0};
                for (int i = 0; i < MAX_JOGADORES; i++)
                    if (pacoteServidor.jogadores[i].hp > 0)
                        posJogadores[pacoteServidor.jogadores[i].x][pacoteServidor.jogadores[i].y] = i + 1;

                //realiza uma ação a depender da pacoteCliente.tecla pressionada
                switch (pacoteCliente.tecla) {
                    case 1: //cima
                        if (pacoteServidor.jogadores[id].y > 0 && mapa[pacoteServidor.jogadores[id].x][pacoteServidor.jogadores[id].y-1] < 8 && posJogadores[pacoteServidor.jogadores[id].x][pacoteServidor.jogadores[id].y-1] == 0){
                            pacoteServidor.jogadores[id].y--;
                            pacoteServidor.jogadores[id].tile = CIMA;
                        }
                        break;
                    case 2: //baixo
                        if (pacoteServidor.jogadores[id].y < ALTURA_MAPA - 1 && mapa[pacoteServidor.jogadores[id].x][pacoteServidor.jogadores[id].y+1] < 8 && posJogadores[pacoteServidor.jogadores[id].x][pacoteServidor.jogadores[id].y+1] == 0){
                            pacoteServidor.jogadores[id].y++;
                            pacoteServidor.jogadores[id].tile = BAIXO;
                        }
                        break;
                    case 3: //esquerda
                        if (pacoteServidor.jogadores[id].x > 0 && mapa[pacoteServidor.jogadores[id].x-1][pacoteServidor.jogadores[id].y] < 8 && posJogadores[pacoteServidor.jogadores[id].x-1][pacoteServidor.jogadores[id].y] == 0){
                            pacoteServidor.jogadores[id].x--;
                            pacoteServidor.jogadores[id].tile = ESQ;
                        }
                        break;
                    case 4: //direita
                        if (pacoteServidor.jogadores[id].x < LARGURA_MAPA && mapa[pacoteServidor.jogadores[id].x+1][pacoteServidor.jogadores[id].y] < 8 && posJogadores[pacoteServidor.jogadores[id].x+1][pacoteServidor.jogadores[id].y] == 0){
                            pacoteServidor.jogadores[id].x++;
                            pacoteServidor.jogadores[id].tile = DIR;
                        }
                        break;
                    case 5: //espaço - atira
                        pacoteServidor.tiro.tile = pacoteServidor.jogadores[id].tile;
                        pacoteServidor.tiro.x = pacoteServidor.jogadores[id].x;
                        pacoteServidor.tiro.y = pacoteServidor.jogadores[id].y;

                        FPSLimit();

                        //renderiza (frame a frame) o tiro
                        int alcance = 0;
                        while (alcance++ < 8) {
                            startTimer();

                            if (pacoteServidor.tiro.tile == CIMA)
                                pacoteServidor.tiro.y--;
                            else if (pacoteServidor.tiro.tile == BAIXO)
                                pacoteServidor.tiro.y++;
                            else if (pacoteServidor.tiro.tile == ESQ)
                                pacoteServidor.tiro.x--;
                            else
                                pacoteServidor.tiro.x++;

                            if (mapa[pacoteServidor.tiro.x][pacoteServidor.tiro.y] >= 8)
                                break;
                            else if (posJogadores[pacoteServidor.tiro.x][pacoteServidor.tiro.y] != 0){
                                pacoteServidor.jogadores[posJogadores[pacoteServidor.tiro.x][pacoteServidor.tiro.y]-1].hp -= 25;
                                break;
                            }

                            broadcast(&pacoteServidor, sizeof(PacoteServidor));
                            FPSLimit();
                        }
                        startTimer();

                        pacoteServidor.tiro.tile = -1;
                }
            }
        }

        broadcast(&pacoteServidor, sizeof(PacoteServidor));

        //compensa o tempo que falta para o fim do tempo do frame
        FPSLimit();
    }

    //finaliza os modulos do allegro
    allegroEnd();
}