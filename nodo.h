#ifndef NODO_H
#define NODO_H

typedef struct nodo{
    char car;
    int val;
    struct nodo *a;
    struct nodo *d;
    struct nodo *w;
    struct nodo *s;
}nodo;



nodo* crear_nodo(){
	nodo *p = (nodo*)malloc(sizeof(nodo));
    p->car = 'O';
    p->val = 00;
    p->w = NULL;
    p->s = NULL;
    p->a = NULL;
    p->d = NULL;
    return p;
	
}

nodo** matriz(int n, int m){
	nodo **l=(nodo **)malloc(sizeof(nodo)*n);
	for (int i = 0; i < n; ++i)
	{
		l[i]=(nodo *)malloc(sizeof(nodo)*m);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			l[i][j]=(*crear_nodo());
		}
	}
	return l;
}

void crear_grilla(nodo** l, int n, int m){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			//condiciones grilla central
			if(j != m-1){
				(&l[i][j])->s = (&l[i][j+1]);								
			}
			if(i != n-1){
				(&l[i][j])->d = (&l[i+1][j]);	
			}
			if(i != 0){
				(&l[i][j])->a = (&l[i-1][j]);
			}
			if(j != 0){
				(&l[i][j])->w = (&l[i][j-1]);
			}


			//condiciones extremo grilla
			if(i == 0){
				(&l[i][j])->a = (&l[n-1][j]);
			}
			if(j == 0){
				(&l[i][j])->w = (&l[i][m-1]);
			}
			if(i == n-1){
				(&l[i][j])->d = (&l[0][j]);
			}
			if(j == m-1){
				(&l[i][j])->s = (&l[i][0]);
			}
		}
	}
}

