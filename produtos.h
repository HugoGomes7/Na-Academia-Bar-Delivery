#ifndef PRODUTOS_H
#define PRODUTOS_H

// Declara��o do tipo Produto da estrutura produto
typedef struct produto Produto;

// Declara��o do tipo TabelaDeProdutos da estrutura tabelaDeProdutos
typedef struct tabelaDeProdutos TabelaDeProdutos;

// Prot�tipo da fun��o que cria uma lista encadeada de produtos
TabelaDeProdutos *criaTabelaDeProdutos();

// Prot�tipo da fun��o que adiciona um produto cadastrado em um espa�o da lista
void adicionaProduto (TabelaDeProdutos *i, Produto *produto);

//Prot�tipo da fun��o que libera os elementos presentes na lista
void liberaTabelaDeProdutos (TabelaDeProdutos *tab);

//Prot�tipo da fun��o que escreve os produtos comprados no arquivo de nota fiscal
int escreveProdutos(FILE *arquivo, const TabelaDeProdutos *produtos);

// Prot�tipo da fun��o que define o valor do produto com base no c�digo cadastrado
Produto *criaProduto(int codigo);

// Prot�tipo da fun��o que calcula o valor total de todos os produtos cadastrados na lista
double valorTotal(const TabelaDeProdutos *tab);

// Prot�tipo da fun��o que verifica se a lista est� vazia
int temProdutos(const TabelaDeProdutos *tab);

#endif
