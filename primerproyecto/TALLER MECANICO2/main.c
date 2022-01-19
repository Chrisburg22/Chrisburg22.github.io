//****************** LIBRERIAS *******************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

//************** VARIABLES GLOBALES **************
int placa[25];
int i,opc,n=0,continuar='Y',pos,opcion=1,clientes_registrados=0;

//************* FUNCIONES PROTOTIPO **************
int CargarDatos ();
void ImprimirLista();
int menu ();
void Busqueda();
void SetColor(int ForgC);
int error();
int modificar();

//************* COLOR DE TEXTO **************
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

//************* ESTRUCTURA DE DATOS **************
struct serv{
    int id;
    char fm[100];
    float km;
    float costo;
};

struct cliente {
	char nombre [100];
	int pla[25];
	char modelo[20];
	char marca[20];
	char tipauto[20];
	int ns;
	int eliminar;
	int ano;
    struct serv A[100];
} cliente[50]={'\0'};

//*************** FUNCION BUSCAR ******************
void Busqueda() {
	int pos1,j;
	system ("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c BUSQUEDA DE CLIENTE %c \n",4,4);
	printf("\n\t\t ************************************\n");SetColor(11);
	printf ("\nINGRESE LA PLACA DEL CLIENTE A BUSCAR: "); scanf("%d",&placa);

	for (i=0; i<n;i++){
		if(placa == cliente[i].pla){
			pos1=i;
			i=n;
		}
		else pos1=-1;
	}
	for (j=0; j<n;j++){
		if (pos1>=0 && cliente[j].eliminar == 1){
			printf(" \n\t EL CLIENTE HA SIDO ELIMINADO");
			j=n;
		}
		else if (pos1 >=0 && cliente[j].eliminar == 0){
			printf("\n\t\t NOMBRE: %s", cliente [pos1].nombre);
			printf("\n\t\t PLACA: %d", cliente [pos1].pla);
			printf("\n\t\t TIPO DE AUTO: %s", cliente [pos1].tipauto);
			printf("\n\t\t MARCA: %s", cliente [pos1].marca);
			printf("\n\t\t MODELO: %s", cliente [pos1].modelo);
			printf("\n\t\t A%cO: %d",64, cliente [pos1].ano);
			j=n;
		}
		else{
			printf(" \n\t EL CLIENTE NO HA SIDO REGISTRADO");
			j=n;
		}
	}
	getch();
}

//******************* FUNCION ELIMINAR ******************

void eliminar() {
	system ("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c ELIMINAR REGISTRO %c \n",4,4);
	printf("\n\t\t ************************************\n");
	SetColor(11);

	if(clientes_registrados==0) printf("\n\n\n\n\n\n\n\n\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	else{
		printf ("\nIngrese La placa Del Cliente A Eliminar: ");
		scanf("%d",&placa);
	for (i=0; i<n;i++){
		if(placa == cliente[i].pla && cliente[i].eliminar==0){
			pos=i;i=n;
		}
		else pos=-1;
	}
	if (pos!=-1){
		printf("\n\t\t NOMBRE: %s", cliente [pos].nombre);
		printf("\n\t\t PLACA: %d", cliente [pos].pla);
		printf("\n\t\t TIPO DE AUTO: %s", cliente [pos].tipauto);
		printf("\n\t\t MARCA: %s", cliente [pos].marca);
		printf("\n\t\t MODELO: %s", cliente [pos].modelo);
		printf("\n\t\t A%cO: %s",64, cliente [pos].ano);
		printf("\n\n\n\t\t Desea Eliminar Registro (Y/N): ");
		scanf("%s",&opc);
		if (toupper(opc)=='Y'){
			cliente[pos].eliminar=1;
			printf("\n\n\t\tRegistro Eliminado...");
			clientes_registrados--;
		}
		else
		printf("\n\n\t\tNigun Registro Eliminado...");
	}
	else
	printf("\n\n\t\tRegistro No existe");
	}
	getch();
}

