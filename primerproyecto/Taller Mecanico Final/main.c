#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

int opc,aux=0,pos,j,i,po,r,y=0;
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
    int x;
    do{
    SetColor(17);
    printf("Placa: ");
    fflush(stdin);
    scanf("%s",&BD[*aux].placa);
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
    SetColor(11);
    printf("\n1)Agregar otro 2)Salir a Menu\n");
    scanf("%d",&x);
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
			     {   do{
                     system("cls");
                     SetColor(17);
                     printf("\t\t Consultar Automovil\n\n");
                     printf("Ingresa placa: ");
                     fflush(stdin);
                     scanf("%s",&pla);
                     pos=buscar(pla,aux);
                     if(pos<0)
                    {
                        printf("Auto no registrado!!\n");
                        break;
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
                        SetColor(11);
                        printf("\n1)Consultar Nuevamente  2)Volver al menu\n");
                        scanf("%d",&po);
			     }while(po!=2);
                    getch();
                    break; }
            case '3':
                 {  do{
                    system("cls");
                    SetColor(17);
                    printf("\t\t Modificar Automovil\n");
                    printf("Ingresa placa: ");
                    fflush(stdin);
                    scanf("%s",&pla);
                    pos=buscar(pla,aux);
                    if(pos<0)
                    {
                      printf(" Auto no registrado!!\n");
                      break;
                    }else{
                        printf("\n\tNOMBRE\t\tPLACA\t\tTIPO DE AUTO\t\tMARCA\t\tMODELO\n",64);
			        printf("\n\t\%s\t\t%s\t\t%s\t\t%s\t\t%s\n\n" , BD[pos].prop, BD[pos].placa ,BD[pos].tipo, BD[pos].marca, BD[pos].modelo);
            do{
                          SetColor(17);
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
        SetColor(11);
        printf("\n1)Modificar otro campo  2)Salir\n");
        scanf("%d",&r);
        }while(r!=2);
        sleep(10);
        printf("Registro Modificado\n");
        SetColor(11);
        printf("\n1)Modificar Otro  2)Volver al menu\n");
        scanf("%d",&po);}
        }while(po!=2);
        getch();break; }
        case '4':
			     { do{
                   system("cls");
                   SetColor(17);
                    printf("\t\t Eliminar Automovil\n");
        printf("Ingresa placa: ");
        fflush(stdin);
        scanf("%s",&pla);
        pos=buscar(pla,aux);
        if(pos<0)
        {
            printf("Auto no registrado!!\n");
            break;
        }else{
            strcpy(BD[pos].placa,"*");
            sleep(10);
            printf("El registro a sido eliminado\n");
        }
        SetColor(11);
        printf("\n1)Eliminar Nuevamente  2)Volver al menu\n");
        scanf("%d",&po);
        }while(po!=2);
        getch();break; }
        case '5':
        {   do{
            system("cls");
        SetColor(17);
        printf("\t\t Taller Automotriz\n");
        do{
        printf("Ingresa placa: ");
        fflush(stdin);
        scanf("%s",&pla);
        pos=buscar(pla,aux);
        if(pos<0)
        {
            printf("Auto no registrado!!\n");
            break;
        }else{

            BD[pos].s[BD[pos].ns].ID=BD[pos].ns+1;
            printf("ID:%d\n",BD[pos].s[BD[pos].ns].ID);
            printf("Falla o Mentenimiento:\n");
            fflush(stdin);
            gets(BD[pos].s[BD[pos].ns].fm);
            printf("\nCosto: ");
            scanf("%f",&BD[pos].s[BD[pos].ns].costo);
            SetColor(11);
            BD[pos].ns=BD[pos].ns+1;
            printf("\n1)Agregar nuevo  2)Volver al menu de Taller\n");
            scanf("%d",&po);
            }
            }while(po!=2);
        printf("\n1)Agregar otro  2)Volver al menu\n");
        scanf("%d",&r);
        }while(r!=2);
        getch();break; }
			case '6':
			     {  SetColor(17);
	                system ("cls");
	                printf(" \n\t\t\t %c R E P O R T E  D E  A U T O M O V I L E S %c",4,4);
	                for (pos=0;pos<aux;pos++){
                        if(strcmpi(BD[pos].placa,"*")!=0){
			        printf("\n\t_________________________________________________________________________________________________\n\n");
			        printf("\n\tNOMBRE\t\tPLACA\t\tTIPO DE AUTO\t\tMARCA\t\tMODELO\n",64);
			        printf("\n\t\%s\t\t%s\t\t%s\t\t%s\t\t%s\n\n" , BD[pos].prop, BD[pos].placa ,BD[pos].tipo, BD[pos].marca, BD[pos].modelo);
                    printf("\t %c R E P O R T E S  D E  T A L L E R %c\n",4,4);
                    printf("\n\tID\t\tFalla/Mantenimiento\t\tCosto\t\n");
                    for(i=0;i<BD[pos].ns;i++)
                        printf("\t%d\t\t%s\t\t\t%.2f\n",BD[pos].s[i].ID,BD[pos].s[i].fm,BD[pos].s[i].costo);
                    }
	            }getch(); break; }
            case '7':
                SetColor(10);
                 {   printf("\n\t\t Gracias por utilizar el sistema\n");
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

