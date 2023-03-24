#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz=NULL;
void insertar(int x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        struct nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (x < reco->dato)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (x < anterior->dato)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

void Pre_orden(struct nodo *reco)
{
    if (reco != NULL)
    {
        printf("%i,",reco->dato);
        Pre_orden(reco->izq);
        Pre_orden(reco->der);
    }
}

void Post_orden(struct nodo *reco)
{
    if (reco != NULL)
    {
        Post_orden(reco->izq);
        Post_orden(reco->der);
        printf("%i,",reco->dato);
    }
}

void In_orden(struct nodo *reco)
{
    if (reco != NULL)
    {
        In_orden(reco->izq);
        printf("%i,",reco->dato);
        In_orden(reco->der);
    }
}

void borrar(struct nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        free(reco);
    }
}

int main()
{;
    insertar(100);
    insertar(50);
    insertar(25);
    insertar(75);
    insertar(150);
    printf("Impresion pre-orden: ");
    Pre_orden(raiz);
    printf("\nImpresion post-orden: ");
    Post_orden(raiz);
    printf("\nImpresion in-orden: ");
    In_orden(raiz);
    borrar(raiz);
    getch();
    return 0;
}
