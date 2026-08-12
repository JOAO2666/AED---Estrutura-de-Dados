CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -pedantic

FONTES := $(wildcard listas/*.c pilhas/*.c filas/*.c arvores/*.c)

.PHONY: verificar listar-fontes

verificar:
	@falhou=0; for arquivo in $(FONTES); do \
		echo "Verificando $$arquivo"; \
		$(CC) $(CFLAGS) -fsyntax-only "$$arquivo" || falhou=1; \
	done; exit $$falhou

listar-fontes:
	@printf '%s\n' $(FONTES)
