#include "structs.h"
#include <stdio.h>

//Funcion que se encarga de insertar en el ultimo lugar de una lista de listas ListaEnlazada, la lista L1 
lista * appendLista(lista L1, lista * ListaEnlazada, int * CantidadElementos)
{
	//Se aumenta en uno la cantidad de elementos que posee esa lista
	* CantidadElementos = *CantidadElementos + 1; 
	
	//Se asigna mAs memoria a la lista enlazada que contendrA las listas
	ListaEnlazada = (lista *) realloc(ListaEnlazada,*CantidadElementos*sizeof(lista));
	
	//Se asigna en la posicion indicada, la lista L1
	ListaEnlazada[*CantidadElementos-1] = L1;
	
	return ListaEnlazada;
	
}
//Muestra por pantalla todos los elementos que se encuentran en la lista que contiene las listas de combinaciones
void mostrarListaEnlazada(lista * ListaEnlazada, int CantidadElementos)
{
	int i;
	for(i=0;i<CantidadElementos;i++)
	{
		printf("%d: ",i+1);
		mostrar(ListaEnlazada[i]);
	}
}

//Funcion que se encarga de escribir en el archivo de Salida la lista Combinacion
void imprimirArchivoLista(FILE * archivoSalida, lista Combinacion)
{
	int indice = Combinacion.cabeza;
    while(indice != NULO) {
        fprintf(archivoSalida,"%c", Combinacion.arreglo[indice].elemento);
        indice = Combinacion.arreglo[indice].siguiente;
    }
    fprintf(archivoSalida,"\n");
}


//O(n)=n^2
void imprimirArchivoListaBidimensional(FILE * archivoSalida, lista * ListaEnlazada, int CantidadElementos)
{
	int i;
	for(i=0;i<CantidadElementos;i++)
	{
		fprintf(archivoSalida,"%d: ",i+1);
		//mostrar(ListaEnlazada[i]);
		imprimirArchivoLista(archivoSalida,ListaEnlazada[i]);
	}
	printf("El programa ha finalizado de forma exitosa\nLas combinaciones vAlidas se encuentran en el archivo Salida.out alojado en la misma carpeta que el cOdigo.");
	
}

//Funcion recibe como entrada una lista con los caracteres a ocupar en la fuerza bruta, ademAs de un puntero a entero donde se mantendrA un registro de la cantidad
//de listas que contendrA la salida de este algoritmo, es decir, la cantidad de combinaciones.
lista * fuerzaBrutaPassword(lista Caracteres, int * CantidadListas)
{
	//Se crea y se asigna memoria a un puntero de la estructura lista (structs.h), se le asigna la memoria para una lista.
	lista * Resultado = (lista *) malloc(sizeof(lista));
    *CantidadListas = 0;
    lista L1;

    int a,b,c,d,e,f,g,h;
	//8 For anidados, cada uno por la cantidad de caracteres que posee la contrasenha
	
    for(a=0;a< Caracteres.fin;a++)
    {
		
		//Se crea la lista que contendrA la combinacion n-Esima de la aplicacion de la fuerza bruta
		L1 = crearLista();
		
		for(b=0;b< Caracteres.fin;b++)
		{
			for(c=0;c< Caracteres.fin;c++)
			{
				for(d=0;d< Caracteres.fin;d++)
				{
					for(e=0;e< Caracteres.fin;e++)
					{
						for(f=0;f< Caracteres.fin;f++)
						{
							for(g=0;g< Caracteres.fin;g++)
							{
								for(h=0;h< Caracteres.fin;h++)
								{
									
									//Se 'Concatena' a lista L1 el los caracteres que estan siendo permutados, contenidos en la lista Caracteres la cual es la entrada de la funcion 
									//Se inserta en la posicion 0, el caracter en la posicion 'a' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[a].elemento,0);
									//Se inserta en la posicion 1, el caracter en la posicion 'b' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[b].elemento,1);
									//Se inserta en la posicion 2, el caracter en la posicion 'c' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[c].elemento,2);
									//Se inserta en la posicion 3, el caracter en la posicion 'd' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[d].elemento,3);
									//Se inserta en la posicion 4, el caracter en la posicion 'e' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[e].elemento,4);
									//Se inserta en la posicion 5, el caracter en la posicion 'f' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[f].elemento,5);
									//Se inserta en la posicion 6, el caracter en la posicion 'g' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[g].elemento,6);
									//Se inserta en la posicion 7, el caracter en la posicion 'h' en la lista que contiene los caracteres a utilizar.
									L1 = insertar(L1,Caracteres.arreglo[h].elemento,7);
									
									//Se agrega en la lista de listas resultado, en la ultima posicion disponible, la lista anteriormente creada con la combinacion correspondiente a esta iteraciOn.
									Resultado = appendLista(L1, Resultado, CantidadListas);
									
									//Es necesario borrar todos los elementos de la lista L1, ya que provoca conflictos reutilizarla si no es borrada correctamente
									L1=borrarLista(L1);							
								}						
							}
						}				
					}						
				}				
			}		
		}
	}
	
    return Resultado;
} 



