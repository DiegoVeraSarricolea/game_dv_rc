#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <time.h>
#include "nodo.h"



// coliumna- fila.
int main(int argc, char **argv){
    if(argc!=3 || atoi(argv[1]) < 2 || atoi(argv[2]) < 2){
        fprintf(stderr, "ejecutar como ./prog n m con numeros mayores o iguales a 2\n");
        exit(EXIT_SUCCESS);
    }
	char k;
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	nodo **g=matriz(n,m);
	crear_grilla(g,n,m);
	int salida=1;
	//(g[0][0].a)->car='$';
	insertar_personaje(g,n,m);
	
	while(salida != 0){
		imprimir(g,n,m);
		printf("Movimiento: 'wasd', Eliminar: 'q', Construir: 'e', Salir: 'p' \n");
        printf("\nEliga Opción: ");
		scanf("%c",&k);
        printf("\n");
		//fflush(stdin);
		//printf("\n");
		//system("clear");
		
    	if(k=='a' || k=='s' || k=='d' || k=='w'){
    		//printf("moviendo...\n");
    		mover(g,k,n,m);
    		imprimir(g,n,m);
    	}

    	if(k=='q'){
    		//printf("eliminando...\n");
    		eliminar_tierra(g,n,m);
    		imprimir(g,n,m);
    	}
    	if(k=='e'){
    		//printf("construyendo...\n");
    		construir_tierra(g,n,m);
    		imprimir(g,n,m);
    	}
    	if(k=='p'){
			salida = 0;
    	}
    	//printf("trolo\n");
    	system("clear");
    	fflush(stdin);
    	//fflush(stdin);
	}

	return EXIT_SUCCESS;
}