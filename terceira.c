struct BDF
{
    char nome[SNOME];
    int x;
    int y;
    int z;
    int prim;
} figura[MAXF];

struct BDO
{
    char nome[SNOME];
    int x;
    int y;
    int z;
    int alfa;
    int beta;
    int teta;
    int primv;
    int priml;
    int proxo;
} objeto[MAXO];

struct BDV
{
    int x;
    int y;
    int z;
    int proxv;
} vertice[MAXV];

struct BDL
{
    int l1;
    int l2;
} linha[MAXL];

struct BDC
{
    int x;
    int y;
} ponto[MAXV];

int nf = 0;
int no = 0;
int nv = 0;
int nl = 0;
int deslx, desly;
int seno[360], coss[360];

void incf(char nome[SNOME], int x, int y, int z)
{
    if (nf != MAXF)
    {
        strcpy(figura[nf].nome, nome);
        figura[nf].x = x;
        figura[nf].y = y;
        figura[nf].z = z;
        figura[nf].prim = no;
        nf++;
    }
    else
    {
        printf("\nBanco de Figuras Esta Cheio !");
        sai(1);
    }
}

void inco(char nome[SNOME], int x, int y, int z, int prox, int alfa, int beta, int teta)
{
    if (no != MAXO)
    {
        strcpy(objeto[no].nome, nome);
        objeto[no].x = x;
        objeto[no].y = y;
        objeto[no].z = z;
        objeto[no].alfa = alfa;
        objeto[no].beta = beta;
        objeto[no].teta = teta;
        objeto[no].proxo = prox;
        objeto[no].primv = nv;
        objeto[no].priml = nl;
    }
    else
    {
        printf("Banco de objetos esta Cheio !!!");
        sai(1);
    }
}

void incv(int x, int y, int z, int proximo)
{
    if (nv != MAXV)
    {
        vertice[nv].x = x;
        vertice[nv].y = y;
        vertice[nv].z = z;
        vertice[nv].proxv = proximo;
        nv++;
    }
    else
    {
        printf("\nBanco de Vertices esta Cheio !!!");
        sai(1);
    }
}

void incl(int p1, int p2)
{
    if (nl != MAXL)
    {
        linha[nl].l1 = p1;
        linha[nl].l2 = p2;
        nl++;
    }
    else
    {
        printf("\nBanco de Linhas esta Cheio !!!");
        sai(1);
    }
}

void inigraus(void)
{
    int graus;
    deslx = getmaxx() / 2;
    desly = getmaxy() / 2;
    puts("AGUARDE CALCULOS INICIAIS...");
    for (graus = 0; graus < 360; graus++)
    {
        seno[graus] = (int)(sin(graus * 3.1415926 / 180) * 256);   
        coss[graus] = (int)(cos(graus * 3.1415926 / 180) * 256);
    }
}

void rot(int refx, int refy, int refz, int *x, int *y, int *z, int alfa, int beta, int teta)
{
    int x1, x2, y1, y2, z1, z2;
    x1 = (((*x) * coss[alfa]) >> 8) - (((*y) * seno[alfa]) >> 8);
    y1 = (((*y) * coss[alfa]) >> 8) + (((*x) * seno[alfa]) >> 8);
    x2 = (((x1)*coss[beta]) >> 8) - (((*z) * seno[beta]) >> 8);
    z1 = (((*z) * coss[beta]) >> 8) + ((x1 * seno[beta]) >> 8);
    z2 = ((z1 * coss[teta]) >> 8) - ((y1 * seno[teta]) >> 8);
    y2 = ((y1 * coss[teta]) >> 8) + ((z1 * seno[teta]) >> 8);
    *x = refx + x2;
    *y = refy + y2;
    *z = refz + z2;
}

void bidi(int x, int y, int z, int *h, int *v, int dist, int l)
{
    *h = (int)((long)x * dist / (z + dist + l));
    *v = (int)((long)y * dist / (z + dist + l));
}

char girao(char nome[SNOME], int alfa, int beta, int teta)
{
    int buscao;
    for (buscao = 0; buscao < no; buscao++)
        if (!strcmp(objeto[buscao].nome, nome))
            break;

    if (buscao == no)
    {
        return ('*');
    };

    objeto[buscao].alfa = alfa;
    objeto[buscao].beta = beta;
    objeto[buscao].teta = teta;
}

char movf(char nome[SNOME], int x, int y, int z)
{
    int buscaf;
    for (buscaf = 0; buscaf < nf; buscaf++)
        if (!strcmp(figura[buscaf].nome, nome))
            break;

    if (buscaf == nf)
    {
        return ('*');
    };

    figura[buscaf].x = x;
    figura[buscaf].y = y;
    figura[buscaf].z = z;
}

