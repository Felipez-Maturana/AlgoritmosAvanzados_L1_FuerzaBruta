#include "structs.h"
#include <stdio.h>
#include <string.h>

lista InsertSort(lista L) // Funcion que permite ordenar una lista a traves del algoritmo de insercion O(n)=n^2. T(n) = 3n^2 + 12n + 4.
{
    int i,j,aux,MINindice,MINvalor;
    for(i=0;i<=L.fin-2;i++)
    {
        MINindice=i;
        MINvalor=obtener(L,i);

        for(j=i+1;j<=L.fin-1;j++)// en la i-Esima iteraciOn
        {
            if(obtener(L,j) < MINvalor)
            {
                MINindice= j;
                MINvalor= obtener(L,j);
            }
        }
        if(MINindice != i)
        {
            aux=obtener(L,i);

            L=insertar(L, obtener(L,MINindice),i); //inserta el i-esimo elemtno en su posicion correcta, entre los i-1 elementos anteriores 
            //mostrar(L);
            L=borrar(L,i+1);
            //mostrar(L);
            L=insertar(L, aux ,MINindice);
            L=borrar(L,MINindice+1);

        }
    }

    return L;
}

lista EliminarRepetidos(lista L)// Funcion que elimina los repetidos en una lista previamente ordenada O(n)=n^2	T(n) = 3n^2 + 17n + 2.
{
    int i;
    for(i =0; i < L.fin; i++)
    {
        if(obtener(L,i)==obtener(L,i+1)) //Si dos elementos son iguales de forma consecutiva (Se asume que estan ordenados)
        {
            L=borrar(L,i+1); // Elimina el elemento.
            i=i-1;
            if(i<0)
            {
				i=0;
			}
        }
    }
    L=insertar(L,' ',L.fin);//Segun el algoritmo de cifrado es necesario que el alfabeto a utilizar luego de ser ordenado posea un espacio en el ultimo elemento
    
    if(obtener(L,0)==32)
	{
		L=borrar(L,0); //Si el primer elemento es un espacio este se borra, ya que el espacio debe ir en ultimo lugar pero el espacio en ASCII es 32, siempre estara primero.
	}
    return L;
}

int verificarVocal(int elemento)   //Retorna -1 si es una vocal y -2 si es una consontante. O(n) = 1. T(n) = 14.
{
    if(elemento==32 || elemento==65 || elemento==69 || elemento==73 || elemento==79 || elemento==85 || elemento==97 || elemento==101 || elemento==105 || elemento==111 || elemento==117)
    {
		// los numeros en esta bifurcacion representan las vocales, tanto minusculas y mayusculas. Y el espacio = 32
        return -1;
    }
    else
    {
		// si no es vocal, retorna -2
        return -2;
    }
}

lista moverDerecha(lista L) //Funcion que desplaza una lista a la derecha una vez O(n)=n^2. T(n) = 3n^2 + 11n + 2.
{
    int i;
    lista L2;
    L2=crearLista(); //Se crea la lista que se retornarA 

    L2=insertar(L2, obtener(L,L.fin-1) ,0); //Se inserta el ultimo elemento en el primero (Lista circular)
    for(i=0; i<L.fin-1 ;i++)
    {
        L2=insertar(L2, obtener(L,i),i+1); //Se corren todos los elementos una posicion a la derecha
    }

    return L2;
}

lista moverIzquierda(lista L) //Funcion que desplaza una lista a la izquierda una vez O(n)=n^2. T(n) = 3n^2 + 11n + 2.
{
    int i;

    lista L2;
    L2=crearLista();

    for(i=1; i<=L.fin-1 ;i++)
    {
        L2=insertar(L2, obtener(L,i),i-1); // Se desplazan todos los elementos una posicion hacia la izquierda
    }

    L2=insertar(L2, obtener(L,0) , L.fin-1); //Se inserta el primer elemento en la ultima posicion
    return L2;
}

int BuscarEspacio(lista L1,int a) //Funcion que retorna la posicion del entero (caracter ASCII) en la lista L1. O(n)=n^2. T(n) = 3n^2 + 6n + 2.
{
    int i=0;
    int z=0;

    for(i=0;i<L1.fin;i++)
    {
        z=obtener(L1,i); //z es el entero con el cual se compara el entero que entra como argumento en la funcion.
        if(z==a)
        {
            return i; // Si lo encontrO, retorna la posicion que ocupa el entero z.
        }
    }
    //Si el elemento no estA, generalmente en el alfabeto el programa finalizarA
    printf("El elemento que estAs buscando no se encuentra en la lista buscada\n El programa se cerrarA\n");
    printf("Presione una tecla para salir...");
    getchar();
    exit(0);
    
    return -1;
}

int calcularDesfase(lista L1,lista L2) //Funcion que calcula el desfase entre dos listas O(n)=n. T(n) = n+7.
{
    int a=0;
    int b=0;
    int resultado=0;
    //El espacio (de referencia) siempre se encuentra en la ultima posicion del Alfabeto utilizado
    a=L1.fin-1;  //32 corresponde al ASCII de espacio ' '
    b=BuscarEspacio(L2,32);
    //Resta la posicion del espacio en el alfabeto, con la posicion del espacio que actualmente ocupa en la Lista que contiene las letras del cifrado

    resultado=a-b;

    if(resultado<0)
    {
        resultado=-resultado;
    }

    return resultado;
}

