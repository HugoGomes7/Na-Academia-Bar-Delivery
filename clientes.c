#include <stdio.h> // Include para entrada e saída e manipulação de arquivos
#include <stdlib.h> // Include para alocação
#include <string.h> // Include para manipulação de string

#include "clientes.h" // Include para importar a TAD de clientes
#include "outras_funcoes.h" // Include para importar a TAD de outras funções
#include "produtos.h" // Include para importar a TAD de produtos

// Estrutura que representa os dados de um cliente
struct cliente{
    char nome[81];
    long int cpf;
    char endereco[50];
    char pagamento[10];
    Cliente* prox; /*encadeamento na lista de colisão*/
};

// Estrutura responsável pela função de dispersão da tabela
struct hash{
    Cliente* clientes[101];
    int tamanho;
};


// Função hash que cria uma hash de clientes
Hash* hash_cria() {
    Hash* tab = calloc(1, sizeof(Hash));
    for (int i = 0; i < 101; i += 1) {
        tab->clientes[i] = NULL;
    }
    tab->tamanho = 101;
    // for (int i = 0; i < 100; tab->clientes[i] = NULL, i += 1);
    leHashArquivo(tab);
    return tab;
}

// Função de dispersão
long int hash(long int cpf){
    return (cpf % 101);
}

// Função principal que gerencia o cadastro do cliente
Cliente* cadastro(){
    limpar();

    char nome [50];
    printf("-----------------------------------------------");
    printf("\n\t\tCadastro do Cliente\n\n");
    printf("   Nome: ");
    scanf(" %[^\n]", nome);
    printf("   CPF (formato: apenas numeros): ");
    long int cpf = 0;
    scanf(" %ld", &cpf);
    char endereco[100];
    printf("   Endereço: ");
    scanf(" %[^\n]", endereco);
    char pagamento[9];
    printf("   Metodo de pagamento: ");
    printf("\n   1 - Cartao");
    printf("\n   2 - Dinheiro");
    printf("\n   Digite: ");
    int pagamento_escolha;
    scanf("%i", &pagamento_escolha);

    if(pagamento_escolha==1){
        sprintf(pagamento, "%s", "Cartao");
    }
    else if(pagamento_escolha==2){
        sprintf(pagamento, "%s", "Dinheiro");
    }
    else{
        puts("Entrada Invalida!");
    }
    printf("-----------------------------------------------\n");

    Cliente* c = cria_Cliente(nome, cpf, endereco, pagamento);

    printf("\n\n-----------------------------------------------");
    printf("\n              Registro do Cliente              \n");
    printa_Cliente(c);
    printf("-----------------------------------------------");
    delay (3);
    return c;
}

// Função que cria e preenche os dados de um Cliente, em caso de sucesso retorna a instância criada, em erro finaliza o programa
Cliente* cria_Cliente(char* nome, long int cpf, char* endereco, char *pagamento){
    Cliente* c = malloc(sizeof(Cliente));
    if(!c){
        printf("Memória insuficiente.\n");
        exit(1);
    }
    c->prox = NULL;
    snprintf(c->nome, 50, "%s", nome);
    c->cpf = cpf;
    snprintf(c->endereco, 100, "%s", endereco);
    snprintf(c->pagamento, 50, "%s", pagamento);

    return c;
}

// Função que printa na tela os dados do cliente
void printa_Cliente(Cliente* c) {
    printf("Nome: %s\n", c->nome);
    printf("CPF: %ld\n", c->cpf);
    printf("Endereco: %s\n", c->endereco);
    printf("Metodo de pagamento: %s\n", c->pagamento);
}

// Função que insere um cliente na tabela
void hash_insere(Hash* tab, Cliente *cliente) {
    long int h = hash(cliente->cpf);

    if (tab->clientes[h]) {
        Cliente *c = tab->clientes[h];
        for (; c->prox; c = c->prox);
        c->prox = cliente;
    } else {
        tab->clientes[h] = cliente;
    }

    printf("\n\n*********************************************\n");
    printf("\n** Cliente inserido na tabela com sucesso! **\n");
    printf("\n*********************************************\n");
    delay(3);
}

// Função que mostra os clientes cadastrados na tabela
void hash_imprime(Hash* tab) {
    printf("\n\n-----------------------------------------------");
    printf("\n               Tabela de Clientes            \n\n");
    for(int i = 0; i < 101; i++){
        if (tab->clientes[i]) {
            printa_Cliente(tab->clientes[i]);
            printf("\n");
        }
    }
    printf("-----------------------------------------------\n\n");
}

// Função que busca um cliente específico na tabela
Cliente* hash_busca (Hash* tab, long int cpf){
    int h = hash(cpf);
    Cliente* c = tab->clientes[h];

    while(c != NULL){
        if(c->cpf == cpf){
            printf("\n\t***** Cliente do CPF %ld foi encontrado na tabela! ******\n", cpf);
            delay(3);
            limpar();
            printf("\n***************************************************\n");
            printf("\n********        Realize seu pedido        *********\n");
            printf("\n***************************************************\n");
            delay(4);
            return c;
        }
        c = c->prox;
    }
    printf("\n\t***** Cliente do CPF %ld nao foi encontrado na tabela! ******\n", cpf);
    delay(2);
    return NULL;
}