char movo(char nome[SNOME], int x, int y, int z)
{
    int buscao;
    for (buscao = 0; buscao < no; buscao++)
        if (!strcmp(objeto[buscao].nome, nome))
            break;

    if (buscao == no)
    {
        return ('*');
    };

    objeto[buscao].x = x;
    objeto[buscao].y = y;
    objeto[buscao].z = z;
}

char mostraf(char nome[SNOME], int dx, int dy, int alfa, int beta, int teta, int dist, int l)
{
    int buscaf, np;
    int al, be, te;
    int refx, refy, refz;
    int refox, refoy, refoz;
    int alfao, betao, tetao;
    int vx, vy, vz;
    int rego;
    register int regv, regl;
    int h, v, ho, vo;

    for (buscaf = 0; buscaf < nf; buscaf++)
        if (!strcmp(figura[buscaf].nome, nome))
            break;

    if (buscaf == nf)
    {
        return ('*');
    };

    refx = figura[buscaf].x;
    refy = figura[buscaf].y;
    refz = figura[buscaf].z;
    rego = figura[buscaf].prim;
    do
    {
        refox = objeto[rego].x;
        refoy = objeto[rego].y;
        refoz = objeto[rego].z;
        bidi(refox, refoy, refoz, &ho, &vo, dist, l);
        rot(refx, refy, refz, &refox, &refoy, &refoz, alfa, beta, teta);
        regv = objeto[rego].primv;
        np = 1;
        do
        {
            vx = vertice[regv].x;
            vy = vertice[regv].y;
            vz = vertice[regv].z;
            alfao = objeto[rego].alfa;
            betao = objeto[rego].beta;
            tetao = objeto[rego].teta;
            al = alfa + alfao;
            be = beta + betao;
            te = teta + tetao;
            if (al >= 360)
                al -= 360;
            if (al < 0)
                al += 360;
            if (be >= 360)
                be -= 360;
            if (be < 0)
                be += 360;
            if (te >= 360)
                te -= 360;
            if (te < 0)
                te += 360;
            rot(refx, refy, refz, &vx, &vy, &vz, al, be, te);
            vx += refox;
            vy += refoy;
            vz += refoz;
            bidi(vx, vy, vz, &h, &v, dist, l);
            ponto[np].x = h;
            ponto[np].y = v;
            np++;
            regv++;
        } while (vertice[regv - 1].proxv);
        regl = objeto[rego].priml;
        while (linha[regl].l1)
        {
            line(deslx + dx + ponto[linha[regl].l1].x,
                 desly + dy + ponto[linha[regl].l1].y,
                 deslx + dx + ponto[linha[regl].l2].x,
                 desly + dy + ponto[linha[regl].l2].y);
            regl++;
        }
        if (objeto[rego].proxo == 0)
            break;
        rego++;
    } while (1);
}

void lin3d(int refx, int refy, int refz, int x1, int y1, int z1, int x2, int y2, int z2, int a, int b, int t, int d, int l)
{
    int h1, v1, h2, v2, rx, ry, rz;
    rot(refx, refy, refz, &x1, &y1, &z1, a, b, t);
    bidi(x1, y1, z1, &h1, &v1, d, l);
    rot(refx, refy, refz, &x2, &y2, &z2, a, b, t);
    bidi(x2, y2, z2, &h2, &v2, d, l);
    line(deslx + h1, desly + v1, deslx + h2, desly + v2);
}

void cir3d(int x, int y, int z, int r, int a, int b, int t, int d, int l)
{
    int ang = 0, rx, ry, rz, x2, y2, z2, dx, dy;
    dx = (r * coss[ang] / 256);
    dy = (r * seno[ang] / 256);
    x2 = dx;
    y2 = dy;
    z2 = z;
    for (ang = 0; ang < 360; ang += 5)
    {
        if (ang == 360)
            ang = 0;
        dx = (r * coss[ang] / 256);
        dy = (r * seno[ang] / 256);
        rx = dx;
        ry = dy;
        rz = z;
        lin3d(x, y, z, rx, ry, rz, x2, y2, z2, a, b, t, d, l);
        x2 = rx;
        y2 = ry;
        z2 = rz;
    }
}

sai(int erro)
{
    char tecla;
    if (erro == 1)
    {
        printf("\nExecucao terminada...tecle algo.\n");
        getch(&tecla);
        exit(1);
    };
    if (erro == 0)
    {
        printf("\nAviso apenas...tecle algo.\n");
        getch(&tecla);
    };
}
