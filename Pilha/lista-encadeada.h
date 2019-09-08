#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* cria_lista (void);
TLista* insere_inicio (TLista* li, int i);
TLista* insere_fim (TLista* li, int i);
TLista* insere_ordenado (TLista* li, int i);
void imprime_lista(TLista *li);
TLista* altera(TLista* li, int vantigo, int vnovo);
TLista* exclui(TLista* li, int i);

