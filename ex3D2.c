#include "3D.H"

int l = 1500;

main()
{
    int l = 1500;
    int a = 0, b = 0, t = 0;
    int placa = 9;  /* 1 */
    int modo = 1;   /* 4 */
    char path = ' ';
    int x = -180, y = 0, ix = 10, iy = 10;

    initgraph(&placa, &modo, &path);
    setcolor(1);
    inigraus();

    incf("teste", -200, 0, 0);
    inco("quad", 0, 0, 0, no + 1, 0, 0, 0);
    incv(-40, -40, 40, nv + 1);
    incv(-40, 40, 40, nv + 1);
    incv(-40, -40, -40, nv + 1);
    incv(-40, 40, -40, nv + 1);
    incv(40, -40, 40, nv + 1);
    incv(40, 40, 40, nv + 1);
    incv(40, -40, -40, nv + 1);
    incv(40, 40, -40, 0);

    incl(1, 2);
    incl(1, 3);
    incl(1, 5);
    incl(2, 4);
    incl(2, 6);
    incl(3, 7);
    incl(4, 3);
    incl(4, 8);
    incl(6, 5);
    incl(6, 8);
    incl(8, 7);
    incl(5, 7);
    incl(0, 0);

    do
    {
        cleardevice();
        mostraf("teste", 0, 0, a, b, t, 300, l);
        a += 10;
        if (a > 359)
            a = -360;
        l -= 25;
    } while (l > 500);

    do
    {
        cleardevice();
        mostraf("teste", 0, 0, a, b, t, 300, l);
        x += ix;
        if (x > 180 || x < -180)
            ix = -ix;
        y += iy;
        if (y > 180 || y < -180)
            iy = -iy;
        a += 10;
        if (a > 359)
            a = -360;
        movf("teste", x, y, 0);

    } while (!kbhit());

    do
    {
        cleardevice();
        mostraf("teste", 0, 0, a, b, t, 300, l);
        a += 10;
        if (a > 359)
            a = -360;
        l += 25;
    } while (l < 1500);

    closegraph();
}
