#include <stdio.h>
#include <stdlib.h>

/*
Como já discutimos, a alocação sequencial apresenta algumas desvantagens.
 Em virtude disso, podemos nós utilizar de uma lista
encadeada para armazenarmos uma pilha, assim
como fizemos com as filas.
 Como todas as operações ocorrem numa das
extremidades da lista, a representação da pilha se
reduz a um único ponteiro para o primeiro nodo da
lista.

A implementação das operações é trivial. O que vai ser diferente é a implementação das funções que manipulam a pilha.
pois, basta colocar um ponteiro para o primeiro nodo da lista, e assim vai ser mais facil a implementação das funções que manipulam a pilha.
*/

// Definição da estrutura do nosso NODO (NODE).
// Ele contém um campo para o valor (inf) e um ponteiro (next)
// para o próximo NODO da pilha.
typedef struct nodo{
    int inf;
    struct nodo *next;
}NODE;

// A representação da pilha se reduz a um único ponteiro
// que vai apontar para o primeiro nodo da lista (o topo).
typedef NODE *PILHA_ENC; // O tipo PILHA_ENC é um ponteiro para um NODE.

// Protótipos das funções
void create(PILHA_ENC *);//criar a pilha
int is_empty(PILHA_ENC);//verificar se a pilha está vazia
void push(PILHA_ENC *, int);//empilhar um elemento
int top(PILHA_ENC);//consultar o elemento que está no topo da pilha
void pop(PILHA_ENC *);//retirar um elemento da pilha
int top_pop(PILHA_ENC *);//consultar e retirar um elemento da pilha
void destroy(PILHA_ENC *);//destruir a pilha

// Criar uma pilha significa que ela está inicialmente vazia.
// Para isso, a referência externa (o ponteiro para o topo)
// deve ser inicializada com um valor que indique isso, no caso, NULL.
void create(PILHA_ENC *pp){
    *pp = NULL;
}

// Para verificar se uma pilha é vazia, simplesmente observamos
// o conteúdo da referência externa (o ponteiro para o topo).
// Se ele for NULL, a pilha está vazia.
int is_empty(PILHA_ENC p){
    return (p == NULL); // Retorna TRUE (1) se p for NULL, e FALSE (0) caso contrário.
}

// Empilhar é o mesmo que inserir um novo primeiro elemento na lista.
void push(PILHA_ENC *pp, int v){
    NODE *new; // Variável local auxiliar para o novo nodo.
    
    // Tenta alocar memória para um novo nodo.
    new = (NODE *)malloc(sizeof(NODE));
    
    // Verifica se a alocação de memória foi bem-sucedida.
    if(!new){
        printf("\nErro! Memoria insuficiente.\n");
        exit(1);
    }
    
    // Inicializa os campos do novo nodo.
    new->inf = v; // O campo de informação recebe o valor a ser empilhado.
    
    // O próximo do novo elemento será o elemento que estava no topo.
    // Mesmo que a pilha esteja vazia (*pp é NULL), está correto.
    new->next = *pp;
    
    // Atualiza a referência externa para que o topo da pilha
    // agora aponte para o novo elemento.
    *pp = new;
}

// Consulta o valor do topo. Só pode ser feito em uma pilha não vazia.
int top(PILHA_ENC p){
    // Verifica se a pilha está vazia antes de tentar a consulta.
    if(is_empty(p)){
        printf("\nErro! Consulta em pilha vazia.\n");
        exit(2);
    }
    
    // Se não estiver vazia, retorna o valor do campo 'inf' do nodo
    // que está no topo da pilha.
    return (p->inf);
}

// Desempilhar é o mesmo que remover o primeiro elemento da lista.
void pop(PILHA_ENC *pp){
    // Só é possível desempilhar de uma pilha não vazia.
    if(is_empty(*pp)){
        printf("\nErro! Retirada em pilha vazia.\n");
        exit(3);
    } else {
        // Cria uma variável local 'aux' para guardar o endereço
        // do elemento que será removido, para não perdermos a referência a ele.
        NODE *aux = *pp;
        
        // Atualiza o topo da pilha, fazendo-o apontar para o próximo elemento.
        *pp = (*pp)->next;
        
        // Libera a área de memória ocupada pelo elemento que foi desempilhado.
        free(aux);
    }
}

