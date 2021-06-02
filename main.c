// Projeto Laborat�rio de Estrutura de Dados II

// gcc -fsanitize=address -Wall -Wextra -Wpedantic -Wwrite-strings
// alias n="gcc -fsanitize=address -Wall -Wextra -Wpedantic -Wwrite-strings main.c menus.c clientes.c outras_funcoes.c produtos.c -o main && ./main"

#include <stdlib.h> // Include para aloca��o
#include <stdio.h> // Include para entrada e sa�da e manipula��o de arquivos
#include <string.h> // Include para manipula��o de string
#include <locale.h> // Include para acentua��o

#include "menus.h" // Include para importar a TAD dos menus

int main() {

    setlocale(LC_ALL, "Portuguese");
    menu();

    puts(" ");
    return 0;
}
