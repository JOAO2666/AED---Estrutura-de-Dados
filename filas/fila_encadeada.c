#include <stdio.h>
#include <stdlib.h>
// fila encadeada
//desvantagens:
//reserva estática de memoria
// como resolver? lista encadeada dinâmica
/*Uma estratégia, muito aplicada, é a utilização de
uma representação baseada em um descritor
contendo duas referências, ao primeiro e ao último
nodo.
*/
/* Desta forma, definiremos e implementaremos,
agora, o TAD FILA_ENC (de valores inteiros).
 Obs.: Se para a aplicação se fizer relevante o
descritor pode armazenar, também, o número de
elementos na fila.*/

typedef struct nodo {
    int info;
    struct nodo *next;
}NODO;//definicao do nodo
typedef struct{
       NODO *INICIO;//endereço de memoria do primeiro nodo
       NODO *FIM;//endereço de memoria do ultimo nodo

}DESCRITOR;//definicao do descritor

typedef DESCRITOR *FILA_ENC;//definicao do tipo fila encadeada
// fila *ENC o ponteiro para o descritor
void cria_fila (FILA_ENC *);
int eh_vazia(FILA_ENC );
void ins(FILA_ENC, int);
int cons(FILA_ENC );
void ret(FILA_ENC );
int cons_ret(FILA_ENC );
void destruir(FILA_ENC );//liberar a área de memoria

void cria_fila (FILA_ENC *pf)// ponteiro para fila enc
/* pf Estabelecer valores iniciais, validos e coerentes para a fila*/
/*Ela não ocupa memoria nenhuma. Então, não se tem área de memoria para o descritor*/
{ 
    *pf=(DESCRITOR *)malloc(sizeof(DESCRITOR));
    if(!*pf)
    /*tentar armazenar memoria para o descritor*/
    /*se não conseguir, imprimir uma mensagem de erro e sair do programa*/
    {
    printf("\nErro! Memoria insuficiente.\n");
    exit(1);
    }
    (*pf)->INICIO = (*pf)->FIM = NULL;
    /*atribuir NULL aos ponteiros do descritor*/
}

int eh_vazia(FILA_ENC f)
{
    return (f->INICIO == NULL);
    /*retornar TRUE se o ponteiro do inicio for NULL*/
    /*retornar FALSE se o ponteiro do inicio não for NULL*/
    // se retornar NULL, a fila está vazia
}
/*dicas:
Tem espaço na memória para armazenar mais um
elemento?
Todas as situações de inserção são tratadas da
mesma forma?*/

//situação 1 - tentar reserva uma área de mémoria e
/* se a reserva foi bem, eu vou inicializar os campos do descritor*/ 
/* se a reserva foi mal, eu vou imprimir uma mensagem de erro e sair do programa*/
//situação 2 - tentar inserir um elemento
/* se a fila estiver vazia, eu vou atribuir o endereço do novo nodo ao campo INICIO e FIM*/
/* se a fila não estiver vazia, eu vou atribuir o endereço do novo nodo ao campo FIM*/
//situação 3 - tentar retirar um elemento
/* se a fila estiver vazia, eu vou imprimir uma mensagem de erro e sair do programa*/
/* no campo Next atualizar tipo como ultimo elemento que vai ter o novo ultimo nodo
depois disso atualizar o descritor, que será o campo fim   */

/*situação se for uma fila vazia, eu vou atribuir o endereço do novo nodo ao campo INICIO e FIM*/

void ins(FILA_ENC f, int v) {
    /*declarar uma variável local*/
    NODO *novo;
    novo = (NODO *)malloc(sizeof(NODO));
    /*se a reserva foi bem, eu vou inicializar os campos do novo nodo*/
    if(!novo){
        printf("\nErro!Memoria insuficiente\n");
        exit(1);//retornar para o usuário uma mensagem de erro e sair do programa
        /*se a reserva foi mal, eu vou imprimir uma mensagem de erro e sair do programa*/
    }
    novo->info = v;//inicializar o campo info do novo nodo
    novo->next = NULL;//ultimo elemento
    if(eh_vazia(f)){ //verificar se a fila está vazia
        f->INICIO = novo;
    } else { //se a fila não estiver vazia, eu vou atribuir o endereço do novo nodo ao campo FIM,
        // e o campo Next do ultimo elemento vai ser o novo nodo
        f->FIM->next = novo;
    }
    f->FIM = novo;
    //se a fila estiver vazia, eu vou atribuir o endereço do novo nodo ao campo INICIO e FIM
}
int cons (FILA_ENC f){//consultar o valor de um elemento de uma fila não vazia
    if(eh_vazia(f)){//se a fila for vazia, imprimir uma mensagem de erro e sair do programa
        printf("\nErro! Consulta na Fila vazia.\n");
        exit(2);
    }else{// acessar o elemento apontado e retornar o valor do campo info
        return (f->INICIO->info);
    }
}

