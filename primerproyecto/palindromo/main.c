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
    int tamanodepalindromo;

    printf("\t*Verificador de palindromos*\n\n");
    printf("-------------------------------------\n\n");

    printf("Ingresa una frase o palabra para comprobar si es palindromo o no:\n");
    gets(palindromo);
    printf("\n\n");

    printf("La frase introducida es:\n");
    puts(palindromo);
    printf("\n\n");

    strlwr(palindromo);
    quitar_espacios(palindromo);
    tamanodepalindromo=strlen(palindromo);


    printf("La frase introducida es:\n");
    puts(palindromo);
    printf("\n\n");

    printf("%i\n", tamanodepalindromo);





    for(int izquierda=0, derecha=tamanodepalindromo-1;izquierda<=tamanodepalindromo/2;izquierda++,derecha--){

        system ("pause");

        printf("comparando posiciones de letras numero [%i] con [%i]\n", izquierda+1,derecha+1);

        if(palindromo[izquierda]==palindromo[derecha]){
            printf("okok, sigamos\n");
        }else{
            printf("parece q no es un palindromo, intentalo otra vez\n");
            return 0;
        }
    }
    printf("Felicidades tu frase es un palindromo :D\n");
    return 0;
}

