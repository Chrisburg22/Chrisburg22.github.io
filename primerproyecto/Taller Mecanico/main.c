#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct serv
{
    int ID;
    char fm[100];
    float km;
    float costo;
};

struct Auto
{
    char placa[15],propietario[25];
    char tipauto[25],marca[25],modelo[25];
    int ano,Ns;
    struct serv A[100];
} BD[50];

void agregar(int *aux)
{
    system("color 0A");
    printf("Placa: ");
    scanf("%s",&BD[*aux].placa);

    printf("\nPropietario: ");
    scanf("%s",&BD[*aux].propietario);

    printf("\nTipo de auto: ");
    scanf("%s",&BD[*aux].tipauto);

    printf("\nMarca: ");
    scanf("%s",&BD[*aux].marca);

    printf("\nModelo: ");
    scanf("%s",&BD[*aux].modelo);

    printf("\nA%co: ",164);
    scanf("%d",&BD[*aux].ano);
    BD[*aux].Ns=0;
    *aux=*aux+1;
};

int buscar(char placa[],int aux)
{
    int i,band=0;

    for(i=0;i<aux;i++)
    {
        if(BD[i].placa==placa)
        {
            band=1;
            return 'i';
        }
    }
    if(band==0)
    return -1;
    };

int main()
{
    int aux=0,opc,pos;
    char placa[50],op;

    do{
        system("cls");
        system("color 0D");
        printf("1)Agregar\n");
        printf("2)Consultar\n");
        printf("3)Modificar\n");
        printf("4)Eliminar\n");
        printf("5)Taller\n");
        printf("6)Reporte\n");
        printf("7)Salir\n");
        scanf("%d",&opc);

        switch(opc)
        {
            case 1:
                printf("Agregar Automovil\n");
                agregar(&aux);
                system("pause");
                aux=aux+1;
                break;
            case 2:
                printf("Consultar\n");

                printf("Ingresa la placa\n");
                scanf("%s",&placa);
                pos=buscar(placa,aux);
                if(pos<0)
                    printf("No existe el regristro\n");
                else
                 {
                     printf("Propietario %s\n",BD[pos].propietario);
                     printf("Tipo %s \n",BD[pos].tipauto);
                     printf("Marca %s \n",BD[pos].marca);
                     printf("Modelo %s \n",BD[pos].modelo);
                     printf("A%co %d \n",164,BD[pos].ano);
                 }system("Pause");
                 break;
    }
    printf("Pulsa 0 para salir\n");
    scanf("%d",&opc);
    }while(opc!=3);
    return 0;
}
