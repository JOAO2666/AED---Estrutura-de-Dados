#include <stdio.h>
#include <stdlib.h>
/*Além das árvores serem muito apropriadas para representar a estrutura
hierárquica de um certo domínio, o processo de
busca por um elemento em uma árvore tende a ser
muito mais rápido do que em uma lista encadeada.
 Contudo, para que efetivamente uma busca por
um determinado elemento em uma árvore seja
eficiente esta, além de ser uma árvore binária de
busca, deve ter seus nós adequadamente
distribuídos. 
*/

/* Sendo assim, podemos estabelecer a seguinte
definição: Uma árvore binária é balanceada em
altura ou simplesmente balanceada se a diferença
na altura de ambas as subárvores de qualquer nó
na árvore é zero ou um.
*/

/*Uma definição complementar é a de
árvore perfeitamente balanceada.
 Uma árvore binária é perfeitamente balanceada
quando, além de ser balanceada, todas as suas
folhas encontram-se em um ou dois níveis.
 Para facilitar a visualização, uma árvore que
possui 10.000 nós pode ser configurada em uma
árvore com altura igual a log2
(10000) = ceil(13.289) =
14. Ou seja, qualquer elemento é passível de ser
localizado com no máximo 14 comparações se a
árvore for perfeitamente balanceada.*/

/*Uma definição complementar é a de
árvore perfeitamente balanceada.
 Uma árvore binária é perfeitamente balanceada
quando, além de ser balanceada, todas as suas
folhas encontram-se em um ou dois níveis.
 Para facilitar a visualização, uma árvore que
possui 10.000 nós pode ser configurada em uma
árvore com altura igual a log2
(10000) = ceil(13.289) =
14. Ou seja, qualquer elemento é passível de ser
localizado com no máximo 14 comparações se a
árvore for perfeitamente balanceada.
Árvore Balanceada
 Neste ponto cabe a seguinte pergunta:
Ao se analisar uma árvore pode-se determinar qual dentre os seus nós seria uma raiz
adequada para torná-la perfeitamente balanceada?
 Qual seria este nó?
 O nó cuja sua chave (valor) representa a mediana
das chaves presentes nos nós que compõem a
árvore, para uma árvore com número impar de nós.
Ou o nó cuja sua chave (valor) representa um dentre
os dois valores mais próximos da mediana das
chaves presentes nos nós que compõem a árvore,
para uma árvore com número par de nós*/


/*Uma estratégia baseada nesta observação que pode ser utilizada para balancear
uma árvore é:
 - Retire os dados da árvore e armazene-os em um
vetor;
 - Após todos os dados terem sido armazenados no
vetor, ordene-o;
 - Agora determine como raiz o elemento do meio do
vetor;
 - O vetor consistirá agora em dois subvetores. O filho
esquerdo da raiz será o nó com valor no meio do
subvetor constituído do início do vetor até o elemento
escolhido como raiz;
Árvore Balanceada
 - Um procedimento similar é adotado para a
definição do filho direito da raiz;
 - Este processo se repete até não existirem mais
elementos a serem retirados do vetor.
 Uma proposta de exercício de fixação consiste
em implementar uma função, na linguagem C, que
implementa este processo.
Árvore Balanceada
 O algoritmo mencionado possui um
sério inconveniente, pois, caso a árvore
já exista, os seus elementos devem ser retirados e
colocado em um vetor, para que a mesma seja
recriada.
 Caso a árvore ainda não exista, o inconveniente
ainda persiste. Pois, todos os dados precisam ser
colocados em um vetor antes da árvore ser criada.
 Uma pequena melhoria pode ser feita. Pois,
mesmo que a árvore binária de busca esteja
desbalanceada, se for efetuado um percurso inordem elimina-se a necessidade de ordenar o vetor.
Árvore Balanceada
 Existem formas mais eficientes de se
balancear uma árvore.
 Um exemplo é o algoritmo denominado DSW
(proposto por Colin Day e posteriormente
melhorado por Quentin F. Stout e Bette L. Warren).
O qual baseia-se em percorrer uma árvore binária
de busca tornando-a uma arvore degenerada
(similar a uma lista encadeada) e posteriormente
percorrê-la novamente tornando-a uma árvore
perfeitamente balanceada.
Árvore Balanceada
 Até o momento foram mencionados
algoritmos que balanceiam árvores globalmente.
 Contudo, o rebalanceamento pode ocorrer
localmente se alguma porção da árvore for
desbalanceada por uma operação de inserção ou
remoção de um elemento da árvore.
 Um método clássico, que nomeia uma árvore
modificada pelo mesmo como AVL. (Em função de
seus idealizadores, Adel’son-Vel’skii e Landis)
Árvore AVL
 Uma árvore AVL é uma árvore binária de
busca onde a diferença em altura entre as
subárvores esquerda e direita de cada nó é no máximo
um (positivo ou negativo).
 Esta diferença é chamada de fator de balanceamento
(FB).
 O FB (ou informações que permitam sua obtenção) é
acrescentado a cada nó da árvore AVL.
 FB = altura subárvore – altura subárvore
 nó p direita de p esquerda de p*/


