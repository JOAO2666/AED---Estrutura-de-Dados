/*
	Origem preservada: MEGA-C-DIGO-DE-ESTRUTURA-DE-DADOS---LISTAS
	Commit: f0febb67ad38e1bd910d45cd85dca876d778b6a8

	============================================================================
	MEGA CÓDIGO DE ESTRUTURA DE DADOS - LISTAS
	============================================================================
	Implementação de diversos tipos de listas em C, baseado nos conceitos
	de Algoritmos e Estrutura de Dados.

	Funcionalidades:
		- Menu interativo para testar cada tipo de lista.
		- Implementações completas com operações de criar, inserir, remover,
		  buscar, listar, etc.

	Tipos de Listas Implementadas:
		1. Lista Sequencial (Array)
		2. Lista Simplesmente Encadeada
		3. Lista Circular Simplesmente Encadeada
		4. Lista Duplamente Encadeada
		5. Lista Circular Dupl1amente Encadeada
	============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Para facilitar a leitura, cada tipo de lista terá seu próprio bloco de código.

//===========================================================================
// 1. LISTA SEQUENCIAL (BASEADA EM ARRAY)
//===========================================================================
#define MAX_ELEMENTOS 50

typedef struct {
    int dados[MAX_ELEMENTOS];
    int quantidade; // Controla o número de elementos na lista
} ListaSequencial;

// Protótipos - Lista Sequencial
void seq_inicializar(ListaSequencial *lista);
int seq_esta_cheia(ListaSequencial *lista);
int seq_esta_vazia(ListaSequencial *lista);
int seq_tamanho(ListaSequencial *lista);
void seq_imprimir(ListaSequencial *lista);
int seq_inserir(ListaSequencial *lista, int valor, int posicao);
int seq_remover(ListaSequencial *lista, int posicao);
int seq_buscar(ListaSequencial *lista, int valor);

// Implementações - Lista Sequencial

void seq_inicializar(ListaSequencial *lista) {
    lista->quantidade = 0;
}

int seq_esta_cheia(ListaSequencial *lista) {
    return (lista->quantidade == MAX_ELEMENTOS);
}

int seq_esta_vazia(ListaSequencial *lista) {
    return (lista->quantidade == 0);
}

int seq_tamanho(ListaSequencial *lista) {
    return lista->quantidade;
}

void seq_imprimir(ListaSequencial *lista) {
    if (seq_esta_vazia(lista)) {
        printf("Lista Sequencial vazia!\n");
        return;
    }
    printf("Elementos da Lista Sequencial: [ ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("]\n");
}

int seq_inserir(ListaSequencial *lista, int valor, int posicao) {
    if (seq_esta_cheia(lista)) {
        printf("Erro: Lista cheia!\n");
        return 0; // Falha
    }
    if (posicao < 1 || posicao > lista->quantidade + 1) {
        printf("Erro: Posicao de insercao invalida!\n");
        return 0; // Falha
    }

    // Desloca os elementos para a direita para abrir espaço
    for (int i = lista->quantidade; i >= posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao - 1] = valor;
    lista->quantidade++;
    return 1; // Sucesso
}

int seq_remover(ListaSequencial *lista, int posicao) {
    if (seq_esta_vazia(lista)) {
        printf("Erro: Lista vazia!\n");
        return 0; // Falha
    }
    if (posicao < 1 || posicao > lista->quantidade) {
        printf("Erro: Posicao de remocao invalida!\n");
        return 0; // Falha
    }

    // Desloca os elementos para a esquerda para fechar o espaço
    for (int i = posicao - 1; i < lista->quantidade - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->quantidade--;
    return 1; // Sucesso
}

int seq_buscar(ListaSequencial *lista, int valor) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->dados[i] == valor) {
            return i + 1; // Retorna a posição (base 1)
        }
    }
    return -1; // Não encontrado
}

//===========================================================================
// 2. LISTA SIMPLESMENTE ENCADEADA
//===========================================================================
typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

// Protótipos - Lista Simplesmente Encadeada
void sll_inicializar(NoSimples **cabeca);
int sll_esta_vazia(NoSimples *cabeca);
void sll_imprimir(NoSimples *cabeca);
void sll_inserir_final(NoSimples **cabeca, int valor);
int sll_remover(NoSimples **cabeca, int valor);
NoSimples* sll_buscar(NoSimples *cabeca, int valor);
int sll_tamanho(NoSimples *cabeca);
void sll_destruir(NoSimples **cabeca);

// Implementações - Lista Simplesmente Encadeada

void sll_inicializar(NoSimples **cabeca) {
    *cabeca = NULL;
}

int sll_esta_vazia(NoSimples *cabeca) {
    return (cabeca == NULL);
}

void sll_imprimir(NoSimples *cabeca) {
    if (sll_esta_vazia(cabeca)) {
        printf("Lista Simplesmente Encadeada vazia!\n");
        return;
    }
    printf("Elementos da Lista Simplesmente Encadeada: [ ");
    NoSimples *aux = cabeca;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL ]\n");
}

void sll_inserir_final(NoSimples **cabeca, int valor) {
    NoSimples *novo = (NoSimples*)malloc(sizeof(NoSimples));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (sll_esta_vazia(*cabeca)) {
        *cabeca = novo;
    } else {
        NoSimples *aux = *cabeca;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int sll_remover(NoSimples **cabeca, int valor) {
    if (sll_esta_vazia(*cabeca)) return 0;

    NoSimples *corrente = *cabeca;
    NoSimples *anterior = NULL;

    while (corrente != NULL && corrente->valor != valor) {
        anterior = corrente;
        corrente = corrente->prox;
    }

    if (corrente == NULL) return 0; // Não encontrado

    if (anterior == NULL) { // Remove o primeiro elemento
        *cabeca = corrente->prox;
    } else {
        anterior->prox = corrente->prox;
    }
    free(corrente);
    return 1;
}

NoSimples* sll_buscar(NoSimples *cabeca, int valor) {
    NoSimples *aux = cabeca;
    while(aux != NULL) {
        if(aux->valor == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

int sll_tamanho(NoSimples *cabeca) {
    int tam = 0;
    NoSimples *aux = cabeca;
    while(aux != NULL) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void sll_destruir(NoSimples **cabeca) {
    NoSimples *corrente = *cabeca;
    NoSimples *proximo;
    while(corrente != NULL) {
        proximo = corrente->prox;
        free(corrente);
        corrente = proximo;
    }
    *cabeca = NULL;
}


//===========================================================================
// 3. LISTA CIRCULAR SIMPLESMENTE ENCADEADA
//===========================================================================
// Usaremos a mesma struct NoSimples
// A referência da lista será para o *último* elemento, para acesso O(1) à cauda e à cabeça
typedef NoSimples* ListaCircular;

// Protótipos - Lista Circular
void slcl_inicializar(ListaCircular *lista);
int slcl_esta_vazia(ListaCircular lista);
void slcl_imprimir(ListaCircular lista);
void slcl_inserir_final(ListaCircular *lista, int valor);
int slcl_remover(ListaCircular *lista, int valor);
int slcl_tamanho(ListaCircular lista);
void slcl_destruir(ListaCircular *lista);

// Implementações - Lista Circular

void slcl_inicializar(ListaCircular *lista) {
    *lista = NULL;
}

int slcl_esta_vazia(ListaCircular lista) {
    return (lista == NULL);
}

void slcl_imprimir(ListaCircular lista) {
    if (slcl_esta_vazia(lista)) {
        printf("Lista Circular Simplesmente Encadeada vazia!\n");
        return;
    }
    printf("Elementos da Lista Circular: [ ");
    NoSimples *aux = lista->prox; // Começa da cabeça
    do {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    } while (aux != lista->prox);
    printf(" (volta para %d) ]\n", lista->prox->valor);
}

void slcl_inserir_final(ListaCircular *lista, int valor) {
    NoSimples *novo = (NoSimples*)malloc(sizeof(NoSimples));
    if (!novo) return;
    novo->valor = valor;

    if (slcl_esta_vazia(*lista)) {
        *lista = novo;
        novo->prox = novo; // Aponta para si mesmo
    } else {
        novo->prox = (*lista)->prox; // O próximo do novo aponta para a antiga cabeça
        (*lista)->prox = novo;      // O próximo do antigo último aponta para o novo
        *lista = novo;              // A lista agora aponta para o novo último
    }
}

int slcl_remover(ListaCircular *lista, int valor) {
    if (slcl_esta_vazia(*lista)) return 0;

    NoSimples *corrente = (*lista)->prox; // cabeça
    NoSimples *anterior = *lista;

    do {
        if (corrente->valor == valor) {
            if (corrente == anterior) { // Único elemento
                *lista = NULL;
            } else {
                anterior->prox = corrente->prox;
                if (corrente == *lista) { // Removendo o último
                    *lista = anterior;
                }
            }
            free(corrente);
            return 1;
        }
        anterior = corrente;
        corrente = corrente->prox;
    } while (corrente != (*lista)->prox);

    return 0; // Não encontrado
}

int slcl_tamanho(ListaCircular lista) {
    if(slcl_esta_vazia(lista)) return 0;

    int tam = 0;
    NoSimples *aux = lista->prox;
    do {
        tam++;
        aux = aux->prox;
    } while (aux != lista->prox);
    return tam;
}

void slcl_destruir(ListaCircular *lista) {
    if (slcl_esta_vazia(*lista)) return;

    NoSimples *corrente = (*lista)->prox;
    NoSimples *proximo;

    // Quebra o ciclo para tratar como uma lista linear simples
    (*lista)->prox = NULL;

    while(corrente != NULL) {
        proximo = corrente->prox;
        free(corrente);
        corrente = proximo;
    }
    *lista = NULL;
}


//===========================================================================
// 4. LISTA DUPLAMENTE ENCADEADA
//===========================================================================
typedef struct NoDuplo {
    int valor;
    struct NoDuplo *prox;
    struct NoDuplo *ant;
} NoDuplo;

// Protótipos - Lista Duplamente Encadeada
void dll_inicializar(NoDuplo **cabeca);
int dll_esta_vazia(NoDuplo *cabeca);
void dll_imprimir(NoDuplo *cabeca);
void dll_inserir_final(NoDuplo **cabeca, int valor);
int dll_remover(NoDuplo **cabeca, int valor);
int dll_tamanho(NoDuplo *cabeca);
void dll_destruir(NoDuplo **cabeca);

// Implementações - Lista Duplamente Encadeada

void dll_inicializar(NoDuplo **cabeca) {
    *cabeca = NULL;
}

int dll_esta_vazia(NoDuplo *cabeca) {
    return (cabeca == NULL);
}

void dll_imprimir(NoDuplo *cabeca) {
    if (dll_esta_vazia(cabeca)) {
        printf("Lista Duplamente Encadeada vazia!\n");
        return;
    }
    printf("Elementos da Lista Duplamente Encadeada: [ NULL <=> ");
    NoDuplo *aux = cabeca;
    while (aux != NULL) {
        printf("%d <=> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL ]\n");
}

void dll_inserir_final(NoDuplo **cabeca, int valor) {
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if (!novo) return;
    novo->valor = valor;
    novo->prox = NULL;

    if(dll_esta_vazia(*cabeca)) {
        novo->ant = NULL;
        *cabeca = novo;
    } else {
        NoDuplo *aux = *cabeca;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
}

int dll_remover(NoDuplo **cabeca, int valor) {
    if (dll_esta_vazia(*cabeca)) return 0;

    NoDuplo *aux = *cabeca;
    while(aux != NULL && aux->valor != valor) {
        aux = aux->prox;
    }

    if (aux == NULL) return 0; // Não encontrado

    if (aux->ant == NULL) { // É o primeiro
        *cabeca = aux->prox;
        if (*cabeca != NULL) {
            (*cabeca)->ant = NULL;
        }
    } else {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }
    }
    free(aux);
    return 1;
}

int dll_tamanho(NoDuplo *cabeca) {
    int tam = 0;
    NoDuplo *aux = cabeca;
    while(aux != NULL) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void dll_destruir(NoDuplo **cabeca) {
    NoDuplo *corrente = *cabeca;
    NoDuplo *proximo;
    while(corrente != NULL) {
        proximo = corrente->prox;
        free(corrente);
        corrente = proximo;
    }
    *cabeca = NULL;
}


//===========================================================================
// 5. LISTA CIRCULAR DUPLAMENTE ENCADEADA
//===========================================================================
// Usaremos a mesma struct NoDuplo
typedef NoDuplo* ListaCircDupla;

// Protótipos - Lista Circular Duplamente Encadeada
void dlcl_inicializar(ListaCircDupla *cabeca);
int dlcl_esta_vazia(ListaCircDupla cabeca);
void dlcl_imprimir(ListaCircDupla cabeca);
void dlcl_inserir_final(ListaCircDupla *cabeca, int valor);
int dlcl_remover(ListaCircDupla *cabeca, int valor);
void dlcl_destruir(ListaCircDupla *cabeca);

// Implementações - Lista Circular Duplamente Encadeada

void dlcl_inicializar(ListaCircDupla *cabeca) {
    *cabeca = NULL;
}

int dlcl_esta_vazia(ListaCircDupla cabeca) {
    return (cabeca == NULL);
}

void dlcl_imprimir(ListaCircDupla cabeca) {
    if (dlcl_esta_vazia(cabeca)) {
        printf("Lista Circular Duplamente Encadeada vazia!\n");
        return;
    }
    printf("Elementos da Lista Circular Dupla: [ ...<=> ");
    NoDuplo *aux = cabeca;
    do {
        printf("%d <=> ", aux->valor);
        aux = aux->prox;
    } while (aux != cabeca);
    printf("... (volta para %d) ]\n", cabeca->valor);
}

void dlcl_inserir_final(ListaCircDupla *cabeca, int valor) {
    NoDuplo *novo = (NoDuplo*)malloc(sizeof(NoDuplo));
    if(!novo) return;
    novo->valor = valor;

    if(dlcl_esta_vazia(*cabeca)) {
        *cabeca = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        NoDuplo *ultimo = (*cabeca)->ant;

        novo->prox = *cabeca;
        (*cabeca)->ant = novo;
        novo->ant = ultimo;
        ultimo->prox = novo;
    }
}

int dlcl_remover(ListaCircDupla *cabeca, int valor) {
    if (dlcl_esta_vazia(*cabeca)) return 0;

    NoDuplo *aux = *cabeca;
    do {
        if(aux->valor == valor) {
            if(aux->prox == aux) { // Único elemento
                *cabeca = NULL;
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                if (aux == *cabeca) { // Removendo a cabeça
                    *cabeca = aux->prox;
                }
            }
            free(aux);
            return 1;
        }
        aux = aux->prox;
    } while (aux != *cabeca);

    return 0; // Não encontrado
}

void dlcl_destruir(ListaCircDupla *cabeca) {
    if (dlcl_esta_vazia(*cabeca)) return;

    NoDuplo *ultimo = (*cabeca)->ant;
    ultimo->prox = NULL; // Quebra o ciclo

    NoDuplo *corrente = *cabeca;
    NoDuplo *proximo;
    while(corrente != NULL) {
        proximo = corrente->prox;
        free(corrente);
        corrente = proximo;
    }
    *cabeca = NULL;
}


//===========================================================================
// FUNÇÕES DE TESTE E MENU PRINCIPAL
//===========================================================================

void testar_lista_sequencial() {
    ListaSequencial lista;
    seq_inicializar(&lista);
    printf("\n--- Testando Lista Sequencial ---\n");
    seq_imprimir(&lista);
    seq_inserir(&lista, 10, 1);
    seq_inserir(&lista, 20, 2);
    seq_inserir(&lista, 30, 3);
    seq_imprimir(&lista);
    printf("Tamanho: %d\n", seq_tamanho(&lista));
    seq_inserir(&lista, 25, 3); // Inserir no meio
    seq_imprimir(&lista);
    int pos = seq_buscar(&lista, 20);
    if(pos != -1) printf("Valor 20 encontrado na posicao %d\n", pos);
    seq_remover(&lista, 2); // Remover o 20
    printf("Apos remover o elemento da posicao 2:\n");
    seq_imprimir(&lista);
    printf("Tamanho: %d\n", seq_tamanho(&lista));
    printf("----------------------------------\n");
}

void testar_lista_simples_encadeada() {
    NoSimples *lista = NULL;
    printf("\n--- Testando Lista Simplesmente Encadeada ---\n");
    sll_imprimir(lista);
    sll_inserir_final(&lista, 100);
    sll_inserir_final(&lista, 200);
    sll_inserir_final(&lista, 300);
    sll_imprimir(lista);
    printf("Tamanho: %d\n", sll_tamanho(lista));
    if(sll_buscar(lista, 200)) printf("Valor 200 encontrado!\n");
    sll_remover(&lista, 200);
    printf("Apos remover o valor 200:\n");
    sll_imprimir(lista);
    sll_remover(&lista, 100); // Remover cabeça
    sll_remover(&lista, 300); // Remover cauda
    printf("Apos remover todos:\n");
    sll_imprimir(lista);
    sll_destruir(&lista);
    printf("----------------------------------\n");
}

void testar_lista_circular() {
    ListaCircular lista = NULL;
    printf("\n--- Testando Lista Circular Simplesmente Encadeada ---\n");
    slcl_imprimir(lista);
    slcl_inserir_final(&lista, 11);
    slcl_inserir_final(&lista, 22);
    slcl_inserir_final(&lista, 33);
    slcl_imprimir(lista);
    printf("Tamanho: %d\n", slcl_tamanho(lista));
    slcl_remover(&lista, 22);
    printf("Apos remover o 22:\n");
    slcl_imprimir(lista);
    slcl_remover(&lista, 33); // Remover último
    printf("Apos remover o 33 (ultimo):\n");
    slcl_imprimir(lista);
    slcl_destruir(&lista);
    printf("----------------------------------\n");
}

void testar_lista_duplamente_encadeada() {
    NoDuplo *lista = NULL;
    printf("\n--- Testando Lista Duplamente Encadeada ---\n");
    dll_imprimir(lista);
    dll_inserir_final(&lista, 15);
    dll_inserir_final(&lista, 25);
    dll_inserir_final(&lista, 35);
    dll_imprimir(lista);
    printf("Tamanho: %d\n", dll_tamanho(lista));
    dll_remover(&lista, 25);
    printf("Apos remover 25:\n");
    dll_imprimir(lista);
    dll_remover(&lista, 15); // Remover cabeça
    printf("Apos remover 15 (cabeca):\n");
    dll_imprimir(lista);
    dll_destruir(&lista);
    printf("----------------------------------\n");
}

void testar_lista_circular_dupla() {
    ListaCircDupla lista = NULL;
    printf("\n--- Testando Lista Circular Duplamente Encadeada ---\n");
    dlcl_imprimir(lista);
    dlcl_inserir_final(&lista, 101);
    dlcl_inserir_final(&lista, 202);
    dlcl_inserir_final(&lista, 303);
    dlcl_imprimir(lista);
    dlcl_remover(&lista, 202);
    printf("Apos remover 202:\n");
    dlcl_imprimir(lista);
    dlcl_remover(&lista, 101);
    printf("Apos remover 101 (cabeca):\n");
    dlcl_imprimir(lista);
    dlcl_destruir(&lista);
    printf("----------------------------------\n");
}


void exibir_menu() {
    printf("\n### MEGA CODIGO DE LISTAS ###\n");
    printf("1. Testar Lista Sequencial\n");
    printf("2. Testar Lista Simplesmente Encadeada\n");
    printf("3. Testar Lista Circular Simplesmente Encadeada\n");
    printf("4. Testar Lista Duplamente Encadeada\n");
    printf("5. Testar Lista Circular Duplamente Encadeada\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                testar_lista_sequencial();
                break;
            case 2:
                testar_lista_simples_encadeada();
                break;
            case 3:
                testar_lista_circular();
                break;
            case 4:
                testar_lista_duplamente_encadeada();
                break;
            case 5:
                testar_lista_circular_dupla();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