/*Dicas:
A FILA não é vazia?
Todas as situações de remoção são tratadas da
mesma forma?*/
/*tiamos uma corereção de excessão e retirada, duas situações.
retirar um elemento de uma fila*/
//situação 1 - tentar retirar um elemento
/* se a fila estiver vazia, eu vou imprimir uma mensagem de erro e sair do programa*/
/* no campo Next atualizar tipo como ultimo elemento que vai ter o novo ultimo nodo
depois disso atualizar o descritor, que será o campo fim   */
//situação 2 - tentar retirar um elemento de uma fila que possui mais de um elemento
/* se a fila estiver vazia, eu vou imprimir uma mensagem de erro e sair do programa*/
/* no campo Next atualizar tipo como ultimo elemento que vai ter o novo ultimo nodo
depois disso atualizar o descritor, que será o campo fim   */


/*como funciona?
temos uma variavel auxiliar que vai receber o endereço do primeiro elemento que vamos retirar
guardar o endereço do primeiro elemento NODO em aux*/
/*atualizar o campo INICIO para o campo Next do primeiro elemento*/
/*atualizar o campo FIM para o campo Next do ultimo elemento*/
/*liberar a memoria do elemento aux*/
/*retornar o valor do campo info do elemento aux*/
/*atualizar o campo Next do ultimo elemento para NULL*/
/*atualizar o campo Next do primeiro elemento para NULL*/
/*atualizar o campo Next do ultimo elemento para NULL*/


void ret (FILA_ENC f){// só posso retira uma fila que não está vazia
    if (eh_vazia(f)){//se a fila for vazia, imprimir uma mensagem de erro e sair do programa
        printf("\nErro! Retirada na Fila vazia.\n");
        exit(3);
    }else{//se a fila não estiver vazia, eu vou atribuir o endereço do primeiro elemento ao campo INICIO
        NODO *aux = f->INICIO;//endereço de memeoria do elemento do primeiro nodo
        f->INICIO = f->INICIO->next;//atualizar o campo INICIO para o campo Next do primeiro elemento
        if(!f->INICIO){//se o campo INICIO for NULL, eu vou atribuir NULL ao campo FIM
            f->FIM = NULL;//atualizar o campo FIM para o descritor
        }
        free(aux);//liberar a área de memoria que era ocupada pelo elemento que estou retirando
    }
}
int cons_ret (FILA_ENC f){//combinação da consulta e retirada
    /* a condição para imprementar ambas, só posso consultar se a fila for vazia*/
    if(eh_vazia(f)){//se a fila for vazia, imprimir uma mensagem de erro e sair do programa
        printf("\nErro! Consulta e Retirada na Fila vazia.\n");
        exit(4);
    }else{//se a fila não estiver vazia, eu vou atribuir o endereço do primeiro elemento ao campo INICIO
        int v=f->INICIO->info;//armazenar na variavel local, armazenar contido no campo info do primieiro elemento da fila e guarda na variável v
        NODO *aux = f->INICIO;//endereço de memeoria do elemento do primeiro nodo
        f->INICIO = f->INICIO->next;//atualizar o campo INICIO para o campo Next do primeiro elemento
        if(!f->INICIO)//se o campo INICIO for NULL, eu vou atribuir NULL ao campo FIM
        f->FIM = NULL;
    free(aux);//liberar a área de memoria que era ocupada pelo elemento que estou retirando
    return(v);//retornar o valor de contido que eu retirei
    }
}
void destruir(FILA_ENC f){//liberar a área de memoria que era ocupada pela fila
    NODO *aux; //vareável auxiliar de ponteiro para NODO
    while (f->INICIO){//verificar se tem algum campo na fila
        aux = f->INICIO;//se esse for diferente de NULL, eu vou atribuir o endereço do primeiro elemento ao campo INICIO
        f->INICIO = f->INICIO->next;//atualizar o campo INICIO para o campo Next do primeiro elemento
        free(aux);//liberar a área de memoria que era ocupada pela fila que estou destruindo
    }
    free(f);//libera a área de memoria ocupada pelo descritor
}


