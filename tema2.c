#include <stdio.h>
#include <string.h>


int main(){

	int i, j, k, x = 0, y = 0, nr = 0 , n , m , aux, poz , ok , lungime_maxima_coloane , lungime_maxima_celule;
	int vector_celule[50]; //definesc un vector de celule
	char pozitionare; /*definesc o variabila care specifica daca
						prima coloana este ridicata sau coborata*/
	int vector_regine[160]; /*definesc un vector care 
										retine coordonatele unei regine*/
	char A[160][160]; //definesc matricea din care va fi generat fagurele

	//citire fagure
	char input[500];
	
	while (fgets(input, 500, stdin)){

			nr = 0;
			x = 0;
			y = 0;
			i = 0;
			for( m = 0; m < 50 ; m++){
				vector_celule[m] = 0;
			}
			for( m = 0; m < 160 ; m++){
				vector_regine[m] = 0;
			}
			for( m = 0; m < 160 ; m++){
				for( n = 0 ; n<160 ; n++){
					A[m][n] = 0;
				}
			}

                while(input[nr] != 'R' && input[nr] != 'C' ){
                        nr++;
                }
		pozitionare = input[nr];
                while( i < nr ){
                        if ( ( input[i] >= '0' && input[i] <= '9' ) && ( input[i+1] >= '0' && input[i+1] <= '9' ) ){
                                vector_celule[x] = (input[i] - 48)*10 + input[i+1] - 48;
                                i += 2;
                                x++;
                        }else if( ( input[i] >= '0' && input[i] <= '9' ) && input[i+1] == ' ' ){
                                vector_celule[x] = input[i] - 48;
                                i++;
                                x++;
                        }else{
                                i++;
                		}
                }
                j = nr + 1;
                while( input[j] != '\0' ){
                        if ( ( input[j] >= '0' && input[j] <= '9' ) && ( input[j+1] >= '0' && input[j+1] <= '9' ) ){
                                vector_regine[y] = (input[j] - 48)*10 + input[j+1] - 48;
                                j += 2;
                                y++;
                        }else if( ( input[j] >= '0' && input[j] <= '9' ) && (input[j+1] < '0' || input[j+1] > '9')  ){
                                vector_regine[y] = input[j] - 48;
                                j++;
                                y++;
                        }else{
                                j++;
                		}
                }
   

                

        		 

                

	//initializarea fagurelui cu spatii
	for(i=0; i<160; i++){
		for(j=0; j<160; j++){
			A[i][j]=' ';
		}
	}

	//generare fagure

		for (i = 0; i < x; i++){

			// cazul in care prima coloana este coborata
			if (pozitionare == 'C'){
				for (j = 0; j < vector_celule[i]; j++){

					//coloane coborate
					if (i % 2 == 0 ){

					A[2*j+1][2*i+1] = '_';
					A[2*j+2][2*i] = '/';
					A[2*j+2][2*i+2] = '\\';
					A[2*j+3][2*i] = '\\';
					A[2*j+3][2*i+1] = '_';
					A[2*j+3][2*i+2] = '/';


					//coloanele ridicate
					}else{
					A[2*j][2*i+1] = '_';
					A[2*j+1][2*i] = '/';
					A[2*j+1][2*i+2] = '\\';
					A[2*j+2][2*i] = '\\';
					A[2*j+2][2*i+1] = '_';
					A[2*j+2][2*i+2] = '/';
					}

				}

					//in caz ca sunt matci in fagure pe coloana ridicata
						if (vector_regine != 0){
							for (k = 0; k < y/2; k++){
								if (vector_regine[2*k] % 2 == 0){
									A[2*vector_regine[2*k+1]-1][2*vector_regine[2*k]-1] = 'Q';
								}
							}
						}

							//in caz ca sunt matci in fagure pe coloana coborata
						if (vector_regine != 0){
							for (k = 0; k < y/2; k++){
								if (vector_regine[2*k] % 2 != 0){
									A[2*vector_regine[2*k+1]][2*vector_regine[2*k]-1] = 'Q';
								}
							}
						}
			}

			//cazul in care prima coloana este ridicata 

			if (pozitionare == 'R'){
				for (j = 0; j < vector_celule[i]; j++){

					//coloane ridicate
					if (i % 2 == 0){

					A[2*j][2*i+1] = '_';
					A[2*j+1][2*i] = '/';
					A[2*j+1][2*i+2] = '\\';
					A[2*j+2][2*i] = '\\';
					A[2*j+2][2*i+1] = '_';
					A[2*j+2][2*i+2] = '/';

					//coloane coborate
					}else{

					A[2*j+1][2*i+1] = '_';
					A[2*j+2][2*i] = '/';
					A[2*j+2][2*i+2] = '\\';
					A[2*j+3][2*i] = '\\';
					A[2*j+3][2*i+1] = '_';
					A[2*j+3][2*i+2] = '/';

							
					}

				}

							//in caz ca sunt matci in fagure pe coloana coborata
						if (y != 0){
							for (k = 0; k < y/2; k++){
								if (vector_regine[2*k] % 2 == 0){
									A[2*vector_regine[2*k+1]][2*vector_regine[2*k]-1] = 'Q';
								}
							}
						}

							//in caz ca sunt matci in fagure pe coloana ridicata
						if (vector_regine != 0){
							for (k = 0; k < y/2; k++){
								if (vector_regine[2*k] % 2 != 0){
									A[2*vector_regine[2*k+1]-1][2*vector_regine[2*k]-1] = 'Q';
								}
							}
						}

			}
		}

		//aflarea celui mai mare mai mare element al vectorului de celule
		aux = vector_celule[0];
		ok = 0;					// ia valoarea 1 daca coloana indicata de i este coborata si 0 daca este ridicata
		poz = 0;				// vatiabila menita sa retina pozitia elementului maxim
		for (i = 0; i < x; i++){
			if ( vector_celule[i] > aux){
				aux = vector_celule[i];
				poz = i;
				if ( pozitionare == 'R' ){
					if ( i % 2 != 0 ){
						ok = 1;
					}else{
						ok = 0;
					}
				}
				if ( pozitionare == 'C' ){
					if ( i % 2 == 0 ){
						ok = 1;
					}else{
						ok = 0;
					}
				}

			}

			if ( vector_celule[i] == aux ){
				if ( pozitionare == 'R' ){
					if ( i % 2 != 0 ){
						aux = vector_celule[i];
						poz = i;
						ok = 1;
					}else{
						ok = 0;
					}
				}

				if ( pozitionare == 'C' ){
					if ( i % 2 == 0 ){
						aux = vector_celule[i];
						poz = i;
						ok = 1;
					}else{
						ok = 0;
					}
				}

			}

			if ( vector_celule[i] < aux){
				
				if ( pozitionare == 'R' ){
					if ( i % 2 != 0 ){
						ok = 1;
					}else{
						ok = 0;
					}
				}
				if ( pozitionare == 'C' ){
					if ( i % 2 == 0 ){
						ok = 1;
					}else{
						ok = 0;
					}
				}
			} 

		}

		//dimensionarea corecta a fagurelui si afisarea sa
		lungime_maxima_celule = 0; 
		lungime_maxima_coloane = 0;
		if( aux == 24 ){
			lungime_maxima_celule = 2 * aux + 1;
		}else{
		if ( ok = 0 ){
			lungime_maxima_celule = 2 * aux + 1;
		}else{
			lungime_maxima_celule = 2 * aux + 2;
		}
		}
		lungime_maxima_coloane = 2 * x + 1;

	
		for ( i = 0; i < lungime_maxima_celule; i++){
			for ( j = 0; j < lungime_maxima_coloane; j++){
				printf("%c",A[i][j]);
			}
			printf("\n");
		}

		
	}

	
	return 0;
}
