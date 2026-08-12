#include <stdio.h>
#include <stdlib.h>

/*FILA_ENC (de valores inteiros). Onde o descritor
deve armazenar o número de elementos na fila e
teremos a operação que determinará o tamanho da
fila*/

typedef struct nodo{//não vai ter nenhuma alteração no que vai ser o NODO
    int inf; 
    struct nodo *next;
}NODO; 
typedef struct{// vamos ter uma peculiridade uma inserção do NE
    int ne;//número de elementos na fila
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;//
typedef DESCRITOR *FILA_ENC; //um ponteiro para o descritor
/* os mesmos protótipos, porém teremos um novo protótipo TAM*/
void cria_fila(FILA_ENC *);
int eh_vazia(FILA_ENC);
void ins(FILA_ENC, int);
int cons(FILA_ENC);
void ret(FILA_ENC);
int cons_ret(FILA_ENC);
void destruir(FILA_ENC);
int tam(FILA_ENC);// temos um protótipo novo que vamos implementa
}

void cria_fila(FILA_ENC *pf){//A única diferença é a inicalização adequada do NE
    *pf = (DESCRITOR *)malloc(sizeof(DESCRITOR));
    if(!*pf){

        printf("\nErro! Memoria insuficiente.\n");
        exit(1);
    }
    (*pf)->ne = 0;//vai receber o valor 0, já que não tem nenhum elemento na fila
    (*pf)->INICIO = (*pf)->FIM = NULL;
}

void ins(FILA_ENC f, int v){
    NODO *novo;
    novo = (NODO *)malloc(sizeof(NODO));
    if(!novo){
        printf("\nErro! Memoria insuficiente.\n");
        exit(1);
    }
    novo->inf = v;
    novo->next = NULL;
    if(eh_vazia(f)){
        f->INICIO = novo;
    }else{
        f->FIM->next = novo;
        f->FIM = novo;
    }
    f->ne++;//necessidade de atualizar o numero de elementos na fila
}

void ret(FILA_ENC f){
    /* se estamos tratando de retirada, a gente precisa atualizar a quantidade 
    de elementos, fazendo a decrementação do NE*/
    if(!f->INICIO){
        printf("\nerro! retirada na fila vazia.\n");
        exit(3);
    }
    else{
        NODO *aux = f->INICIO;
        f->INICIO = f->INICIO->next;
        if(!f->INICIO)
        f->FIM=NULL;
    free(aux);
    f->ne--;//decrementar o numero de elementos na fila
    }
}
int cons_ret(FILA_ENC f){
    /*Peculiaridade de consulta e retirada, a eu preciso atualizar o conteúdo do NE
    do meu descritor, decrementando uma unidade do valor contido do mesmo.*/
    if (!f->INICIO){
        printf("\nerro!Consulta e retirada em fila vazia.\n");
        exit(4);
    }
    else{
        int v = f->INICIO->inf;
        NODO *aux = f->INICIO;
        f->INICIO = f->INICIO->next;
        f->FIM = NULL;
        free(aux);
        f->ne--;//decrementar o numero de elementos na fila
        return(v);
    }
}
int tam(FILA_ENC f){
    /*Função que não constava na outra lista encadeada, mas agora tem*/
   /* eu vou ter acessao ao tamanho, apenas acessando o campo NE do meu descritor.
   E retorno o campo NE do meu descritor.*/
    return(f->ne);
}
/*Como vimos, uma fila nada mais é do
que uma lista com uma disciplina de acesso.
 Logo, podemos nos utilizar de todos os conceitos
vistos em listas para implementarmos filas.
 Por exemplo, podemos utilizar uma lista circular
para armazenar uma fila.
 Como exercício de fixação, implemente um TAD
FILA, armazenado a mesma em uma lista circular.*/