//Funcion que verifica que la lista de caracteres a utilizar, solo contenga caracteres validos.
//Es decir, solo contenga digitos (0-9) y letras minUsculas.
void verificarCaracteresValidos(lista Caracteres)
{
	int i;
	for(i=0;i<Caracteres.fin;i++)
	{
		if(Caracteres.arreglo[i].elemento <=48 || (Caracteres.arreglo[i].elemento >=57 && Caracteres.arreglo[i].elemento <=97) || Caracteres.arreglo[i].elemento >=122)
		{   
			
			printf("EL CARACTER INGRESADO NO ES VALIDO. Solo se permiten letras minUsculas y nUmeros del 0 al 9\n");
			printf("A continuaciOn el programa se cerrarA \n");
			getchar();
			exit(0);
		}
	}
}



//Retorna 1 si el elemento a analizar es una vocal y -1 si es una consontante. O(n) = 1. T(n) = 14.
int verificarVocal_Consonante(int elemento)   
{
    if(elemento==97 || elemento==101 || elemento==105 || elemento==111 || elemento==117)
    {
		// los numeros en esta bifurcacion representan las vocales minUsculas.
        return 1;
    }
    else if(elemento >97 && elemento <=122)
    {
		//En esta bifurcacion representa todos los elementos que no son vocales y estan dentro de la numeracion 97 y 122 ASCII
		//Es decir, son las consonantes minUsculas.
		return -1;
	}
	else
	{
		//Si no corresponde a ninguno de los dos elementos anteriormente mencionados, el programa deberia finalizar.
		return -2;
	}
}





//Funcion que verifica que el elemento de entrada sea un Digito (0-9)
//En caso de que efectivamente lo sea, retorna 1.
//Caso contrario retorna -1.
int verificarNumero09(int elemento)
{
	//En ASCII 48 corresponde a el char '0' y 57 corresponde a '9'
	if(elemento>=48 && elemento <=57)
	{
		//Caso de Exito
		return 1;
	}
	else
	{
		//Caso de Fracaso.
		return -1;
	}
}

//Funcion que verifica que el elemento ingresado corresponde a una letra
int verificarLetra(int elemento)
{
	if (elemento>=97 && elemento <=122)
	{
		//Si el elemento efectivamente es una letra minuscula, retorna 1.
		return 1;
	}
	else
	{
		//Caso contrario, retorna -1.
		return -1;
	}
}


