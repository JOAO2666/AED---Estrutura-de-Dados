#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // Para a função pow()
#include <string.h> // Para a função strcspn()

#define MAXCOLS 80 // Define o tamanho máximo das strings de expressão

//-------------------------------------------------------------------
// ESTRUTURA DE DADOS: PILHA DE CARACTERES (PARA OPERADORES)
//-------------------------------------------------------------------
typedef struct node_char {
    char inf;
    struct node_char *next;
} NODE_CHAR;
typedef NODE_CHAR* PILHA_CHAR;

void cria_pilha_char(PILHA_CHAR *p) { *p = NULL; }
int eh_vazia_char(PILHA_CHAR p) { return p == NULL; }
void push_char(PILHA_CHAR *p, char v) {
    NODE_CHAR *novo = (NODE_CHAR *)malloc(sizeof(NODE_CHAR));
    if (!novo) exit(1);
    novo->inf = v;
    novo->next = *p;
    *p = novo;
}
char pop_char(PILHA_CHAR *p) {
    if (eh_vazia_char(*p)) return '\0';
    NODE_CHAR *aux = *p;
    char val = aux->inf;
    *p = aux->next;
    free(aux);
    return val;
}
char top_char(PILHA_CHAR p) {
    if (eh_vazia_char(p)) return '\0';
    return p->inf;
}

//-------------------------------------------------------------------
// ESTRUTURA DE DADOS: PILHA DE INTEIROS (PARA OPERANDOS)
//-------------------------------------------------------------------
typedef struct node_int {
    int inf;
    struct node_int *next;
} NODE_INT;
typedef NODE_INT* PILHA_INT;

void cria_pilha_int(PILHA_INT *p) { *p = NULL; }
int eh_vazia_int(PILHA_INT p) { return p == NULL; }
void push_int(PILHA_INT *p, int v) {
    NODE_INT *novo = (NODE_INT *)malloc(sizeof(NODE_INT));
    if (!novo) exit(1);
    novo->inf = v;
    novo->next = *p;
    *p = novo;
}
int pop_int(PILHA_INT *p) {
    if (eh_vazia_int(*p)) return 0;
    NODE_INT *aux = *p;
    int val = aux->inf;
    *p = aux->next;
    free(aux);
    return val;
}

//-------------------------------------------------------------------
// PROTÓTIPOS DAS FUNÇÕES DE LÓGICA
//-------------------------------------------------------------------
int eh_operando(char op);
int prcd(char op_pilha, char op_atual);
void converter_para_posfixa(char *infixa, char *posfixa);
int aplicar(int op1, char operador, int op2);
int avaliar(char *e);


//-------------------------------------------------------------------
// FUNÇÃO PRINCIPAL (MAIN)
//-------------------------------------------------------------------
int main() {
    char expr_infixa[MAXCOLS];
    char expr_posfixa[MAXCOLS];

    printf("Digite uma expressao infixa (operandos de um digito): ");
    // Lê a linha de forma segura, evitando estouro de buffer.
    fgets(expr_infixa, MAXCOLS, stdin);
    // Remove o caractere de nova linha '\n' que o fgets captura.
    expr_infixa[strcspn(expr_infixa, "\n")] = 0;

    printf("\n--- Processo ---\n");
    
    // 1. Converte a expressão lida para a forma pós-fixa.
    converter_para_posfixa(expr_infixa, expr_posfixa);
    printf("Expressao Infixa Original: %s\n", expr_infixa);
    printf("Expressao Posfixa Gerada: %s\n", expr_posfixa);

    // 2. Avalia a expressão pós-fixa e imprime o resultado.
    int resultado = avaliar(expr_posfixa);
    printf("Resultado da avaliacao: %d\n", resultado);

    return 0;
}

//-------------------------------------------------------------------
// FUNÇÕES DE LÓGICA
//-------------------------------------------------------------------

// Verifica se um caractere é um operando (slide 337).
// Lógica adaptada para ignorar também os parênteses.
int eh_operando(char op) {
    return (op != '+' && op != '-' && op != '*' && op != '/' && op != '^' && op != '(' && op != ')');
}

// Verifica a precedência entre operadores (slides 340, 343, 344).
// Esta é a versão completa que lida com parênteses.
int prcd(char op_pilha, char op_atual) {
    // Regra (slide 344): Um ')' na expressão faz desempilhar tudo até o '('.
    // Qualquer operador na pilha tem precedência sobre ')'.
    if (op_atual == ')') return 1;
    
    // Regra (slide 343): '(' na pilha tem baixa precedência,
    // para que operadores sejam empilhados sobre ele.
    if (op_pilha == '(' || op_atual == '(') return 0;

    if (op_pilha == '^') return 1;
    if ((op_pilha == '*' || op_pilha == '/') && (op_atual != '^')) return 1;
    if ((op_pilha == '+' || op_pilha == '-') && (op_atual != '^' && op_atual != '*' && op_atual != '/')) return 1;

    return 0;
}


// Converte uma string infixa com parênteses para posfixa (slides 341-345).
void converter_para_posfixa(char *infixa, char *posfixa) {
    char symbol;
    int i = 0, j = 0;
    PILHA_CHAR opstk;
    cria_pilha_char(&opstk);

    while ((symbol = infixa[i++]) != '\0') {
        if (eh_operando(symbol)) {
            posfixa[j++] = symbol;
        } else if (symbol == '(') {
            // Regra (slide 343): Parêntese de abertura é sempre empilhado.
            push_char(&opstk, symbol);
        } else if (symbol == ')') {
            // Regra (slide 344): Se encontra ')' desempilha até achar '('.
            while (top_char(opstk) != '(') {
                posfixa[j++] = pop_char(&opstk);
            }
            pop_char(&opstk); // Descarta o '('.
        } else { // É um operador
            // Desempilha operadores com maior ou igual precedência.
            while (!eh_vazia_char(opstk) && prcd(top_char(opstk), symbol)) {
                posfixa[j++] = pop_char(&opstk);
            }
            // Empilha o operador atual.
            push_char(&opstk, symbol);
        }
    }

    // Desempilha todos os operadores restantes.
    while (!eh_vazia_char(opstk)) {
        posfixa[j++] = pop_char(&opstk);
    }
    posfixa[j] = '\0'; // Finaliza a string.
}


// Executa a operação aritmética (slide 337).
int aplicar(int operando1, char operador, int operando2) {
    switch (operador) {
        case '+': return (operando1 + operando2);
        case '-': return (operando1 - operando2);
        case '*': return (operando1 * operando2);
        case '/': return (operando1 / operando2);
        case '^': return ((int)pow(operando1, operando2));
    }
    return 0;
}


// Avalia uma expressão posfixa (slide 336).
int avaliar(char *e) {
    char symbol;
    int i = 0;
    PILHA_INT pilha_operandos;
    cria_pilha_int(&pilha_operandos);

    while ((symbol = e[i++]) != '\0') {
        if (eh_operando(symbol)) {
            // Converte o caractere para seu valor numérico e empilha.
            push_int(&pilha_operandos, (int)(symbol - '0'));
        } else {
            // Desempilha operandos, aplica o operador e empilha o resultado.
            int op2 = pop_int(&pilha_operandos);
            int op1 = pop_int(&pilha_operandos);
            push_int(&pilha_operandos, aplicar(op1, symbol, op2));
        }
    }

    // O resultado final é o único valor restante na pilha.
    return (pop_int(&pilha_operandos));
}