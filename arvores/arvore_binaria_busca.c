#include <stdio.h>  // Biblioteca para funções de entrada e saída
#include <stdlib.h> // Biblioteca para alocação dinâmica de memória

// Estrutura que representa um nó da árvore binária de busca
typedef struct No {
    int valor;           // Valor armazenado no nó
    struct No* esquerda; // Ponteiro para o filho à esquerda
    struct No* direita;  // Ponteiro para o filho à direita
} No;

// Estrutura que representa uma fila para o percurso em largura
typedef struct NoFila {
    No* no;              // Ponteiro para o nó da árvore
    struct NoFila* prox; // Ponteiro para o próximo elemento da fila
} NoFila;

// Estrutura da fila
typedef struct Fila {
    NoFila* frente; // Ponteiro para o primeiro elemento da fila
    NoFila* tras;   // Ponteiro para o último elemento da fila
} Fila;

// Função para criar um novo nó da árvore
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
    if (novoNo == NULL) {                  // Verifica se a alocação foi bem-sucedida
        printf("Erro: Falha na alocação de memória\n");
        return NULL;
    }
    novoNo->valor = valor;     // Define o valor do nó
    novoNo->esquerda = NULL;   // Inicializa o ponteiro esquerdo como NULL
    novoNo->direita = NULL;    // Inicializa o ponteiro direito como NULL
    return novoNo;             // Retorna o ponteiro para o novo nó
}

