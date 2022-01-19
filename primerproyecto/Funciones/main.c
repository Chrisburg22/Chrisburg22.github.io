#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void paresimpares()
{
    int x,cant,num,pares[20]={0},impares[20]={0},w=0,y=0;
    printf("Ingrese la cantidad: ");
    scanf("%d",&cant);

    for(x=0;x<cant;x++)
    {
        printf("Ingresa el %d ° numero\n",x+1);
        scanf("%d",&num);
        if(num%2==0){
            pares[y]=num;
            y++;}
        else
        {
            impares[w]=num;
            w++;
        }
    }
    printf("Lista de Pares\n");
    w=0;
    y=0;
    while(pares[y]!=0){
        printf("%d ",pares[y]);
        y++;
    }
    printf("\n");
    printf("Lista de Impares\n");
    while(impares[w]!=0){
        printf("%d ",impares[w]);
        w++;
    }
    printf("\n\n");
}

void palindromo(char frase[])
{
    int i,j,contador=0;
    for(i=0,j=strlen(frase)-1;frase[i]!='\0';i++,j--)
    {
        while(frase[j]==" "){
            j--;
        }
        while(frase[i]==" "){
            i++;
        }
        if(frase[i]!=frase[j]){
            printf("No es palindromo\n");
            break;}
        else{
            contador++;
        }
    }
    if(contador>strlen(frase)-1){
        printf("Es un palindromo\n");
    }
    printf("\n\n");
}

char comparar(char cad1[],char cad2[])
{
    int l1=0,l2=0,i,mas=0,menos=0;
    while(cad1[l1]!='\0'){
        l1++;}
    while(cad2[l2]!='\0'){
        l2++;}
    if(l1!=l2){
        for(i=0;i<l1;i++){
            if(cad1[i]>cad2[i])
                mas=mas+1;
            else
                if(cad1[i]<cad2[i])
                menos=menos+1;
        }
    }
     else{
           for(i=0;i<l1;i++){
                if(cad1[i]!=cad2[i]){
                    if(cad1[i]>cad2[i])
                        mas=mas+1;
                    if(cad1[i]<cad2[i])
                        menos=menos+1;}
         }
    }
    if(mas>menos)
        printf("+ \n");
    else
        printf("- \n");
   printf("\n");
}

void pot(int *num,int *x)
{
    int aux,i;
    aux=*num;

    for(i=0;i<*x-1;i++){
        *num=(*num)*aux;
    }
    printf("%d",*num);
    printf("\n\n");
}



int main()
{
    int opc,x,n,p;
    char cad[50],p1[20],p2[20];
    do{
    printf("Ingresa el procedimineto que quieras utilizar\n");
    printf("1)Organisador de PARES y IMPARES\n");
    printf("2)Frases Palindromo\n");
    printf("3)Comparar Palabras\n");
    printf("4)Potencia de Numeros\n");
    printf("5)Salir\n");
    scanf("%d",&opc);

    switch(opc)
    {
   case 1:
    paresimpares();
    break;
   case 2:
    printf("Ingresa una palabra\n");
    scanf("%s",&cad);
    palindromo(cad);
    break;
   case 3:
    printf("Ingresa dos palabras\n");
    scanf("%s \n %s",&p1,&p2);
    x=comparar(p1,p2);
    printf("%d",x);
    break;
   case 4:
    printf("Ingresa el numero y su potencia: \n");
    scanf("%d %d",&n,&p);
    pot(&n,&p);
    break;
    }
}while(opc!=5);
    return 0;
}
