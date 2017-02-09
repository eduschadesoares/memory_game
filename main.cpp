//#PANQUECA

//BIBLIOTECAS (INÍCIO) =======================================================//

#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//BIBLIOTECAS (FIM) ==========================================================//

//CONSTANTES (INÍCIO) ========================================================//

#define maxx 1366
#define maxy 768

//CONSTANTES (FIM) ===========================================================//

//PROTÓTIPOS (INÍCIO) ========================================================//

void init();
void deinit();
void menu();
void creditos();
void jogo();

//PROTÓTIPOS (FIM) ===========================================================//

//FUNÇÃO PRINCIPAL (INÍCIO) ==================================================//

int main() {
	init();
	menu();
	deinit();
	return 0;
}

END_OF_MAIN()

//FUNÇÃO PRINCIPAL (FIM) =====================================================//





























//FUNÇÕES (INÍCIO) ===========================================================//

//FUNÇÃO INICIALIZAÇÃO (INÍCIO) **********************************************//

void init() {
	int depth;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) {
    depth = 8;
    }
    
//Definição de Cor
    
	set_color_depth(depth);
	install_timer();
	install_keyboard();
	install_mouse();
	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, maxx, maxy, 0, 0);
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_window_title("Elefante");
	
//Volume
    
	set_volume(150, 255);
	
}

//FUNÇÃO INICIALIZAÇÃO (FIM) *************************************************//

//FECHAR O ALLEGRO (INÍCIO) **************************************************//

void deinit() {
	clear_keybuf();
	allegro_exit();
}

//FECHAR O ALLEGRO (FIM) *****************************************************//

//FUNÇÃO MENU (INÍCIO) *******************************************************//

void menu() {
     
//Palettes

    PALETTE	pal;
    
//Bitmaps

    BITMAP* cursor = load_bitmap("source\\seta3.BMP", NULL);
    BITMAP* tela = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP  *maintext = load_bitmap("Menus\\maintext.bmp",pal);
	BITMAP  *jogar1 = load_bitmap("Menus\\jogar1.bmp",pal);
	BITMAP  *jogar2 = load_bitmap("Menus\\jogar2.bmp",pal);
	BITMAP  *cred1 = load_bitmap("Menus\\cred1.bmp",pal);
	BITMAP  *cred2 = load_bitmap("Menus\\cred2.bmp",pal);
	BITMAP  *sair1 = load_bitmap("Menus\\sair1.bmp",pal);
	BITMAP  *sair2 = load_bitmap("Menus\\sair2.bmp",pal);
	BITMAP  *prod = load_bitmap("Menus\\prod.bmp", pal);
	

	

//Menu Loop

	while (!key[KEY_ESC]) {

    draw_sprite(tela, cursor, mouse_x, mouse_y);
    draw_sprite(screen, tela, 0, 0);
    clear(tela);
    clear_keybuf();
    
    draw_sprite(tela, maintext, (maxx / 2) - 370, 100);
    draw_sprite(tela, jogar1, (maxx / 2) - 65 , 450);
    draw_sprite(tela, cred1, (maxx / 2) - 310 , 595);
    draw_sprite(tela, sair1, (maxx - 460) , 600);
    
// Jogar
    
    if(mouse_x > (maxx / 2 - 65) && mouse_x < (maxx / 2 + 65) && mouse_y > 450 && mouse_y < 496) {
           draw_sprite(tela, jogar2, (maxx / 2) - 65 , 450);  
           if(mouse_b == 1)
       {
           jogo(); 
       }
    }
    
// Créditos

    if(mouse_x > (maxx / 2 - 310) && mouse_x < (maxx/2 - 163) && mouse_y > 595 && mouse_y < 641) {
          draw_sprite(tela, cred2, (maxx / 2) - 310 , 595);
          if(mouse_b == 1)
      {  
          clear(tela);
          creditos();
      }
    }
    
// Sair

    if(mouse_x > (maxx - 460) && mouse_x < (maxx - 390) && mouse_y > 600 && mouse_y < 635) {
           draw_sprite(tela, sair2, (maxx - 460) , 600); 
           if(mouse_b == 1){
               deinit();
           }
    }
    
    
//Finalização Bitmaps
    
	}
	
    destroy_bitmap(cursor);
    destroy_bitmap(tela);
    destroy_bitmap(maintext);
    destroy_bitmap(jogar1);
    destroy_bitmap(jogar2);
    destroy_bitmap(cred1);
    destroy_bitmap(cred2);
    destroy_bitmap(sair1);
    destroy_bitmap(sair2);
    destroy_bitmap(prod);
    
}

//FUNÇÃO MENU (FIM) **********************************************************//

//FUNÇÃO CRÉDITOS (INÍCIO) ***************************************************//

void creditos () {
     
//Palettes

     PALETTE pal;
          
//Bitmaps

     BITMAP *tela = create_bitmap(SCREEN_W, SCREEN_H);
     BITMAP *prod = load_bitmap("Menus\\prod2.BMP", pal);
     
//Créditos Loop
     
     while (!keypressed()) { 
     //clear(screen);
          draw_sprite(screen, prod, 0, 0); 
     }
     
     
     
}

//FUNÇÃO CRÉDITOS (FIM) ******************************************************//

//FUNÇÃO JOGO (INÍCIO) *******************************************************//

void jogo() {
     
//Palettes

     PALETTE pal;

//Bitmaps
     
     BITMAP* cursor = load_bitmap("source\\op_hd2.BMP", NULL);
     BITMAP* cursor2 = load_bitmap("source\\cl_hd2.BMP", NULL);
     BITMAP* tela = create_bitmap(SCREEN_W, SCREEN_H);
     


//Jogo Loop
     clear(tela);
     while (!key[KEY_ESC]) { 
         draw_sprite(screen, tela, 0, 0);
         clear(tela);
         clear_keybuf();
         
         
         if(mouse_b == 1)
         {
            draw_sprite(tela, cursor2, mouse_x, mouse_y);
             
         }
         else
         {
            draw_sprite(tela, cursor, mouse_x, mouse_y); 
            
         }
     }
     
     
}

//FUNÇÃO JOGO (FIM) **********************************************************//


//FUNÇÕES (FIM) ==============================================================//
