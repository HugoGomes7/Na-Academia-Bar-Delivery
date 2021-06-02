#include <stdio.h> // Biblioteca de entrada e sa�da e manipula��o de arquivos.
#include <stdlib.h> // Biblioteca de aloca��o.
#include <string.h> // Biblioteca de strings.
#include <sys/stat.h> // Biblioteca para cria��o de pastas.

#include "clientes.h"

// Estrutura de decis�o com macros pra importar uma biblioteca pro Windows ou pro Linux.
#ifdef __linux       //
#include <unistd.h> //
#define WINDOWS 0   //
#else               // Estrutura de decis�o com macros pra importar uma biblioteca
#include <windows.h> // se o sistema for windows ou linux.
#define WINDOWS 1 //
#endif

// Fun��o apenas para dar um delay na tela.
void delay(int valor_em_segundos){
#ifdef __linux
    sleep (valor_em_segundos);
#else
    Sleep(valor_em_segundos * 1000); // 1000 � a quantidade de milisegundos.
#endif
}

// Fun��o que ir� limpar o que aparece atualmente na tela.
void limpar(){
    if (WINDOWS) system("cls");
    else system("clear");
}
