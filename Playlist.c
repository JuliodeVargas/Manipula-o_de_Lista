#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    char musica[100];  
    struct No *prox;   
    struct No *ant;    
} No;

void copiarStringManual(char *destino, const char *origem) {
    int i = 0;
    while (origem[i] != '\0' && i < 99) {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

void adicionarMusica(No **head, char *nome) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;

    copiarStringManual(novo->musica, nome);

    if (*head == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = *head;
    (*head)->ant = novo;
}

void proximaMusica(No **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->prox;
    }
}

void musicaAnterior(No **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->ant;
    }
}

void exibirPlaylist(No *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *temp = head;
    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;
    } while (temp != head); 

    printf("(volta ao inicio)\n");
}

int totalMusicas(No *head) {
    if (head == NULL) return 0;

    int total = 0;
    No *temp = head;
    do {
        total++;
        temp = temp->prox;
    } while (temp != head);

    return total;
}

void liberarPlaylist(No **head) {
    if (*head == NULL) return;

    No *atual = (*head)->prox;
    while (atual != *head) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

int main() {
    No *playlist = NULL;

    printf("--- Atividade 5 ---\n");
    adicionarMusica(&playlist, "Yung Li");
    adicionarMusica(&playlist, "AC/DC");
    adicionarMusica(&playlist, "LemonSoda");
    adicionarMusica(&playlist, "Charlie Brow JR.");
    adicionarMusica(&playlist, "Projeto Sola");
    adicionarMusica(&playlist, "godzilla");

    exibirPlaylist(playlist);
    printf("Total de musicas: %d\n\n", totalMusicas(playlist));


    No *atual = playlist;
    printf("Tocando agora: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Cliquei em Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Cliquei em Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Cliquei em Proxima (Loop Circular completo!): %s\n", atual->musica);

    musicaAnterior(&atual);
    printf("Cliquei em Voltar: %s\n", atual->musica);

    liberarPlaylist(&playlist);
    return 0;
}