lista moverNDerecha(lista L, int veces) //Funcion que mueve N veces una lista a la derecha O(n)=n^2. T(n) = n*(3n^2 + 11n + 2).
{
	lista L1;
	L1=L;
	int i;
	for(i=0;i<veces;i++)
	{
		L1=moverDerecha(L1);
		
	}
	return L1;
}

lista moverNIzquierda(lista L, int veces) //Funcion que mueve N veces una lista a la izquierda O(n)=n^3. T(n) = n*(3n^2 + 11n + 2).
{
	lista L1;
	L1=L;
	int i;
	for(i=0;i<veces;i++)
	{
		L1=moverIzquierda(L1);
	}
	
	return L1;
}

lista Codificar(lista L) //Funcion que se encarga de codificar una lista O(n)=n^4. T(n) en el peor de los casos (solo vocales), realiza dos veces el llamado a InsertSort y EliminarRepetidos, ademas de n veces el llamado a moverNIzquierda (n*n^3).
{
	lista LLetras = crearLista();
	lista LCodificada = crearLista();
	lista LLetrasCodificada = crearLista();
	
	FILE * Salida;
	
	LLetras = InsertSort(L); // O(n)=n^2
	LLetras = EliminarRepetidos(LLetras); //O(n)=n^2
	LCodificada = InsertSort(L); //O(n)=n^2
	LCodificada = EliminarRepetidos(LCodificada); //O(n)=n^2
	//mostrar(LLetras);
	//mostrar(LCodificada);
	Salida = fopen("Salida.out","w");
	int a=0; //SerA el caracter de la lista original 
	int Pos=0; //PosiciOn en la que se encuentra el caracter de la lista original en la lista Letras
	int CaracterLC=0; //Valor ASCII del caracter que se encuentra en la PosiciOn pos en la Lista Codificada
	int i=0;
	for(i=0;i<L.fin;i++)
	{
		//Obtengo el caracter que se codificara en la lista original
		
		a=obtener(L,i);
		//printf("El caracter de la lista original a codificar es %c\n",a);
		
		Pos = BuscarEspacio(LLetras,a); //O(n)=1
		//printf("El caracter buscado se encuentra en la posicion %d\n",Pos);
		
		CaracterLC = obtener(LCodificada,Pos); //O(n)=n
		//printf("El caracter (en la misma posicion) en la lista Codificada es %c\n",CaracterLC);
		
		
		LLetrasCodificada = insertar( LLetrasCodificada,CaracterLC,i);
		
		
		if( verificarVocal(CaracterLC) == -1)
		{
			//printf("3 Movimientos a la izquierda: ");
			LCodificada = moverNIzquierda(LCodificada,3); //O(n)=n^3
			//mostrar(LCodificada);
		}
		else if( verificarVocal(CaracterLC) == -2)
		{
			//printf("1 Movimiento a la derecha: ");
			LCodificada = moverDerecha(LCodificada); //O(n)=n^2
			//mostrar(LCodificada);
		}
		  
	}
	
	//printf("El alfabeto utilizado:\n");
	//mostrar(LLetras);
	//printf("La Lista Codificada:\n");
	//mostrar(LCodificada);
	
	printf("La frase o palabra cifrada es: \n");
	mostrar(LLetrasCodificada);
	for(i=0;i<LLetrasCodificada.fin;i++)
	{
		fprintf(Salida,"%c", obtener(LLetrasCodificada,i) );
	}
	fprintf(Salida,"\n");
	int desfase = calcularDesfase(LLetras,LCodificada);
	//printf("El desfase entre el alfabeto y la lista codificada es: %d\n",desfase);
	fprintf(Salida,"%d",desfase);
	
	fclose(Salida);
	return LLetrasCodificada;
}

