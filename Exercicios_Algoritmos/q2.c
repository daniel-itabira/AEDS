#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    scanf("%d", &n);
    if(n<0)
    {
        n = n*-1;
    }
    if(n<=10000)
    {
        n = n*n;
    }
    if(n>10000)
    {
        return 0;
    }
    printf("%d", n);

    return 0;
}
