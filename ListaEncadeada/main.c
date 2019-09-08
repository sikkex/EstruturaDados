#include "lista_encadeada.h"

TLista* cria_lista (void) {
    return NULL;
}

TLista* insere_inicio (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) { /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}

TLista* insere_ordenado (TLista* li, int i) {
    TLista* novo;
    TLista* ant = NULL; /* ponteiro para elemento anterior */
    TLista* p = li; /* ponteiro para percorrer a lista */
    /* procura posição de inserção */
    while (p != NULL && p->info < i) {
        ant = p;
        p = p->prox;
    }
    /* cria novo elemento */
    novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    /* encadeia elemento */
    if (ant == NULL) { /* insere elemento no início */
        novo->prox = li; li = novo;
    }
    else { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return li;
}

void imprime_lista (TLista* li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

TLista* altera(TLista* li, int vantigo, int vnovo){
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = vnovo;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) { /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}
TLista* exclui(TLista* li, int i){
    TLista* novo = cria_lista();
    TLista* ant = NULL;
    TLista* p = li;
    while (p != NULL && p->info != i){
        printf("1");
        ant = p;
        p = p->prox;
    }
    if (p != NULL) {
        printf("2");
        if (ant == NULL) {
            printf("3");
            li = p->prox;
        } else{
            printf("4");
            ant->prox = p->prox;
        }
        free(p);
    }
    novo = li;
    return novo;
}

int main (void) {
    TLista* l1;
    TLista* l2;
    TLista* l3; /* declara listas não inicializadas */
    /* Insere elementos no inicio da lista */
    l1 = cria_lista(); /* cria e inicializa lista como vazia */
    l1 = insere_inicio(l1, 2);
    l1 = insere_inicio(l1, 3);
    l1 = insere_inicio(l1, 5);
    l1 = insere_inicio(l1, 4);
    l1 = exclui(l1, 4);


    printf("Lista 1:\n");
    imprime_lista(l1);
    printf("\n");


    imprime_lista(l1);
    printf("\n");

    /* Insere elementos no final da lista*/
    l2 = cria_lista(); /* cria e inicializa lista como vazia */
    l2 = insere_fim(l2, 2);
    l2 = insere_fim(l2, 3);
    l2 = insere_fim(l2, 5);
    l2 = insere_fim(l2, 4);
    printf("Lista 2:\n");
    imprime_lista(l2);
    printf("\n");

    /* Insere elementos de forma que a lista esteja sempre ordenada */
    l3 = cria_lista(); /* cria e inicializa lista como vazia */
    l3 = insere_ordenado(l3, 2);
    l3 = insere_ordenado(l3, 5);
    l3 = insere_ordenado(l3, 3);
    l3 = insere_ordenado(l3, 4);
    l3 = insere_ordenado(l3, 1);
    printf("Lista 3:\n");
    imprime_lista(l3);
    printf("\n");

    return 0;
}

