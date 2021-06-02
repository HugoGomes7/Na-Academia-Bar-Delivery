#include <stdio.h> // Biblioteca de entrada e saída e manipulação de arquivos.
#include <stdlib.h> // Biblioteca de alocação.
#include <string.h> // Biblioteca de strings.
#include <sys/stat.h> // Biblioteca para criação de pastas.

#include "clientes.h"

// Estrutura de decisão com macros pra importar uma biblioteca pro Windows ou pro Linux.
#ifdef __linux       //
#include <unistd.h> //
#define WINDOWS 0   //
#else               // Estrutura de decisão com macros pra importar uma biblioteca
#include <windows.h> // se o sistema for windows ou linux.
#define WINDOWS 1 //
#endif

// Função apenas para dar um delay na tela.
void delay(int valor_em_segundos){
#ifdef __linux
    sleep (valor_em_segundos);
#else
    Sleep(valor_em_segundos * 1000); // 1000 é a quantidade de milisegundos.
#endif
}

// Função que irá limpar o que aparece atualmente na tela.
void limpar(){
    if (WINDOWS) system("cls");
    else system("clear");
}
