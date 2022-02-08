#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro_image.h>

struct baraja
{
  int numero;
  int dado;
  char tipo[15];
  char color[20];
  char nombre[20];
  ALLEGRO_BITMAP* imagen;//para poder meter una imagen en allegro
};typedef struct baraja B;

void llenacartasmayor(B[53]);
void llenacartasmenor(B[53]);
void entregar(B[53],B[5]);
void entregar2(B[53],B[5]);
void cambiarcartas(B[53],B[5],int);
void cambiarcartas2(B[53],B[5],int);
void sumapuntos(B[5],B[5]);
void sumapuntosa(B[5],B[5]);
void mouset(B[5],int*,int*,int*,int*,int*,int);

int main()
{

int escoger,i,h=1,mousex,mousey;
char ruta[20];

B vec_cartas[53],cartas_entregadas1[5],cartas_entregadas2[5];
srand(time(NULL));
escoger=rand()%2+1;

al_init();
al_init_font_addon();
al_init_ttf_addon();
al_install_mouse();
ALLEGRO_MOUSE_STATE mousets;

ALLEGRO_DISPLAY* disp = al_create_display(1280, 720);//para crear la pantalla (1280 tamaño en x) (720 tamaño en y)
//ALLEGRO_FONT* font = al_create_builtin_font();//declaramos el estilo de fuente
al_init_image_addon();//para permitir que las imagenes sean visibles
ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);


for(i=0;i<53;i++)
{
    sprintf(ruta,"imagenes/card%d.png",i+1);//va a copiar la imagen de la carpeta y la va a guardar en la cadena, %d para ir moviendonos en las imagenes
    vec_cartas[i].imagen=al_load_bitmap(ruta);//guardamos las imagenes de ruta en nuestro vector de imagenes
}

if(escoger==1)
{
    while(h==1)//se mantenga la pantalla abierta
    {

al_get_mouse_state(&mousets);
            mousex = al_get_mouse_state_axis(&mousets,0);
            mousey = al_get_mouse_state_axis(&mousets,1);
        al_flip_display();
            al_clear_to_color(al_map_rgb(0, 100, 0));//añadir color a la pantalla de un color específico
             al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"JUGARAS CON MAXIMOS");
            al_flip_display();//limpiar pantalla

        llenacartasmayor(vec_cartas);
        entregar(vec_cartas,cartas_entregadas1);
        al_flip_display();
        entregar2(vec_cartas,cartas_entregadas2);
        al_flip_display();

        sumapuntos(cartas_entregadas1,cartas_entregadas2);
         al_flip_display();
al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"X: %d , Y: %d",mousex,mousey);
            al_flip_display();
         scanf("%d",&h);


    }
}

else
{
    while(h==1)
    {
al_get_mouse_state(&mousets);
            mousex = al_get_mouse_state_axis(&mousets,0);
            mousey = al_get_mouse_state_axis(&mousets,1);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 100, 0));
          al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"JUGARAS CON MINIMOS");
        al_flip_display();
        llenacartasmenor(vec_cartas);
        entregar(vec_cartas,cartas_entregadas1);
        al_flip_display();
        entregar2(vec_cartas,cartas_entregadas2);
        al_flip_display();
        sumapuntosa(cartas_entregadas1,cartas_entregadas2);
        al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"X: %d , Y: %d",mousex,mousey);
            al_flip_display();
          scanf("%d",&h);
          al_flip_display();


    }
}

    al_destroy_font(font);//cerrar la fuente
    al_destroy_display(disp);//cerrar la pantalla


    return 0;

    }