// Função para inserir um valor na árvore binária de busca
No* inserir(No* raiz, int valor) {
    // Se a raiz é NULL (árvore vazia ou posição de inserção encontrada)
    if (raiz == NULL) {
        return criarNo(valor); // Cria e retorna um novo nó com o valor
    }
    
    // Se o valor a ser inserido é menor que o valor do nó atual
    if (valor < raiz->valor) {
        // Insere recursivamente na subárvore à esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // Se o valor a ser inserido é maior ou igual ao valor do nó atual
    else {
        // Insere recursivamente na subárvore à direita
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz; // Retorna a raiz (possivelmente modificada)
}

// Função para buscar um valor na árvore binária de busca
No* buscar(No* raiz, int valor) {
    // Se a raiz é NULL ou o valor foi encontrado
    if (raiz == NULL || raiz->valor == valor) {
        return raiz; // Retorna o nó encontrado ou NULL se não encontrado
    }
    
    // Se o valor buscado é menor que o valor do nó atual
    if (valor < raiz->valor) {
        // Busca recursivamente na subárvore à esquerda
        return buscar(raiz->esquerda, valor);
    }
    
    // Se o valor buscado é maior que o valor do nó atual
    // Busca recursivamente na subárvore à direita
    return buscar(raiz->direita, valor);
}

// Função para criar uma fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila)); // Aloca memória para a fila
    if (fila == NULL) {                       // Verifica se a alocação foi bem-sucedida
        printf("Erro: Falha na alocação de memória para a fila\n");
        return NULL;
    }
    fila->frente = NULL; // Inicializa o ponteiro da frente como NULL
    fila->tras = NULL;   // Inicializa o ponteiro de trás como NULL
    return fila;         // Retorna o ponteiro para a fila
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->frente == NULL; // Retorna 1 se vazia, 0 caso contrário
}

// Função para adicionar um nó à fila (enfileirar)
void enfileirar(Fila* fila, No* no) {
    NoFila* novoNoFila = (NoFila*)malloc(sizeof(NoFila)); // Aloca memória para o novo elemento da fila
    if (novoNoFila == NULL) {                             // Verifica se a alocação foi bem-sucedida
        printf("Erro: Falha na alocação de memória\n");
        return;
    }
    
    novoNoFila->no = no;     // Define o nó da árvore
    novoNoFila->prox = NULL; // O próximo elemento é NULL (será o último)
    
    // Se a fila está vazia
    if (filaVazia(fila)) {
        fila->frente = novoNoFila; // O novo elemento é tanto a frente quanto atrás
        fila->tras = novoNoFila;
    } else {
        fila->tras->prox = novoNoFila; // Liga o último elemento ao novo
        fila->tras = novoNoFila;       // Atualiza o ponteiro de trás
    }
}

// Função para remover um nó da fila (desenfileirar)
No* desenfileirar(Fila* fila) {
    // Se a fila está vazia
    if (filaVazia(fila)) {
        return NULL; // Retorna NULL
    }
    
    NoFila* temp = fila->frente;    // Armazena temporariamente o primeiro elemento
    No* no = temp->no;              // Obtém o nó da árvore
    fila->frente = fila->frente->prox; // Move a frente para o próximo elemento
    
    // Se a fila ficou vazia após a remoção
    if (fila->frente == NULL) {
        fila->tras = NULL; // Atualiza o ponteiro de trás para NULL
    }
    
    free(temp); // Libera a memória do elemento removido
    return no;  // Retorna o nó da árvore
}

// Função para realizar o percurso em largura (breadth-first traversal)
void percursoLargura(No* raiz) {
    // Se a árvore está vazia
    if (raiz == NULL) {
        printf("Árvore vazia\n");
        return;
    }
    
    Fila* fila = criarFila(); // Cria uma fila para armazenar os nós
    if (fila == NULL) {       // Verifica se a criação da fila foi bem-sucedida
        return;
    }
    
    enfileirar(fila, raiz); // Adiciona a raiz à fila
    
    printf("Percurso em largura: ");
    
    // Enquanto a fila não estiver vazia
    while (!filaVazia(fila)) {
        No* atual = desenfileirar(fila); // Remove o primeiro nó da fila
        printf("%d ", atual->valor);     // Visita o nó (imprime seu valor)
        
        // Se o nó tem filho à esquerda, adiciona-o à fila
        if (atual->esquerda != NULL) {
            enfileirar(fila, atual->esquerda);
        }
        
        // Se o nó tem filho à direita, adiciona-o à fila
        if (atual->direita != NULL) {
            enfileirar(fila, atual->direita);
        }
    }
    
    printf("\n");
    free(fila); // Libera a memória da fila
}

// Função para o percurso em profundidade - inordem (esquerda, raiz, direita)
void percursoInordem(No* raiz) {
    // Se o nó não é NULL
    if (raiz != NULL) {
        percursoInordem(raiz->esquerda); // Visita a subárvore à esquerda
        printf("%d ", raiz->valor);      // Visita a raiz (imprime o valor)
        percursoInordem(raiz->direita);  // Visita a subárvore à direita
    }
}

// Função para o percurso em profundidade - pré-ordem (raiz, esquerda, direita)
void percursoPreOrdem(No* raiz) {
    // Se o nó não é NULL
    if (raiz != NULL) {
        printf("%d ", raiz->valor);       // Visita a raiz (imprime o valor)
        percursoPreOrdem(raiz->esquerda); // Visita a subárvore à esquerda
        percursoPreOrdem(raiz->direita);  // Visita a subárvore à direita
    }
}

// Função para o percurso em profundidade - pós-ordem (esquerda, direita, raiz)
void percursoPosOrdem(No* raiz) {
    // Se o nó não é NULL
    if (raiz != NULL) {
        percursoPosOrdem(raiz->esquerda); // Visita a subárvore à esquerda
        percursoPosOrdem(raiz->direita);  // Visita a subárvore à direita
        printf("%d ", raiz->valor);       // Visita a raiz (imprime o valor)
    }
}

// Função para encontrar o menor valor na árvore (usado na remoção)
No* encontrarMinimo(No* raiz) {
    // Se a raiz é NULL
    if (raiz == NULL) {
        return NULL;
    }
    
    // Continua indo para a esquerda até encontrar o menor valor
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    
    return raiz; // Retorna o nó com o menor valor
}

// Função para remover um valor da árvore binária de busca
No* remover(No* raiz, int valor) {
    // Se a raiz é NULL (valor não encontrado)
    if (raiz == NULL) {
        return raiz;
    }
    
    // Se o valor a ser removido é menor que o valor do nó atual
    if (valor < raiz->valor) {
        // Remove recursivamente da subárvore à esquerda
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    // Se o valor a ser removido é maior que o valor do nó atual
    else if (valor > raiz->valor) {
        // Remove recursivamente da subárvore à direita
        raiz->direita = remover(raiz->direita, valor);
    }
    // Se o valor foi encontrado (valor == raiz->valor)
    else {
        // Caso 1: Nó sem filhos (folha)
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz); // Libera a memória do nó
            return NULL; // Retorna NULL para indicar que o nó foi removido
        }
        // Caso 2: Nó com apenas um filho à direita
        else if (raiz->esquerda == NULL) {
            No* temp = raiz->direita; // Armazena o filho à direita
            free(raiz);               // Libera a memória do nó
            return temp;              // Retorna o filho à direita
        }
        // Caso 3: Nó com apenas um filho à esquerda
        else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda; // Armazena o filho à esquerda
            free(raiz);                // Libera a memória do nó
            return temp;               // Retorna o filho à esquerda
        }
        // Caso 4: Nó com dois filhos
        else {
            // Encontra o sucessor inordem (menor valor na subárvore à direita)
            No* sucessor = encontrarMinimo(raiz->direita);
            
            // Substitui o valor do nó atual pelo valor do sucessor
            raiz->valor = sucessor->valor;
            
            // Remove o sucessor da subárvore à direita
            raiz->direita = remover(raiz->direita, sucessor->valor);
        }
    }
    
    return raiz; // Retorna a raiz (possivelmente modificada)
}

