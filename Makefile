CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic

FONTES := $(wildcard listas/*.c pilhas/*.c filas/*.c arvores/*.c)

.PHONY: verificar compilar-exemplos listar-fontes

verificar:
	@falhou=0; for arquivo in $(FONTES); do \
		echo "Verificando $$arquivo"; \
		$(CC) $(CFLAGS) -fsyntax-only "$$arquivo" || falhou=1; \
	done; exit $$falhou

compilar-exemplos:
	@mkdir -p build
	$(CC) $(CFLAGS) listas/lista_simples_encadeada.c -o build/lista_simples
	$(CC) $(CFLAGS) listas/listas_variacoes.c -o build/listas_variacoes
	$(CC) $(CFLAGS) pilhas/pilha_encadeada.c -o build/pilha_encadeada
	$(CC) $(CFLAGS) pilhas/conversao_expressoes.c -lm -o build/conversao_expressoes
	$(CC) $(CFLAGS) arvores/arvore_binaria_busca.c -o build/arvore_busca

listar-fontes:
	@printf '%s\n' $(FONTES)
