#include "filas-listas.h"

TFila *inicializa(void){
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(TFila *f){
    if (f->inicio == NULL) {
        return 1;
    }
    else return 0;
}

void insere(TFila *f, int elem){
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; //inserção no fim da fila
    if (!fila_vazia(f)){
        f->fim->prox = novo;
    }
    else{
        f->inicio = novo;
    }
    f->fim = novo; //elemento inserido é o novo fim da fila
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira(TFila *f){
    if (fila_vazia(f)){
        exit(1);
    }
    int info = f->inicio->info;

    TLista *aux = f->inicio;
    f->inicio=f->inicio->prox;
    //se elemento removido era o único da fila
    //faz fim apontar para NULL também
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void libera(TFila *f){
    TLista *q, *p = f->inicio;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(f);
}


void imprime_fila(TFila *f){
    TFila* nova = inicializa();
    TLista* aux = f->inicio;
    while(aux->prox != NULL){
        insere(nova, aux->info);
        int x = retira(nova);
        printf("%d ", x);
        aux = aux->prox;
    }
    insere(nova, aux->info);
    int x = retira(nova);
    printf("%d", x);
}

/**
* Altera o inicio da fila
*/
void altera_inicio_fila(TFila *f, int novo){
    TFila* aux = inicializa();
    insere(aux, novo);
    aux->inicio->prox = f->inicio;
    f->inicio = aux->inicio;
    free(aux);
}

int main() {
    TFila *fila = inicializa();
    insere(fila, 5);
    insere(fila, 3);
    insere(fila, 2);


    imprime_fila(fila);
    int x = retira(fila);
    altera_inicio_fila(fila, 9);
    altera_inicio_fila(fila, 6);
    printf("\nelemento %d retirado da fila\n", x);
    imprime_fila(fila);
    libera(fila);

    return 0;
}
