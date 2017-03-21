#include "2EnlazadasCursor.c"
//#include "funciones.h"
#include "structs.h"

#include "funciones.c"


int main()
{
	/*    // INICIO PRUEBAS
    lista L1,L2,L3,L4;
    L1 = crearLista();
    L2 = crearLista();
    L3 = crearLista();
    L4 = crearLista();

    L1=insertar(L1,'a',0);
    L1=insertar(L1,'a',0);
    L1=insertar(L1,'b',1);
    L1=insertar(L1,'c',2);
    L1=insertar(L1,'t',3);
    L1=insertar(L1,'g',4);
    L1=insertar(L1,'z',2);
    L1=insertar(L1,'c',5);
    L1=insertar(L1,'z',3);
    L1=insertar(L1,'y',2);
    L1=insertar(L1,'a',6);
    L1=insertar(L1,'e',2);
    L1=insertar(L1,'r',1);
    L1=insertar(L1,'a',4);
    L1=insertar(L1,'z',1);
    L1=insertar(L1,'z',1);
    L1=insertar(L1,'z',1);
    printf("\n\n**********La lista Original es: %d*********\n\n",L1.fin);
    mostrar(L1);

    int c=anterior(L1,10);
    printf("el elemento anterior es: %d \n",c);

    L2=InsertSort(L1);
    printf("\n\n**********La lista ordenada es: %d**********\n\n",L2.fin);
    mostrar(L2);

    L2=EliminarRepetidos(L2);
    printf("\n\n**********La Lista de letras es: %d**********\n\n",L2.fin);
    mostrar(L2);

    printf("%d\n",verificarVocal(' '));

    L3=moverDerecha(L2);
    
    printf("\n\n**********La Lista movida 3 veces a la Derecha es: %d**********\n\n",L3.fin);
    mostrar(L3);

    L3=moverNDerecha(L3,3);
    mostrar(L3);


	
    L4=moverNIzquierda(L2,3);
    printf("\n\n**********La Lista movida a la 3Izquierda es: %d**********\n\n",L4.fin);
    mostrar(L2);
    mostrar(L4);
	    
    printf("**********inicio del calculo de desfase**********\n\n");

    mostrar(L4);
    mostrar(L3);

    int desfase=calcularDesfase(L3,L4);
    printf("Las listas se encuentran desplazadas por %d\n",desfase);

    int t = BuscarEspacio(L4);
    printf("El espacio se encuentra en: %d\n",t);
	
	*/ //FIN PRUEBAS

/*	
	lista L1,L2,L3,L4,LAlfabeto;
	
	lista L5,L6;
	
	L5 = crearLista();
	L6=crearLista();
	
	
    L1 = crearLista();
    L2 = crearLista();
    L
********** FIN DEL PROCESO DE CIFRADO **********
3 = crearLista();
    L4 = crearLista();
    LAlfabeto = crearLista();
    

	L1=insertar(L1,'J',0);
    L1=insertar(L1,'E',1);
    L1=insertar(L1,'J',2);
    L1=insertar(L1,'E',3);
	
	L2= Codificar (L1);
	
	printf("\n\nPALABRA CODIFICADA\n");
	mostrar(L2);
	printf("\n**********FIN PALABRA CODIFICADA************\n");
	
	L3=insertar(L3,'H',0);
    L3=insertar(L3,'L',1);
    L3=insertar(L3,'A',2);
    L3=insertar(L3,'H',3);

	LAlfabeto=insertar(LAlfabeto,'J',0);
    LAlfabeto=insertar(LAlfabeto,'E',1);
//    LAlfabeto=insertar(LAlfabeto,'J',2);
//    LAlfabeto=insertar(LAlfabeto,'E',3);
	
	
	L4=Decodificar(2, L2, LAlfabeto);
	
	mostrar(L4);
	
*/

	lista L1;
    L1 = crearLista();

    L1=insertar(L1,'a',0);
    L1=insertar(L1,'b',1);
    L1=insertar(L1,'c',2);
    L1=insertar(L1,'d',3);
    L1=append(L1,'d');
    printf("\n\n**********La lista Original es: %d*********\n\n",L1.fin);
    mostrar(L1);

	
	
	//LeerArchivo();
    return 0;
}
 