void llenacartasmayor(B vec_cartas[53])
{
    vec_cartas[0].numero=2;
    vec_cartas[0].dado=0;
    strcpy(vec_cartas[0].tipo,"pica");
    strcpy(vec_cartas[0].color,"negro");
    strcpy(vec_cartas[0].nombre,"dos pica");
    vec_cartas[1].numero=3;
    vec_cartas[1].dado=0;
    strcpy(vec_cartas[1].tipo,"pica");
    strcpy(vec_cartas[1].color,"negro");
    strcpy(vec_cartas[1].nombre,"tres pica");
    vec_cartas[2].numero=4;
    vec_cartas[2].dado=0;
    strcpy(vec_cartas[2].tipo,"pica");
    strcpy(vec_cartas[2].color,"negro");
    strcpy(vec_cartas[2].nombre,"cuatro pica");
     vec_cartas[3].numero=5;
    vec_cartas[3].dado=0;
    strcpy(vec_cartas[3].tipo,"pica");
    strcpy(vec_cartas[3].color,"negro");
    strcpy(vec_cartas[3].nombre,"cinco pica");
     vec_cartas[4].numero=6;
    vec_cartas[4].dado=0;
    strcpy(vec_cartas[4].tipo,"pica");
    strcpy(vec_cartas[4].color,"negro");
    strcpy(vec_cartas[4].nombre,"seis pica");
     vec_cartas[5].numero=7;
    vec_cartas[5].dado=0;
    strcpy(vec_cartas[5].tipo,"pica");
    strcpy(vec_cartas[5].color,"negro");
    strcpy(vec_cartas[5].nombre,"siete pica");
     vec_cartas[6].numero=8;
    vec_cartas[6].dado=0;
    strcpy(vec_cartas[6].tipo,"pica");
    strcpy(vec_cartas[6].color,"negro");
    strcpy(vec_cartas[6].nombre,"ocho pica");
     vec_cartas[7].numero=9;
    vec_cartas[7].dado=0;
    strcpy(vec_cartas[7].tipo,"pica");
    strcpy(vec_cartas[7].color,"negro");
    strcpy(vec_cartas[7].nombre,"nueve pica");
     vec_cartas[8].numero=10;
    vec_cartas[8].dado=0;
    strcpy(vec_cartas[8].tipo,"pica");
    strcpy(vec_cartas[8].color,"negro");
    strcpy(vec_cartas[8].nombre,"diez pica");
     vec_cartas[9].numero=10;
    vec_cartas[9].dado=0;
    strcpy(vec_cartas[9].tipo,"pica");
    strcpy(vec_cartas[9].color,"negro");
    strcpy(vec_cartas[9].nombre,"joto");
     vec_cartas[10].numero=10;
    vec_cartas[10].dado=0;
    strcpy(vec_cartas[10].tipo,"pica");
    strcpy(vec_cartas[10].color,"negro");
    strcpy(vec_cartas[10].nombre,"quina");
     vec_cartas[11].numero=10;
    vec_cartas[11].dado=0;
    strcpy(vec_cartas[11].tipo,"pica");
    strcpy(vec_cartas[11].color,"negro");
    strcpy(vec_cartas[11].nombre,"rey");
     vec_cartas[12].numero=11;
    vec_cartas[12].dado=0;
    strcpy(vec_cartas[12].tipo,"pica");
    strcpy(vec_cartas[12].color,"negro");
    strcpy(vec_cartas[12].nombre,"as");
    vec_cartas[13].numero=2;
vec_cartas[13].dado=0;
strcpy(vec_cartas[13].tipo,"rombo");
strcpy(vec_cartas[13].color,"rojo");
strcpy(vec_cartas[13].nombre,"dos rombo");
vec_cartas[14].numero=3;
vec_cartas[14].dado=0;
strcpy(vec_cartas[14].tipo,"rombo");
strcpy(vec_cartas[14].color,"rojo");
strcpy(vec_cartas[14].nombre,"tres rombo");
vec_cartas[15].numero=4;
vec_cartas[15].dado=0;
strcpy(vec_cartas[15].tipo,"rombo");
strcpy(vec_cartas[15].color,"rojo");
strcpy(vec_cartas[15].nombre,"cuatro rombo");
vec_cartas[16].numero=5;
vec_cartas[16].dado=0;
strcpy(vec_cartas[16].tipo,"rombo");
strcpy(vec_cartas[16].color,"rojo");
strcpy(vec_cartas[16].nombre,"cinco rombo");
vec_cartas[17].numero=6;
vec_cartas[17].dado=0;
strcpy(vec_cartas[17].tipo,"rombo");
strcpy(vec_cartas[17].color,"rojo");
strcpy(vec_cartas[17].nombre,"seis rombo");
vec_cartas[18].numero=7;
vec_cartas[18].dado=0;
strcpy(vec_cartas[18].tipo,"rombo");
strcpy(vec_cartas[18].color,"rojo");
strcpy(vec_cartas[18].nombre,"siete rombo");
vec_cartas[19].numero=8;
vec_cartas[19].dado=0;
strcpy(vec_cartas[19].tipo,"rombo");
strcpy(vec_cartas[19].color,"rojo");
strcpy(vec_cartas[19].nombre,"ocho rombo");
vec_cartas[20].numero=9;
vec_cartas[20].dado=0;
strcpy(vec_cartas[20].tipo,"rombo");
strcpy(vec_cartas[20].color,"rojo");
strcpy(vec_cartas[20].nombre,"nueve rombo");
vec_cartas[21].numero=10;
vec_cartas[21].dado=0;
strcpy(vec_cartas[21].tipo,"rombo");
strcpy(vec_cartas[21].color,"rojo");
strcpy(vec_cartas[21].nombre,"diez rombo");
vec_cartas[22].numero=10;
vec_cartas[22].dado=0;
strcpy(vec_cartas[22].tipo,"rombo");
strcpy(vec_cartas[22].color,"rojo");
strcpy(vec_cartas[22].nombre,"joto");
vec_cartas[23].numero=10;
vec_cartas[23].dado=0;
strcpy(vec_cartas[23].tipo,"rombo");
strcpy(vec_cartas[23].color,"rojo");
strcpy(vec_cartas[23].nombre,"quina");
vec_cartas[24].numero=10;
vec_cartas[24].dado=0;
strcpy(vec_cartas[24].tipo,"rombo");
strcpy(vec_cartas[24].color,"rojo");
strcpy(vec_cartas[24].nombre,"rey");
vec_cartas[25].numero=11;
vec_cartas[25].dado=0;
strcpy(vec_cartas[25].tipo,"rombo");
strcpy(vec_cartas[25].color,"rojo");
strcpy(vec_cartas[25].nombre,"as");
vec_cartas[39].numero=2;
vec_cartas[39].dado=0;
strcpy(vec_cartas[39].tipo,"corazon");
strcpy(vec_cartas[39].color,"rojo");
strcpy(vec_cartas[39].nombre,"dos corazon");
vec_cartas[40].numero=3;
vec_cartas[40].dado=0;
strcpy(vec_cartas[40].tipo,"corazon");
strcpy(vec_cartas[40].color,"rojo");
strcpy(vec_cartas[40].nombre,"tres corazon");
vec_cartas[41].numero=4;
vec_cartas[41].dado=0;
strcpy(vec_cartas[41].tipo,"corazon");
strcpy(vec_cartas[41].color,"rojo");
strcpy(vec_cartas[41].nombre,"cuatro corazon");
vec_cartas[42].numero=5;
vec_cartas[42].dado=0;
strcpy(vec_cartas[42].tipo,"corazon");
strcpy(vec_cartas[42].color,"rojo");
strcpy(vec_cartas[42].nombre,"cinco corazon");
vec_cartas[43].numero=6;
vec_cartas[43].dado=0;
strcpy(vec_cartas[43].tipo,"corazon");
strcpy(vec_cartas[43].color,"rojo");
strcpy(vec_cartas[43].nombre,"seis corazon");
vec_cartas[44].numero=7;
vec_cartas[44].dado=0;
strcpy(vec_cartas[44].tipo,"corazon");
strcpy(vec_cartas[44].color,"rojo");
strcpy(vec_cartas[44].nombre,"siete corazon");
vec_cartas[45].numero=8;
vec_cartas[45].dado=0;
strcpy(vec_cartas[45].tipo,"rombo");
strcpy(vec_cartas[45].color,"rojo");
strcpy(vec_cartas[45].nombre,"ocho corazon");
vec_cartas[46].numero=9;
vec_cartas[46].dado=0;
strcpy(vec_cartas[46].tipo,"corazon");
strcpy(vec_cartas[46].color,"rojo");
strcpy(vec_cartas[46].nombre,"nueve corazon");
vec_cartas[47].numero=10;
vec_cartas[47].dado=0;
strcpy(vec_cartas[47].tipo,"corazon");
strcpy(vec_cartas[47].color,"rojo");
strcpy(vec_cartas[47].nombre,"diez corazon");
vec_cartas[48].numero=10;
vec_cartas[48].dado=0;
strcpy(vec_cartas[48].tipo,"corazon");
strcpy(vec_cartas[48].color,"rojo");
strcpy(vec_cartas[48].nombre,"joto");
vec_cartas[49].numero=10;
vec_cartas[49].dado=0;
strcpy(vec_cartas[49].tipo,"corazon");
strcpy(vec_cartas[49].color,"rojo");
strcpy(vec_cartas[49].nombre,"quina");
vec_cartas[50].numero=10;
vec_cartas[50].dado=0;
strcpy(vec_cartas[50].tipo,"corazon");
strcpy(vec_cartas[50].color,"rojo");
strcpy(vec_cartas[50].nombre,"rey");
vec_cartas[51].numero=11;
vec_cartas[51].dado=0;
strcpy(vec_cartas[51].tipo,"corazon");
strcpy(vec_cartas[51].color,"rojo");
strcpy(vec_cartas[51].nombre,"as");
vec_cartas[26].numero=2;
vec_cartas[26].dado=0;
strcpy(vec_cartas[26].tipo,"trebol");
strcpy(vec_cartas[26].color,"negro");
strcpy(vec_cartas[26].nombre,"dos treboles");
vec_cartas[27].numero=3;
vec_cartas[27].dado=0;
strcpy(vec_cartas[27].tipo,"trebol");
strcpy(vec_cartas[27].color,"negro");
strcpy(vec_cartas[27].nombre,"tres treboles");
vec_cartas[28].numero=4;
vec_cartas[28].dado=0;
strcpy(vec_cartas[28].tipo,"trebol");
strcpy(vec_cartas[28].color,"negro");
strcpy(vec_cartas[28].nombre,"cuatro treboles");
vec_cartas[29].numero=5;
vec_cartas[29].dado=0;
strcpy(vec_cartas[29].tipo,"trebol");
strcpy(vec_cartas[29].color,"negro");
strcpy(vec_cartas[29].nombre,"cinco treboles");
vec_cartas[30].numero=6;
vec_cartas[30].dado=0;
strcpy(vec_cartas[30].tipo,"trebol");
strcpy(vec_cartas[30].color,"negro");
strcpy(vec_cartas[30].nombre,"seis treboles");
vec_cartas[31].numero=7;
vec_cartas[31].dado=0;
strcpy(vec_cartas[31].tipo,"trebol");
strcpy(vec_cartas[31].color,"negro");
strcpy(vec_cartas[31].nombre,"siete treboles");
vec_cartas[32].numero=8;
vec_cartas[32].dado=0;
strcpy(vec_cartas[32].tipo,"trebol");
strcpy(vec_cartas[32].color,"negro");
strcpy(vec_cartas[32].nombre,"ocho treboles");
vec_cartas[33].numero=9;
vec_cartas[33].dado=0;
strcpy(vec_cartas[33].tipo,"trebol");
strcpy(vec_cartas[33].color,"negro");
strcpy(vec_cartas[33].nombre,"nueve treboles");
vec_cartas[34].numero=10;
vec_cartas[34].dado=0;
strcpy(vec_cartas[34].tipo,"trebol");
strcpy(vec_cartas[34].color,"negro");
strcpy(vec_cartas[34].nombre,"diez treboles");
vec_cartas[35].numero=10;
vec_cartas[35].dado=0;
strcpy(vec_cartas[35].tipo,"trebol");
strcpy(vec_cartas[35].color,"negro");
strcpy(vec_cartas[35].nombre,"joto");
vec_cartas[36].numero=10;
vec_cartas[36].dado=0;
strcpy(vec_cartas[36].tipo,"trebol");
strcpy(vec_cartas[36].color,"negro");
strcpy(vec_cartas[36].nombre,"quina");
vec_cartas[37].numero=10;
vec_cartas[37].dado=0;
strcpy(vec_cartas[37].tipo,"trebol");
strcpy(vec_cartas[37].color,"negro");
strcpy(vec_cartas[37].nombre,"rey");
vec_cartas[38].numero=11;
vec_cartas[38].dado=0;
strcpy(vec_cartas[38].tipo,"trebol");
strcpy(vec_cartas[38].color,"negro");
strcpy(vec_cartas[38].nombre,"as");

}
void llenacartasmenor(B vec_cartas[53])
{
    vec_cartas[0].numero=2;
    vec_cartas[0].dado=0;
    strcpy(vec_cartas[0].tipo,"pica");
    strcpy(vec_cartas[0].color,"negro");
    strcpy(vec_cartas[0].nombre,"dos pica");
    vec_cartas[1].numero=3;
    vec_cartas[1].dado=0;
    strcpy(vec_cartas[1].tipo,"pica");
    strcpy(vec_cartas[1].color,"negro");
    strcpy(vec_cartas[1].nombre,"tres pica");
    vec_cartas[2].numero=4;
    vec_cartas[2].dado=0;
    strcpy(vec_cartas[2].tipo,"pica");
    strcpy(vec_cartas[2].color,"negro");
    strcpy(vec_cartas[2].nombre,"cuatro pica");
     vec_cartas[3].numero=5;
    vec_cartas[3].dado=0;
    strcpy(vec_cartas[3].tipo,"pica");
    strcpy(vec_cartas[3].color,"negro");
    strcpy(vec_cartas[3].nombre,"cinco pica");
     vec_cartas[4].numero=6;
    vec_cartas[4].dado=0;
    strcpy(vec_cartas[4].tipo,"pica");
    strcpy(vec_cartas[4].color,"negro");
    strcpy(vec_cartas[4].nombre,"seis pica");
     vec_cartas[5].numero=7;
    vec_cartas[5].dado=0;
    strcpy(vec_cartas[5].tipo,"pica");
    strcpy(vec_cartas[5].color,"negro");
    strcpy(vec_cartas[5].nombre,"siete pica");
     vec_cartas[6].numero=8;
    vec_cartas[6].dado=0;
    strcpy(vec_cartas[6].tipo,"pica");
    strcpy(vec_cartas[6].color,"negro");
    strcpy(vec_cartas[6].nombre,"ocho pica");
     vec_cartas[7].numero=9;
    vec_cartas[7].dado=0;
    strcpy(vec_cartas[7].tipo,"pica");
    strcpy(vec_cartas[7].color,"negro");
    strcpy(vec_cartas[7].nombre,"nueve pica");
     vec_cartas[8].numero=10;
    vec_cartas[8].dado=0;
    strcpy(vec_cartas[8].tipo,"pica");
    strcpy(vec_cartas[8].color,"negro");
    strcpy(vec_cartas[8].nombre,"diez pica");
     vec_cartas[9].numero=0;
    vec_cartas[9].dado=0;
    strcpy(vec_cartas[9].tipo,"pica");
    strcpy(vec_cartas[9].color,"negro");
    strcpy(vec_cartas[9].nombre,"joto");
     vec_cartas[10].numero=0;
    vec_cartas[10].dado=0;
    strcpy(vec_cartas[10].tipo,"pica");
    strcpy(vec_cartas[10].color,"negro");
    strcpy(vec_cartas[10].nombre,"quina");
     vec_cartas[11].numero=0;
    vec_cartas[11].dado=0;
    strcpy(vec_cartas[11].tipo,"pica");
    strcpy(vec_cartas[11].color,"negro");
    strcpy(vec_cartas[11].nombre,"rey");
     vec_cartas[12].numero=1;
    vec_cartas[12].dado=0;
    strcpy(vec_cartas[12].tipo,"pica");
    strcpy(vec_cartas[12].color,"negro");
    strcpy(vec_cartas[12].nombre,"as");
    vec_cartas[13].numero=2;
vec_cartas[13].dado=0;
strcpy(vec_cartas[13].tipo,"rombo");
strcpy(vec_cartas[13].color,"rojo");
strcpy(vec_cartas[13].nombre,"dos rombo");
vec_cartas[14].numero=3;
vec_cartas[14].dado=0;
strcpy(vec_cartas[14].tipo,"rombo");
strcpy(vec_cartas[14].color,"rojo");
strcpy(vec_cartas[14].nombre,"tres rombo");
vec_cartas[15].numero=4;
vec_cartas[15].dado=0;
strcpy(vec_cartas[15].tipo,"rombo");
strcpy(vec_cartas[15].color,"rojo");
strcpy(vec_cartas[15].nombre,"cuatro rombo");
vec_cartas[16].numero=5;
vec_cartas[16].dado=0;
strcpy(vec_cartas[16].tipo,"rombo");
strcpy(vec_cartas[16].color,"rojo");
strcpy(vec_cartas[16].nombre,"cinco rombo");
vec_cartas[17].numero=6;
vec_cartas[17].dado=0;
strcpy(vec_cartas[17].tipo,"rombo");
strcpy(vec_cartas[17].color,"rojo");
strcpy(vec_cartas[17].nombre,"seis rombo");
vec_cartas[18].numero=7;
vec_cartas[18].dado=0;
strcpy(vec_cartas[18].tipo,"rombo");
strcpy(vec_cartas[18].color,"rojo");
strcpy(vec_cartas[18].nombre,"siete rombo");
vec_cartas[19].numero=8;
vec_cartas[19].dado=0;
strcpy(vec_cartas[19].tipo,"rombo");
strcpy(vec_cartas[19].color,"rojo");
strcpy(vec_cartas[19].nombre,"ocho rombo");
vec_cartas[20].numero=9;
vec_cartas[20].dado=0;
strcpy(vec_cartas[20].tipo,"rombo");
strcpy(vec_cartas[20].color,"rojo");
strcpy(vec_cartas[20].nombre,"nueve rombo");
vec_cartas[21].numero=10;
vec_cartas[21].dado=0;
strcpy(vec_cartas[21].tipo,"rombo");
strcpy(vec_cartas[21].color,"rojo");
strcpy(vec_cartas[21].nombre,"diez rombo");
vec_cartas[22].numero=0;
vec_cartas[22].dado=0;
strcpy(vec_cartas[22].tipo,"rombo");
strcpy(vec_cartas[22].color,"rojo");
strcpy(vec_cartas[22].nombre,"joto");
vec_cartas[23].numero=0;
vec_cartas[23].dado=0;
strcpy(vec_cartas[23].tipo,"rombo");
strcpy(vec_cartas[23].color,"rojo");
strcpy(vec_cartas[23].nombre,"quina");
vec_cartas[24].numero=0;
vec_cartas[24].dado=0;
strcpy(vec_cartas[24].tipo,"rombo");
strcpy(vec_cartas[24].color,"rojo");
strcpy(vec_cartas[24].nombre,"rey");
vec_cartas[25].numero=1;
vec_cartas[25].dado=0;
strcpy(vec_cartas[25].tipo,"rombo");
strcpy(vec_cartas[25].color,"rojo");
strcpy(vec_cartas[25].nombre,"as");
vec_cartas[39].numero=2;
vec_cartas[39].dado=0;
strcpy(vec_cartas[39].tipo,"corazon");
strcpy(vec_cartas[39].color,"rojo");
strcpy(vec_cartas[39].nombre,"dos corazon");
vec_cartas[40].numero=3;
vec_cartas[40].dado=0;
strcpy(vec_cartas[40].tipo,"corazon");
strcpy(vec_cartas[40].color,"rojo");
strcpy(vec_cartas[40].nombre,"tres corazon");
vec_cartas[41].numero=4;
vec_cartas[41].dado=0;
strcpy(vec_cartas[41].tipo,"corazon");
strcpy(vec_cartas[41].color,"rojo");
strcpy(vec_cartas[41].nombre,"cuatro corazon");
vec_cartas[42].numero=5;
vec_cartas[42].dado=0;
strcpy(vec_cartas[42].tipo,"corazon");
strcpy(vec_cartas[42].color,"rojo");
strcpy(vec_cartas[42].nombre,"cinco corazon");
vec_cartas[43].numero=6;
vec_cartas[43].dado=0;
strcpy(vec_cartas[43].tipo,"corazon");
strcpy(vec_cartas[43].color,"rojo");
strcpy(vec_cartas[43].nombre,"seis corazon");
vec_cartas[44].numero=7;
vec_cartas[44].dado=0;
strcpy(vec_cartas[44].tipo,"corazon");
strcpy(vec_cartas[44].color,"rojo");
strcpy(vec_cartas[44].nombre,"siete corazon");
vec_cartas[45].numero=8;
vec_cartas[45].dado=0;
strcpy(vec_cartas[45].tipo,"corazon");
strcpy(vec_cartas[45].color,"rojo");
strcpy(vec_cartas[45].nombre,"ocho corazon");
vec_cartas[46].numero=9;
vec_cartas[46].dado=0;
strcpy(vec_cartas[46].tipo,"corazon");
strcpy(vec_cartas[46].color,"rojo");
strcpy(vec_cartas[46].nombre,"nueve corazon");
vec_cartas[47].numero=10;
vec_cartas[47].dado=0;
strcpy(vec_cartas[47].tipo,"corazon");
strcpy(vec_cartas[47].color,"rojo");
strcpy(vec_cartas[47].nombre,"diez corazon");
vec_cartas[48].numero=0;
vec_cartas[48].dado=0;
strcpy(vec_cartas[48].tipo,"corazon");
strcpy(vec_cartas[48].color,"rojo");
strcpy(vec_cartas[48].nombre,"joto");
vec_cartas[49].numero=0;
vec_cartas[49].dado=0;
strcpy(vec_cartas[49].tipo,"corazon");
strcpy(vec_cartas[49].color,"rojo");
strcpy(vec_cartas[49].nombre,"quina");
vec_cartas[50].numero=0;
vec_cartas[50].dado=0;
strcpy(vec_cartas[50].tipo,"corazon");
strcpy(vec_cartas[50].color,"rojo");
strcpy(vec_cartas[50].nombre,"rey");
vec_cartas[51].numero=1;
vec_cartas[51].dado=0;
strcpy(vec_cartas[51].tipo,"corazon");
strcpy(vec_cartas[51].color,"rojo");
strcpy(vec_cartas[51].nombre,"as");
vec_cartas[26].numero=2;
vec_cartas[26].dado=0;
strcpy(vec_cartas[26].tipo,"trebol");
strcpy(vec_cartas[26].color,"negro");
strcpy(vec_cartas[26].nombre,"dos treboles");
vec_cartas[27].numero=3;
vec_cartas[27].dado=0;
strcpy(vec_cartas[27].tipo,"trebol");
strcpy(vec_cartas[27].color,"negro");
strcpy(vec_cartas[27].nombre,"tres treboles");
vec_cartas[28].numero=4;
vec_cartas[28].dado=0;
strcpy(vec_cartas[28].tipo,"trebol");
strcpy(vec_cartas[28].color,"negro");
strcpy(vec_cartas[28].nombre,"cuatro treboles");
vec_cartas[29].numero=5;
vec_cartas[29].dado=0;
strcpy(vec_cartas[29].tipo,"trebol");
strcpy(vec_cartas[29].color,"negro");
strcpy(vec_cartas[29].nombre,"cinco treboles");
vec_cartas[30].numero=6;
vec_cartas[30].dado=0;
strcpy(vec_cartas[30].tipo,"trebol");
strcpy(vec_cartas[30].color,"negro");
strcpy(vec_cartas[30].nombre,"seis treboles");
vec_cartas[31].numero=7;
vec_cartas[31].dado=0;
strcpy(vec_cartas[31].tipo,"trebol");
strcpy(vec_cartas[31].color,"negro");
strcpy(vec_cartas[31].nombre,"siete treboles");
vec_cartas[32].numero=8;
vec_cartas[32].dado=0;
strcpy(vec_cartas[32].tipo,"trebol");
strcpy(vec_cartas[32].color,"negro");
strcpy(vec_cartas[32].nombre,"ocho treboles");
vec_cartas[33].numero=9;
vec_cartas[33].dado=0;
strcpy(vec_cartas[33].tipo,"trebol");
strcpy(vec_cartas[33].color,"negro");
strcpy(vec_cartas[33].nombre,"nueve treboles");
vec_cartas[34].numero=10;
vec_cartas[34].dado=0;
strcpy(vec_cartas[34].tipo,"trebol");
strcpy(vec_cartas[34].color,"negro");
strcpy(vec_cartas[34].nombre,"diez treboles");
vec_cartas[35].numero=0;
vec_cartas[35].dado=0;
strcpy(vec_cartas[35].tipo,"trebol");
strcpy(vec_cartas[35].color,"negro");
strcpy(vec_cartas[35].nombre,"joto");
vec_cartas[36].numero=0;
vec_cartas[36].dado=0;
strcpy(vec_cartas[36].tipo,"trebol");
strcpy(vec_cartas[36].color,"negro");
strcpy(vec_cartas[36].nombre,"quina");
vec_cartas[37].numero=0;
vec_cartas[37].dado=0;
strcpy(vec_cartas[37].tipo,"trebol");
strcpy(vec_cartas[37].color,"negro");
strcpy(vec_cartas[37].nombre,"rey");
vec_cartas[38].numero=1;
vec_cartas[38].dado=0;
strcpy(vec_cartas[38].tipo,"trebol");
strcpy(vec_cartas[38].color,"negro");
strcpy(vec_cartas[38].nombre,"as");
}
void entregar(B vec_cartas[53],B entregadas[5])
{
    int a,b,c,d,e,x=0,k,i,p=0;
    char texto[100];
     //ALLEGRO_FONT* font = al_create_builtin_font();//volver a agregar la misma fuente
     ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);

        a=rand()%51;//me da un numero de carta
        while(vec_cartas[a].dado==1)//verifica si se repite
        {
            a=rand()%51;//cambia el valor de la carta por si esta repetida
        }
        vec_cartas[a].dado=1;//se vulve uno para saber que ya se dio la carta
        b=rand()%51;//se repite el proceso
        while(vec_cartas[b].dado==1)
        {
            b=rand()%51;
        }
        vec_cartas[b].dado=1;
        c=rand()%51;
        while(vec_cartas[c].dado==1)
        {
            c=rand()%51;
        }
        vec_cartas[c].dado=1;
        d=rand()%51;
        while(vec_cartas[d].dado==1)
        {
            d=rand()%51;
        }
         vec_cartas[d].dado=1;
        e=rand()%51;
        while(vec_cartas[e].dado==1)
        {
            e=rand()%51;
        }
        vec_cartas[e].dado=1;
   entregadas[0]=vec_cartas[a];
   entregadas[1]=vec_cartas[b];
   entregadas[2]=vec_cartas[c];
  entregadas[3]=vec_cartas[d];
   entregadas[4]=vec_cartas[e];//para guadar las cartas que se van a mostrar en el vector
 al_flip_display();//limpia la pantalla
   for(i=0;i<5;i++)
   {

       al_draw_scaled_bitmap(entregadas[i].imagen,0/*recorta la imagen en el eje x*/,0/*recorta la imagen en el eje y*/,99/*cuanto mide de ancho*/,138/*cuanto mide de largo*/,99+p/*posicion de la carta en eje x*/,138/*posicion de la carta en el eje y*/,99/*cuanto va a medir de ancho*/,138/*cuanto va a medir de largo*/,0);//para poner la imagen y editarla
       p=p+99;//incrementa en p para ir recorriendo las cartas en el eje x
   }

   al_draw_text(font, al_map_rgb(255, 255, 255)/*color del texto*/, 640, 380/*posicion*/, ALLEGRO_ALIGN_CENTER/*alineralo en el centro*/, "Cuantas cartas quieres cambiar:");
 al_flip_display();
   scanf("%d",&k);//pide las cartas que quiere cambiar
   if(k==0)
   {
     al_draw_text(font, al_map_rgb(255, 255, 255), 640, 400, ALLEGRO_ALIGN_CENTER, "OK:");//no cambia nada
     al_flip_display();
   }
  else
  {

      al_flip_display();
       cambiarcartas(vec_cartas,entregadas,k);
  }


}
void cambiarcartas(B vec_cartas[53],B entregadas[5],int x)
{
    int i=0,al,z,q,p=0,mousex,mousey,k,s=0,cambiar1=0,cambiar2=0,cambiar3=0,cambiar4=0,cambiar5=0,aux1=0,aux2=0,aux3=0,aux4=0,aux5=0;
    char texto[100];
    ALLEGRO_MOUSE_STATE mouse;
    //ALLEGRO_FONT* font = al_create_builtin_font();//inicializa la fuente
    ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
     al_flip_display();
    if(x>3)//evitar que cambie mas de 3 cartas
    {
        x=3;
    }
    al_flip_display();
  //  ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
    ALLEGRO_MOUSE_STATE mousets;
     do
       {

           p=0;
            al_get_mouse_state(&mousets);
            mousex = al_get_mouse_state_axis(&mousets,0);
            mousey = al_get_mouse_state_axis(&mousets,1);
             al_clear_to_color(al_map_rgb(0, 100, 0));
al_draw_text(font, al_map_rgb(255, 255, 255), 640, 520, ALLEGRO_ALIGN_CENTER, "Escoge tus cartas");

             for(s=0;s<5;s++)
            {
        al_draw_scaled_bitmap(entregadas[s].imagen,0/*recorta la imagen en el eje x*/,0/*recorta la imagen en el eje y*/,99/*cuanto mide de ancho*/,138/*cuanto mide de largo*/,99+p/*posicion de la carta en eje x*/,138/*posicion de la carta en el eje y*/,99/*cuanto va a medir de ancho*/,138/*cuanto va a medir de largo*/,0);
       p=p+99;

            }

            if(al_mouse_button_down(&mousets,1))
            {
                if((mousex>100 && mousex<191)&&(mousey>139 && mousey<274)&& aux1==0)
                {
                    cambiar1=1;
                    i=i+1;
                    aux1=1;
                    printf("\nIf 1");
                    al_mouse_button_down(&mousets,1);
                    if(cambiar1==1)
                        {
                            al=rand()%51;

                            while(vec_cartas[al].dado==1)
                                 {
                                    al=rand()%51;
                                 }
                                entregadas[0]=vec_cartas[al];
                        }
                }


                }
                else if((mousex>200 && mousex<291)&&(mousey>139 && mousey<274) && aux2==0)
                {
                    cambiar2=1;
                    i=i+1;
                    aux2=1;
                    printf("\nIf 2");
                        if(cambiar2==1)
                            {
                                al=rand()%51;
                                while(vec_cartas[al].dado==1)
                                    {
                                        al=rand()%51;
                                    }
                                entregadas[1]=vec_cartas[al];
                            }
                    al_mouse_button_down(&mousets,1);



                }
                 else if((mousex>300 && mousex<391)&&(mousey>139 && mousey<274) && aux3==0)
                {
                    cambiar3=1;
                    i=i+1;
                    aux3=1;
                    printf("\nIf 3");
                    if(cambiar3==1)
                           {
                               al=rand()%51;
                           while(vec_cartas[al].dado==1)
                            {
                                al=rand()%51;
                            }
                           entregadas[2]=vec_cartas[al];
                           }
                     al_get_mouse_state(&mousets);
                }
                else if((mousex>400 && mousex<491)&&(mousey>139 && mousey<274) && aux4==0)
                {
                    cambiar4=1;
                   i=i+1;
                   aux4=1;
                   printf("\nIf 4");
                   if(cambiar4==1)
                       {
                           al=rand()%51;
                       while(vec_cartas[al].dado==1)
                        {
                            al=rand()%51;
                        }
                       entregadas[3]=vec_cartas[al];
                       }
                     al_get_mouse_state(&mousets);


                }
                else if((mousex>500 && mousex<591)&&(mousey>139 && mousey<274) && aux5==0)
                {
                    cambiar5=1;
                   i=i+1;
                   printf("\nIf 5");
                   aux5=1;
                   //al_mouse_button_down(&mouse,1);
                    if(cambiar5==1)
                   {
                      al=rand()%51;
                   while(vec_cartas[al].dado==1)
                    {
                        al=rand()%51;
                    }
                   entregadas[4]=vec_cartas[al];
                   }
                    al_get_mouse_state(&mousets);


                }

            al_mouse_button_down(&mouse,1);
            printf("\nI: %d",i);

            al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"X: %d , Y: %d",mousex,mousey);
            al_flip_display();


       }while(i<x);





       p=0;

