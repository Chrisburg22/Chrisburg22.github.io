#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a,b,q;
    do{
    printf("ingresa un numero: ");
    scanf("%d",&x);

    for(a=1;a<=x;a++)
    {
        for(b=1;b<=x;b++)
        {
            if(b<=a)
              printf("* ");
            else
              printf("  ");
        }
        printf("\n");
    }
    printf("Quieres crear otro triangulo\n 1)si 2)no\n");
    scanf("%d",&q);
    }while(q!=2);

    return 0;
}
