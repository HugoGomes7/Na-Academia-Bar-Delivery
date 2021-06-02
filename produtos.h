#ifndef PRODUTOS_H
#define PRODUTOS_H

// Declaração do tipo Produto da estrutura produto
typedef struct produto Produto;

// Declaração do tipo TabelaDeProdutos da estrutura tabelaDeProdutos
typedef struct tabelaDeProdutos TabelaDeProdutos;

// Protótipo da função que cria uma lista encadeada de produtos
TabelaDeProdutos *criaTabelaDeProdutos();

// Protótipo da função que adiciona um produto cadastrado em um espaço da lista
void adicionaProduto (TabelaDeProdutos *i, Produto *produto);

//Protótipo da função que libera os elementos presentes na lista
void liberaTabelaDeProdutos (TabelaDeProdutos *tab);

//Protótipo da função que escreve os produtos comprados no arquivo de nota fiscal
int escreveProdutos(FILE *arquivo, const TabelaDeProdutos *produtos);

// Protótipo da função que define o valor do produto com base no código cadastrado
Produto *criaProduto(int codigo);

// Protótipo da função que calcula o valor total de todos os produtos cadastrados na lista
double valorTotal(const TabelaDeProdutos *tab);

// Protótipo da função que verifica se a lista está vazia
int temProdutos(const TabelaDeProdutos *tab);

#endif
