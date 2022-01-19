#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float bidimen[100][100]={0};
    int x,y,fila,columna,frec1=0,frec2=0,frec3=0,frec4=0,frec5=0,frec6=0,frec7=0,frec8=0,frec9=0;
    srand(time(NULL));

    printf("Numero de Filas\n");
    scanf("%d",&fila);
    printf("Numero de Columnas\n");
    scanf("%d",&columna);

    for(x=0;x<fila;x++){
      for (y=0;y<columna;y++){
        bidimen[x][y]=rand()%9+1;
      }}
       for(x=0;x<fila;x++){
      for (y=0;y<columna;y++){
        printf ("%.1f  ",bidimen[x][y]);
      }
      printf("\n");
      }

      for(x=0;x<fila;x++){
      for (y=0;y<columna;y++){
        if(bidimen[x][y]==1)
            frec1=frec1+1;
        else
            if(bidimen[x][y]==2)
               frec2=frec2+1;
            else
                if(bidimen[x][y]==3)
                  frec3=frec3+1;
                else
                    if(bidimen[x][y]==4)
                      frec4=frec4+1;
                    else
                        if(bidimen[x][y]==5)
                           frec5=frec5+1;
                        else
                           if(bidimen[x][y]==6)
                              frec6=frec6+1;
                           else
                              if(bidimen[x][y]==7)
                                  frec7=frec7+1;
                              else
                                 if(bidimen[x][y]==8)
                                    frec8=frec8+1;
                                  else
                                     if(bidimen[x][y]==9)
                                       frec9=frec9+1;
      }}
      if(frec1>frec2 && frec1>frec3 && frec1>frec4 && frec1>frec5 && frec1>frec6 && frec1>frec7 && frec1>frec8 && frec1>frec9){
            printf("El numero con mayor frecuencia es 1\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
                bidimen[x][y]=bidimen[x][y]/1;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}}

      if(frec2>frec1&&frec2>frec3&&frec2>frec4&&frec2>frec5&&frec2>frec6&&frec2>frec7&&frec2>frec8&&frec2>frec9){
            printf("El numero con mayor frecuencia es 2\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/2;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec3>frec1&&frec3>frec2&&frec3>frec4&&frec3>frec5&&frec3>frec6&&frec3>frec7&&frec3>frec8&&frec3>frec9){
        printf("El numero con mayor frecuencia es 3\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/3;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec4>frec1&&frec4>frec2&&frec4>frec3&&frec4>frec5&&frec4>frec6&&frec4>frec7&&frec4>frec8&&frec4>frec9){
            printf("El numero con mayor frecuencia es 4\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/4;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec5>frec1&&frec5>frec2&&frec5>frec3&&frec5>frec4&&frec5>frec6&&frec5>frec7&&frec5>frec8&&frec5>frec9){
            printf("El numero con mayor frecuencia es 5\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/5;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec6>frec1&&frec6>frec2&&frec6>frec3&&frec6>frec4&&frec6>frec5&&frec6>frec7&&frec6>frec8&&frec6>frec9){
            printf("El numero con mayor frecuencia es 6\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/6;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec7>frec1&&frec7>frec2&&frec7>frec3&&frec7>frec4&&frec7>frec5&&frec7>frec6&&frec7>frec8&&frec7>frec9){
            printf("El numero con mayor frecuencia es 7\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/7;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec8>frec1&&frec8>frec2&&frec8>frec3&&frec8>frec4&&frec8>frec5&&frec8>frec6&&frec8>frec7&&frec8>frec9){
        printf("El numero con mayor frecuencia es 8\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/8;

                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }
      if(frec9>frec1&&frec9>frec2&&frec9>frec3&&frec9>frec4&&frec9>frec5&&frec9>frec6&&frec9>frec7&&frec9>frec8){
          printf("El numero con mayor frecuencia es 9\n");
         for(x=0;x<fila;x++){
          for (y=0;y<columna;y++){
            bidimen[x][y]=bidimen[x][y]/9;
                printf("%.2f  ",bidimen[x][y]);
      }printf("\n");}
      }


    return 0;
}