// Função para liberar toda a memória da árvore
void liberarArvore(No* raiz) {
    // Se o nó não é NULL
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda); // Libera recursivamente a subárvore à esquerda
        liberarArvore(raiz->direita);  // Libera recursivamente a subárvore à direita
        free(raiz);                    // Libera a memória do nó atual
    }
}

// Função principal para demonstrar o funcionamento da árvore binária de busca
int main() {
    No* raiz = NULL; // Inicializa a raiz da árvore como NULL (árvore vazia)
    
    // Demonstração da inserção de valores na árvore
    printf("=== ÁRVORE BINÁRIA DE BUSCA ===\n\n");
    printf("Inserindo valores: 13, 10, 25, 2, 12, 20, 31, 29\n");
    
    // Insere os valores na árvore seguindo a propriedade da árvore binária de busca
    raiz = inserir(raiz, 13); // Valor menor que 13 vai à esquerda, maior à direita
    raiz = inserir(raiz, 10); // 10 < 13, vai à esquerda de 13
    raiz = inserir(raiz, 25); // 25 > 13, vai à direita de 13
    raiz = inserir(raiz, 2);  // 2 < 13, vai à esquerda; 2 < 10, vai à esquerda de 10
    raiz = inserir(raiz, 12); // 12 < 13, vai à esquerda; 12 > 10, vai à direita de 10
    raiz = inserir(raiz, 20); // 20 > 13, vai à direita; 20 < 25, vai à esquerda de 25
    raiz = inserir(raiz, 31); // 31 > 13, vai à direita; 31 > 25, vai à direita de 25
    raiz = inserir(raiz, 29); // 29 > 13, direita; 29 > 25, direita; 29 < 31, esquerda de 31
    
    printf("\n=== PERCURSOS DA ÁRVORE ===\n");
    
    // Demonstra o percurso em largura (nível por nível)
    printf("\n1. Percurso em Largura (Breadth-First):\n");
    percursoLargura(raiz);
    
    // Demonstra os percursos em profundidade
    printf("\n2. Percurso Inordem (Esquerda-Raiz-Direita):\n");
    printf("   Resultado: ");
    percursoInordem(raiz);
    printf("\n   (Note que os valores aparecem em ordem crescente!)\n");
    
    printf("\n3. Percurso Pré-ordem (Raiz-Esquerda-Direita):\n");
    printf("   Resultado: ");
    percursoPreOrdem(raiz);
    printf("\n");
    
    printf("\n4. Percurso Pós-ordem (Esquerda-Direita-Raiz):\n");
    printf("   Resultado: ");
    percursoPosOrdem(raiz);
    printf("\n");
    
    // Demonstração da busca
    printf("\n=== BUSCA NA ÁRVORE ===\n");
    int valorBusca = 20;
    No* resultado = buscar(raiz, valorBusca);
    if (resultado != NULL) {
        printf("Valor %d encontrado na árvore!\n", valorBusca);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }
    
    valorBusca = 15;
    resultado = buscar(raiz, valorBusca);
    if (resultado != NULL) {
        printf("Valor %d encontrado na árvore!\n", valorBusca);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }
    
    // Demonstração da remoção
    printf("\n=== REMOÇÃO DE NÓS ===\n");
    printf("Removendo o valor 10...\n");
    raiz = remover(raiz, 10);
    
    printf("Árvore após remoção (percurso inordem): ");
    percursoInordem(raiz);
    printf("\n");
    
    // Libera toda a memória alocada para a árvore
    liberarArvore(raiz);
    
    printf("\n=== PROGRAMA FINALIZADO ===\n");
    return 0; // Retorna 0 indicando execução bem-sucedida
}

