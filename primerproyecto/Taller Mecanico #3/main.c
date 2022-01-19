#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

int opc,aux=0,pos,j,i;
char pla[15],OP;
int opcion=1;

struct service{
    int ID;
    char fm[50];
    float costo;
};
struct Auto{
    char placa[12];
    char prop[25];
    char tipo[25];
    char marca[25];
    char modelo[25];
    int ns;
    struct service s[50];
};
//inicializacion de un registro
//struct Auto exaple={"JEU4569","Jose","cupe","mazda","x5"};
struct Auto BD[100];
void agregar(int *aux)
{
    int x,y;
    do{
    SetColor(17);
    printf("Placa: ");
    fflush(stdin);
    scanf("%s",&BD[*aux].placa);
    y=buscar(BD[*aux].placa,aux);
    if(y<0)
        printf("El auto ya esta registrado");
    else{
    printf("\nPropietario: ");
    fflush(stdin);
    gets(BD[*aux].prop);
    printf("\nTipo: ");
    fflush(stdin);
    scanf("%s",&BD[*aux].tipo);
    printf("\nMarca: ");
    fflush(stdin);
    gets(BD[*aux].marca);
    printf("\nModelo: ");
    fflush(stdin);
    scanf("%s",&BD[*aux].modelo);
    BD[*aux].ns=0;
    *aux=(*aux)+1;
    SetColor(10);
    printf("\n1)Agregar otro 2)Salir a Menu\n");
    scanf("%d",&x);
    }
    }while(x!=2);
}

void SetColor(int ForgC){

	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
	}
int buscar(char pla[],int aux)
{
    int i,band=0;
    for(i=0;i<aux;i++)
    {
        if(strcmpi(pla,BD[i].placa)==0)
        {
            band=1;
            return i;
        }
    }
    if (band==0)
        return -1;

}

int dibujar(int opcion){
	 system ("cls");
			SetColor(17);
			printf("\n******************************************\n");
			printf("\n %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n******************************************\n\n");
			printf(" 1) Agregar nuevo Auto\n\n",16);
			printf(" 2) Consultar Auto\n\n");
			printf(" 3) Modificar Auto\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Taller Automotriz\n\n");
			printf(" 6) Reporte total de Automotores\n\n");
			printf(" 7) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
}

int menu() {
	while (opc!='7'){
		dibujar(opcion);
		opc=getch();
		switch (opc){

			case '1':
			     {   system("cls");
                     printf("\t\t Agregar Automovil\n");
                     agregar(&aux);
                     sleep(5);
                     printf("Se ha agregado satisfactoriamente...!\n");
                     getch();
                     break; }
			case '2':
			     {   system("cls");
                     printf("\t\t Consultar Automovil\n\n");
                     printf("Ingresa placa: ");
                     fflush(stdin);
                     scanf("%s",&pla);
                     pos=buscar(pla,aux);
                     if(pos<0)
                    {
                        printf("Auto no registrado!!\n");
                    }else{
                        printf("Propietario: %s\n",BD[pos].prop);
                        printf("Tipo: %s\t",BD[pos].tipo);
                        printf("Marca: %s\t",BD[pos].marca);
                        printf("Modelo: %s\n",BD[pos].modelo);
                        printf("\n\nID\tFalla o Mantenimiento\tCosto\n");
                        for(i=0;i<BD[pos].ns;i++)
                        {
                          printf("%d\t",BD[pos].s[i].ID);
                          printf("%s\t",BD[pos].s[i].fm);
                          printf("%.2f\n",BD[pos].s[i].costo);
                        }}
                    getch();
                    break; }
            case '3':
                 {   system("cls");
                    printf("\t\t Modificar Automovil\n");
                    printf("Ingresa placa: ");
                    fflush(stdin);
                    scanf("%s",&pla);
                    pos=buscar(pla,aux);
                    if(pos<0)
                    {
                      printf(" Auto no registrado!!\n");
                    }else{
                         printf("Campos a modificar:\n");
                          printf("a)Propietario\n");
                          printf("b)Tipo\n");
                          printf("c)Marca\n");
                          printf("d)Modelo\n");
                          printf("OPC:");
                          fflush(stdin);
                          scanf("%c",&OP);
                        printf("Ingresa nuevo valor: ");
                        fflush(stdin);
                     switch(OP)
                     {
            case 'a':
                gets(BD[pos].prop);
                break;
            case 'b':
                scanf("%s",&BD[pos].tipo);
                break;
            case 'c':
                gets(BD[pos].marca);
                break;
            case 'd':
                scanf("%s",&BD[pos].modelo);
                break;
            default:
                printf("No existe la OPC\n");
            }
        }
        sleep(10);
        printf("Registro Modificado\n");break; }
			case '4':
			     {  system("cls");
        printf("\t\t Eliminar Automovil\n");
        printf("Ingresa placa: ");
        fflush(stdin);
        scanf("%s",&pla);
        pos=buscar(pla,aux);
        if(pos<0)
        {
            printf("Auto no registrado!!\n");
        }else{
            strcpy(BD[pos].placa,"*");
            sleep(100);
            printf("El registro a sido eliminado\n");
        }
        getch();break; }
			case '5':
			     {   system("cls");
        printf("\t\t Taller Automotriz\n");
        printf("Ingresa placa: ");
        fflush(stdin);
        scanf("%s",&pla);
        pos=buscar(pla,aux);
        if(pos<0)
        {
            printf("Auto no registrado!!\n");
        }else{
            BD[pos].s[BD[pos].ns].ID=BD[pos].ns+1;
            printf("ID:%d\n",BD[pos].s[BD[pos].ns].ID);
            printf("Falla o Mentenimiento:\n");
            fflush(stdin);
            gets(BD[pos].s[BD[pos].ns].fm);
            printf("\nCosto: ");
            scanf("%f",&BD[pos].s[BD[pos].ns].costo);
            BD[pos].ns=BD[pos].ns+1;
        }
        getch();break; }
			case '6':
			     {  SetColor(14);
	                system ("cls");
	                printf(" \n\ %c R E P O R T E  D E  A U T O M O V I L E S %c",4,4);
	                 SetColor(11);
	                if(strcmpi(BD[pos].placa,"*")!=0){
                    for (i=0; i<aux;i++){
			        printf("\n\t__________________________________________________________________\n\n");
			        printf("\n\tNOMBRE\t\tPLACA\t\tTIPO DE AUTO\t\tMARCA\t\tMODELO\n",64);
			        printf("\n\t\%s\t\%s\t\%s\t\%s\t\%s\n\n" , BD[i].prop, BD[i].placa ,BD[i].tipo, BD[i].marca, BD[i].modelo);
		            for(j=0;j<aux;j++)
                    {
                        printf("\t? %c R E P O R T E S  D E  T A L L E R %c\n",4,4);
                        printf("%d\t",BD[pos].s[i].ID);
                        printf("%s\t",BD[pos].s[i].fm);
                        printf("%.2f\n",BD[pos].s[i].costo);

                    }
		                             }
	            }getch(); break; }
            case '7':
                 {   printf("\n\t\t Gracias por utilizar el sistama\n");
                     break; }
                 }
        }
}

int main()
{
    system("color 0F");
	menu();
    return 0;
}