//******************* FUNCION DIBUJAR ******************
int dibujar(int opcion){
	 system ("cls");
			SetColor(14);
			printf("\n******************************************\n");
			printf("\n %c REGISTRO DE CLIENTES %c \n",4,4);
			printf("\n******************************************\n\n");
			printf(" 1) Agregar nuevo Auto\n\n",16);
			printf(" 2) Consultar Auto\n\n");
			printf(" 3) Modificar Auto\n\n");
			printf(" 4) Eliminar Cliente\n\n");
			printf(" 5) Taller Automotriz\n\n");
			printf(" 6) Reporte total de Automotores\n\n");
			printf(" 6) Salir del Registro\n\n\n");
			SetColor(11);
			printf(" Seleccione Una Opcion: ");
}

//******************* FUNCION MODIFICAR ******************
int modificar (){

	bool cliente_no_registrado=false;
	int a;
	system("cls");
	SetColor(14);
	printf("\n\t\t ************************************\n");
	printf("\n\t\t %c MODIFICAR LOS DATOS DEL AUTO %c \n",4,4);
	printf("\n\t\t ************************************\n");
	SetColor(11);

	if(clientes_registrados==0)
		printf("\n\n\n\n\n\n\n\n\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	else{
		printf ("\nINGRESE LA PLCACA DEL AUTO A MODIFICAR: ");
		scanf("%d",&placa);
		for (i=0; i<n;i++){
			if(placa == cliente[i].pla){
				system("cls");
				SetColor(14);
				printf("\n\t\t ************************************\n");
				printf("\n\t\t %c MODIFICAR LOS DATOS DEL CLIENTE %c\n",4,4);
				printf("\n\t\t ************************************\n");
				SetColor(11);
				printf("\n\t\t NOMBRE: %s", cliente [i].nombre);
				printf("\n\t\t PLACA: %d", cliente [i].pla);
				printf("\n\t\t TIPO DE AUTO: %s", cliente [i].tipauto);
				printf("\n\t\t MARCA: %s", cliente [i].marca);
				printf("\n\t\t MODELO: %s", cliente [i].modelo);
				printf("\n\t\t A%cO: %s",64,cliente [i].ano);
				printf("\n\n\tDATOS A MODIFICAR\n");
				printf("\n\t\t NOMBRE: ");
				scanf("%s",&cliente[400].nombre);
				printf("\n\t\t PLACA: ");
				scanf("%d",&cliente[400].pla);
				//---------------------------REVISAR QUE NO EXISTA--------------------------
				for (a=0; a<n-1; a++){
					if(cliente[400].pla == cliente[a].pla){
						error();
						a=n;
						return 0;
					}
				}
				//---------------------------------------------------------------------------
				continuar:
				printf("\n\t\t TIPO DE AUTO: ");
				scanf("%s",&cliente[400].tipauto);
				printf("\n\t\t MARCA: ");
				scanf("%s",&cliente[400].marca );
                printf("\n\t\t MODELO: ");
                scanf("%s",&cliente[400].modelo);
                printf("\n\t\t A%cO: ");
                scanf("%d",&cliente[400].ano);
                strcpy(cliente[i].nombre, cliente[400].nombre);
				strcpy(cliente[i].pla, cliente[400].pla);
				strcpy(cliente[i].tipauto, cliente[400].tipauto);
				strcpy(cliente[i].marca, cliente[400].marca);
				strcpy(cliente[i].modelo, cliente[400].modelo);
				cliente[i].ano = cliente[400].ano;
				printf("\n\t\tDATOS MODIFICADOS EXITOSAMENTE!\n");
				cliente[i].eliminar=0;
				cliente_no_registrado=false;
				i=n;
			}
			else cliente_no_registrado=true;
		}
	}
	if(cliente_no_registrado == true) printf("\n\t\t\tCLIENTE NO REGISTRADO\n");
	getch();
}


//******************* FUNCION MENU ******************