//Funcion que verifica si los tres elementos ingresados son consonantes
//En el caso que lo sean, la funcion retorna 1.
//Caso contrario, retorna -1.
int verificar3ConsonantesConsecutivas(int elemento1, int elemento2, int elemento3)
{
	//Se realiza la verificacion y se guarda en Resultado 1 2 y 3.
	int resultado1 = verificarVocal_Consonante(elemento1);
	int resultado2 = verificarVocal_Consonante(elemento2);
	int resultado3 = verificarVocal_Consonante(elemento3);
	//Se espera que el resultado del llamado de las 3 funciones sea -1, ya que por convenciOn es el resultado que esperamos cuando buscamos consonantes.
	if( resultado1==-1 && resultado2==-1 && resultado3==-1)
	{
		//Caso de Exito. los 3 elementos ingresados son 
		return 1;
	}
	
	//Si uno de los 3 elementos no es una consonante, se retorna -1.
	return -1;
}


//Funcion que verifica si los tres elementos ingresados son consonantes
//En el caso que lo sean, la funcion retorna 1.
//Caso contrario, retorna -1.
int verificar3VocalesConsecutivas(int elemento1, int elemento2, int elemento3)
{
	//Se realiza la verificacion y se guarda en Resultado 1 2 y 3.
	int resultado1 = verificarVocal_Consonante(elemento1);
	int resultado2 = verificarVocal_Consonante(elemento2);
	int resultado3 = verificarVocal_Consonante(elemento3);
	//Se espera que el resultado del llamado de las 3 funciones sea -1, ya que por convenciOn es el resultado que esperamos cuando buscamos consonantes.
	if(resultado1==1 && resultado2==1 && resultado3==1)
	{
		//Caso de Exito. los 3 elementos ingresados son 
		return 1;
	}
	
	//Si uno de los 3 elementos no es una consonante, se retorna -1.
	return -1;
}


//Funcion que verifica si los tres elementos ingresados son consonantes
//En el caso que lo sean, la funcion retorna 1.
//Caso contrario, retorna -1.
int verificar3LetrasConsecutivas(int elemento1, int elemento2, int elemento3)
{
	//Se realiza la verificacion y se guarda en Resultado 1 2 y 3.
	int resultado1 = verificarLetra(elemento1);
	int resultado2 = verificarLetra(elemento2);
	int resultado3 = verificarLetra(elemento3);
	//Se espera que el resultado del llamado de las 3 funciones sea -1, ya que por convenciOn es el resultado que esperamos cuando buscamos consonantes.
	if(resultado1==1 && resultado2==1 && resultado3==1)
	{
		//Caso de Exito. los 3 elementos ingresados son letras.
		return 1;
	}
	
	//Si uno de los 3 elementos no es una consonante, se retorna -1.
	return -1;
}


//Funcion que verifica si los tres elementos ingresados son consonantes
//En el caso que lo sean, la funcion retorna 1.
//Caso contrario, retorna -1.
int verificar3NumerosConsecutivos(int elemento1, int elemento2, int elemento3)
{
	//Se realiza la verificacion y se guarda en Resultado 1 2 y 3.
	int resultado1 = verificarNumero09(elemento1);
	int resultado2 = verificarNumero09(elemento2);
	int resultado3 = verificarNumero09(elemento3);
	//Se espera que el resultado del llamado de las 3 funciones sea -1, ya que por convenciOn es el resultado que esperamos cuando buscamos consonantes.
	if(resultado1==1 && resultado2==1 && resultado3==1)
	{
		//Caso de Exito. los 3 elementos ingresados son digitoss.
		return 1;
	}
	
	//Si uno de los 3 elementos no es una consonante, se retorna -1.
	return -1;
}





