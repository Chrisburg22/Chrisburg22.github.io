#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pun1[20]={'a','e','i','o','u','l','n','r','s','t','A','E','I','O','U','L','N','R','S','T'};
    char pun2[4]={'d','g','D','G'};
    char pun3[8]={'b','c','m','p','B','C','M','P'};
    char pun4[10]={'f','h','v','w','y','F','H','V','W','Y'};
    char pun5[2]={'k','K'};
    char pun8[4]={'j','x','J','X'};
    char pun10[4]={'q','z','Q','Z'};
    char palabra[40]={'0'};
    int x,y,total=0,opc;

    do{
        printf("******Scrabble Game********\n\n");
        printf("Ingresa una palabra: ");
        scanf("%s",&palabra);

        for(x=0;x<strlen(palabra);x++){
            for(y=0;y<20;y++){
            if(palabra[x]==pun1[y]){
                    total=total+1;break;}
                else
                   if(palabra[x]==pun2[y]&& y<3){
                     total=total+2;break;}
                    else
                       if(palabra[x]==pun3[y] && y<5){
                         total=total+3;break;}
                    else
                       if(palabra[x]==pun4[y] && y<6){
                          total=total+4;break;}
                       else
                          if(palabra[x]==pun5[y] && y<2){
                             total=total+5;break;}
                          else
                             if(palabra[x]==pun8[y] && y<3){
                               total=total+8;break;}
                               else
                                  if(palabra[x]==pun10[y] && y<3){
                                    total=total+10;break;}
            }
        }
            printf("La Puntuacion de la palabra %s son: %d\n\n",palabra,total);
            total=0;
            printf("%cQuieres Probar con otra palabra? 1)SI 2)NO\n",168);
            scanf("%d",&opc);


    }while(opc!=2);

    return 0;
}