int menu() {
	while (opc!='6'){
		dibujar(opcion);
		opc=getch();
		switch (opc){

			case '1':
			     { opcion=1; CargarDatos(); break; }
			case '2':
			     { opcion=2; Busqueda(); break; }
            case '3':
                 { opcion=3; modificar(); break; }
			case '4':
			     { opcion=4; eliminar(); break; }
			case '5':
			     { opcion=3;  }
			case '6':
			     { opcion=6; ImprimirLista(); break; }
            case '7':
                 { opcion=7;  return 0; break; }
			default : break;
                    }
            }
}

//******************* FUNCION IMPRIMIR ******************
void ImprimirLista(){

	SetColor(14);
	system ("cls");
	printf(" \n\t\t %c L i s t a d o d e C l i e n t e s %c",4,4);
	SetColor(11);
	if(clientes_registrados==0) printf("\n\n\n\n\n\n\n\n\n\n\t\t\tNO SE HA REGISTRADO NINGUN CLIENTE");
	for (i=0; i<n;i++){
		if (cliente[i].eliminar==0 && n>0){
			printf("\n\t__________________________________________________________________\n\n");
			printf("\n\tNOMBRE\t\tPLACA\t\tTIPO DE AUTO\t\tMARCA\t\tMODELO\t\tA%cO\n\n",64);
			printf("\n %-20s %-13d %-15s %-15s %-15s %-15d \n\n" , cliente[i].nombre, cliente[i].pla,cliente[i].tipauto, cliente[i].marca, cliente[i].modelo, cliente[i].ano);
		}
	}
	getch();
}

//******************* FUNCION ERROR ******************
int error(){

	system("cls");
	SetColor(11);
	int j;
	char reg;
	for (j=0; j<n; j++){
		if(cliente[j].eliminar == 1){
			printf("\n\n ESTE USUARIO YA HABIA SIDO REGISTRADO, DESEA VOLVER A REGISTRARLO (Y/N): \n\n");
			reg=getch();
			reg=toupper(reg);
			if(reg=='Y'){
				printf("\n\n USUARIO REGISTRADO DE NUEVO!\n\n");
				cliente[j].eliminar=0;
				clientes_registrados++;
				j=n;
			}
		}
		else{
			printf("\n\n\t\tUSUARIO REGISTRADO\n\n");
			j=n;
		}
	}
	system("PAUSE");
	menu();
}

//******************* FUNCION REGISTRAR ******************
int CargarDatos() {
	int a;
	do {
		system ("cls");
		SetColor(14);
		printf("\n\t\t ************************************\n");
		printf("\n\t\t %c INTRODUZCA LOS DATOS DEL CLIENTE %C \n",4,4);
		printf("\n\t\t ************************************\n");
		SetColor(11);
		printf("\n\tNOMBRE: ");
        scanf("%s",&cliente[i].nombre);
		printf("\n\tPLACA: ");
		scanf("%d",&cliente[i].pla);
		//---------------------------REVISAR QUE NO EXISTA--------------------------
		for (a=0; a<n; a++){
			if(cliente[i].pla == cliente[a].pla){
				error();
				a=n;
				return 0;
			}
		}
		//---------------------------------------------------------------------------
		printf("\n\tTIPO DE AUTO: ");
		scanf("%s",&cliente[i].tipauto);
		printf("\n\tMARCA: ");
		scanf("%s",&cliente[i].marca );
		printf("\n\tMODELO: ");
		scanf("%s",&cliente[i].modelo);
		printf("\n\tA%cO: ",64);
		scanf("%d",&cliente[i].ano);
		cliente[i].eliminar=0;
		n++;
		i++;
		clientes_registrados++;
		printf("\n\n\t\tDesea continuar(Y/N): ");
		continuar=getch();
	}while(toupper(continuar)!='N');
}

//------------------------- FUNCION PRINCIPAL --------------------------------
int main () {
	system("color 2F");
	menu();

	return 0;
}
