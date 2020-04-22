#include <stdio.h>
#include <stdlib.h>
int swap(float *x, float *y)
{
    float aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
int main()
{
    float x,y;
    scanf("%f \n %f", &x,&y);
    swap(&x,&y);

    printf("%f \n%f",x,y);
    return 0;
}