/*
================================================================================
        IMPLEMENTAÇÃO USANDO O TAD ARV_BIN_ENC (CONFORME OS SLIDES)
================================================================================
*/

// Definição da estrutura do nó conforme o TAD ARV_BIN_ENC dos slides
typedef struct node {
    int info;            // Informação armazenada no nó
    struct node *left;   // Ponteiro para o filho à esquerda
    struct node *right;  // Ponteiro para o filho à direita
    struct node *father; // Ponteiro para o nó pai
} NODE;

// Definição do tipo ARV_BIN_ENC como ponteiro para NODE
typedef NODE* ARV_BIN_ENC;

// ============================================================================
// PRIMITIVAS DO TAD ARV_BIN_ENC (funções básicas de acesso)
// ============================================================================

// Função para obter a informação de um nó
int info(ARV_BIN_ENC arvore) {
    if (arvore != NULL) {
        return arvore->info;  // Retorna o valor armazenado no nó
    }
    return -1; // Valor de erro se o nó for NULL
}

// Função para obter o filho à esquerda
ARV_BIN_ENC left(ARV_BIN_ENC arvore) {
    if (arvore != NULL) {
        return arvore->left;  // Retorna ponteiro para o filho esquerdo
    }
    return NULL; // Retorna NULL se o nó for NULL
}

// Função para obter o filho à direita
ARV_BIN_ENC right(ARV_BIN_ENC arvore) {
    if (arvore != NULL) {
        return arvore->right; // Retorna ponteiro para o filho direito
    }
    return NULL; // Retorna NULL se o nó for NULL
}

// Função para obter o nó pai
ARV_BIN_ENC father(ARV_BIN_ENC arvore) {
    if (arvore != NULL) {
        return arvore->father; // Retorna ponteiro para o nó pai
    }
    return NULL; // Retorna NULL se o nó for NULL
}

// Função para criar uma árvore vazia
ARV_BIN_ENC maketree(int valor) {
    ARV_BIN_ENC novo_no = (ARV_BIN_ENC)malloc(sizeof(NODE)); // Aloca memória
    if (novo_no != NULL) {
        novo_no->info = valor;    // Define o valor do nó
        novo_no->left = NULL;     // Inicializa filho esquerdo como NULL
        novo_no->right = NULL;    // Inicializa filho direito como NULL  
        novo_no->father = NULL;   // Inicializa pai como NULL
    }
    return novo_no; // Retorna o novo nó criado
}

// Função para definir filho à esquerda
void setleft(ARV_BIN_ENC pai, ARV_BIN_ENC filho) {
    if (pai != NULL) {
        pai->left = filho;      // Define o filho esquerdo
        if (filho != NULL) {
            filho->father = pai; // Define o pai do filho
        }
    }
}

// Função para definir filho à direita
void setright(ARV_BIN_ENC pai, ARV_BIN_ENC filho) {
    if (pai != NULL) {
        pai->right = filho;     // Define o filho direito
        if (filho != NULL) {
            filho->father = pai; // Define o pai do filho
        }
    }
}

// Função para obter o irmão de um nó
ARV_BIN_ENC brother(ARV_BIN_ENC arvore) {
    if (arvore != NULL && father(arvore) != NULL) {
        // Se o nó é filho esquerdo, retorna o filho direito do pai
        if (left(father(arvore)) == arvore) {
            return right(father(arvore));
        }
        // Se o nó é filho direito, retorna o filho esquerdo do pai
        else {
            return left(father(arvore));
        }
    }
    return NULL; // Retorna NULL se não há irmão
}

