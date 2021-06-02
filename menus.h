#ifndef MENUS_H
#define MENUS_H

#include "clientes.h" // Include para importar a TAD de cliente
#include "produtos.h" // Include para importar a TAD de produto

// Prot�tipo da fun��o do menu principal.
void menu();

// Prot�tipo da fun��o do menu de atendimento.
void atendimentoPrincipal();

// Prot�tipo da fun��o do menu de cardapio.
void cardapio(Cliente* cliente);

// Prot�tipo da fun��o do menu de petiscos.
void petiscos(TabelaDeProdutos* tabelaDeProdutos);

// Prot�tipo da fun��o do menu de cervejas.
void cervejas(TabelaDeProdutos* tabelaDeProdutos);

// Prot�tipo da fun��o do menu de destilados.
void destilados(TabelaDeProdutos* tabelaDeProdutos);

// Prot�tipo da fun��o do menu de cacha�as.
void cachacas(TabelaDeProdutos* tabelaDeProdutos);

// Prot�tipo da fun��o do menu de bebidas n�o alc�olicas.
void bebnalc(TabelaDeProdutos* tabelaDeProdutos);

#endif
