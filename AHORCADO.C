#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <graphics.h>

char palabras[10][10];
char pala_del[10],resp[10];
char letra,opc,catego;

/*arreglos del muñeco con el arco*/
 int madera[]={565,309,595,309,595,6,363,6,363,70,381,70,
  381,30,565,30,565,309};
  int madera1[]={459,21,489,21,565,100,565,123,459,21};

  int boca[]={352,124,363,119,380,119,391,124,
  388,129,380,125,364,125,355,129,352,124};

  int brazoizq[]={375,160,375,169,412,207,417,203,375,160};

  int brazoder[]={369,160,369,169,331,207,326,203,369,160};

  int piernaizq[]={375,226,407,279,401,282,371,231,375,226};

  int piernader[]={368,226,336,279,342,282,375,226,368,226};

  int i,j,y,z,aum,elegida,longi,opor,a;

  int cate(void);
  int elegir(int);
  int imprime(void);

void main(void)
{
int ad=DETECT,modo;
char cad[100];
int correcto=0;
initgraph(&ad,&modo,"c:\\tc\\bgi");
do{
    categoria();
    setbkcolor(BLUE);  /*COLOR DE FONDO AZUL*/
    setcolor(WHITE);      /*COLOR DE LETRA BLANCO*/
    cleardevice();              /*LIMPIO PANTALLA*/



    i=0,j=0,y=0,z=0,aum=0,elegida=0,longi=0,opor=0,a=0;

   for(i=0;i<10;i++)
   {
       resp[i]=NULL;        /* LIMPIO LA CADENA*/
   }

   /*JUEGO DEL AHORCADO*/

   outtextxy(180,15,"El Ahorcado");

   /*ESTE FOR DESPLIEGA EL ALFABETO*/
   for(i=0;i<26;i++)
   {
      gotoxy(i*2+18,4);
      printf("%c",65+i);
   }
   /*ESTA FUNCION ELIGE UN NUMERO ALEATORIO PARA ESCOGER UNA PALABRA*/
       randomize();
       j=random(9);

       /*FUNCION QUE ELIGE ALEATORIAMENTE LA PALABRA*/
       elegir(j);
       longi=strlen(pala_del);
       imprime();


   do{
	  gotoxy(5,9);
	  printf("ADIVINA LA PALABRA");
	  gotoxy(10,12);
	  printf("EVITE QUE SE AHORQUE EL HOMBRE");

	  do
	  {
		letra=toupper(getch());/*CON ESTE DO NO ADMITO NUMEROS*/
	  }
	  while(!isalpha(letra) );


	  gotoxy(11+opor*3,22);
	  printf("%c",letra);

	   fflush(stdin);
	  for(i=0;i<longi;i++)
	     {
	      if(letra==pala_del[i])
	      {

		 gotoxy(13+i*4+18,19);
		 printf("%c",letra);
		 fflush(stdin);
		 resp[i]=letra;
		 correcto=1;

	       }

	     }

	     y=strcmp(pala_del,resp);

	     if(y==0){
		textcolor(WHITE);
		outtextxy(120,100," CORRECTO, ERES UN CRACK");
		     }

	       fflush(stdin);



		if (correcto==0)
	     {
	     opor++;
	       if (opor==1)
	     {
	     /*marco madera */
	  setcolor(BROWN);
	 setfillstyle(SOLID_FILL,BROWN);
	 fillpoly(9,madera);

	     }

	     if (opor==2)
	       {
		fillpoly(5,madera1);
	       }

	     if (opor==3)
	     {
	       setcolor(WHITE);
	  setfillstyle(SOLID_FILL,WHITE);
	  circle(372,108,38);
	     }

	     if (opor==4)
	     {
	     circle(384,97,7);/*ojo derecha*/
	   floodfill(384,97,WHITE);

	     }

	    if (opor==5)
	     {
	      circle(359,97,7);/*ojo izquierda*/
       floodfill(359,97,WHITE);

	     }

	     if (opor==6)
	     {
		fillpoly(9,boca);/*boca*/
	     }

	     if (opor==7)
	     {
	     /*tronco*/
	rectangle(369,147,375,224);
       floodfill(373,176,WHITE);
	     }

	     if (opor==8)
	     {
	     fillpoly(5,brazoizq);/*brazo izquierd0*/
	     }

	     if (opor==9)
	     {
	     fillpoly(5,brazoder);/*brazo derecho*/
	     }

	     if (opor==10)
	     {
	     fillpoly(5,piernaizq);/*pierna izquierda*/
	     }

	     if (opor==11)
	     {
	     fillpoly(5,piernader);/*pierna derecha*/
	     }

/*controla el moviento del muñeco*/
		if (opor==12)
	     {
			for (z=0; z<20; z++)
			{

				if(aum%2==0)
				{
					/*elimina la boca*/
					setcolor(LIGHTBLUE);
					setfillstyle(SOLID_FILL,LIGHTBLUE);
					bar(350,117,393,134);
					/*abre la boca*/
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,WHITE);
					pieslice(371,129,0,360,11);
					/*elimina la boca abierta*/
					setcolor(LIGHTBLUE);
					setfillstyle(SOLID_FILL,LIGHTBLUE);
					bar(359,115,385,142);
					/*pone boca anterior*/
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,WHITE);
					fillpoly(9,boca);/*boca*/

				}

			}


		}

	    }
	    correcto=0;
	     fflush(stdin);

   }while(opor<13 && y!=0);

	 if(opor==13)
	 {

	    setcolor(RED);
	    outtextxy(150,370,"INCORRECTO!!!...\n La palabra era");
	    setcolor(LIGHTRED);
	    outtextxy(300,400,       pala_del);

	 }



	 outtextxy(200,420,"Desea volver a jugar (s\\n)");


	 do{
	   opc=toupper(getch());
	 }while(opc!='S' && opc!='N');

}while(opc!='N');
   cleardevice();

   exit(1);
   closegraph();
   return;

}