// Função para verificar se um nó é filho esquerdo
int isleft(ARV_BIN_ENC arvore) {
    if (arvore != NULL && father(arvore) != NULL) {
        return (left(father(arvore)) == arvore); // Retorna 1 se for filho esquerdo
    }
    return 0; // Retorna 0 se não for filho esquerdo ou não tiver pai
}

// ============================================================================
// FUNÇÕES DE PERCURSO USANDO O TAD ARV_BIN_ENC (EXATAMENTE COMO NOS SLIDES)
// ============================================================================

// Percurso Pré-Ordem: Raiz → Esquerda → Direita
void percursoPreOrdemTAD(ARV_BIN_ENC arvore) {
    if (arvore) {                               // Se o nó existe
        printf("%d ", info(arvore));            // Visita a raiz (imprime o valor)
        percursoPreOrdemTAD(left(arvore));      // Percorre a subárvore esquerda
        percursoPreOrdemTAD(right(arvore));     // Percorre a subárvore direita
    }
}

// Percurso In-Ordem: Esquerda → Raiz → Direita
void percursoInOrdemTAD(ARV_BIN_ENC arvore) {
    if (arvore) {                               // Se o nó existe
        percursoInOrdemTAD(left(arvore));       // Percorre a subárvore esquerda
        printf("%d ", info(arvore));            // Visita a raiz (imprime o valor)
        percursoInOrdemTAD(right(arvore));      // Percorre a subárvore direita
    }
}

// Percurso Pós-Ordem: Esquerda → Direita → Raiz
void percursoPosOrdemTAD(ARV_BIN_ENC arvore) {
    if (arvore) {                               // Se o nó existe
        percursoPosOrdemTAD(left(arvore));      // Percorre a subárvore esquerda
        percursoPosOrdemTAD(right(arvore));     // Percorre a subárvore direita
        printf("%d ", info(arvore));            // Visita a raiz (imprime o valor)
    }
}

// ============================================================================
// FUNÇÕES ADICIONAIS PARA O TAD ARV_BIN_ENC
// ============================================================================

// Função para inserir um valor na árvore binária de busca usando TAD
ARV_BIN_ENC inserirTAD(ARV_BIN_ENC arvore, int valor) {
    // Se a árvore está vazia, cria um novo nó
    if (arvore == NULL) {
        return maketree(valor);
    }
    
    // Se o valor é menor, insere à esquerda
    if (valor < info(arvore)) {
        if (left(arvore) == NULL) {
            setleft(arvore, maketree(valor)); // Cria e define filho esquerdo
        } else {
            inserirTAD(left(arvore), valor);  // Continua a busca à esquerda
        }
    }
    // Se o valor é maior ou igual, insere à direita
    else {
        if (right(arvore) == NULL) {
            setright(arvore, maketree(valor)); // Cria e define filho direito
        } else {
            inserirTAD(right(arvore), valor);  // Continua a busca à direita
        }
    }
    
    return arvore; // Retorna a raiz da árvore
}

// Função para buscar um valor na árvore usando TAD
ARV_BIN_ENC buscarTAD(ARV_BIN_ENC arvore, int valor) {
    // Se a árvore está vazia ou o valor foi encontrado
    if (arvore == NULL || info(arvore) == valor) {
        return arvore;
    }
    
    // Se o valor é menor, busca à esquerda
    if (valor < info(arvore)) {
        return buscarTAD(left(arvore), valor);
    }
    
    // Se o valor é maior, busca à direita
    return buscarTAD(right(arvore), valor);
}

// Função para liberar memória da árvore TAD
void liberarArvoreTAD(ARV_BIN_ENC arvore) {
    if (arvore != NULL) {
        liberarArvoreTAD(left(arvore));  // Libera subárvore esquerda
        liberarArvoreTAD(right(arvore)); // Libera subárvore direita
        free(arvore);                    // Libera o nó atual
    }
}

// ============================================================================
// FUNÇÃO PRINCIPAL PARA DEMONSTRAR O TAD ARV_BIN_ENC
// ============================================================================

