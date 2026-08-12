#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int info;   
    int left;
    int right;
    int father;
}NODE;
typedef struct{
    int root;
    int nodeFree;
    NODE nodes[NUMNODES];//define NUMNODES 100*
}ARV_BIND_SEQ;//define o tipo arvore binaria sequencial
void maketree(ARV_BIND_SEQ *, int);
void setleft(ARV_BIND_SEQ *, int, int);
void setright(ARV_BIND_SEQ *, int, int);
void info(ARV_BIND_SEQ *, int);
int left(ARV_BIND_SEQ *, int);
int right(ARV_BIND_SEQ *, int);
int brother(ARV_BIND_SEQ *, int);
int isleft(ARV_BIND_SEQ *, int);
int isright(ARV_BIND_SEQ *, int);

void setleft(ARV_BIND_SEQ *t, int p, int x){//implementacao da funcao setleft
    int ind = getNode(t);//atribuicao do valor de getNode(t) ao campo ind
    if (ind != -1){//se o valor de ind for diferente de -1
        t->nodes[ind].info = x;//atribuicao do valor de x ao campo info
        t->nodes[ind].left = ind;//atribuicao do valor de ind ao campo left
        t->nodes[ind].right = -1;//atribuicao do valor -1 ao campo right
        t->nodes[ind].father = p;//atribuicao do valor de p ao campo father
    }else{//se o valor de ind for igual a -1
        printf("Impossivel inserir filho a esquerda!.\n");
        exit(2);//sair do programa

    }
}
void setright(ARV_BIND_SEQ *t, int p, int x){//implementacao da funcao setright
    int ind = getNode(t);//atribuicao do valor de getNode(t) ao campo ind
    if (ind != -1){//se o valor de ind for diferente de -1
        t->nodes[ind].info = x;//atribuicao do valor de x ao campo info
        t->nodes[ind].left = -1;//atribuicao do valor -1 ao campo left
        t->nodes[ind].right = -1;//atribuicao do valor -1 ao campo right
        t->nodes[p].right = ind;//atribuicao do valor de ind ao campo right
        t->nodes[ind].father = p;//atribuicao do valor de p ao campo father
    }else{//se o valor de ind for igual a -1
        printf("Impossivel inserir filho a direita!.\n");
        exit(2);//sair do programa

        int info(ARV_BIND_SEQ *t, int p){
            //implementacao da funcao info
            return t->nodes[p].info;//retorno do valor do campo info
        }
int left(ARV_BIND_SEQ *t, int p){
    //implementacao da funcao left
    return t´>nodes[p].left;//retorno do valor do campo left
}
int right(ARV_BIND_SEQ *t, int p){
    //implementacao da funcao right
    return t->nodes[p].right;//retorno do valor do campo right
}
int father(ARV_BIND_SEQ *t, int p){
    return t->nodes[p].father;
    //retorno do valor do campo father
    int brother(ARV_BIND_SEQ *t, int p){
        if{father(t,p) != -1)/*se não for a raiz*/
            if(isleft(t,p))
                return right(t,father(t,p));
            else{
                return t->nodes[p].father].left;
            return -1;
    }
    int isleft(ARV_BIND_SEQ *t, int p){
        int q = father(t,p);
        if(q != -1) /*se for raiz*/
        return 0;
        if (left(t,q) == p)
            return 1;
        return 0;
    }
    int isright(ARV_BIND_SEQ *t, int p){
        int q = (father(t,p)!= -1) /*se for raiz*/
            return(!isleft(t,p));
        return 0;
    }
    }