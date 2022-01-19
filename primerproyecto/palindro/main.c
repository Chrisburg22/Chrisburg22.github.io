#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *quitar_espacios(char *palindromo){
    int i=0, j=0;
    while(palindromo[i]){
        if(palindromo[i] !=' ')
            palindromo[j++] =palindromo[i];
        i++;
    }
    palindromo[j]='\0';
    return palindromo;
}


int main()
{
    char palindromo[100];
    int tamanodepalindromo,opc=0,aux=0,a=0;

    printf("\t*Verificador de palindromos*\n");

    while(opc<=2){

    printf("1)Para jugar 2)Para Salir\n");
    scanf("%i",&opc);

    if(opc==1){
    printf("Ingresa una frase o palabra para comprobar si es palindromo o no:\n");
    scanf("%s",&palindromo);
    printf("\n");

    strlwr(palindromo);
    quitar_espacios(palindromo);
    tamanodepalindromo=strlen(palindromo);

    for(int izquierda=0, derecha=tamanodepalindromo-1;izquierda<=tamanodepalindromo/2;izquierda++,derecha--){


        if(palindromo[izquierda]==palindromo[derecha]){
            printf("Cargando...");
        }else{
            printf("Parece que no es un palindromo, intentalo otra vez\n");
            aux=1;
        }break;
        system ("pause");

    }

    if(aux==0){
    printf("Felicidades tu frase es un palindromo :D\n");system ("pause");}
    }
    if(opc>=2){
        printf("Hasta Pronto\n");}
    }

    return 0;
}