void exemploTAD_ARV_BIN_ENC() {
    printf("\n\n");
    printf("================================================================================\n");
    printf("           DEMONSTRAÇÃO DO TAD ARV_BIN_ENC (CONFORME OS SLIDES)\n");
    printf("================================================================================\n");
    
    // Criando a árvore conforme o exemplo dos slides
    ARV_BIN_ENC raiz_tad = maketree(13);  // Cria raiz com valor 13
    
    // Inserindo os demais valores usando o TAD
    printf("\nInserindo valores: 13, 10, 25, 2, 12, 20, 31, 29\n");
    raiz_tad = inserirTAD(raiz_tad, 10);
    raiz_tad = inserirTAD(raiz_tad, 25);
    raiz_tad = inserirTAD(raiz_tad, 2);
    raiz_tad = inserirTAD(raiz_tad, 12);
    raiz_tad = inserirTAD(raiz_tad, 20);
    raiz_tad = inserirTAD(raiz_tad, 31);
    raiz_tad = inserirTAD(raiz_tad, 29);
    
    printf("\n=== PERCURSOS USANDO TAD ARV_BIN_ENC ===\n");
    
    // Demonstrando os três tipos de percurso usando o TAD
    printf("\n1. Percurso Pré-Ordem (Raiz-Esquerda-Direita):\n");
    printf("   Resultado: ");
    percursoPreOrdemTAD(raiz_tad);
    printf("\n");
    
    printf("\n2. Percurso In-Ordem (Esquerda-Raiz-Direita):\n");
    printf("   Resultado: ");
    percursoInOrdemTAD(raiz_tad);
    printf("\n   (Valores em ordem crescente!)\n");
    
    printf("\n3. Percurso Pós-Ordem (Esquerda-Direita-Raiz):\n");
    printf("   Resultado: ");
    percursoPosOrdemTAD(raiz_tad);
    printf("\n");
    
    // Demonstrando funcionalidades específicas do TAD
    printf("\n=== FUNCIONALIDADES ESPECÍFICAS DO TAD ===\n");
    
    // Encontrando um nó para demonstrar as funções
    ARV_BIN_ENC no_teste = buscarTAD(raiz_tad, 10);
    if (no_teste != NULL) {
        printf("\nAnalisando o nó com valor %d:\n", info(no_teste));
        
        if (father(no_teste) != NULL) {
            printf("- Pai: %d\n", info(father(no_teste)));
        }
        
        if (left(no_teste) != NULL) {
            printf("- Filho esquerdo: %d\n", info(left(no_teste)));
        }
        
        if (right(no_teste) != NULL) {
            printf("- Filho direito: %d\n", info(right(no_teste)));
        }
        
        if (brother(no_teste) != NULL) {
            printf("- Irmão: %d\n", info(brother(no_teste)));
        }
        
        printf("- É filho esquerdo? %s\n", isleft(no_teste) ? "Sim" : "Não");
    }
    
    // Liberando a memória
    liberarArvoreTAD(raiz_tad);
    
    printf("\n=== TAD ARV_BIN_ENC DEMONSTRADO COM SUCESSO ===\n");
}

// Função principal atualizada para chamar ambos os exemplos
int mainCompleto() {
    printf("========================================================================\n");
    printf("    COMPARAÇÃO: IMPLEMENTAÇÃO PRÓPRIA vs TAD ARV_BIN_ENC\n");
    printf("========================================================================\n");
    
    // Chama a implementação original (que já está na função main acima)
    printf("\n[1] Executando implementação própria...\n");
    // main(); // A função main original já foi executada
    
    // Chama o exemplo do TAD ARV_BIN_ENC
    printf("\n[2] Executando implementação com TAD ARV_BIN_ENC...\n");
    exemploTAD_ARV_BIN_ENC();
    
    printf("\n========================================================================\n");
    printf("                    COMPARAÇÃO FINALIZADA\n");
    printf("========================================================================\n");
    printf("\nAmbas as implementações demonstram os mesmos conceitos de:\n");
    printf("- Árvore Binária de Busca\n");
    printf("- Inserção respeitando a propriedade BST\n");  
    printf("- Percursos em profundidade (Pré, In e Pós-ordem)\n");
    printf("- Busca eficiente baseada na propriedade BST\n");
    printf("\nDiferença principal: TAD oferece navegação para o pai e irmão!\n");
    
    return 0;
}