//Condicion 1.1 que no existan 3 consonantes de forma consecutiva.
//Condicion 1.2 
//Se revisa toda la lista, en caso de encontrar 3 consonantes de forma consecutiva la funcion retorna -1.
//Caso contrario, la funcion retorna 1.
//O(n)=n
int condicion_1LetrasConsecutivas(lista combinacion)
{
	int i;
	for (i=0;i<=combinacion.fin-3;i++)
	{
		//Se realiza la verificacion meidante la funciOn verificar3ConsonantesConsecutivas, si Esta funciOn retorna 1, entonces
		//Quiere decir que ha encontrado 3 consonantes de forma consecutiva.
		
		if(verificar3LetrasConsecutivas(combinacion.arreglo[i].elemento,combinacion.arreglo[i+1].elemento,combinacion.arreglo[i+2].elemento)== 1)
		{
			//Caso de fracaso, esta combinaciOn no sirve ya que hay 3 letras de forma consecutiva.
			//Se retorna -1 en caso de fracaso.
			
			//printf("3 consonantes consecutivas en las posiciones %d %d %d\n",i,i+1,i+2);
			return -1;
		}
		else if(verificar3NumerosConsecutivos(combinacion.arreglo[i].elemento,combinacion.arreglo[i+1].elemento,combinacion.arreglo[i+2].elemento)== 1)
		{
			//Caso fracaso, esta combinacion no sirve ya que hay 3 nUmeros consecutivos
			return -1;
		}
	}
	//Caso de Exito
	return 1;
}

//FunciOn que verifica que la combinaciOn a analizar, si comienza con un nUmero, Este no termine en un nUmero.
//Y que si la funciOn comience con una letra, esta termine con un nUmero o una letra.
//O(n)=1
int condicion_2ComienzoNumero(lista combinacion)
{
	//Condicion que verifique si los elementos iniciales y finales no sean un nUmero (al mismo tiempo).
	if(verificarNumero09(combinacion.arreglo[0].elemento) == 1 && verificarNumero09(combinacion.arreglo[combinacion.fin-1].elemento) == -1)
	{
		//printf("Comienza con numero y no termina con numero\n");
		
		return 1;
	}
	else if (verificarLetra(combinacion.arreglo[0].elemento) == 1) 
//	&& (verificarNumero09(combinacion.arreglo[combinacion.fin-1].elemento) == 1 || verificarLetra(combinacion.arreglo[combinacion.fin-1].elemento) == 1))
	{
		
		
		return 1;
	}
	else
	{
		return -1;
	}
}

