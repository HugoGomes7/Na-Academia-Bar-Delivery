// Projeto Laboratório de Estrutura de Dados II

// gcc -fsanitize=address -Wall -Wextra -Wpedantic -Wwrite-strings
// alias n="gcc -fsanitize=address -Wall -Wextra -Wpedantic -Wwrite-strings main.c menus.c clientes.c outras_funcoes.c produtos.c -o main && ./main"

#include <stdlib.h> // Include para alocação
#include <stdio.h> // Include para entrada e saída e manipulação de arquivos
#include <string.h> // Include para manipulação de string
#include <locale.h> // Include para acentuação

#include "menus.h" // Include para importar a TAD dos menus

int main() {

    setlocale(LC_ALL, "Portuguese");
    menu();

    puts(" ");
    return 0;
}
