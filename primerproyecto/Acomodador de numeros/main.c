#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int vec[100],x,y,a,b;
    srand(time(NULL));

    printf("%cCuantos numeros quieres acomodar? ",168);
    scanf("%d",&b);

    for(a=0;a<b;a++){
        vec[a]=rand()%1001;
        printf("%d  ",vec[a]);
    }
    printf("\n");
     for(a=0;a<b;a++){
       for(y=0,x=1;x<b;y++,x++){
           if(vec[y]<vec[x]){
               int temp=vec[x];
               vec[x]=vec[y];
               vec[y]=temp;
           }
       }}

       for(a=0;a<b;a++)
            printf("%d  ",vec[a]);


    return 0;
}

