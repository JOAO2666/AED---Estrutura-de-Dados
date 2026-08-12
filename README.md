<div align="center">

# Estruturas de Dados em C

Implementações didáticas de listas, pilhas, filas e árvores, organizadas para estudo progressivo, consulta e experimentação.

[![Linguagem C](https://img.shields.io/badge/linguagem-C11-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c/11)
[![Compilação](https://img.shields.io/github/actions/workflow/status/JOAO2666/AED---Estrutura-de-Dados/compilar.yml?branch=main&style=for-the-badge&label=compila%C3%A7%C3%A3o)](https://github.com/JOAO2666/AED---Estrutura-de-Dados/actions/workflows/compilar.yml)
[![Foco](https://img.shields.io/badge/foco-aprendizado-2E8B57?style=for-the-badge)](#trilha-de-estudo)

**C11 · GCC/Clang · estruturas lineares · árvores · exemplos comentados**

[Visão geral](#visão-geral) · [Conteúdo](#conteúdo-do-repositório) · [Início rápido](#início-rápido) · [Trilha de estudo](#trilha-de-estudo) · [Materiais](#materiais-de-apoio)

</div>

---

## Visão geral

Este repositório funciona como um laboratório de Estruturas de Dados em C. O conteúdo foi consolidado a partir de materiais do mesmo autor, separado por assunto e revisado para facilitar a navegação e a compilação independente.

O projeto foi organizado com quatro compromissos:

- **clareza:** um assunto por pasta e nomes de arquivo previsíveis;
- **progressão:** exemplos ordenados do fundamento às estruturas hierárquicas;
- **preservação:** materiais históricos continuam disponíveis, mesmo quando incompletos;
- **verificação:** todo arquivo C ativo é analisado com GCC/C11, e os programas completos também são compilados pelo GitHub Actions.

> Este é um acervo didático. Os exemplos favorecem a leitura e a compreensão dos algoritmos; não pretendem substituir bibliotecas de produção.

## Conteúdo do repositório

| Área | O que você encontra | Conceitos principais |
| --- | --- | --- |
| [`listas/`](listas/) | Lista simplesmente encadeada e comparação entre cinco variações | nós, ponteiros, inserção, remoção e percursos |
| [`pilhas/`](pilhas/) | Pilhas sequencial e encadeada; conversão de expressões | LIFO, topo, alocação e notação pós-fixa |
| [`filas/`](filas/) | Fila circular sequencial e filas encadeadas | FIFO, cursores, descritor, início e fim |
| [`arvores/`](arvores/) | Árvore binária de busca e árvore AVL | recursão, percursos, busca, remoção e rotações |
| [`materiais/`](materiais/) | PDF, notas históricas, referências e rascunhos preservados | revisão e rastreabilidade do conteúdo |

### Catálogo dos exemplos

| Arquivo | Tipo | Finalidade |
| --- | --- | --- |
| [`listas/lista_simples_encadeada.c`](listas/lista_simples_encadeada.c) | Executável | Introdução prática a nós e ligações por ponteiros |
| [`listas/listas_variacoes.c`](listas/listas_variacoes.c) | Executável | Comparação interativa de listas sequencial, simples, circular, dupla e circular dupla |
| [`pilhas/pilha_sequencial.c`](pilhas/pilha_sequencial.c) | Módulo | Representação de pilha em vetor |
| [`pilhas/pilha_encadeada.c`](pilhas/pilha_encadeada.c) | Executável | Operações de pilha com alocação dinâmica |
| [`pilhas/conversao_expressoes.c`](pilhas/conversao_expressoes.c) | Executável | Uso de pilhas na conversão de expressões |
| [`filas/fila_sequencial.c`](filas/fila_sequencial.c) | Módulo | Fila circular com capacidade fixa |
| [`filas/fila_encadeada.c`](filas/fila_encadeada.c) | Módulo | Fila dinâmica com descritor de início e fim |
| [`filas/fila_encadeada_inteiros.c`](filas/fila_encadeada_inteiros.c) | Módulo | Variação que também mantém o número de elementos |
| [`filas/ordenacao_distribuicao.c`](filas/ordenacao_distribuicao.c) | Esboço histórico | Ponto de partida para estudar ordenação por distribuição |
| [`arvores/arvore_binaria_busca.c`](arvores/arvore_binaria_busca.c) | Executável | Inserção, busca, remoção e percursos em ABB |
| [`arvores/arvore_avl.c`](arvores/arvore_avl.c) | Módulo | Balanceamento de árvore por rotações AVL |

## Início rápido

### Pré-requisitos

- Git;
- GCC ou Clang com suporte a C11;
- `make` opcional, mas recomendado.

### Clonar e verificar

```bash
git clone https://github.com/JOAO2666/AED---Estrutura-de-Dados.git
cd AED---Estrutura-de-Dados

make verificar
make compilar-exemplos
```

Os cinco programas completos serão criados em `build/`. Para executar um deles:

```bash
./build/lista_simples
```

No Windows, o executável normalmente terá a extensão `.exe`:

```powershell
.\build\lista_simples.exe
```

<details>
<summary><strong>Compilação manual, sem Make</strong></summary>

```bash
gcc -std=c11 -Wall -Wextra -pedantic listas/lista_simples_encadeada.c -o lista_simples
gcc -std=c11 -Wall -Wextra -pedantic listas/listas_variacoes.c -o listas_variacoes
gcc -std=c11 -Wall -Wextra -pedantic pilhas/pilha_encadeada.c -o pilha_encadeada
gcc -std=c11 -Wall -Wextra -pedantic pilhas/conversao_expressoes.c -lm -o conversao_expressoes
gcc -std=c11 -Wall -Wextra -pedantic arvores/arvore_binaria_busca.c -o arvore_busca
```

Para verificar um módulo que não possui `main`, use `-fsyntax-only`:

```bash
gcc -std=c11 -Wall -Wextra -pedantic -fsyntax-only filas/fila_sequencial.c
```

</details>

## Trilha de estudo

Uma sequência eficiente para percorrer o conteúdo é:

1. **Ponteiros e nós:** comece por [`lista_simples_encadeada.c`](listas/lista_simples_encadeada.c).
2. **Representações de listas:** compare as alternativas em [`listas_variacoes.c`](listas/listas_variacoes.c).
3. **Disciplina de acesso:** estude pilhas (LIFO) e filas (FIFO), primeiro em vetor e depois com alocação dinâmica.
4. **Aplicação de pilhas:** acompanhe a conversão de expressões para observar uma estrutura sendo usada na solução de um problema.
5. **Estruturas hierárquicas:** avance para árvore binária de busca e, por último, para balanceamento AVL.

Em cada exemplo, uma boa rotina é:

1. identificar a estrutura declarada por `struct` e `typedef`;
2. listar as invariantes que precisam ser mantidas;
3. acompanhar inserção, consulta e remoção com papel e caneta;
4. compilar e executar o exemplo;
5. alterar os valores de entrada e observar os casos-limite.

## Organização interna

```text
.
├── listas/       # estruturas lineares de acesso geral
├── pilhas/       # política LIFO e aplicações
├── filas/        # política FIFO, vetor circular e nós encadeados
├── arvores/      # ABB e AVL
├── materiais/    # referências e conteúdo histórico preservado
├── Makefile      # comandos de verificação e compilação
├── ORIGENS.md    # procedência e critérios da consolidação
└── README.md
```

Os arquivos usam `snake_case`, sem espaços ou acentos. Artefatos de compilação, como `*.o`, `*.obj`, `*.exe` e a pasta `build/`, não são versionados.

## Qualidade e validação

O workflow [`Verificar compilação em C`](.github/workflows/compilar.yml) é executado a cada atualização da branch e em pull requests. Ele:

1. verifica todos os arquivos `.c` ativos com `gcc -std=c11 -Wall -Wextra -pedantic`;
2. apresenta todos os erros encontrados em uma única execução;
3. compila e liga os cinco exemplos que possuem `main`.

Localmente, os mesmos critérios podem ser aplicados com:

```bash
make verificar
make compilar-exemplos
```

## Materiais de apoio

- [`roteiro-segunda-prova.pdf`](materiais/roteiro-segunda-prova.pdf): roteiro de revisão preservado do repositório original;
- [`recursos-externos.md`](materiais/recursos-externos.md): PDFs, playlist e videoaulas citados no conteúdo original;
- [`materiais/notas/`](materiais/notas/): anotações e rascunhos incompletos mantidos para consulta histórica;
- [`todos_os_arquivos.zip`](materiais/arquivos-originais/todos_os_arquivos.zip): pacote legado preservado para evitar perda de material.

Os rascunhos incompletos usam extensões como `.c.txt`. Assim, permanecem legíveis e rastreáveis sem serem confundidos com exemplos prontos para compilação.

## Origem e preservação

A consolidação comparou outros repositórios do usuário `JOAO2666`, incorporou somente exemplos úteis e não redundantes e registrou os commits de origem. Consulte [`ORIGENS.md`](ORIGENS.md) para ver:

- quais repositórios foram analisados;
- quais arquivos foram incorporados;
- por que determinados materiais não foram copiados;
- como as renomeações preservam o histórico do Git.

## Como contribuir

Ao propor melhorias:

- mantenha cada exemplo autocontido ou documente claramente suas dependências;
- preserve a intenção didática e evite alterações de lógica sem justificativa;
- use nomes em `snake_case`;
- compile com as opções definidas no `Makefile`;
- atualize a documentação da pasta quando adicionar ou mover conteúdo.

---

<div align="center">

Feito para estudar estruturas de dados entendendo cada ponteiro, operação e escolha de representação.

</div>
