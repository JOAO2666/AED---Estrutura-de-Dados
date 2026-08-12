# Origem e critérios da consolidação

Esta reorganização comparou o repositório principal com quatro repositórios do usuário `JOAO2666` em 11 de agosto de 2026.

## Materiais incorporados

| Arquivo atual | Repositório de origem | Commit consultado | Motivo |
| --- | --- | --- | --- |
| `listas/lista_simples_encadeada.c` | `Programa-o-em-C---Lista-encadeada-linked-list-` | `584e046f321427ee944073df3e967e58cb2997b9` | Exemplo focado, executável e amplamente comentado de lista simplesmente encadeada. |
| `listas/listas_variacoes.c` | `MEGA-C-DIGO-DE-ESTRUTURA-DE-DADOS---LISTAS` | `f0febb67ad38e1bd910d45cd85dca876d778b6a8` | Reúne, em um menu único, listas sequencial, simples, circular, dupla e circular dupla. |

Os comentários de autoria presentes nos arquivos de origem foram preservados.

## Materiais consultados, mas não copiados

| Repositório | Commit consultado | Decisão |
| --- | --- | --- |
| `curso-estruturas-de-dados-i` | `5c3f245ad0b4f55e39026d575a6cf490ee05a498` | O conteúdo é majoritariamente C++, slides e dependências de apresentação. O único arquivo C é uma revisão introdutória e não acrescenta uma estrutura de dados ao acervo. |
| `C-digos-da-segunda-prova-de-linder` | `a947b534868980471fa36b2ccc61e1a73ab21aa4` | O arquivo reúne fragmentos de filas, pilhas e árvores que já existem, de forma mais completa e separada, no repositório principal. Também depende de constantes e cabeçalhos externos, portanto não é autocontido. |

## Preservação do histórico

Os arquivos que já pertenciam ao repositório principal foram movidos com o Git, permitindo que ferramentas como `git log --follow` acompanhem as renomeações. Para arquivos vindos de outros repositórios, a origem e o commit foram registrados acima, pois o histórico Git não pode ser unido por uma simples cópia de arquivo.
