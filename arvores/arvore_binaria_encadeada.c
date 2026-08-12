#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int info;
    struct *left;
    struct *right;
    struct *father;
}NODE;
typedef struct node{
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
}NODE;
typedf NODE *ARV_BIN_ENC;
void maketree(ARV_BIN_ENC *, int);
void setleft(ARV_BIN_ENC *, int, int);
void setright(ARV_BIN_ENC *, int, int);
void info(ARV_BIN_ENC *, int);
ARV_BIN_ENC left(ARV_BIN_ENC );
ARV_BIN_ENC right(ARV_BIN_ENC);
ARV_BIN_ENC father(ARV_BIN_ENC );
ARV_BIN_ENC brother(ARV_BIN_ENC);
int brother(ARV_BIN_ENC *, int);
int isleft(ARV_BIN_ENC *, int);
int isright(ARV_BIN_ENC *, int);

void maketree(ARV_BIN_ENC *t, int x){//implementacao da funcao maketree
    *t =  (ARV_BIN_ENC)malloc(sizeof(NODE));//atribuição do valor de t ao campo t
    if(!*t){//se o valor de *t for NULL
        printf("\nErro! Memoria insuficiente.\n");//    
        exit(1);//sair do programa
    }
    (*t)->info = x;
    (*t)->left = NULL;
    (*t)->right = NULL;
    (*t)->father = NULL;
}
void setleft(ARV_BIN_ENC *t, int x){//implementacao da funcao setleft
    t->left = (ARV_BIN_ENC)malloc(sizeof(NODE));
    if(!(t->left){//se o valor de t->left for NULL
        printf("\nErro!Não existe memoria disponivel.\n");
        exit(1);//sair do programa
    }
    t->left->info = x;//atribuição do valor de x ao campo info
    t->left->left = NULL;//atribuição do valor NULL ao campo left
    t->left->right = NULL;//atribuição do valor NULL ao campo right
    t->left->father = t;//atribuição do valor de t ao campo father
}
void setright(ARV_BIN_ENC *t, int x){//implementacao da funcao setright
    t->right = (ARV_BIN_ENC)malloc(sizeof(NODE));//atribuição do valor de t->right ao campo right
    if(!(t->right){//se o valor de t->right for NULL
        printf("\nErro!Não existe memoria disponivel.\n");
        exit(1);//sair do programa
    }
    t->right->info = x;//atribuição do valor de x ao campo info
    t->right->left = NULL;//atribuição do valor NULL ao campo left
    t->right->right = NULL;//atribuição do valor NULL ao campo right
    t->right->father = t;//atribuição do valor de t ao campo father
}