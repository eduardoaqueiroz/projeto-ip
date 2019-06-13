#include <server.h>
#include <ACore.h>

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

Pack pack;

void criaJogador(int id){
    Jogador jogador;
    jogador.id = id;
    jogador.hp = 100;
    jogador.x = 0;
    jogador.y = 0;
    jogador.tile = 0;
    jogador.character = pack.qtdJogadores;

    pack.jogadores[pack.qtdJogadores] = jogador;

    pack.qtdJogadores++;
}

int buscaJogador(int id){
    for (int i=0; i<pack.qtdJogadores; i++)
        if (pack.jogadores[i].id == id)
            return i;
    return -1;
}

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

int main() {
    serverInit(6);
    printf("Server is running!\n");
    int sair = 0;

    pack.qtdJogadores = 0;

    while (!sair) {
        startTimer();

        int id = acceptConnection();
        if (id != NO_CONNECTION){
            sendMsgToClient(&id, sizeof(int), id);
            if (buscaJogador(id) == -1)
                criaJogador(id);

            printf("%d conctou-se\n", id);
        }

        int tecla = 0;

        struct msg_ret_t chegou = recvMsg(&tecla);
        if(chegou.status == MESSAGE_OK){
            short int posJogadores[20][20] = {0};
            for (int i = 0; i < pack.qtdJogadores; i++)
                posJogadores[pack.jogadores[i].x][pack.jogadores[i].y] = 1;
            Jogador jogador = pack.jogadores[buscaJogador(chegou.client_id)];
            switch (tecla){
                case 1:
                    if (jogador.y > 0 && mapa[jogador.x][jogador.y-1] == 0 && posJogadores[jogador.x][jogador.y-1] == 0){
                        jogador.y--;
                        jogador.tile = 2;
                    }
                    break;
                case 2:
                    if (jogador.y < 19 && mapa[jogador.x][jogador.y+1] == 0 && posJogadores[jogador.x][jogador.y+1] == 0){
                        jogador.y++;
                        jogador.tile = 1;
                    }
                    break;
                case 3:
                    if (jogador.x > 0 && mapa[jogador.x-1][jogador.y] == 0 && posJogadores[jogador.x-1][jogador.y] == 0){
                        jogador.x--;
                        jogador.tile = 3;
                    }
                    break;
                case 4:
                    if (jogador.x < 19 && mapa[jogador.x+1][jogador.y] == 0 && posJogadores[jogador.x+1][jogador.y] == 0){
                        jogador.x++;
                        jogador.tile = 0;
                    }
                    break;
            }

            pack.jogadores[buscaJogador(chegou.client_id)] = jogador;
        }

        broadcast(&pack, sizeof(Pack));

        //FPSLimit();
    }

    allegroEnd();
}