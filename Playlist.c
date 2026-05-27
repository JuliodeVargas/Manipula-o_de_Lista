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

    adicionarMusica(&playlist, "Yung Li");
    adicionarMusica(&playlist, "AC/DC");
    adicionarMusica(&playlist, "LemonSoda");
    adicionarMusica(&playlist, "Charlie Brow JR.");
    adicionarMusica(&playlist, "Projeto Sola");
    adicionarMusica(&playlist, "godzilla");

    printf("--- Atividade 5 ---\n");
    printf("Playlist carregada: ");
    exibirPlaylist(playlist);
    printf("Total de musicas: %d\n", totalMusicas(playlist));
    printf("--------------------------------------\n");

    No *atual = playlist; 
    int comando = -1;

    while (comando != 0) {
        printf("\n Tocando agora: %s \n", atual->musica);
        printf("1 - Proxima musica (->)\n");
        printf("2 - Musica anterior (<-)\n");
        printf("0 - Sair do player\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &comando);

        if (comando == 1) {
            proximaMusica(&atual);
            printf(">> Avancando...\n");
        } else if (comando == 2) {
            musicaAnterior(&atual);
            printf("<< Voltando...\n");
        } else if (comando == 0) {
            printf("Fechando o player. Ate mais!\n");
        } else {
            printf("Opcao invalida!\n");
        }
    }

    liberarPlaylist(&playlist);
    return 0;
}