cargarfamosos()
{

  strcpy(palabras[0],"RONALDO");
  strcpy(palabras[1],"MESSI");
  strcpy(palabras[2],"CASILLAS");
  strcpy(palabras[3],"JAKE");
  strcpy(palabras[4],"BENJAMINZELEDON");
  strcpy(palabras[5],"ANDRESCASTRO");
  strcpy(palabras[6],"LENNIN");
  strcpy(palabras[7],"XAVI");
  strcpy(palabras[8],"OZIL");
  strcpy(palabras[9],"HIGUAIN");
  return 0;

}


elegir(int pal)
{
  strcpy(pala_del,palabras[pal]);
  return 0;
}

imprime()
{
 int ad=DETECT,modo;
 initgraph(&ad,&modo,"c:\\tc\\bgi");

 setbkcolor(LIGHTBLUE);
 setcolor(WHITE);
 for(i=1;i<=longi;i++)
 {
    outtextxy(210+i*28+5,300,"_");
    }
    return 0;
}



cargarmusica()
{
  strcpy(palabras[0],"GUSTAVOLEYTON");
  strcpy(palabras[1],"CUNETASONMACHIN");
  strcpy(palabras[2],"CALVINHARRIS");
  strcpy(palabras[3],"LUDACRIS");
  strcpy(palabras[4],"TUPAC");
  strcpy(palabras[5],"SLASH");
  strcpy(palabras[6],"MANA");
  strcpy(palabras[7],"DAFTPUNK");
  strcpy(palabras[8],"TIESTO");
  strcpy(palabras[9],"LUISENRIQUE");
  return 0;

}

cargarcomidas()
{
strcpy(palabras[0],"NACATAMAL");
  strcpy(palabras[1],"GALLOPINTO");
  strcpy(palabras[2],"ARROZ");
  strcpy(palabras[3],"FRIJOLES");
  strcpy(palabras[4],"FRITO");
  strcpy(palabras[5],"SOPA");
  strcpy(palabras[6],"POLLO");
  strcpy(palabras[7],"CARNE");
  strcpy(palabras[8],"LECHUGA");
  strcpy(palabras[9],"ENZALADA");
  return 0;
}


categoria()
{
   int ad=DETECT,modo;
   initgraph(&ad,&modo,"c:\\tc\\bgi");
  setbkcolor(LIGHTBLUE);
  setcolor(WHITE);
  cleardevice();
  settextstyle(8,0,2);
  outtextxy(130,30,"      CATEGORIAS");

  setcolor(LIGHTRED);
  outtextxy(100,90,"1.-FAMOSOS");
  outtextxy(100,110,"2.-COMIDA");
  outtextxy(100,130,"3.-CANTANTES");

  settextstyle(1,0,1);

  setcolor(GREEN);
   outtextxy(100,170,"ELIGE TU OPCION!!");

  do{
    catego=getch();
  }while(catego!='1' && catego!='2' && catego!='3');

  switch(catego){
	case '1':cargarfamosos();
	break;
	case '2':cargarcomidas();
	break;
	case '3':cargarmusica();
	break;
   }
   return 0;
}