al_clear_to_color(al_map_rgb(0, 100, 0));//limpia el color de la pantalla
     for(s=0;s<5;s++)
            {
        al_draw_scaled_bitmap(entregadas[s].imagen,0/*recorta la imagen en el eje x*/,0/*recorta la imagen en el eje y*/,99/*cuanto mide de ancho*/,138/*cuanto mide de largo*/,99+p/*posicion de la carta en eje x*/,138/*posicion de la carta en el eje y*/,99/*cuanto va a medir de ancho*/,138/*cuanto va a medir de largo*/,0);
       p=p+99;

            }

 al_flip_display();
}
void sumapuntos(B cartas_entregadas1[5],B cartas_entregadas2[5])
{
     //ALLEGRO_FONT* font = al_create_builtin_font();//inicializa la fuente
     ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
al_clear_to_color(al_map_rgb(0, 100, 0));
     int i,b=0,c=0,q,p;
    char texto[100];
    for(i=0;i<5;i++)
    {
        b=cartas_entregadas1[i].numero+b;
        c=cartas_entregadas2[i].numero+c;
    }
     sprintf(texto,"Puntos: %d %d",b,c);//guarda en la pantalla los datos guardados de b y c
          al_draw_textf(font, al_map_rgb(255, 255, 255), 640, 600, ALLEGRO_ALIGN_CENTER, texto);//imprime el texto en la pantalla
          al_draw_text(font, al_map_rgb(255, 255, 255)/*color del texto*/, 640, 380/*posicion*/, ALLEGRO_ALIGN_CENTER/*alineralo en el centro*/, "Quieres volver a jugar 1. Si 0. No");
    if(b>c)
    {
         al_draw_text(font, al_map_rgb(255, 255, 255), 640, 560, ALLEGRO_ALIGN_CENTER, "Gana el jugador 1");
    }
    else
    {
         al_draw_text(font, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Gana el jugador 2");

    }
     for(q=0;q<5;q++)
   {

       al_draw_scaled_bitmap(cartas_entregadas1[q].imagen,0,0,99,138,99+p,138,99,138,0);
        al_draw_scaled_bitmap(cartas_entregadas2[q].imagen,0,0,99,138,750+p,148.5,99,138,0);
       p=p+99;
       al_flip_display();
   }
    al_flip_display();

}
void sumapuntosa(B cartas_entregadas1[5],B cartas_entregadas2[5])
{
     //ALLEGRO_FONT* font = al_create_builtin_font();
     ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
al_clear_to_color(al_map_rgb(0, 100, 0));
    int i,b=0,c=0,p,q;
    char texto[100];
    for(i=0;i<5;i++)
    {
        b=cartas_entregadas1[i].numero+b;
        c=cartas_entregadas2[i].numero+c;
    }
    sprintf(texto,"Puntos: %d %d",b,c);
     al_draw_textf(font, al_map_rgb(255, 255, 255), 640, 600, ALLEGRO_ALIGN_CENTER, texto);
     al_draw_text(font, al_map_rgb(255, 255, 255)/*color del texto*/, 640, 380/*posicion*/, ALLEGRO_ALIGN_CENTER/*alineralo en el centro*/, "Quieres volver a jugar 1. Si 0. No");
    if(b>c)
    {
         al_draw_text(font, al_map_rgb(255, 255, 255), 640, 560, ALLEGRO_ALIGN_CENTER, "Gana el jugador 2");
    }
    else
    {
         al_draw_text(font, al_map_rgb(255, 255, 255), 640, 580, ALLEGRO_ALIGN_CENTER, "Gana el jugador 1");

    }
       for(q=0;q<5;q++)
   {

       al_draw_scaled_bitmap(cartas_entregadas1[q].imagen,0,0,99,138,99+p,138,99,138,0);
        al_draw_scaled_bitmap(cartas_entregadas2[q].imagen,0,0,99,138,750+p,148.5,99,138,0);
       p=p+99;
       al_flip_display();
   }

    al_flip_display();



}

void entregar2(B vec_cartas[53],B entregadas[5])
{
    int a,b,c,d,e,x=0,k,i,p=0;
    char texto[100];
     //ALLEGRO_FONT* font = al_create_builtin_font();
     ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);

        a=rand()%51;
        while(vec_cartas[a].dado==1)
        {
            a=rand()%51;
        }
        vec_cartas[a].dado=1;
        b=rand()%51;
        while(vec_cartas[b].dado==1)
        {
            b=rand()%51;
        }
        vec_cartas[b].dado=1;
        c=rand()%51;
        while(vec_cartas[c].dado==1)
        {
            c=rand()%51;
        }
        vec_cartas[c].dado=1;
        d=rand()%51;
        while(vec_cartas[d].dado==1)
        {
            d=rand()%51;
        }
        vec_cartas[d].dado=1;
        e=rand()%51;
        while(vec_cartas[e].dado==1)
        {
            e=rand()%51;
        }
         vec_cartas[e].dado=1;
   entregadas[0]=vec_cartas[a];
   entregadas[1]=vec_cartas[b];
   entregadas[2]=vec_cartas[c];
  entregadas[3]=vec_cartas[d];
   entregadas[4]=vec_cartas[e];

    al_flip_display();

    for(i=0;i<5;i++)
   {
       al_draw_scaled_bitmap(entregadas[i].imagen,0,0,99,138,750+p,148.5,99,138,0);
       p=p+99;
   }

 al_flip_display();
   al_draw_text(font, al_map_rgb(255, 255, 255), 640, 480, ALLEGRO_ALIGN_CENTER, "Cuantas cartas quieres cambiar:");
al_flip_display();
   scanf("%d",&k);

   if(k==0)
   {
     al_draw_text(font, al_map_rgb(255, 255, 255), 640, 500, ALLEGRO_ALIGN_CENTER, "OK:");
     al_flip_display();
   }
  else
  {

      al_flip_display();
       cambiarcartas2(vec_cartas,entregadas,k);
  }


}


