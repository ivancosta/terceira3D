#include <math.h>
#include <graphics.h>

#define MAXF 50
#define MAXO 100
#define MAXV 500
#define MAXL 1000
#define SNOME 15

int nf, no, nv, nl, seno[360], coss[360];

void incf (char nome[SNOME], int x, int y, int z);
void inco (char nome[SNOME], int x, int y, int z, int prox, int alfa,int beta,int teta);
void incv (int x, int y, int z, int proximo);
void incl (int p1, int p2);
void inigraus(void);
void rot (int refx,int refy,int refz,int *x,int *y,int *z,int alfa,int beta,int teta);
void bidi (int x,int y,int z, int *h, int *v, int dist,int l);
char girao (char nome[SNOME],int alfa,int beta,int teta);
char movf (char nome[SNOME], int x,int y,int z);
char movo (char nome[SNOME], int x,int y,int z);
char mostraf(char nome[SNOME],int dx,int dy,int alfa,int beta,int teta,int dist,int l);
void lin3d (int refx,int refy,int refz,int x1,int y1,int z1,int x2,int y2,int z2,int a,int b,int t,int d,int l);
void cir3d (int x,int y,int z,int r,int a,int b,int t,int d,int l);
