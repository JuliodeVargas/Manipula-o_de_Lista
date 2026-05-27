#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;


void inverterLista(No **head) {
    No *anterior = NULL;
    No *atual = *head;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox; 
        atual->prox = anterior; 
        
        anterior = atual;       
        atual = proximo;       
    }

    *head = anterior; 
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

    printf("--- Atividade 3 ---\n");
    printf("Lista antes da inversao: ");
    exibirLista(lista);

    inverterLista(&lista);

    printf("Lista depois da inversao: ");
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}