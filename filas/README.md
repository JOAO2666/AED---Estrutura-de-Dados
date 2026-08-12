# Filas

Filas seguem a política FIFO: o primeiro elemento inserido é o primeiro removido.

- `fila_sequencial.c`: implementação circular em vetor, com capacidade fixa.
- `fila_encadeada.c`: implementação encadeada genérica do material original.
- `fila_encadeada_inteiros.c`: variação voltada a valores inteiros.
- `ordenacao_distribuicao.c`: esboço histórico de uma aplicação de filas; ainda não contém o algoritmo completo.

Compare os cursores da versão sequencial com os ponteiros de início e fim das versões encadeadas. Verifique especialmente como eles mudam quando o último elemento é removido.
