#include <stdio.h>
#include <stdlib.h>

typedef struct strNodo{
	int numero;
	struct strNodo *izq;
	struct strNodo *der;
}NODO;

typedef struct{
	NODO *raiz;
	int altura;
	int peso;
}ARBOL;

void agregar_a_arbol(ARBOL *, int);
void recorrer_preorden(NODO *);
void recorrer_inorden(NODO *);
void recorrer_postorden(NODO *);
void recorrer_amplitud(NODO *);
void peso(NODO *);


int main(){
	system("Title Recorridos Arboles");
	ARBOL *arbol=NULL;
	int number;
	arbol=(ARBOL *) malloc(sizeof(ARBOL));
	arbol->raiz=NULL;
	arbol->altura=0;
	arbol->peso=0;
	int peso;
	
	
	do{
    printf("Introduce una numero: (0 para cancelar)\n");
    scanf("%d",&number);
    system("cls");
    if(number!=0){
        agregar_a_arbol(arbol,number);
    }
}while(number!=0);
	
	printf("Impresion del arbol en preorden***\n");
	recorrer_preorden(arbol->raiz);
	printf("Impresion del arbol en inorden***\n");
	recorrer_inorden(arbol->raiz);
	printf("Impresion del arbol en postorden***\n");
	recorrer_postorden(arbol->raiz);
	printf("Impresion del arbol en amplitud***\n");
	recorrer_amplitud(arbol->raiz);
	

	//peso(arbol->peso);
	//imprimir_nodoizq(arbol->raiz);

	return;
}

int altura(NODO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altura_izquierda = altura(raiz->izq);
    int altura_derecha = altura(raiz->der);
    if (altura_izquierda > altura_derecha) {
        return altura_izquierda + 1;
    }else{
        return altura_derecha + 1;
    }
}



//printf("Peso: \n", peso);

void agregar_a_arbol(ARBOL *aux2, int number){
	NODO *nuevo_nodo=NULL;
	int alt=1;
	int peso=0;
	nuevo_nodo=(NODO *) malloc(sizeof(NODO));
	if(nuevo_nodo==NULL){
    	printf("ERROR DE MEMORIA \n");
    	exit(1);
	}
	nuevo_nodo->numero=number;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->der=NULL;
	
	if(aux2->raiz==NULL){
    aux2->raiz=nuevo_nodo;
    aux2->peso++;
    aux2->altura++;
	}else{
	NODO *p_aux, *p_anterior;
	p_anterior=NULL;
	p_aux = aux2->raiz;
	
	while(p_aux!=NULL){
    p_anterior = p_aux;
    if(number<p_aux->numero){
        p_aux=p_aux->izq;
    }else{
    p_aux=p_aux->der;
    }
    alt++;

    
	}
	if(number<p_anterior->numero){
	    p_anterior->izq=nuevo_nodo;
	}else{
	    p_anterior->der=nuevo_nodo;
	}
	aux2->peso++;
	printf("Nodo derecho: %d \n", p_anterior->der);
	printf("Nodo izquierdo: %d \n", p_anterior->izq);
	aux2->altura=alt;
	printf("Altura: %d \n", alt);
	printf("Peso: %d \n", aux2->peso);
	}

	return;
}


void recorrer_preorden(NODO *nodo){
	if(nodo!=NULL){
    printf(" %d \n",nodo->numero);
    recorrer_preorden(nodo->izq);
    recorrer_preorden(nodo->der);
    }
	return;
}

void recorrer_inorden(NODO *nodo){
	if(nodo!=NULL){
    recorrer_inorden(nodo->izq);
    printf(" %d \n",nodo->numero);
    recorrer_inorden(nodo->der);
    }
	return;
}

void recorrer_postorden(NODO *nodo){
	if(nodo!=NULL){
    recorrer_postorden(nodo->izq);
    recorrer_postorden(nodo->der);
    printf(" %d\n",nodo->numero);
   }
	return;
}

void recorrer_amplitud(NODO *nodo){
	if(nodo!=NULL){
		
   }
}