void imprimir(nodo **l,int n, int m){
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%c", (&l[i][j])->car);
			if(((&l[i][j])->d)->val == 11 || ((&l[i][j])->d)->val == 01){
				printf(" ");
			}
			else if((i != n-1 && (&l[i][j])->val == 00) ||(i != n-1 && (&l[i][j])->val == 10)){
				printf("-");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
		for(int i=  0; i < n; i++){
			if(((&l[i][j])->s)->val == 11 || ((&l[i][j])->s)->val == 10){
				printf(" ");
			}
			else if((j != m-1 && (&l[i][j])->val == 01) || (j != m-1 &&(&l[i][j])->val == 00)){
				printf("|");
			}else
				printf(" ");
			
			if(i != n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}

void insertar_personaje(nodo **l,int n,int m){

	(&l[0][0])->car='#';
	(&l[0][0])->d->car='x';
	
}

int posi_gato(nodo **l, int n, int m){
	int a = 0;
	for(int j = 0; j < m; ++j){
		for(int i = 0; i< n; ++i){
			if((&l[i][j])->car=='#'){
				a = i;
			}
		}
	}
	return a;
}

int posj_gato(nodo **l, int n, int m){
	int a = 0;
	for(int j = 0; j < m; ++j){
		for(int i = 0; i< n; ++i){
			if((&l[i][j])->car=='#'){
				a = j;
			}
		}
	}
	return a;
}

int posi_x(nodo **l, int n, int m){
	int a = 0;
	for(int j = 0; j < m; ++j){
		for(int i = 0; i< n; ++i){
			if((&l[i][j])->car=='x'){
				a = i;
			}
		}
	}
	return a;

}

int posj_x(nodo **l, int n, int m){
	int a = 0;
	for(int j = 0; j < m; ++j){
		for(int i = 0; i< n; ++i){
			if((&l[i][j])->car=='x'){
				a = j;
			}
		}
	}
	return a;

}

void mover(nodo **l,char k,int n,int m){
	if(k == 'a'){ //listo
		if((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a->car == 'x'){
			 if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 10 || (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
			 	int a = posi_gato(*(&l),n,m);
			 	int b = posj_gato(*(&l),n,m);
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = 'O';
			 	((&l[a][b])->a)->car = '#';
				while((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 11 || (&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 01){
					int c = posi_gato(*(&l),n,m);
			 		int d = posj_gato(*(&l),n,m);
			 		(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = ' ';
			 		((&l[c][d])->a)->car = '#';
			 		
			 	}
			 	((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a)->car = 'x';
			 	
			}
			else{
				(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->car = 'O';
				((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)]))->car = '#';
				(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a->car = 'x';

			}
		}
	else{
		if( (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
    			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = ' ';
    			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a->car = 'x';
		}
		else{
		(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = 'O';
		(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a->car = 'x';
		}
	}
}

	if(k == 's'){ //listo
		if((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s->car == 'x'){
			if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 01 || (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
				int a = posi_gato(*(&l),n,m);
			 	int b = posj_gato(*(&l),n,m);
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = 'O';
			 	((&l[a][b])->s)->car = '#';
			 	while((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 11 || (&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 10){
			 		int c = posi_gato(*(&l),n,m);
			 		int d = posj_gato(*(&l),n,m);
			 		(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = ' ';
			 		((&l[c][d])->s)->car = '#';
			 	}
			 	((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s)->car = 'x';
			 }
			 else{
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->car = 'O';
				((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)]))->car = '#';
				(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s->car = 'x';

			 }
		}
		else{
			if( (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
    			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = ' ';
    			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s->car = 'x';
			}
			else{
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = 'O';
			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s->car = 'x';
			}
		}
	}
		

	if(k == 'd'){ //listo
		if((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d->car == 'x'){
			if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 10 || (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
				int a = posi_gato(*(&l),n,m);
			 	int b = posj_gato(*(&l),n,m);
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = 'O';
			 	((&l[a][b])->d)->car = '#';
			 	while((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 11 || (&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 01){
			 		int c = posi_gato(*(&l),n,m);
			 		int d = posj_gato(*(&l),n,m);
			 		(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = ' ';
			 		((&l[c][d])->d)->car = '#';
			 	}
			 	((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d)->car = 'x';
			}
			else{
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->car = 'O';
				((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)]))->car = '#';
				(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d->car = 'x';
			}
		}
		else{
			if( (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
    			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = ' ';
    			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d->car = 'x';
			}
			else{
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = 'O';
			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d->car = 'x';
			}
		}

	}

	if(k == 'w'){ //listo
		if((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w->car == 'x'){
			if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 01 || (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
				int a = posi_gato(*(&l),n,m);
			 	int b = posj_gato(*(&l),n,m);
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = 'O';
			 	((&l[a][b])->w)->car = '#';
			 	while((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 11 || (&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->val == 10){
			 		int c = posi_gato(*(&l),n,m);
			 		int d = posj_gato(*(&l),n,m);
			 		(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])-> car = ' ';
			 		((&l[c][d])->w)->car = '#';
			 	}

			 	((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w)->car = 'x';
			}
			else{
			 	(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->car = 'O';
				((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)]))->car = '#';
				(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w->car = 'x';
			}
			
    	}
    	else{
    		if( (&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 11){
    			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = ' ';
    			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w->car = 'x';
			}
			else{
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->car = 'O';
			(&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w->car = 'x';
		   	}
		}

    }
}


void eliminar_tierra(nodo **l, int n, int m){
	(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 11;


}

void construir_tierra(nodo **l, int n,int m){

	if(((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->a)->car == 'x' || ((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->d)->car == 'x'){
		if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 01){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 00;	
		}
		
		else if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 00){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 00;
		}
		else if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 11){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 10;
		}
			
	}
	else if(((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->w)->car == 'x' || ((&l[posi_gato(*(&l),n,m)][posj_gato(*(&l),n,m)])->s)->car == 'x'){
		if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 10){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 00;
		}	
		
		else if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val == 00){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 00;
		}
		else if((&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 11){
			(&l[posi_x(*(&l),n,m)][posj_x(*(&l),n,m)])->val = 01;
		}
	}
	

} 
	

#endif