lista Decodificar(int desfase, lista LDescifrar, lista Alfabeto) //Funcion que se encarga de decodificar una lista O(n)=n^4
{
	//2 llamados a InsertSort y Eliminar Repetidos, ademas de mover N izquierda para iniciar el proceso de descifrado y N mover derecha en el mismo proceso de descifrado.
	lista resultado = crearLista();
	FILE * Salida;
	Salida = fopen("Salida.out","w");
	
	lista Alfabeto2= InsertSort(Alfabeto); //O(n)=n^2
	Alfabeto2 = EliminarRepetidos(Alfabeto2); //O(n)=n^2
	
	//printf("\nEL ALFABETO UTILIZADO: ");
	//mostrar(Alfabeto2);
	lista LLetras = Alfabeto2;
	
	//printf("El alfabeto a utilizar tiene %d, LLetras tiene %d\n",Alfabeto2.fin,LLetras.fin);
	//printf("*%c*\n",obtener(Alfabeto2,0)); //O(n)=n
	if(desfase >0)
	{
		LLetras = moverNIzquierda(LLetras,desfase);
	}
	
	//printf("LLetras INICIAL :");
	//mostrar(LLetras);
	//printf("El largo de L.Descifrar es %d\n",LDescifrar.fin);
	int a=0;
	int i=0;
	int pos=0;
	int z=0;
	
	int AUX[LDescifrar.fin+1];
	
	for(i= LDescifrar.fin-1 ; i>=0 ;i--)
	{
		a=obtener(LDescifrar,i);
		//printf("El elemento obtenido en i = %d es : %c\n",i,a);
		z= verificarVocal(a);
		if(z==-1)
		{
			LLetras = moverNDerecha(LLetras,3); //O(n)=n^3
		}
		else if(z==-2)
		{
			LLetras = moverIzquierda(LLetras); //O(n)=n^2
		}
		
		//mostrar(LLetras);
		
		pos = BuscarEspacio(LLetras,a); //O(n)=n^2
		//printf("El termino buscado en la pos %d es %c ?\n",pos,obtener(Alfabeto2,pos));

		AUX[i]=obtener(Alfabeto2,pos);
	}
	
	for(i=0;i<LDescifrar.fin;i++)
	{
		resultado = insertar(resultado, AUX[i],i);
	}
	
	for(i=0;i<resultado.fin;i++)
	{
		fprintf(Salida,"%c", obtener(resultado,i) );
	}
	int desfase2= calcularDesfase(Alfabeto2,LLetras);
	fprintf(Salida,"\n");
	fprintf(Salida,"%d",desfase2);	
	
	fclose(Salida);
	
	return resultado;
}
 
void LeerArchivo() //Funcion que se encarga de leer un archivo y dar la intruccion de codificar o decodificar segun sea el caso
{
	FILE * Entrada;
	char Cabecera[11];
	char * Cifrado = "Cifrado";
	char * Descifrado = "Descifrado";
	lista PalabraACifrar = crearLista();
	
	//char * Descifrado = "Descifrado";
	char Caracter;
	Entrada = fopen("Entrada.in","r");
	
	if(Entrada != NULL)
	{
		fscanf(Entrada,"%s",Cabecera);
		
		if(strncmp(Cabecera, Cifrado, 7) ==0 )
		{
			printf("\n********** INICIO DEL PROCESO DE CIFRADO **********\n");
			
			int contador=0;
			while(!feof(Entrada))
			{
				fscanf(Entrada,"%c",&Caracter);
				if((Caracter >= 65 && Caracter <=90) || (Caracter >= 67 && Caracter <=122) || Caracter==32 ) 	// Solo se admiten Letras (mayUsculas o minUsculas)
				{
					PalabraACifrar = insertar(PalabraACifrar,Caracter,contador);
					contador=contador+1;
				} 
			}
			printf("La Palabra a cifrar es: \n");
			mostrar(PalabraACifrar);
			printf("\n");
			
			Codificar(PalabraACifrar);
			printf("********** FIN DEL PROCESO DE CIFRADO **********\n");
			fclose(Entrada);
		}
		else if(strncmp(Cabecera, Descifrado, 7) ==0)
		{
			printf("********** INICIO DEL PROCESO DE DESCIFRADO **********\n");
			int contador2=0;
			int contador3=0;
			int linea=0;
			int desfase2=0;
			lista TextoADescifrar= crearLista();
			lista AlfabetoUtilizado = crearLista();
			while(!feof(Entrada))
			{
				fscanf(Entrada,"%c",&Caracter);
				//printf("**%d**\n",Caracter);
				if(Caracter == 10)
				{
					linea=linea+1;
				}
				
				if(linea == 1)
				{
					fscanf(Entrada,"%d",&desfase2);
//					printf("El desfase del Archivo leido es %d\n",desfase2);
				}	
				else if(linea ==2)
				{
					
					if((Caracter >= 65 && Caracter <=90) || (Caracter >= 67 && Caracter <=122) || Caracter==32 ) 	// Solo se admiten Letras (mayUsculas o minUsculas)
					{
						TextoADescifrar = insertar(TextoADescifrar,Caracter,contador2);
						contador2=contador2+1;					
					}					
				}
				else if(linea == 3)
				{
					if((Caracter >= 65 && Caracter <=90) || (Caracter >= 67 && Caracter <=122) || Caracter==32 ) 	// Solo se admiten Letras (mayUsculas o minUsculas)
					{
						//printf("Insertando -%c- en la posicion %d\n",Caracter,contador3);
						AlfabetoUtilizado = insertar(AlfabetoUtilizado,Caracter,contador3);
						contador3=contador3+1;					
					}	
				}
			}
			
			printf("\nEL TEXTO A DESCIFRAR: ");
			mostrar(TextoADescifrar);
			
			printf("La frase o palabra decodificada es: ");
			mostrar(Decodificar(desfase2,TextoADescifrar,AlfabetoUtilizado));
			printf("********** FIN DEL PROCESO DE DESCIFRADO **********\n");
			fclose(Entrada);
		}
		else
		{
			printf("No se encuentra la instrucciOn Intente con:\n-Cifrado\n-Descifrado\n");
		} 
		
	}
	else
	{
		printf("NO SE ENCUENTRA EL ARCHIVO");
	}

}