void precursoEmLaguraColocacaoEmVetor(ARV_BIN_BUSCA arvore, int vetor[], int *num_elem){
FIAL_ENC fila;
cria_fia(&fila);
if (arvore) {
    ins_fila(fila,arvore);
    *num_elem = 0;
    vetor = NULL;
}
while (!eh_vazia(fila)){
    if(!(vetor = (int *)realloc(vetor,(*num_elem)) * sizeof(int))))
    exit(1);
vetor[*num_elem)-1 =info_cons(fila);
    if(left(cons_fila(fila)));
    if(rifgt(c0ns_fila(filla)))
    ins_fila(fila,right(cons_fila(fila)));
    ret_fila(fila);
    }
}
// Implementação completa do QuickSort

int particionar(int v[], int ii, int is) {
    int esq=ii, dir=is, pivo=v[ii]; // Inicializa ponteiros esquerdo e direito, define pivô como primeiro elemento
    while(esq<dir) { // Loop principal enquanto os ponteiros não se cruzarem
        while(v[esq]<=pivo && esq<is) // Procura elemento maior que o pivô pela esquerda
            esq++; // Avança ponteiro esquerdo
        while(v[dir]>pivo) // Procura elemento menor ou igual ao pivô pela direita
            dir--; // Recua ponteiro direito
        if(esq<dir) { // Se os ponteiros ainda não se cruzaram
            int temp; // Declara variável temporária para troca
            temp = v[esq]; // Armazena valor da esquerda
            v[esq]=v[dir]; // Move valor da direita para esquerda
            v[dir]=temp; // Move valor temporário para direita
        }
    }
    v[ii]=v[dir]; // Coloca elemento da posição direita na posição inicial
    v[dir]=pivo; // Coloca pivô na posição final correta
    return dir; // Retorna posição final do pivô
}

void quicksort(int *v, int n) {
    if(n>1) { // Verifica se há mais de um elemento para ordenar
        int pont_part=particionar(v, 0, n-1); // Particiona o vetor e obtém posição do pivô
        quicksort(v, pont_part); // Chama recursivamente para a parte esquerda (elementos menores)
        quicksort(&v[pont_part+1], n-1-pont_part); // Chama recursivamente para a parte direita (elementos maiores)
    }
}

// Função auxiliar para balancear árvore binária
void balancearArvoreBinariaAux (ARV_BIN_BUSCA *arvore,
int vetor[], int inicio, int fim)
{
    if (inicio <= fim) // Verifica se ainda há elementos no intervalo para processar
    {
        int meio = (inicio+fim)/2; // Calcula o índice do elemento do meio do intervalo
        ins_ele(arvore, vetor[meio]); // Insere o elemento do meio como raiz da subárvore
        balancearArvoreBinariaAux (arvore, vetor, inicio, meio-1); // Constrói subárvore esquerda recursivamente
        balancearArvoreBinariaAux (arvore, vetor, meio+1, fim); // Constrói subárvore direita recursivamente
    }
}

// Função principal para balancear árvore binária
void balancearArvoreBinaria (ARV_BIN_BUSCA *arvore)
{
    int *vetor, num_elem; // Declara ponteiro para vetor e variável para número de elementos
    precursoEmLarguraColocacaoEmVetor (*arvore, vetor, &num_elem); // Extrai todos elementos da árvore para um vetor
    quicksort (vetor, num_elem); // Ordena o vetor com os elementos extraídos
    while (*arvore) // Loop para remover todos os elementos da árvore original
        remocaoPorCopia (arvore); // Remove um elemento por vez da árvore
    balancearArvoreBinariaAux (arvore, vetor, 0, num_elem-1); // Reconstrói a árvore de forma balanceada
    free(vetor); // Libera a memória alocada para o vetor
}

