#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *izq;
    struct Nodo *der;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
    struct Nodo* nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Función para insertar un nodo en el árbol binario
struct Nodo* insertar(struct Nodo* nodo, int valor) {
    if (nodo == NULL) {
        return crearNodo(valor);
    } else {
        if (valor < nodo->valor) {
            nodo->izq = insertar(nodo->izq, valor);
        } else {
            nodo->der = insertar(nodo->der, valor);
        }
        return nodo;
    }
}

// Función para buscar el nodo padre de un valor dado
struct Nodo* buscarPadre(struct Nodo* nodo, int valor) {
    if (nodo == NULL || nodo->valor == valor) {
        return NULL;
    } else {
        if ((nodo->izq != NULL && nodo->izq->valor == valor) || (nodo->der != NULL && nodo->der->valor == valor)) {
            return nodo;
        } else {
            struct Nodo* izq = buscarPadre(nodo->izq, valor);
            if (izq != NULL) {
                return izq;
            } else {
                return buscarPadre(nodo->der, valor);
            }
        }
    }
}

// Función para buscar el nodo hermano de un valor dado
struct Nodo* buscarHermano(struct Nodo* nodo, int valor) {
    struct Nodo* padre = buscarPadre(nodo, valor);
    if (padre == NULL) {
        return NULL;
    } else {
        if (padre->izq != NULL && padre->izq->valor == valor && padre->der != NULL) {
            return padre->der;
        } else if (padre->der != NULL && padre->der->valor == valor && padre->izq != NULL) {
            return padre->izq;
        } else {
            return NULL;
        }
    }
}

// Función principal
int main() {
    int n, valor, i;
    struct Nodo* raiz = NULL;

    // Pedir el número de nodos
    printf("Ingrese el número de nodos: ");
    scanf("%d", &n);

    // Pedir los valores de los nodos y agregarlos al árbol
    printf("Ingrese los valores de los nodos:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        raiz = insertar(raiz, valor);
    }

    // Pedir un valor para buscar su padre y su hermano
    printf("Ingrese un valor para buscar su padre y su hermano: ");
    scanf("%d", &valor);

    // Buscar el padre y el hermano del valor dado
    struct Nodo* padre = buscarPadre(raiz, valor);
    struct Nodo* hermano = buscarHermano(raiz, valor);

    // Mostrar el resultado
    printf("El padre de %d es ", valor);
    if (padre == NULL) {
