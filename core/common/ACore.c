#include "ACore.h"

/*
INITIALIZATION OF BASIC CORE MODULES:
--ALLEGRO
--ALLEGRO IMAGE
--ALLEGRO FONTS
--ALLEGRO TTF FONT SUPPORT
--ALLEGRO PRIMITIVES
--EVENT QUEUE
*/
bool coreInit() {
    //modules and add-ons initialization
	if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar Allegro.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_init_font_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_font.\n");
        return false;
    }

    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_primitives.\n");
        return false;
    }
    if(!al_install_audio()) {
        printf("Falha ao instalar o audio.\n");
        return 0;
    }
    if(!al_init_acodec_addon()) {
        printf("Falha ai inicializar o codec de audio.\n");
        return 0;
    }
    if(!al_reserve_samples(15)) {
        printf("Nao foi possivel reservar as amostras de audio necessarias.\n");
        return 0;
    }

    eventsQueue = al_create_event_queue();
    if (!eventsQueue) {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        return false;
    }

    return true;
}


//FOR INITIALIZING A WINDOW OF WxH SIZE WITH TEXT "title[]"
bool windowInit(int W, int H, char title[]) {
    //window and event queue creation
    main_window = al_create_display(W, H);
    if (!main_window)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
    al_set_window_title(main_window, title);

    //registra janela na fila de eventos
    al_register_event_source(eventsQueue, al_get_display_event_source(main_window));

    return true;
}


//FOR INITIALIZING MAIN EXTERNAL INPUTS (KEYBOARD, MOUSE AND CURSOR)
bool inputInit() {
    /*------------------------------KEYBOARD------------------------------*/
    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    //Registra teclado na fila de eventos
    al_register_event_source(eventsQueue, al_get_keyboard_event_source());

    return true;
}

//FPS CONTROL (FPS IS DEFINED IN ACORE.H)
void startTimer() {
    startingTime = al_get_time();
}

void FPSLimit() {
    al_rest((1.0 / FPS) - (al_get_time() - startingTime));
}

//FOR DEALLOCATING ALL ALLEGRO STUFF
void allegroEnd() {
    al_destroy_bitmap(objects);
    al_destroy_bitmap(bg);
    al_destroy_bitmap(mapaTiles);
    al_destroy_display(main_window);
    al_destroy_event_queue(eventsQueue);
    al_destroy_font(titulo);
    al_destroy_font(info);
    al_destroy_font(infoMaior);
    al_destroy_sample(somTiro);
    al_destroy_audio_stream(somMenu);
}


//MODIFY THIS TO LOAD YOUR OWN FONTS (FONT POINTERS ARE DEFINED AT ACORE.H)
bool fontInit() {
    /*------------------------------FONTE--------------------------------*/
    titulo = al_load_font("core/Resources/Fonts/joystix_monospace.ttf", 50, 0);
    if (!titulo) {
        fprintf(stderr, "Falha ao carregar \"core/Resources/Fonts/joystix_monospace.ttf\".\n");
        return false;
    }

    subtitulo = al_load_font("core/Resources/Fonts/joystix_monospace.ttf", 30, 0);
    if (!titulo) {
        fprintf(stderr, "Falha ao carregar \"core/Resources/Fonts/joystix_monospace.ttf\".\n");
        return false;
    }

    info = al_load_font("core/Resources/Fonts/joystix_monospace.ttf", 10, 0);
    if (!info) {
        fprintf(stderr, "Falha ao carregar \"core/Resources/Fonts/joystix_monospace.ttf\".\n");
        return false;
    }

    infoMaior = al_load_font("core/Resources/Fonts/joystix_monospace.ttf", 15, 0);
    if (!infoMaior) {
        fprintf(stderr, "Falha ao carregar \"core/Resources/Fonts/joystix_monospace.ttf\".\n");
        return false;
    }

    return true;
}


//MODIFY THIS TO LOAD YOUR OWN GRAPHICS (BITMAP POINTERS ARE DEFINED AT ACORE.H)
bool loadGraphics() {
    objects = al_load_bitmap("core/Resources/Tilesets/objects.png");
    if (!objects){
        fprintf(stderr, "Falha carregando objects.png\n");
        return false;
    }

    mapaTiles = al_load_bitmap("core/Resources/Tilesets/mapa.png");
    if (!mapaTiles){
        fprintf(stderr, "Falha carregando tileSet do mapa.png\n");
        return false;
    }

    bg = al_load_bitmap("core/Resources/Tilesets/bg.png");
    if (!bg){
        fprintf(stderr, "Falha carregando a imagem de fundo da tela inicial.png\n");
        return false;
    }

    return true;
}

bool loadSounds() {
    somTiro = al_load_sample("core/Resources/Etc/shot.ogg");
    if (!somTiro){
        fprintf(stderr, "Falha carregando som somTiro\n");
        return false;
    }

    somMenu = al_load_audio_stream("core/Resources/Etc/menuTheme.ogg", 4, 1024);
    if (!somMenu){
        fprintf(stderr, "Falha carregando som somMenu\n");
        return false;
    }

    return true;
}