#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
}NODO;

typedef struct{
	NODO *raiz;
	int altura;
	int peso;
}ARBOL;

void agregar_a_arbol(ARBOL *, int);
void preorden(NODO *);
void inorden(NODO *);
void postorden(NODO *);
void amplitud(NODO *);

void agregar_a_arbol(ARBOL *aux2, int number){
	NODO *nuevo_nodo=NULL;
	int alt=1;
	nuevo_nodo=(NODO *) malloc(sizeof(NODO));
	if(nuevo_nodo==NULL){
    	printf("ERROR DE MEMORIA \n");
    	exit(1);
	}
	nuevo_nodo->dato=number;
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
    if(number<p_aux->dato){
        p_aux=p_aux->izq;
    }else{
    p_aux=p_aux->der;
    }
    alt++;
	}
	if(number<p_anterior->dato){
	    p_anterior->izq=nuevo_nodo;
	}else{
	    p_anterior->der=nuevo_nodo;
	}
	aux2->peso++;
	aux2->altura=alt;
	printf("Altura: %d \n", alt);
	printf("Peso: %d \n", aux2->peso);
	}
	return;
}
//Recorrido en pre-orden
void preorden(struct nodo *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
//Recorrido en in_orden
void inorden(struct nodo *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}
//Recorrido en post-orden
void postorden(struct nodo *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}
//Recorrido en amplitud
void amplitud(struct nodo *raiz) {
    if (raiz == NULL) {
        return;
    }
    struct nodo *cola[100];
    int inicio = 0, fin = 0;
    cola[fin++] = raiz;
    while (inicio != fin) {
        struct nodo *nodo_actual = cola[inicio++];
        printf("%d ", nodo_actual->dato);
        if (nodo_actual->izq != NULL) {
            cola[fin++] = nodo_actual->izq;
        }
        if (nodo_actual->der != NULL) {
            cola[fin++] = nodo_actual->der;
        }
    }
}
//izquierda(VALOR)
int izquierda(struct nodo *nodo_actual) {
    if (nodo_actual->izq != NULL) {
        return nodo_actual->izq->dato;
    } else {
        return -1; 
    }
}
//derecha(VALOR)
int derecha(struct nodo *nodo_actual) {
    if (nodo_actual->der != NULL) {
        return nodo_actual->der->dato;
    } else {
        return -1; 
    }
}

int main() {
	system("Title Recorridos Arboles");
	ARBOL *arbol=NULL;
	int number;
	arbol=(ARBOL *) malloc(sizeof(ARBOL));
	arbol->raiz=NULL;
	arbol->altura=0;
	arbol->peso=0;
	do{
    printf("Introduce una numero: (0 para cancelar)\n");
    scanf("%d",&number);
    system("cls");
    if(number!=0){
        agregar_a_arbol(arbol,number);
    }
}while(number!=0);
	
    printf("Recorrido en Pre-orden: ");
    preorden(arbol->raiz);
    printf("\nRecorrido en Post-orden: ");
    postorden(arbol->raiz);
    printf("\nRecorrido en In-orden: ");
    inorden(arbol->raiz);
    printf("\nRecorrido en Amplitud: ");
    amplitud(arbol->raiz);
    printf("Valor del nodo a la izquierda: %d\n" );
	izquierda(arbol->raiz->izq);
    printf("Valor del nodo a la derecha: %d\n");
	derecha(arbol->raiz->der);
	
	return;
}
