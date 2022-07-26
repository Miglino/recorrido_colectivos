#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void cargarVectores(int*, char*, int, char, int);
void consultarInformacion(int*, char*, int);
int opcionesMenu();

int main () {
    
	int a;
	int opcionSeleccionada;
	int validarParada;
	int i = 0;
	int numeroDeParada;
	char barrioDeParada;
	int vecParada[50];
	char vecBarrio[50];
	
	for(a=0; a<50; a++) {
		vecParada[a] = 0;
	}
	
	for(a=0; a<50; a++) {
		vecBarrio[a] = 'z';
	}
	
	
     opcionSeleccionada = opcionesMenu();
     system("cls");
	
	while(opcionSeleccionada != 3) {

		switch(opcionSeleccionada) {
			case 1:
                 validarParada = 0;
                 while(validarParada==0) {
                                     
    				printf("Ingrese el numero de la parada de colectivo:\n 1-2-3: Barrio Liniers\n 4-5: Barrio Flores\n 6-7: Barrio Caballito\n 8-9-10: Barrio Palermo\n");
    				scanf("%d", &numeroDeParada);
    				system("cls");
    				
    				if(numeroDeParada <= 10 && numeroDeParada != 0) {
    				
    				if(numeroDeParada > 0  && numeroDeParada <= 3) {
    					barrioDeParada = 'l';
    				} else if(numeroDeParada == 4 || numeroDeParada == 5) {
    					barrioDeParada = 'f';
    				} else if(numeroDeParada == 6 || numeroDeParada == 7) {
    					barrioDeParada = 'c';
    				} else if(numeroDeParada >= 8  && numeroDeParada <= 10) {
    					barrioDeParada = 'p';
    				}
    				
    				cargarVectores(vecParada, vecBarrio, numeroDeParada, barrioDeParada, i);
    				i++;
                    
                    validarParada = 1;
                   }
                  }
            
			break;
    		case 2:
    			consultarInformacion(vecParada, vecBarrio, i);
    			system("pause");
    			system("cls");
    		break;
    		}
           opcionSeleccionada = opcionesMenu();
           system("cls");
	}
}

int opcionesMenu (){ 
        
        int opcionMenu;
        int validarOpcion = 0;
        
        while(validarOpcion == 0) {
                            
            printf("1- Ingresar datos de parada de la linea de colectivos\n2- Consulta de la informacion sobre la linea de colectivos\n3- Salir\n");
    		fflush(stdin);
    		scanf("%d", &opcionMenu);
    		system("cls");
    		
    		if(opcionMenu <= 3 && opcionMenu != 0){
            
            validarOpcion = 1;
            }
        }
		
        return opcionMenu;   
}


void cargarVectores (int* vecParada, char* vecBarrio, int numeroDeParada, char barrioDeParada, int x) {
	
	*(vecParada + x) = numeroDeParada;
	*(vecBarrio + x) = barrioDeParada;
	
}

void consultarInformacion (int* vecParada, char* vecBarrio, int i) {
	
	int contL = 0, contF = 0, contC = 0, contP = 0, cont = 0;
	int j;
	char paradaInicial;
	char paradaFinal;
	
	
	for (j=0; j<i; j++) {
		
		cont++;	
		
		switch (*(vecBarrio + j)) {
               case 'l':
			        contL = contL +1;
               break;
               case 'f':
			        contF = contF +1;
               break;
               case 'c':
			        contC = contC +1;
               break;
               case 'p':
			        contP = contP +1;
               break;
           }
		
		if(j==0) {
			paradaInicial=*(vecBarrio + j);
		}
		if(j==i-1){
			paradaFinal=*(vecBarrio + j);
		}
		
		printf("Los datos de cada parada son: %d %c\n", *(vecParada + j), *(vecBarrio + j));
		
	  }
	
	printf("La cantidad de paradas en el barrio de Liniers son: %d\nLa cantidad de paradas en el barrio de Flores son: %d\nLa cantidad de paradas en el barrio de Caballito son: %d\nLa cantidad de paradas en el barrio de Palermo son: %d\n", contL, contF, contC, contP);
	
	
	
	if(paradaInicial==paradaFinal){
		printf("La linea de colectivo comienza y termina en el mismo barrio: %c\n",paradaInicial);
	} else {
		printf("La linea de colectivo comienza y termina en distintos lugares\n");
	}
		
	if(cont == contL || cont == contF || cont == contC || cont == contP ) {
		printf("Todas las paradas son del mismo barrio\n");
	} else {
		printf("Las paradas son de distintos barrios\n");
	}
	
}
