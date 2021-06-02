#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "produtos.h" //Include para importar a TAD de produtos

        /*Estruturas*/
// Declara��o do tipo Cliente da struct cliente
typedef struct cliente Cliente;
// Declara��o do tipo Hash da struct hash
typedef struct hash Hash;

        /*Tabela de Dispers�o*/
// Prot�tipo da fun��o que cria uma hash
Hash* hash_cria (void);
// Prot�tipo da fun��o de dispers�o da hash usando o cpf
long int hash(int long cpf);

        /*Fun��es do cliente */
// Prot�tipo da fun��o que faz o cadastro do cliente
Cliente* cadastro();
// Prot�tipo da fun��o que cria um cliente
Cliente* cria_Cliente(char* nome, long int cpf, char* endereco, char *pagamento);
// Prot�tipo da fun��o que printa os clientes na tela
void printa_Cliente(Cliente* c);
// Prot�tipo da fun��o que imprime a nota fiscal do cliente
void imprimeNotaFiscal(const Cliente *cliente, const TabelaDeProdutos *produtos);

        /*Fun��es da Hash*/
// Prot�tipo da fun��o que insere um cliente na hash
void hash_insere(Hash* tab, Cliente *cliente);
// Prot�tipo da fun��o que imprime o(os) cliente(s) da hash
void hash_imprime (Hash* tab);
// Prot�tipo da fun��o que busca o cliente conforme o seu cpf
Cliente* hash_busca (Hash* tab, long int cpf);
// Prot�tipo da fun��o que remove o cliente da tabela conforme o seu cpf
void hash_removecliente (Hash* tab, long int cpf);
// Prot�tipo da fun��o que retorna a quantidade de clientes da tabela
int qtd_elementos_tab(Hash* tab);
// Prot�tipo da fun��o que verifica se a tabela est� vazia
int hash_estaVazia (Hash *tab);
// Prot�tipo da fun��o que imprime a tabela de clientes ordenada alfabeticamente
void hash_imprimeOrdenado (Hash* tab);
// Prot�tipo da fun��o que libera a hash
void hash_libera (Hash* tab);

        /*Fun��es para manipula��o de arquivos*/
// Prot�tipo da fun��o que salva o cliente com seus dados em um arquivo
int salvaClientes(char const* caminho, const Hash* hash);
// Prot�tipo da fun��o que escreve o cliente com seus dados em um arquivo
void escreveCliente(FILE* arquivo, const Cliente *c);
// Prot�tipo da fun��o que l� o arquivo de uma hash de clientes
void leHashArquivo(Hash *tab);


#endif
