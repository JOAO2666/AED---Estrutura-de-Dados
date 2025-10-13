#include <stdio.h>
#include <stdlib.h>

/*Uma pilha é uma lista com restrições
de acesso, onde todas as operações só
podem ser aplicadas sobre uma das extremidades da
lista, denominada topo da pilha.
 Com isso estabelece-se o critério LIFO (Last In, First
Out), que indica que o último item que entra é o
primeiro a sair
O modelo intuitivo para isto é, por exemplo, uma pilha
de livros onde só se pode visualizar o último empilhado
e este é o único que pode ser retirado; Qualquer novo
empilhamento se fará sobre o último da pilha.*/

/*Uma forma de se implementar uma
pilha é armazená-la num vetor VAL de
MAX elementos associado com um cursor inteiro
TOPO que indica onde está o topo da pilha,*/


typedef struct{
    int TOPO;
    int VAL[MAX];//definir como uma macro. exemplo:100
}PILHA_SEQ; //uma estrutura que vai ter um campo inteiro TOPO

void cria_pilha(PILHA_SEQ *);
int eh_vazia(PILHA_SEQ *);
void push(PILHA_SEQ *, int v);//empilhamento
int top(PILHA_SEQ *);
void pop(PILHA_SEQ *);

void cria_pilha(PILHA_SEQ *p){
    p->TOPO = -1;
    //atribuir -1 ao campo TOPO
}
int eh_vazia(PILHA_SEQ *p){
    return (p->TOPO == -1);
    //retornar TRUE se o campo TOPO for -1
    //retornar FALSE se o campo TOPO não for -1
}
void push(PILHA_SEQ *p, int v){
    p->TOPO++;
    p->VAL[p->TOPO] = v;
    //incrementar o campo TOPO
    //atribuir o valor de v ao campo VAL[p->TOPO]
}