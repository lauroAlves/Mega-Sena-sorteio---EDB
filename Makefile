# Variável que define o compilador a ser usado
CC = gcc

# -Wall: Ativa todos os avisos comuns do compilador.
# -Wextra: Ativa avisos adicionais do compilador.
CFLAGS = -Wall -Wextra

# Lista de arquivos objeto (.o) que serão gerados a partir dos arquivos .c
OBJ = main.o hash_table.o menu.o

# vai ser executado se "make" for chamado sem parâmetros.
all: main

# como vai ser gerado o executável "main".
# $(CC) -o main $(OBJ) compila e cria o executável "main" a partir dos objetos.
main: $(OBJ)
	$(CC) -o main $(OBJ)

# $(CC) $(CFLAGS) -c main.c compila "main.c" e gera o objeto "main.o".
main.o: main.c hash_table.h menu.h
	$(CC) $(CFLAGS) -c main.c

# $(CC) $(CFLAGS) -c hash_table.c compila "hash_table.c" e gera o objeto "hash_table.o".
hash_table.o: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -c hash_table.c

# $(CC) $(CFLAGS) -c menu.c compila "menu.c" e gera o objeto "menu.o".
menu.o: menu.c menu.h hash_table.h
	$(CC) $(CFLAGS) -c menu.c

# Remove todos os arquivos objeto (.o) e o executável "main".
clean:
	rm -f *.o main
