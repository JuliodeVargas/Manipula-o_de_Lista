#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;


int buscarValor(No *head, int valor) {
    int posicao = 0;

    while (head != NULL) {
        if (head->valor == valor) {
            return posicao; 
        }
        head = head->prox;
        posicao++;
    }

    return -1; 
}


void inserirNoFim(No **head, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->prox = NULL;

    if (*head == NULL) {
        *head = novo;
        return;
    }
    No *atual = *head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

void liberarLista(No **head) {
    No *atual = *head;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *head = NULL;
}

int main() {
    No *lista = NULL;
    inserirNoFim(&lista, 10);
    inserirNoFim(&lista, 20);
    inserirNoFim(&lista, 30);

    printf("--- Atividade 2 ---\n");
    printf("Buscando o valor 20: Posicao %d\n", buscarValor(lista, 20)); 
    printf("Buscando o valor 50: Posicao %d\n", buscarValor(lista, 50)); 

    liberarLista(&lista);
    return 0;
}