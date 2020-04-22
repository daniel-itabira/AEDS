#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    scanf("%d", &idade);

    int a=0,m=0,d=0;

    if(idade>=30)
    {
        for(idade;idade>=30;idade=idade-30)
        {
            m++;
        }
    if(m>=12)
        {
        for(m;m>=12;m=m-12)
            {
                a++;
            }
        }
        d=idade/2;
    }else{d=idade;}

    printf("%d dano(s) \n%d mes(es) \n%d dias(s)",a,m,d);

    return 0;
}
