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


/*
 * O esboço incompleto de balanceamento global que ocupava este ponto foi
 * preservado em materiais/notas/balanceamento_arvore_binaria_incompleto.md.
 * Ele dependia de tipos externos e continha pseudocódigo ainda não compilável.
 * A implementação AVL independente começa abaixo.
 */

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

