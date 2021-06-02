#ifndef MENUS_H
#define MENUS_H

#include "clientes.h" // Include para importar a TAD de cliente
#include "produtos.h" // Include para importar a TAD de produto

// Protótipo da função do menu principal.
void menu();

// Protótipo da função do menu de atendimento.
void atendimentoPrincipal();

// Protótipo da função do menu de cardapio.
void cardapio(Cliente* cliente);

// Protótipo da função do menu de petiscos.
void petiscos(TabelaDeProdutos* tabelaDeProdutos);

// Protótipo da função do menu de cervejas.
void cervejas(TabelaDeProdutos* tabelaDeProdutos);

// Protótipo da função do menu de destilados.
void destilados(TabelaDeProdutos* tabelaDeProdutos);

// Protótipo da função do menu de cachaças.
void cachacas(TabelaDeProdutos* tabelaDeProdutos);

// Protótipo da função do menu de bebidas não alcóolicas.
void bebnalc(TabelaDeProdutos* tabelaDeProdutos);

#endif