// Função que remove um cliente específico da tabela
void hash_removecliente(Hash* tab, long int cpf){
    long int h = hash(cpf);

    Cliente* c = tab->clientes[h];
    if (!c) return;

    Cliente *aDeletar = NULL;

    if (c->cpf == cpf) {
        aDeletar = c;
        tab->clientes[h] = c->prox;
        free(aDeletar);
    }
    else {
        while(c->prox != NULL){
            if (c->prox->cpf == cpf) {
                aDeletar = c->prox;
                c->prox = c->prox->prox;
                free(aDeletar);
                break;
            }
            c = c->prox;
        }
    }
    printf("\n***************************************************\n");
    printf("\n***** Cliente removido da tabela com sucesso! *****\n");
    printf("\n***************************************************\n");
    delay(2);
}

// Função que retorna a quantidade de elementos na tabela
int qtd_elementos_tab(Hash* tab){
    int total = 0;
    for(int i = 0; i < 101; i++) {
        for(Cliente* c = tab->clientes[i]; c; c = c->prox, total++);
    }
    return total;
}

// Função retorna o tamanho da tabela e verifica se ela está vazia ou não
int hash_estaVazia (Hash *tab){
    return qtd_elementos_tab(tab) != 0;
}

// Função que cria o vetor de ponteiros,percorre os clientes da tabela e preenche o conteúdo do vetor
Cliente** criar_vetor(int n, Hash* tab){
    Cliente** vet = calloc(n, sizeof(Cliente*));
    for (int i = 0, j = 0; i < 101 && j < n; i++) {
        for (Cliente* c = tab->clientes[i]; c; c = c->prox){
            vet[j] = c;
            j += 1;
        }
    }

    return vet;
}

// Função que dada a tabela de dispersão já preenchida conta o número de elementos, cria o vetor, compara e ordena-os alfabeticamente
void ordenar_alfabeticamente(Hash* tab) {
    int n = qtd_elementos_tab(tab);
    Cliente** vet = criar_vetor(n, tab);

    for (int i = 0; i < n; i += 1) {
        for (int j = i + 1; j < n; j += 1) {
            if (strcmp(vet[i]->nome, vet[j]->nome) > 0) {
                Cliente *temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
    limpar();
    printf("\n--------------------------------------------------------\n");
    printf("       Tabela de clientes ordenados alfabeticamente       \n");

    for (int i = 0; i < n; i++){
        printa_Cliente(vet[i]);
        printf("\n");
    }
    printf("--------------------------------------------------------\n");
    free(vet);
}

// Função que ordena a tabela de clientes por ordem alfabetica
void hash_imprimeOrdenado (Hash* tab){
   ordenar_alfabeticamente(tab);
}

// Função que escreve os dados do cliente no arquivo
void escreveCliente(FILE* arquivo, const Cliente *c) {
    if (c) {
        fprintf(arquivo, "%s\n%li\n%s\n%s\n\n", c->nome, c->cpf, c->endereco, c->pagamento);
    }
}

// Função que lê os dados de um cliente presente no arquivo da tabela de clientes
void leHashArquivo(Hash *tab) {
    FILE* arquivo;
    arquivo = fopen("Clientes/tabela.txt", "r");
    if(arquivo == NULL) return;

    int long cpf;
    char nome[81], endereco[50], pagamento[10];
    while (fscanf(arquivo, "%[^\n]\n%li\n%[^\n]\n%s\n\n", nome, &cpf, endereco, pagamento) == 4) {
        int hash_gerada = hash(cpf);
        Cliente * cliente = cria_Cliente(nome, cpf, endereco, pagamento);
        tab->clientes[hash_gerada] = cliente;
    }
    fclose(arquivo);
}


// Função que escreve os dados do cliente da tabela no arquivo
int salvaClientes(char const* caminho, const Hash* hash){
    FILE* arquivo;
    arquivo = fopen(caminho, "w");
    if(arquivo == NULL) return 0;

    Cliente* c = hash->clientes[0];
    for(int i = 0; i < hash->tamanho; i++, c = hash->clientes[i]) {
        escreveCliente(arquivo, c);
    }
    fclose(arquivo);
    return 1;
}

// Função que gera a nota fiscal do cliente com todos os produtos comprados por ele
void imprimeNotaFiscal(const Cliente *cliente, const TabelaDeProdutos *produtos) {
    if (!temProdutos(produtos)) return;

    FILE *notaFiscal;
    notaFiscal = fopen("Clientes/nota_fiscal.txt", "at");
    if(notaFiscal==NULL) return;

    const char* cabecalho = "                            ---NaAcademia Bar---\n                          CNPJ: 34.874.313/0302-77\n";

    const char* meio = "Iten(s)              Codigo                             Valor\n";

    const char* separador = "-------------------------------------------------------------------------------\n";

    fprintf(notaFiscal, "%s", separador);
    fprintf(notaFiscal, "%s", cabecalho);
    fprintf(notaFiscal, "%s", separador);

    escreveCliente(notaFiscal, cliente);

    fprintf(notaFiscal, "%s", separador);
    fprintf(notaFiscal, "%s", meio);
    fprintf(notaFiscal, "%s", separador);

    int quantidadeTotal = escreveProdutos(notaFiscal, produtos);

    fprintf(notaFiscal, "%s", separador);

    fprintf(notaFiscal, "Quantidade Total: %i                                 ", quantidadeTotal);
    fprintf(notaFiscal, "| Total: R$ %.2lf\n", valorTotal(produtos));

    fprintf(notaFiscal, "%s", separador);

    fclose(notaFiscal);

}

// Função que libera a tabela
void hash_libera (Hash* tab) {
    for(int i = 0; i < 101; i++) {
        free(tab->clientes[i]);
    }
    free(tab);
}
