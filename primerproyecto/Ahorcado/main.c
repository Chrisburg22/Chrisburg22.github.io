#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#ifdef _TURBOC_
    #define _getch getch
#endif

static int oportunidades = 8;

int main(void)
{
    char *palabras[] =
    {
        "Argentina",
        "Belice",
        "Bolivia",
        "Brasil",
        "Canada",
        "Colombia",
        "Cuba",
        "Chile",
        "Ecuador",
        "Espa\244a",
        "EstadosUnidos",
        "Guatemala",
        "Haiti",
        "Honduras",
        "Mexico",
        "Panama",
        "Paraguay",
        "Peru",
        "PuertoRico",
        "RepublicaDominicana",
        "Uruguay",
        "Venezuela"
    };
    char *palabra, *casillas, letra,caracter;
    int i, n, turnos = 0, aciertos = 0, encontrado,opc;
    do{
    printf("°°°JUEGO DEL AHORCADO°°°");
    srand ((unsigned) time (NULL));
    palabra = palabras[rand()%(sizeof (palabras) / sizeof (palabras[0]))];
    n = strlen (palabra);
    casillas = (char*) malloc (n);
    for (i=0; i<n; i++)
        casillas[i] = '_';
    do {
        printf ("\nOportunidades restantes: %d\n", oportunidades-turnos);
        for (i=0; i<n; i++){
            printf ("%c", casillas[i]);}

        printf ("\nEscriba una letra: ");
        scanf("%s",&letra);
        encontrado = 0;
        for (i=0; i<n; i++) {
            caracter = palabra[i];
            if (toupper(letra)==toupper(caracter))
            {
                encontrado = 1;
                if (casillas[i]=='_')
                {
                    casillas[i] = caracter;
                    aciertos++;
                }
            }
        }
        if (encontrado==0)
        {
            turnos++;
            printf ("Letra no encontrada.\n");
            switch (turnos){
    case 1:
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
    break;
    case 2:
        printf("________\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
    break;
    case 3:
        printf("________\n");
        printf("|      |\n");
        printf("|      O\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
    break;
    case 4:
        printf("________\n");
        printf("|      |\n");
        printf("|      O\n");
        printf("|     /|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
    break;
    case 5:
        printf("________\n");
        printf("|      |\n");
        printf("|      O\n");
        printf("|     /|%c\n",92);
        printf("|\n");
        printf("|\n");
        printf("|\n");
    break;
    case 6:
        printf("________\n");
        printf("|      |\n");
        printf("|      O\n");
        printf("|     /|%c\n",92);
        printf("|      |\n");
        printf("|     /\n");
        printf("|\n");
    break;
    case 8:
         printf("________\n");
        printf("|      |\n");
        printf("|      O\n");
        printf("|     /|%c\n",92);
        printf("|      |\n");
        printf("|     / %c\n",92);
        printf("|\n");
        printf("HAZ PERDIDO!!!\n");
    break;
        }
    }} while (turnos<oportunidades&&aciertos<n);
    if (aciertos==n)
        printf ("Felicidades, has ganado.");
    else
        printf ("Has perdido.");
    printf ("\nLa palabra secreta es: %s\n\n\n", palabra);
    system ("pause");
    printf("%cQuieres Volver a juagar?\n 1)SI 2)NO\n",168);
    scanf("%d",&opc);
}while(opc!=2);
    return EXIT_SUCCESS;
}