//Funcion que verifica si la combinaciOn comienza con vocal
//O(n)=1
int condicion_3ComienzoVocal(lista combinacion)
{
	//Si el elemento que ocupa la posiciOn 0, es un nUmero la funciOn retorna 1.
	if(verificarVocal_Consonante(combinacion.arreglo[0].elemento) == 1)
	{
		return -1;
	}
	else
	{
		return 1;
	}	
}

    
//Funcion que recibe una lista que contiene la lista de combinaciones y somete a prueba cada una de ellas
//Si la lista a analizar  efectivamente cumple con las 3 condiciones, se agrega a la lista resultados.
//O(n)=n^2
lista * aplicarFiltro(lista * ListaCombinaciones, int * cantidadCombinaciones, int * cantidadCombinacionesValidas)
{
	int i;
	lista * CombinacionesValidas;
	
	for(i=0;i<*cantidadCombinaciones;i++)
	{
		//Orden, n*(
		if(condicion_1LetrasConsecutivas(ListaCombinaciones[i])==1 && condicion_2ComienzoNumero(ListaCombinaciones[i])==1
		&& condicion_3ComienzoVocal(ListaCombinaciones[i])==1)
		{
			
			//Si la combinacion iterada cumple con todos los requisitos que expone nuestro problema
			//Es agregada a nuestra lista que contiene las combinaciones vAlidas.
			CombinacionesValidas = appendLista(ListaCombinaciones[i],CombinacionesValidas,cantidadCombinacionesValidas);														
		}  			
	}
	
	return CombinacionesValidas;
	
}      
void LeerArchivo() //Funcion que se encarga de leer un archivo y dar la intruccion de codificar o decodificar segun sea el caso
{
	FILE * Entrada;
	Entrada = fopen("Entrada.in","r");
	
			
	FILE * Salida;
	Salida = fopen ("Salida.out", "w");
	
	char Caracter;
	lista Caracteres = crearLista();
	int i;
	
	if(Entrada != NULL)
	{
		while(!feof(Entrada))
		{
			fscanf(Entrada,"%c",&Caracter);
			//printf("-%d-\n",Caracter);
			//Si el proximo caracter corresponde a un numero entre 0 y 9
			//O a una letra minUscula, entonces se 
			if( (Caracter >=48 && Caracter <=57) || (Caracter >=97 && Caracter <=122))
			{
				//Se Verifica que el caracter no estE repetido
				//Para todos los caracteres obtenidos desde el archivo de entrada, que se encuentren
				//En la Lista caracteres								
				for(i=0;i<Caracteres.fin;i++)
				{
					//Si el caracter que se quiere ingresar ya estA en el arreglo
					//el programa finaliza y sugiere que el alfabeto ingresado no se puede utilizar.
					if(Caracter == Caracteres.arreglo[i].elemento)
					{
						//Se escribe en el archivo de salida. 
						printf("No se puede utilizar el alfabeto ingresado, verifique el archivo Salida.out para obtener mAs informaciOn\n El programa se cerrarA, presione una tecla para continuar");
						fprintf(Salida,"El Caracter %c se encuentra duplicado en el alfabeto a utilizar\n", Caracter);
						fprintf(Salida,"No se puede utilizar el alfabeto ingresado\n");
						//Se cierran ambos archivos.
						fclose(Entrada);
						fclose(Salida);
						getchar();
						exit(0);
					} 					
				}				
				Caracteres = append(Caracteres,Caracter);
			}
			else if(Caracter == 10)
			{
				//Se ataja el salto de linea, no se hace nada
			}
			else
			{
				//Se escribe en el archivo de salida. 
				printf("No se puede utilizar el alfabeto ingresado, verifique el archivo Salida.out para obtener mAs informaciOn\n El programa se cerrarA, presione una tecla para continuar");
				
				fprintf(Salida,"El Caracter %c no estA permitido para realizar combinaciones\n", Caracter);
				fprintf(Salida,"No se puede utilizar el alfabeto ingresado\n");
				//Se cierran ambos archivos.
				fclose(Entrada);
				fclose(Salida);
				getchar();
				exit(0);				
			}
			 			
		}
		
		fclose(Entrada);	
			
		lista * CombinacionesPosibles;
		int * totalCombinaciones;
		

		totalCombinaciones = malloc(sizeof(int));
		CombinacionesPosibles = fuerzaBrutaPassword(Caracteres,totalCombinaciones);
		//mostrarListaEnlazada(CombinacionesPosibles,*totalCombinaciones);
		
		//printf("Cantidad de Listas que contiene Resultado: %d\n",*totalCombinaciones);
		//mostrarListaEnlazada(CombinacionesPosibles, *totalCombinaciones);
		
		
		
		lista * CombinacionesValidas;
		int * totalCombinacionesValidas=malloc(sizeof(int));
		*totalCombinacionesValidas = 0;
		CombinacionesValidas=aplicarFiltro(CombinacionesPosibles,totalCombinaciones,totalCombinacionesValidas);	
		
		

		fprintf(Salida, "De un total de %d Combinaciones creadas, se han obtenido %d Combinaciones Validas.\n",*totalCombinaciones,*totalCombinacionesValidas);
		//mostrarListaEnlazada(CombinacionesValidas, *totalCombinacionesValidas);
		imprimirArchivoListaBidimensional(Salida,CombinacionesValidas,*totalCombinacionesValidas);
		
		fclose(Salida);
	
		}
		else
		{
			fprintf(Salida,"NO SE ENCUENTRA EL ARCHIVO QUE CONTIENE EL ALFABETO");
		}
}