// Estrutura do nó para árvore AVL
typedef struct node{
    int num, altd, alte; // número do nó, altura direita, altura esquerda
    struct node *dir, *esq; // ponteiros para filhos direito e esquerdo
}NODE;

typedef NODE *ArvoreAVL; // Definição do tipo árvore AVL

// Função para rotação à esquerda
void rotacao_esquerda(ArvoreAVL *arvore)
{
    ArvoreAVL aux1, aux2; // Declara ponteiros auxiliares
    aux1 = (*arvore)->dir; // aux1 aponta para o filho direito da raiz
    aux2 = aux1->esq; // aux2 aponta para o filho esquerdo de aux1
    (*arvore)->dir = aux2; // Filho direito da raiz recebe aux2
    aux1->esq = (*arvore); // Filho esquerdo de aux1 recebe a raiz
    if ((*arvore)->dir == NULL) // Se não há filho direito
        (*arvore)->altd = 0; // Altura direita é zero
    else
        if ((*arvore)->dir->alte > (*arvore)->dir->altd) // Compara alturas do filho direito
            (*arvore)->altd = (*arvore)->dir->alte+1; // Altura direita = maior altura + 1
        else
            (*arvore)->altd = (*arvore)->dir->altd+1; // Altura direita = altura direita + 1
    if (aux1->esq->alte > aux1->esq->altd) // Compara alturas do filho esquerdo de aux1
        aux1->alte = aux1->esq->alte + 1; // Altura esquerda = altura esquerda + 1
    else
        aux1->alte = aux1->esq->altd + 1; // Altura esquerda = altura direita + 1
    *arvore = aux1; // A nova raiz é aux1
}

// Função para rotação à direita
void rotacao_direita(ArvoreAVL *arvore)
{
    ArvoreAVL aux1, aux2; // Declara ponteiros auxiliares
    aux1 = (*arvore)->esq; // aux1 aponta para o filho esquerdo da raiz
    aux2 = aux1->dir; // aux2 aponta para o filho direito de aux1
    (*arvore)->esq = aux2; // Filho esquerdo da raiz recebe aux2
    aux1->dir = (*arvore); // Filho direito de aux1 recebe a raiz
    if ((*arvore)->esq == NULL) // Se não há filho esquerdo
        (*arvore)->alte = 0; // Altura esquerda é zero
    else
        if ((*arvore)->esq->alte > (*arvore)->esq->altd) // Compara alturas do filho esquerdo
            (*arvore)->alte = (*arvore)->esq->alte+1; // Altura esquerda = maior altura + 1
        else
            (*arvore)->alte = (*arvore)->esq->altd+1; // Altura esquerda = altura direita + 1
    if (aux1->dir->alte > aux1->dir->altd) // Compara alturas do filho direito de aux1
        aux1->altd = aux1->dir->alte + 1; // Altura direita = altura esquerda + 1
    else
        aux1->altd = aux1->dir->altd + 1; // Altura direita = altura direita + 1
    *arvore = aux1; // A nova raiz é aux1
}

// Função de balanceamento da árvore AVL
void balanceamento(ArvoreAVL *arvore) {
    int FBpai, FBfilho; // Fatores de balanceamento do pai e do filho
    FBpai = (*arvore)->altd - (*arvore)->alte; // Calcula fator de balanceamento do nó pai
    if (FBpai == 2) { // Se desbalanceado para a direita
        FBfilho = (*arvore)->dir->altd - (*arvore)->dir->alte; // FB do filho direito
        if (FBfilho >= 0) // Se filho direito também desbalanceado para direita
            rotacao_esquerda(arvore); // Rotação simples à esquerda
        else { // Se filho direito desbalanceado para esquerda
            rotacao_direita(&(*arvore)->dir); // Rotação dupla: direita no filho
            rotacao_esquerda(arvore); // depois esquerda na raiz
        }
    } else {
        if (FBpai == -2) { // Se desbalanceado para a esquerda
            FBfilho = (*arvore)->esq->altd - (*arvore)->esq->alte; // FB do filho esquerdo
            if (FBfilho <= 0) // Se filho esquerdo também desbalanceado para esquerda
                rotacao_direita(arvore); // Rotação simples à direita
            else { // Se filho esquerdo desbalanceado para direita
                rotacao_esquerda(&(*arvore)->esq); // Rotação dupla: esquerda no filho
                rotacao_direita(arvore); // depois direita na raiz
            }
        }
    }
}

