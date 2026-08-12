#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//usado para coocar restrições nos dados que são passados para a função
/*fila é uma lista com 
restrições de acesso, sobre as operações de 
inserção consulta e retida. Isto leva, ao critério FIFO (firs in, first out)
Uma fila, como uma estrutura linear, pode ser
armazenada em um vetor, mas necessita de dois
cursores, de modo a se ter controle do início e do
fim da fila. Para facilitar a implementação das
operações e torná-las mais eficientes, também é
utilizado um inteiro N que contém o número de
elementos na fila.*/


/*fila com restrições de acesso*/
typedef struct{
    int N;
    int INICIO;
    int FIM;
    int val[MAX];
}Fila_SEQ;
/*fila com restrições de acesso*/

/* A implementação das operações pode se dar de
modo simples: a fila cresce do começo para o fim
do vetor; para se inserir um elemento, incrementase o cursor FIM que serve como índice do novo
elemento; para consulta, INICIO é o índice usado,
o qual, ao ser incrementado, efetua uma retirada.*/


/*  Qual o problema com esta proposta?
*/

/*  Como resolver este problema?
Valor de fim, como sendo, acada nova secção eu vou incrementa-lo, para ficar mais fácil a implementação das operações
O truque de implementação se resume a fazer o cursor de inserção, sempre
chegar a MAX-1, e quando chegar a MAX, eu vou decrementar o cursor de inicio, e assim vai acontecendo. Assumir 0 no proximo

um operador que ajuda nisso é o %, pois, para todo k<MAX, k%MAX=k, %MAX = 0;
*/

/*prototipos das funções*/
void cria_fila(Fila_SEQ *);
int eh_vazia(Fila_SEQ *);
int tam(Fila_SEQ *);
void ins(Fila_SEQ *, int);
int cons(Fila_SEQ *);
void ret(Fila_SEQ *);
int cons_ret(Fila_SEQ *);
//cons_ret retirar elemento e retornar o valor deste elemento

/*prototipos das funções*/

/*implementação das funções*/
void cria_fila(Fila_SEQ *f){
    f->N = f->INICIO = 0;
    f->FIM = -1;
    // estabeler valores iniciais, validos e coerentes para a fila
    //quando fizer a inserção de um elemento, eu vou incrementa-lo, e o cursor de fim vai ser incrementado
    //quando fizer a consulta de um elemento, eu vou decrementa-lo, e o cursor de inicio vai ser decrementado -1
    // no vetor não precisa
    //atribuir zer0 para o cursor de inicio e fim
}
int eh_vazia(Fila_SEQ *f){
    return (!f->N);
    //consulta o valor de N, se for 0, a fila está vazia
    //retornar N negativo para indicar que a fila está vazia
}
int tam(Fila_SEQ *f){
    return (f->N);
    //retornar o valor de N, e retorna o tamanho da fila
}
void ins(Fila_SEQ *f, int v){
    if(f->N == MAX)
    { 
        printf("\nErro! Estouro na fila.\n");
        exit(1);
    }
    f->FIM = (f->FIM + 1) % MAX;
    f->val[f->FIM] = v;
    f->N++;
// certificar se existe passo na fila, se N for igual a MAX, a fila está cheia
//se a fila estiver cheia, imprimir uma mensagem de erro e sair do programa
//se a fila não estiver cheia, incrementar o valor de N e o valor de FIM
//atribuir o valor de v ao vetor de valores
//APOIS isso indexa o valor de v ao vetor de valores
//atualizar o valor de N
}
int cons(Fila_SEQ *f){
    //para consulta, eu preciso verificar se a fila está vazia
    if(eh_vazia(f))
    {
        printf("\nErro! Consulta na Fila vazia.\n");
        exit(2);
    }else 
        return (f->val[f->INICIO]);
    // se não entrei no meu if, eu tenho o meu else e retorno o valor indexado no vetor de valores
    //atualizar o valor de INICIO
}
void ret(Fila_SEQ *f){
    //para retirada, eu preciso verificar se a fila está vazia
    if(eh_vazia(f))
    {
        printf("\nErro! Retirada na Fila vazia.\n");
        exit(3);
    }else{
        //se não entrei no meu if, eu tenho o meu else e retorno o valor indexado no vetor de valores
        //atualizar o valor de INICIO
        f->INICIO = (f->INICIO + 1) % MAX;
        f->N--;
        //verifica o resto da divisão de INICIO por MAX, se for 0, eu vou atribuir 0 a INICIO
        //se não for 0, eu vou atribuir o resto da divisão de INICIO por MAX a INICIO
        //decrementar o valor de N
    }
}
int cons_ret(Fila_SEQ *f){
    //para consulta e retirada, eu preciso verificar se a fila está vazia
    if (eh_vazia(f))
    {
        printf("\nErro! Consulta e Retirada na Fila vazia.\n");
        exit(4);
    }else{
        int v = (f->val[f->INICIO]);
        f->INICIO = (f->INICIO + 1) % MAX;
        f->N--;
        return (v);
        //se não entrei no meu if, eu tenho o meu else e retorno o valor indexado no vetor de valores
        //atualizar o valor de INICIO
        //decrementar o valor de N
        //retornar o valor de v
    }
}

/* Implemente, no TAD FILA_SEQ, utilizando recursividade, a seguinte operação:
void gera_fila (FILA_SEQ *f, int m, int n);
a qual utilizando-se das operações do TAD
FILA_SEQ produz uma fila de inteiros
correspondente a [m..n].*/

void gera_fila(Fila_SEQ *f, int m, int n){
    //para gerar a fila, eu preciso verificar se o intervalo é válido
    if(m > n)
    //1 é maior que 2, então o intervalo é inválido
    {  printf("\nErro! Intervalo inválido.\n");
        exit(5);
        }else
        //se não entrei no meu if, eu tenho o meu else e gero a fila
         if(m == n){
        cria_fila(f);
        ins(f, m);
    }else{
        gera_fila(f, m, n-1);
        ins(f, n);
        //aproximo meu valor de n para o meu valor de m

    }
}

/* Implemente, no TAD FILA_SEQ, utilizando recursividade, a seguinte operação:
void gera_fila (FILA_SEQ *f, int m, int n);
a qual utilizando-se das operações do TAD
FILA_SEQ produz uma fila de inteiros
correspondente a [m..n].*/
