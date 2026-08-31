/* Animador em 3D- Exemplo de uso das funcoes em TRES DIMENSOES - Vander R. N. D. */
#include <3d.h> 
#include <ctype.h>

int dist=400,l=900; /* Distancia do observador */

/* A biblioteca 3D.LIB ja define algumas variaveis, que nao podem modificadas:
nf = NUMERO DE FIGURAS DEFINIDAS
no = NUMERO DE OBJETOS DEFINIDOs
nv = NUMERO DE VERTICES DEFINIDOS
nl = NUMERO DE LINHAS DEFINIDAS
deslx,
desly,
SNOME (macro)
MAXF (macro)
MAXO (macro)
MAXV (macro)
MAXL (macro)
figura[]
objeto[]
vertice[]
ponto[]   */


main() 
{
	int placa=1;
	int modo=4;
	char path=' ';
	char tecla='Q';      /* necessario apenas para o exemplo */
	char *ptecla=&tecla; /* exemplo */
	int a=0,b=0,t=0,ao=0,bo=0,to=0;
	int aa,ba,ta,la,lc;

	initgraph(&placa,&modo,&path);

	inigraus(); /* Deve sempre ser chamada APOS a mudanca do modo de video,
				pois ira extrair a resolucao grafica !!! */

	/* Este trecho sera´ modificado de acordo com a aplicacao */

	cleardevice(); gotoxy(1,1);
	puts("     GRAFICOS TRIDIMENSIONAIS\n");
	puts("           DEMONSTRACAO\n");
	puts("       Controle da rotacao:\n");
	puts("TECLAS /EFEITO\n");
	puts("q | a   -10 | +10 graus ALFA\n");
	puts("w | s   -10 | +10 graus BETA\n");
	puts("e | d   -10 | +10 graus TETA\n");
	puts("= | -   -10 | +10 pixels DISTANCIA\n");
	puts("v       retorna eixos a 0 graus\n");
	puts("f       FIM DO PROGRAMA\n");
	puts("     Tecle algo para iniciar...");
	gotoxy(48,18);puts("Programado por");
	gotoxy(50,19);puts("Vander Roberto Nunes Dias");
	gotoxy(48,22);puts("Matematica de");
	gotoxy(50,23);puts("Jose Roberto Mendonca Xavier");
	gotoxy(50,24);puts("e Roberto Colistete Junior");
	rectangle(320,0,639,130);

	/* Inclui uma figura chamada "EXEMPLO", com X=0, Y=0 e Z=0 */
	incf("exemplo",0,0,0);

	/* Inclui o objeto "PIRAMIDE", com X=0, Y=-80 e Z=0 ,
	se liga ao objeto 2, e tem rotaca ALFA=0, BETA=0 e TETA=0 */
	inco("piramide",0,-80,0,2,0,0,0);

	/* Vertices da "PIRAMIDE", coordenadas relativas as do OBJETO:
	o primeiro vertice esta em X=0, Y=-50, Z=0 */
	incv(0,-25,0,nv+1);   /* a variavel NV nao pode ser modificada ! */
	incv(50,25,-50,nv+1);
	incv(50,25,50,nv+1);
	incv(-50,25,50,nv+1);
	incv(-50,25,-50,0);
	/* As linhas que ligam os vertices da "PIRAMIDE" */
	incl(1,2); /* Vertice 1 se liga ao 2 */ 
	incl(1,3); /* Vertice 1 se liga ao 3... */ 
	incl(1,4);
	incl(1,5);
	incl(2,3);
	incl(2,5);
	incl(3,4);
	incl(4,5);
	incl(0,0);

	/* o objeto "CAIXA", X=0, Y=0, Z=0, ultimo objeto, tem rotacao
		ALFA=0, BETA=0 e TETA=0 */
	inco("caixa",0,0,0,0,0,0,0);
	incv(-50,-50,60,nv+1);
	incv(-50,-50,-60,nv+1);
	incv(50,-50,-60,nv+1);
	incv(50,-50,60,nv+1);
	incv(50,15,60,nv+1);
	incv(-50,15,60,nv+1);
	incv(-50,15,-60,nv+1);
	incv(50,15,-60,0);
	incl(1,2);
	incl(1,4);
	incl(1,6);
	incl(3,2);
	incl(3,4);
	incl(3,8);
	incl(2,7);
	incl(4,5);

	/* NOTA: 4 linhas abaixo estavam faltando no artigo original*/
	incl(5,6); 
	incl(6,7);
	incl(7,8);
	incl(8,5);

	incl(0,0);
	
	incf("exemplo2",0,0,0);
	inco("seta",0,0,0,0,0,0,0);
	incv(-50,0,0,nv+1);
	incv(50,0,0,nv+1);
	incv(40,-10,0,nv+1);
	incv(40,10,0,0);

	incl(1,2);
	incl(3,2);
	incl(4,2);
	incl(0,0);

	do {
		setcolor(1); mostraf("exemplo",110,-40,a,b,t,dist,600);
		mostraf("exemplo2",250,-30,0,b,-20,dist,150);
		setcolor(0); mostraf("exemplo",110,-40,a,b,t,dist,600);
		mostraf("exemplo2",250,-30,0,b,-20,dist,150);
		b+=10; if(b>=360) b-=360;
		t+=5; if(t>=360) t-=360;
	} while (!kbhit());
	a=0; b=0; t=0; cleardevice();

	/* Mostra toda a figura "EXEMPLO", com seus objetos */
	setcolor(1);
	mostraf("exemplo",0,0,0,0,0,dist,l);
	while(*ptecla!='f') {
		*ptecla=tolower(getch(tecla));
		aa=a; ba=b; ta=t; la=l;
		if (*ptecla=='q') a-=10;
		if (*ptecla=='a') a+=10;
		if (*ptecla=='w') b-=10;
		if (*ptecla=='s') b+=10;
		if (*ptecla=='e') t-=10;
		if (*ptecla=='d') t+=10;
		if (*ptecla=='-' && l<2040) l+=40;
		if (*ptecla=='=' && l>40) l-=40;
		if (*ptecla=='v') {a=1; b=1; t=1; }

		if (a<0) a+=360;
		if (a>=360) a-=360;
		if (b<0) b+=360;
		if (b>=360) b-=360;
		if (t<0) t+=360;
		if (t>=360) t-=360;
		lc=l;
		l=la;
		setcolor(0);
		mostraf("exemplo",0,0,aa,ba,ta,dist,l); /* Mostra a figura na mesma posicao, 
												com cor preta, apenas para apaga-la */
		l=lc;
		if (ao<0) ao+=360;
		if (ao>=360) ao-=360;
		if (bo<0) bo+=360;
		if (bo>=360) bo-=360;
		if (to<0) to+=360;
		if (to>=360) to-=360;
		setcolor(1);
		mostraf("exemplo",0,0,a,b,t,dist,l); 
	}

	/* Aqui termina o trecho que sera´ modificado de acordo com a aplicacao. */

	closegraph();
	printf("\n\nAte logo.\n\n\n");

}
