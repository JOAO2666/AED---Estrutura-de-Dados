#include <stdio.h>
#include <stdlib.h>

/*Qual a carência das pilhas e filas?
 Estas são de difícil utilização para a
 representação hierárquica de elementos.
 Devido a…
 Serem limitadas a apenas uma dimensão.
 Visando eliminar esta limitação foi criado o
conceito de árvore.*/

typedef struct {//definicao do nodo
    int info;//campo de informacao
    int left;//campo de esquerda
    int right;//campo de direita
    int father;//campo de pai
}NODE;//definicao do tipo nodo
typedef struct{//definicao da arvore
    int root;//campo de raiz
    int nodeFree;//campo de nodo livre
    NODE nodes[NUMNODES];//define NUMNODES 100*
}ARV_BIND_SEQ;//definicao do tipo arvore
voud maketree(ARV_BIND_SEQ *, int);//prototipo da funcao maketree
void setleft(ARV_BIND_SEQ *, int, int);//prototipo da funcao setleft
void setright(ARV_BIND_SEQ *, int, int);//prototipo da funcao setright
void info(ARV_BIND_SEQ *, int);//prototipo da funcao info
int left(ARV_BIND_SEQ *, int);//prototipo da funcao left
int right(ARV_BIND_SEQ *, int);//prototipo da funcao right
int brother(ARV_BIND_SEQ *, int);//prototipo da funcao brother
int isleft(ARV_BIND_SEQ *, int);   //prototipo da funcao isleft
int is right(ARV_BIND_SEQ *, int);//prototipo da funcao is right
}ARV_BIND_SEQ;
void maketree(ARV_BIND_SEQ *p, int v){//implementacao da funcao maketree
    int i, ind;//declaracao de variaveis
    for(i=0;i<NUMNODES;i++){//laço de repeticao
        t->nodes[i].left = i +1;//atribuicao do valor de i +1 ao campo left
        t->nodes[i].left = -1;//atribuicao do valor -1 ao campo left
        t->nodeFree=0;//atribuicao do valor 0 ao campo nodeFree
        ind = getNode(t);//atribuicao do valor de getNode(t) ao campo ind
        if (ind != -1){//se o valor de ind for diferente de -1
            t->nodes[ind].info = v;//atribuicao do valor de v ao campo info
            t->nodes[ind].left = -1;//atribuicao do valor -1 ao campo left
            t->nodes[ind].right = -1;
            t->nodes[ind].father = -1;//atribuicao do valor -1 ao campo father
            t->root = ind;//atribuicao do valor de ind ao campo root
            return;//retorno da funcao
        }else{//se o valor de ind for igual a -1
    printf("\nErro! Memoria insuficiente.\n");//imprimindo uma mensagem de erro
    exit(1);//sair do programa
}
}
}
int getNode{ARV_BIND_SEQ *t}{//implementacao da funcao getNode
    if (t->nodeFree != -1){//se o valor de t->nodeFree for diferente de -1
        int i = t->nodeFree;//atribuicao do valor de t->nodeFree ao campo i
        t->nodeFree = t->nodes[t->nodeFree].left;//atribuicao do valor de  t->nodes[t->nodeFree].left ao campo nodeFree
        return i;//retorno da funcao
    }else{//se o valor de ind for igual a -1
        return -1;//retorno da funcao
    }
}

void freeNode (ARV_BIND_SEQ *t, int node){//implementacao da funcao freeNode
    t->nodes[node].left = t->nodeFree;//atribuicao do valor de t->nodeFree ao campo left
    t->nodeFree = node;//atribuicao do valor de node ao campo nodeFree
}