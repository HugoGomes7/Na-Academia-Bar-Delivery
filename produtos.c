#include <stdio.h> // include para entrada e saída e manipulação de arquivos
#include <stdlib.h> // include para alocação

#include "produtos.h" // Include para importar a TAD de produto
#include "outras_funcoes.h" // Include para importar a TAD de utilitário

// Estrutura que armazena os dados do produto cadastrado
struct produto {
    int codigo;
    float preco;
    int quantidade;
    struct produto *proximo;
};

// Estrutura que cria o nó que aponta para o primeiro item da lista
struct tabelaDeProdutos{
    int tamanho;
    Produto* primeiro;
};

// Função que cria lista encadeada de produtos
TabelaDeProdutos *criaTabelaDeProdutos(){
    TabelaDeProdutos *tabelaDeProdutos = calloc(1, sizeof(TabelaDeProdutos));
    if (!tabelaDeProdutos) {
        printf("Sem memoria.\n");
        exit(EXIT_FAILURE);
    }
    return tabelaDeProdutos;
}

// Função que adiciona um produto a tabela
void adicionaProduto (TabelaDeProdutos *i, Produto *produto){
  if(i->tamanho == 0){
    i->primeiro = produto;
  }
  else {
    Produto *ultimaPosicao = i->primeiro;
    if (i->primeiro->codigo == produto->codigo) {
        i->primeiro->quantidade += 1;
        free(produto);
        return;
    }
    for(; ultimaPosicao->proximo; ultimaPosicao = ultimaPosicao->proximo) {
        if (ultimaPosicao->proximo->codigo == produto->codigo) {
            ultimaPosicao->proximo->quantidade += 1;
            free(produto);
            return;
        }
    }
    ultimaPosicao->proximo = produto;
  }
  i->tamanho++;
}

// Função que libera os elementos da lista
void liberaTabelaDeProdutos (TabelaDeProdutos *tab){
    Produto *aDeletar = NULL, *produto = tab->primeiro;
    while(produto) {
        aDeletar = produto;
        produto = produto->proximo;
        free(aDeletar);
    }
    free(tab);
}

// Função que escreve os produtos comprados no arquivo de nota fiscal
int escreveProdutos(FILE *arquivo, const TabelaDeProdutos *produtos) {
    int quantidadeTotal = 0;
    if (produtos->tamanho > 0) {
        for (Produto *produto = produtos->primeiro; produto != NULL; produto = produto->proximo, quantidadeTotal++) {
            char item[63];
            sprintf(item, "%i: ------------------[    ]-------------------------| R$    ", produto->quantidade);
            sprintf(&item[23], "%i", produto->codigo);
            if (item[24] == '\0') item[24] = ' ';
            else if (item[25] == '\0') item[25] = ' ';
            sprintf(&item[57], "%.2f", produto->preco);
            fprintf(arquivo, "%s\n", item);
        }
    }
    return quantidadeTotal;
}

// Função que define o valor do produto com base no código cadastrado
Produto *criaProduto(int codigo) {
    Produto *produto = malloc(sizeof(Produto));
    if(produto == NULL){
        printf("Erro na alocacao.\n");
        exit(EXIT_FAILURE);
    }
    produto->codigo = codigo;
    produto->quantidade = 1;
    produto->proximo = NULL;
    if(codigo==1) produto->preco = 20.00f;
    else if(codigo==2) produto->preco = 15.00f;
    else if(codigo==3) produto->preco = 18.00f;
    else if(codigo==4) produto->preco = 25.00f;
    else if(codigo==5) produto->preco = 6.00f;
    else if(codigo==6) produto->preco = 5.00f;
    else if(codigo==7) produto->preco = 5.00f;
    else if(codigo==8) produto->preco = 6.00f;
    else if(codigo==9) produto->preco = 3.00f;
    else if(codigo==10) produto->preco = 2.50f;
    else if(codigo==11) produto->preco = 3.00f;
    else if(codigo==12) produto->preco = 3.00f;
    else if(codigo==13) produto->preco = 5.00f;
    else if(codigo==14) produto->preco = 5.00f;
    else if(codigo==15) produto->preco = 33.90f;
    else if(codigo==16) produto->preco = 85.72f;
    else if(codigo==17) produto->preco = 43.90f;
    else if(codigo==18) produto->preco = 17.90f;
    else if(codigo==19) produto->preco = 127.84f;
    else if(codigo==20) produto->preco = 159.99f;
    else if(codigo==21) produto->preco = 89.90f;
    else if(codigo==22) produto->preco = 91.30f;
    else if(codigo==23) produto->preco = 38.90f;
    else if(codigo==24) produto->preco = 8.99f;
    else if(codigo==25) produto->preco = 14.90f;
    else if(codigo==26) produto->preco = 14.90f;
    else if(codigo==27) produto->preco = 5.00f;
    else if(codigo==28) produto->preco = 12.00f;
    else if(codigo==29) produto->preco = 11.00f;
    else if(codigo==30) produto->preco = 5.00f;
    else if(codigo==31) produto->preco = 4.00f;
    else if(codigo==32) produto->preco = 2.50f;

    return produto;
}

// Função que calcula o valor total de todos os produtos cadastrados na lista
double valorTotal(const TabelaDeProdutos *tab) {
    double valorTotal = 0;
    for (Produto *produto = tab->primeiro; produto != NULL; produto = produto->proximo)
        valorTotal += produto->preco * produto->quantidade;

    return valorTotal;
}

// Função que verifica se a lista de produtos está vazia
int temProdutos(const TabelaDeProdutos *tab) {
    return tab->tamanho > 0;
}
