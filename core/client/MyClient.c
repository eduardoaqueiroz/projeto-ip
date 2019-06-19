#include <client.h>
#include <ACore.h>

ALLEGRO_BITMAP *buffer_janela = NULL;

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

void exibeMensagem(char str[50]){
    int sair = 0;

    while(!sair) {
        startTimer();

        al_set_audio_stream_playing(somMenu, true);

        al_set_target_bitmap(buffer_janela);
        al_clear_to_color(al_map_rgb(47, 47, 47));

        al_draw_scaled_bitmap(bg, 0, 0, al_get_bitmap_width(bg), al_get_bitmap_height(bg), 0, 0, LARGURA, ALTURA, 0);

        al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA/2, 250, ALLEGRO_ALIGN_CENTER, str);

        al_set_target_bitmap(al_get_backbuffer(main_window));
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(eventsQueue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            sair = 1;

        FPSLimit();
    }

    allegroEnd();
}

int main () {
    //inciializa os modilos do allegro
    if(!coreInit())
        return -1;

    if (!windowInit(LARGURA, ALTURA, "CInFIRE"))
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

    int sairInic = 0;

    int opc = 0;

    al_attach_audio_stream_to_mixer(somMenu, al_get_default_mixer());
    al_set_audio_stream_playmode(somMenu, ALLEGRO_PLAYMODE_LOOP);

    while(!sairInic) {
        startTimer();

        al_set_target_bitmap(buffer_janela);
        al_clear_to_color(al_map_rgb(47, 47, 47));

        al_draw_scaled_bitmap(bgInit, 0, 0, al_get_bitmap_width(bgInit), al_get_bitmap_height(bgInit), 0, 0, LARGURA, ALTURA, 0);

        al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA - 40, 350, ALLEGRO_ALIGN_RIGHT, "JOGAR");
        al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA - 40, 390, ALLEGRO_ALIGN_RIGHT, "OPCOES");
        al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA - 40, 430, ALLEGRO_ALIGN_RIGHT, "SAIR");

        if (opc == 0)
            al_draw_text(subtitulo, al_map_rgb(255,200,0), LARGURA - 40, 350, ALLEGRO_ALIGN_RIGHT, "JOGAR");
        else if (opc == 1)
            al_draw_text(subtitulo, al_map_rgb(255,200,0), LARGURA - 40, 390, ALLEGRO_ALIGN_RIGHT, "OPCOES");
        else
            al_draw_text(subtitulo, al_map_rgb(255,200,0), LARGURA - 40, 430, ALLEGRO_ALIGN_RIGHT, "SAIR");

        al_set_target_bitmap(al_get_backbuffer(main_window));
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(eventsQueue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if(event.keyboard.keycode == ALLEGRO_KEY_UP && opc > 0)
                opc--;
            else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN && opc < 2)
                opc++;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && opc == 0)
                sairInic = 1;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && opc == 1)
                sairInic = -1; //opcoes
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && opc == 2)
                sairInic = -1;
        } else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            sairInic = -1;

        FPSLimit();
    }

    if (sairInic == -1){
        allegroEnd();
        return 0;
    }

    int sairIpReq = 0;
    char ipServidor[20] = {0};
    bool enter = 1;

    while(!sairIpReq) {
        startTimer();

        al_set_target_bitmap(buffer_janela);
        al_clear_to_color(al_map_rgb(47, 47, 47));

        al_draw_scaled_bitmap(bg, 0, 0, al_get_bitmap_width(bg), al_get_bitmap_height(bg), 0, 0, LARGURA, ALTURA, 0);
        al_draw_text(titulo, al_map_rgb(255,255,255), LARGURA/2, 150, ALLEGRO_ALIGN_CENTER, "DIGITE SEU IP:");
        al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA/2, 250, ALLEGRO_ALIGN_CENTER, ipServidor);

        al_set_target_bitmap(al_get_backbuffer(main_window));
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(eventsQueue, &event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
            if ((event.keyboard.unichar >= '0' && event.keyboard.unichar <= '9') || event.keyboard.unichar == '.')
                ipServidor[strlen(ipServidor)] = event.keyboard.unichar;
            else if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
                ipServidor[strlen(ipServidor) - 1] = 0;
            else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER && enter == false)
                sairIpReq = 1;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            sairIpReq = -1;

        enter = 0;
        FPSLimit();
    }

    if (sairIpReq == -1){
        allegroEnd();
        return 0;
    }

    al_set_audio_stream_playing(somMenu, false);

    int id = -1;

    //estabelece conexão com o servidor
    connectToServer(ipServidor);
    recvMsgFromServer(&id, WAIT_FOR_IT); //recebe o id do cliente

    if (id < 0 || id >= MAX_JOGADORES){
        exibeMensagem("Falha na conexão");
        return -1;
    }

    if (id == 0) {
        int sairEspera = 0;

        PacoteCliente pacoteCliente;
        pacoteCliente.comecou = 0;
        pacoteCliente.tecla = 0;

        while(!sairEspera) {
            al_set_target_bitmap(buffer_janela);
            al_clear_to_color(al_map_rgb(47, 47, 47));

            al_draw_scaled_bitmap(bg, 0, 0, al_get_bitmap_width(bg), al_get_bitmap_height(bg), 0, 0, LARGURA, ALTURA, 0);
            al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA/2, 250, ALLEGRO_ALIGN_CENTER, "Pressione espaço para iniciar");

            al_set_target_bitmap(al_get_backbuffer(main_window));
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
            al_flip_display();

            if(!al_is_event_queue_empty(eventsQueue)) {
                ALLEGRO_EVENT event;
                al_wait_for_event(eventsQueue, &event);

                if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    sairEspera = -1;
                else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE && enter == false)
                    pacoteCliente.comecou = 1;
            }

            sendMsgToServer(&pacoteCliente, sizeof(PacoteCliente));

            PacoteServidor pacoteServidor;
            recvMsgFromServer(&pacoteServidor, WAIT_FOR_IT);
            if (pacoteServidor.jogadores[0].tile >= 0 && pacoteServidor.jogadores[0].tile <= 3)
                sairEspera = 1;
        }

        if (sairEspera == -1) {
            allegroEnd();
            return -1;
        }
    } else {
        int sairEspera = 0;
        while(!sairEspera) {
            al_set_target_bitmap(buffer_janela);
            al_clear_to_color(al_map_rgb(47, 47, 47));

            al_draw_scaled_bitmap(bg, 0, 0, al_get_bitmap_width(bg), al_get_bitmap_height(bg), 0, 0, LARGURA, ALTURA, 0);

            al_draw_text(subtitulo, al_map_rgb(255,255,255), LARGURA/2, 250, ALLEGRO_ALIGN_CENTER, "Aguardando início da partida");

            al_set_target_bitmap(al_get_backbuffer(main_window));
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
            al_flip_display();

            if(!al_is_event_queue_empty(eventsQueue)) {
                ALLEGRO_EVENT event;
                al_wait_for_event(eventsQueue, &event);

                if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    sairEspera = -1;
            }

            PacoteServidor pacoteServidor;
            recvMsgFromServer(&pacoteServidor, WAIT_FOR_IT);
            if (pacoteServidor.jogadores[0].tile >= 0 && pacoteServidor.jogadores[0].tile <= 3)
                sairEspera = 1;
        }

        if (sairEspera == -1){
            allegroEnd();
            return -1;
        }
    }

    bool sairJogo = 0;
    int ganhou = -1;
    PacoteServidor pacoteServidor;
    PacoteCliente pacoteCliente;
    pacoteCliente.comecou = 1;

    while(!sairJogo) {
        //cria uma janela auxiliar e deixa preta
        al_set_target_bitmap(buffer_janela);
        al_clear_to_color(al_map_rgb(47, 47, 47));

        if(recvMsgFromServer(&pacoteServidor, WAIT_FOR_IT) == sizeof(PacoteServidor)) {
            if (pacoteServidor.jogadores[id].hp == 0){
                ganhou = 0;
                break;
            }

            Regiao regiao = defineRegiao(pacoteServidor.jogadores[id].x, pacoteServidor.jogadores[id].y);
            int numJogadores = 0;

            //renderiza mapa
            for (int i=0; i<LARGURA_REGIAO; i++)
                for (int j=0; j<ALTURA_REGIAO; j++)
                    if (regiao.x + i >= 0 && regiao.y + j >= 0 && regiao.x + i < LARGURA_MAPA && regiao.y + j < ALTURA_MAPA)
                        al_draw_bitmap_region(mapaTiles,
                            mapa[regiao.x + i][regiao.y + j]*TILE, 0,
                            TILE, TILE,
                            TILE * i, TILE * j, 0);

            //renderiza jogadores
            for (int i = 0; i < MAX_JOGADORES; i++)
                if (pacoteServidor.jogadores[i].hp > 0){
                    numJogadores++;
                    if (pacoteServidor.jogadores[i].x >= regiao.x && pacoteServidor.jogadores[i].x < regiao.xw && pacoteServidor.jogadores[i].y >= regiao.y && pacoteServidor.jogadores[i].y < regiao.yh)
                        al_draw_bitmap_region(objects,
                            pacoteServidor.jogadores[i].tile*TILE, (i+1)*TILE,
                            TILE, TILE,
                            TILE * (pacoteServidor.jogadores[i].x - regiao.x), TILE * (pacoteServidor.jogadores[i].y - regiao.y), 0);
                }

            if (numJogadores == 1){
                ganhou = 1;
                break;
            }

            //renderiza tiro
            if (pacoteServidor.tiro.tile != -1 && pacoteServidor.tiro.x >= regiao.x && pacoteServidor.tiro.x < regiao.xw && pacoteServidor.tiro.y >= regiao.y && pacoteServidor.tiro.y < regiao.yh){
                al_draw_bitmap_region(objects,
                    pacoteServidor.tiro.tile*TILE, 7*TILE,
                    TILE, TILE,
                    TILE * (pacoteServidor.tiro.x - regiao.x), TILE * (pacoteServidor.tiro.y - regiao.y), 0);
                if (tiroVerif == 0){
                    al_play_sample(somTiro, 0.7, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
                tiroVerif = 1;
            } else
                tiroVerif = 0;

            char texto[20];
            sprintf(texto, "Jogadores vivos: %d", numJogadores);

            //renderiza informacoes
            al_draw_text(info, al_map_rgb(255, 255, 255), LARGURA - 120, 5, ALLEGRO_ALIGN_RIGHT, texto);
            al_draw_text(infoMaior, al_map_rgb(0, 0, 0), LARGURA - 8, 2, ALLEGRO_ALIGN_RIGHT, "♥ ♥ ♥ ♥");
            al_draw_text(info, al_map_rgb(100, 100, 100), LARGURA - 10, 5, ALLEGRO_ALIGN_RIGHT, "♥  ♥  ♥  ♥");
            if (pacoteServidor.jogadores[id].hp ==  25)
                al_draw_text(info, al_map_rgb(255, 0, 0), LARGURA - 10, 5, ALLEGRO_ALIGN_RIGHT, "♥         ");
            else if (pacoteServidor.jogadores[id].hp == 50)
                al_draw_text(info, al_map_rgb(255, 0, 0), LARGURA - 10, 5, ALLEGRO_ALIGN_RIGHT, "♥  ♥      ");
            else if (pacoteServidor.jogadores[id].hp == 75)
                al_draw_text(info, al_map_rgb(255, 0, 0), LARGURA - 10, 5, ALLEGRO_ALIGN_RIGHT, "♥  ♥  ♥   ");
            else
                al_draw_text(info, al_map_rgb(255, 0, 0), LARGURA - 10, 5, ALLEGRO_ALIGN_RIGHT, "♥  ♥  ♥  ♥");
        }

        //captura eventos
        while(!al_is_event_queue_empty(eventsQueue)){
            ALLEGRO_EVENT event;
            pacoteCliente.tecla = 0;

            //recebe evento do pacoteCliente.teclado
            al_wait_for_event(eventsQueue, &event);
            if(event.type == ALLEGRO_EVENT_KEY_CHAR){
                if(event.keyboard.keycode == ALLEGRO_KEY_UP)
                    pacoteCliente.tecla = 1;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                        pacoteCliente.tecla = 2;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
                        pacoteCliente.tecla = 3;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                        pacoteCliente.tecla = 4;
                    else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
                        pacoteCliente.tecla = 5;

                //envia evento recebido para o servidor
                sendMsgToServer(&pacoteCliente, sizeof(PacoteCliente));
            } else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                sairJogo = 1;
        }

            //exibe os componentes graficos na janela principal
            al_set_target_bitmap(al_get_backbuffer(main_window));
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_scaled_bitmap(buffer_janela, 0, 0, LARGURA, ALTURA, 0, 0, LARGURA, ALTURA, 0);
            al_flip_display();
    }

    if (ganhou == 1)
        exibeMensagem("Parabéns, voce ganhou!");
    else if (ganhou == 0)
        exibeMensagem("GAME OVER");

    //finaliza os modulos do allegro
    allegroEnd();

    return 0;
}
