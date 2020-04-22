#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double p1[2],p2[2],x,y,distancia;
    scanf("%lf %lf",&p1[0],&p1[1]);
    scanf("%lf %lf",&p2[0],&p2[1]);

    x=p2[0]-p1[0];
    y=p2[1]-p1[1];

    x= x*x;
    y= y*y;

    distancia=sqrt(x+y);

    printf("Distancia = %.4lf", distancia);



    return 0;
}
