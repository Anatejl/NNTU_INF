#include <stdio.h>
#include <math.h>

int main()
{
    //вводные
    double S=0.000300, U = 330, n=1, D =10, H = 17.5, E[10];

    double d,C,r,e,a,b,c,x=0, Em, L, B=100;
    int i;

    //вычисления
    d = sqrt(4*S/3.14);
    r = d/2;
    C = 24/(log10(2*D/d));
    e = C*U/(2*sqrt(3)*3.14*8.85);
    Em = e/r;
    L = 20+0.0111*Em+900*r+15*log10(n)-20*log10(B);

    //вывод результата
    printf("d=%lf,\tr=%lf,C=%lf*10^-12,\t\n", d,r,C);

    for(i=0;i<6;i++)
    {
        a=2*H/(pow((x-D),2)+pow(H,2));
        b=H/(pow(x,2)+pow(H,2));
        c=H/(pow((x+D),2)+pow(H,2));
        E[i] = e*(a-b-c);
        printf("x=%lf,\tE=%lf\n", x,E[i]);
        x+=10;
    }

    printf("\nEm=%lf,\nL=%lf", Em,L);

    return 0;
}

