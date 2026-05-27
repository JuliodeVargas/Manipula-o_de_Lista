#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserirPosicao(No **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Erro: Posicao invalida!\n");
        return;
    }

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;
    novo->valor = valor;

    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    No *atual = *head;
    int i = 0;

    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

   
    if (atual == NULL) {
        printf("Erro: Posicao invalida!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
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

    printf("--- Atividade 1 ---\n");
    inserirPosicao(&lista, 10, 0); 
    inserirPosicao(&lista, 20, 1); 
    inserirPosicao(&lista, 30, 2); 
    
    printf("Lista original: ");
    exibirLista(lista);

    printf("Inserindo 99 na posicao 1...\n");
    inserirPosicao(&lista, 99, 1); 
    exibirLista(lista);

    printf("Tentando inserir em posicao invalida (-1 e 10)...\n");
    inserirPosicao(&lista, 50, -1);
    inserirPosicao(&lista, 50, 10);

    liberarLista(&lista);
    return 0;
}