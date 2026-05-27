#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void dividirLista(No *head, No **lista1, No **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head->prox;


    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }


    *lista1 = head;
    *lista2 = lento->prox;


    lento->prox = NULL;
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

void exibirLista(No *head) {
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }
    printf("NULL\n");
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
    inserirNoFim(&lista, 40);
    inserirNoFim(&lista, 50);

    printf("--- Atividade 4 ---\n");
    printf("Lista Completa: ");
    exibirLista(lista);

    No *lista1 = NULL;
    No *lista2 = NULL;

    dividirLista(lista, &lista1, &lista2);

    printf("Lista 1 (Metade Inicial): ");
    exibirLista(lista1);
    printf("Lista 2 (Metade Final): ");
    exibirLista(lista2);

    
    liberarLista(&lista1);
    liberarLista(&lista2);
    return 0;
}