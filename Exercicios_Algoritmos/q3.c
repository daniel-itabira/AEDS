#include <stdio.h>
#include <stdlib.h>

int main()
{
    float area,r,pi;
    pi = 3.14159;

    scanf("%f",&r);

    r=r*r;
    area = r*pi;

    printf("A=%.4f", area);
    return 0;

}