void cambiarcartas2(B vec_cartas[53],B entregadas[5],int x)
{
     int i=0,al,z,q,p=0,mousex,mousey,k,s=0,cambiar1=0,cambiar2=0,cambiar3=0,cambiar4=0,cambiar5=0,aux1=0,aux2=0,aux3=0,aux4=0,aux5=0;
    char texto[100];

    ALLEGRO_MOUSE_STATE mouse;
    //ALLEGRO_FONT* font = al_create_builtin_font();//inicializa la fuente
    ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
     al_flip_display();

    if(x>3)//evitar que cambie mas de 3 cartas
    {
        x=3;
    }
    al_flip_display();
    /*ALLEGRO_FONT* font=al_load_font("KIN668.ttf",20,0);
    ALLEGRO_MOUSE_STATE mousets;*/
     do
       {

           p=0;
            al_get_mouse_state(&mouse);
            mousex = al_get_mouse_state_axis(&mouse,0);
            mousey = al_get_mouse_state_axis(&mouse,1);
            al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"X: %d , Y: %d",mousex,mousey);
             al_clear_to_color(al_map_rgb(0, 100, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 640, 520, ALLEGRO_ALIGN_CENTER, "Escoge tus cartas");
             for(s=0;s<5;s++)
            {
        al_draw_scaled_bitmap(entregadas[s].imagen,0/*recorta la imagen en el eje x*/,0/*recorta la imagen en el eje y*/,99/*cuanto mide de ancho*/,138/*cuanto mide de largo*/,750+p/*posicion de la carta en eje x*/,148.5/*posicion de la carta en el eje y*/,99/*cuanto va a medir de ancho*/,138/*cuanto va a medir de largo*/,0);
        p=p+99;
            }

            if(al_mouse_button_down(&mouse,1))
            {
                if((mousex>750 && mousex<850)&&(mousey>139 && mousey<274)&& aux1==0)
                {
                    cambiar1=1;
                    i=i+1;
                    aux1=1;
                    printf("\nIf 1");
                    //al_mouse_button_down(&mouse,1);
                    if(cambiar1==1)
                        {
                            al=rand()%51;

                            while(vec_cartas[al].dado==1)
                                 {
                                    al=rand()%51;
                                 }
                                entregadas[0]=vec_cartas[al];
                        }
                }


                }
                else if((mousex>851 && mousex<951)&&(mousey>139 && mousey<274) && aux2==0)
                {
                    cambiar2=1;
                    i=i+1;
                    aux2=1;
                    //al_mouse_button_down(&mouse,1);
                    printf("\nIf 2");
                        if(cambiar2==1)
                            {
                                al=rand()%51;
                                while(vec_cartas[al].dado==1)
                                    {
                                        al=rand()%51;
                                    }
                                entregadas[1]=vec_cartas[al];
                            }



                }
                 else if((mousex>952 && mousex<1052)&&(mousey>139 && mousey<274) && aux3==0)
                {
                    cambiar3=1;
                    i=i+1;
                    aux3=1;
                    //al_mouse_button_down(&mouse,1);
                    printf("\nIf 3");
                    if(cambiar3==1)
                           {
                               al=rand()%51;
                           while(vec_cartas[al].dado==1)
                            {
                                al=rand()%51;
                            }
                           entregadas[2]=vec_cartas[al];
                           }
                }
                else if((mousex>1053 && mousex<1153)&&(mousey>139 && mousey<274) && aux4==0)
                {
                    cambiar4=1;
                   i=i+1;
                   aux4=1;
                   printf("\nIf 4");
                   //al_mouse_button_down(&mouse,1);
                   if(cambiar4==1)
                       {
                           al=rand()%51;
                       while(vec_cartas[al].dado==1)
                        {
                            al=rand()%51;
                        }
                       entregadas[3]=vec_cartas[al];
                       }


                }
                else if((mousex>1154 && mousex<1254)&&(mousey>139 && mousey<274) && aux5==0)
                {
                    cambiar5=1;
                   i=i+1;
                   printf("\nIf 5");
                   aux5=1;
                   //al_mouse_button_down(&mouse,1);
                    if(cambiar5==1)
                   {
                      al=rand()%51;
                   while(vec_cartas[al].dado==1)
                    {
                        al=rand()%51;
                    }
                   entregadas[4]=vec_cartas[al];
                   }

                }

            al_mouse_button_down(&mouse,1);
            printf("\nI: %d",i);
            al_flip_display();
            al_draw_textf(font,al_map_rgb(0,0,0),0,0,ALLEGRO_ALIGN_LEFT,"X: %d , Y: %d",mousex,mousey);
            al_flip_display();


       }while(i<x);



p=0;



al_clear_to_color(al_map_rgb(0, 100, 0));//limpia el color de la pantalla

     for(s=0;s<5;s++)
            {
        al_draw_scaled_bitmap(entregadas[s].imagen,0/*recorta la imagen en el eje x*/,0/*recorta la imagen en el eje y*/,99/*cuanto mide de ancho*/,138/*cuanto mide de largo*/,750+p/*posicion de la carta en eje x*/,148.5/*posicion de la carta en el eje y*/,99/*cuanto va a medir de ancho*/,138/*cuanto va a medir de largo*/,0);
       p=p+99;

            }

 al_flip_display();
}