// É a combinação das operações TOP e POP.
int top_pop(PILHA_ENC *pp){
    // A operação só é válida em uma pilha não vazia.
    if(is_empty(*pp)){
        printf("\nErro! Consulta e retirada em pilha vazia.\n");
        exit(4);
    } else {
        // Armazena o valor do topo em uma variável local para retorná-lo depois.
        int v = (*pp)->inf;
        NODE *aux = *pp;
        
        // Move o topo para o próximo elemento.
        *pp = (*pp)->next;
        
        // Libera a memória do antigo topo.
        free(aux);
        
        // Retorna o valor que estava no topo.
        return(v);//retornar o valor de v
    }
}

// Libera toda a memória alocada para a pilha.
void destroy(PILHA_ENC *pp){
    // Laço de repetição que continua enquanto a pilha não for vazia.
    while(!is_empty(*pp)){
        // O processo é similar ao POP, mas sem a verificação de erro,
        // pois o próprio laço já garante que a pilha não está vazia.
        NODE *aux = *pp;//atribuir o endereço do novo nodo ao campo topo
        *pp = (*pp)->next;//
        free(aux);//liberar a memoria do novo nodo
    }
}

/*O mesmo que discutimos a respeito das
filas ocorre com as pilhas.
 Ou seja, uma pilha nada mais é do que uma lista
com uma disciplina de acesso.
 Logo, podemos nos utilizar de todos os conceitos
vistos em listas para implementarmos pilhas.
 Por exemplo, podemos utilizar uma lista
encadeada com nó cabeçalho (contendo o número
de elementos) para armazenar uma pilha*/


//=========================================================
// FUNÇÃO MAIN PARA TESTE DA PILHA
//=========================================================
int main() {
    PILHA_ENC minha_pilha;

    // 1. Criar a pilha
    create(&minha_pilha);
    printf("Pilha recem-criada.\n");

    // 2. Verificar se está vazia
    if (is_empty(minha_pilha)) {
        printf("Confirmado: a pilha esta vazia.\n\n");
    }

    // 3. Empilhar alguns elementos
    printf("Empilhando os valores 10, 20 e 30...\n");
    push(&minha_pilha, 10);
    push(&minha_pilha, 20);
    push(&minha_pilha, 30); // O último a entrar é o 30, então ele é o topo.
    
    if (!is_empty(minha_pilha)) {
        printf("A pilha nao esta mais vazia.\n");
    }

    // 4. Consultar o topo
    printf("O elemento no topo da pilha eh: %d\n\n", top(minha_pilha));

    // 5. Retirar um elemento com pop
    printf("Desempilhando um elemento (pop)...\n");
    pop(&minha_pilha);
    printf("Agora, o novo elemento no topo eh: %d\n\n", top(minha_pilha));

    // 6. Consultar e retirar com top_pop
    printf("Consultando e desempilhando com top_pop...\n");
    int valor_removido = top_pop(&minha_pilha);
    printf("Valor removido: %d\n", valor_removido);
    printf("Apos o top_pop, o novo topo eh: %d\n\n", top(minha_pilha));

    // 7. Esvaziar o restante da pilha
    printf("Esvaziando o restante da pilha...\n");
    while (!is_empty(minha_pilha)) {
        printf("Removido: %d\n", top_pop(&minha_pilha));
    }

    if (is_empty(minha_pilha)) {
        printf("A pilha agora esta vazia novamente.\n\n");
    }
    
    // 8. Destruir a pilha (embora já esteja vazia, é uma boa prática
    //    chamar a função destroy para garantir que qualquer lógica de
    //    limpeza seja executada).
    printf("Empilhando novos valores 55 e 66 para teste do destroy...\n");
    push(&minha_pilha, 55);
    push(&minha_pilha, 66);
    printf("O topo atual eh: %d\n", top(minha_pilha));
    
    printf("Destruindo a pilha para liberar a memoria...\n");
    destroy(&minha_pilha);

    if (is_empty(minha_pilha)) {
        printf("Pilha destruida com sucesso e memoria liberada.\n");
    }
    
    return 0;
}