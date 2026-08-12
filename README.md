# Estruturas de Dados em C

Coleção didática de implementações de estruturas de dados na linguagem C. O repositório reúne exemplos independentes, módulos de apoio e materiais de estudo organizados por assunto.

## Objetivos

- apresentar implementações legíveis de listas, pilhas, filas e árvores;
- comparar alocação sequencial e encadeada;
- servir como referência para exercícios e revisão;
- facilitar a compilação isolada de cada exemplo;
- preservar os materiais originais e indicar a origem do conteúdo consolidado.

## Índice

1. [Organização do repositório](#organização-do-repositório)
2. [Como compilar](#como-compilar)
3. [Como estudar os exemplos](#como-estudar-os-exemplos)
4. [Materiais de apoio](#materiais-de-apoio)
5. [Origem da consolidação](#origem-da-consolidação)

## Organização do repositório

| Pasta | Conteúdo |
| --- | --- |
| [`listas/`](listas/) | Lista simplesmente encadeada e comparação entre listas sequenciais, simples, circulares e duplamente encadeadas. |
| [`pilhas/`](pilhas/) | Pilhas com alocação sequencial e encadeada, além da conversão de expressões. |
| [`filas/`](filas/) | Fila circular sequencial, filas encadeadas e um esboço histórico sobre ordenação por distribuição. |
| [`arvores/`](arvores/) | Árvore binária de busca e AVL em exemplos compiláveis. |
| [`materiais/`](materiais/) | Roteiro da segunda prova, notas, rascunhos incompletos preservados e um arquivo compactado legado. |

Os nomes de arquivos usam `snake_case`, sem espaços ou acentos, para funcionar de forma previsível em diferentes sistemas operacionais.

## Como compilar

Use um compilador compatível com C11, como GCC ou Clang.

### Exemplos executáveis

Os arquivos abaixo possuem `main` e geram programas completos:

```bash
gcc -std=c11 -Wall -Wextra -pedantic listas/lista_simples_encadeada.c -o lista_simples
gcc -std=c11 -Wall -Wextra -pedantic listas/listas_variacoes.c -o listas_variacoes
gcc -std=c11 -Wall -Wextra -pedantic pilhas/pilha_encadeada.c -o pilha_encadeada
gcc -std=c11 -Wall -Wextra -pedantic pilhas/conversao_expressoes.c -lm -o conversao_expressoes
gcc -std=c11 -Wall -Wextra -pedantic arvores/arvore_binaria_busca.c -o arvore_busca
```

No Windows, acrescente `.exe` ao nome de saída se desejar, por exemplo `-o lista_simples.exe`.

### Módulos sem `main`

Alguns arquivos foram escritos como módulos de estudo. Para verificar a sintaxe sem criar um executável, compile apenas o arquivo-objeto:

```bash
gcc -std=c11 -Wall -Wextra -pedantic -c filas/fila_sequencial.c
gcc -std=c11 -Wall -Wextra -pedantic -c filas/fila_encadeada.c
gcc -std=c11 -Wall -Wextra -pedantic -c arvores/arvore_avl.c
```

Os artefatos de compilação (`*.o`, `*.obj` e `*.exe`) são ignorados pelo Git.

Em sistemas com `make`, use `make verificar` para conferir todos os arquivos C e `make compilar-exemplos` para gerar os cinco programas completos na pasta `build/`. O mesmo processo é executado automaticamente pelo GitHub Actions.

## Como estudar os exemplos

Uma sequência sugerida é:

1. `listas/lista_simples_encadeada.c`, para praticar ponteiros e alocação dinâmica;
2. `listas/listas_variacoes.c`, para comparar representações sequenciais e encadeadas;
3. `pilhas/` e `filas/`, para comparar LIFO e FIFO;
4. as notas históricas em `materiais/notas/`, como apoio conceitual;
5. `arvores/arvore_binaria_busca.c` e `arvores/arvore_avl.c`, para os tópicos avançados.

Leia primeiro as estruturas (`struct` e `typedef`), depois os protótipos e, por fim, acompanhe as operações de inserção, busca e remoção. Quando houver `main`, altere os valores de exemplo e observe o efeito.

## Materiais de apoio

- [`materiais/roteiro-segunda-prova.pdf`](materiais/roteiro-segunda-prova.pdf): roteiro de revisão preservado do repositório original.
- [`materiais/notas/pilha_sequencial.txt`](materiais/notas/pilha_sequencial.txt): anotação histórica sobre pilha sequencial.
- [`materiais/arquivos-originais/todos_os_arquivos.zip`](materiais/arquivos-originais/todos_os_arquivos.zip): pacote legado mantido para não eliminar conteúdo potencialmente útil.
- [`materiais/recursos-externos.md`](materiais/recursos-externos.md): links para PDFs, playlist e videoaulas que constavam no README original.

## Origem da consolidação

Os exemplos complementares de listas vieram de outros repositórios do mesmo autor. O arquivo [`ORIGENS.md`](ORIGENS.md) registra os repositórios e commits consultados, além dos critérios usados para evitar cópias redundantes.

> Observação: o foco desta coleção é didático. Antes de reutilizar uma implementação em produção, acrescente testes, tratamento de erros adequado ao projeto e uma API separada em arquivos `.h` e `.c`.
