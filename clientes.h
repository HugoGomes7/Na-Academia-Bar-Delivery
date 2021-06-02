#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "produtos.h" //Include para importar a TAD de produtos

        /*Estruturas*/
// Declaração do tipo Cliente da struct cliente
typedef struct cliente Cliente;
// Declaração do tipo Hash da struct hash
typedef struct hash Hash;

        /*Tabela de Dispersão*/
// Protótipo da função que cria uma hash
Hash* hash_cria (void);
// Protótipo da função de dispersão da hash usando o cpf
long int hash(int long cpf);

        /*Funções do cliente */
// Protótipo da função que faz o cadastro do cliente
Cliente* cadastro();
// Protótipo da função que cria um cliente
Cliente* cria_Cliente(char* nome, long int cpf, char* endereco, char *pagamento);
// Protótipo da função que printa os clientes na tela
void printa_Cliente(Cliente* c);
// Protótipo da função que imprime a nota fiscal do cliente
void imprimeNotaFiscal(const Cliente *cliente, const TabelaDeProdutos *produtos);

        /*Funções da Hash*/
// Protótipo da função que insere um cliente na hash
void hash_insere(Hash* tab, Cliente *cliente);
// Protótipo da função que imprime o(os) cliente(s) da hash
void hash_imprime (Hash* tab);
// Protótipo da função que busca o cliente conforme o seu cpf
Cliente* hash_busca (Hash* tab, long int cpf);
// Protótipo da função que remove o cliente da tabela conforme o seu cpf
void hash_removecliente (Hash* tab, long int cpf);
// Protótipo da função que retorna a quantidade de clientes da tabela
int qtd_elementos_tab(Hash* tab);
// Protótipo da função que verifica se a tabela está vazia
int hash_estaVazia (Hash *tab);
// Protótipo da função que imprime a tabela de clientes ordenada alfabeticamente
void hash_imprimeOrdenado (Hash* tab);
// Protótipo da função que libera a hash
void hash_libera (Hash* tab);

        /*Funções para manipulação de arquivos*/
// Protótipo da função que salva o cliente com seus dados em um arquivo
int salvaClientes(char const* caminho, const Hash* hash);
// Protótipo da função que escreve o cliente com seus dados em um arquivo
void escreveCliente(FILE* arquivo, const Cliente *c);
// Protótipo da função que lê o arquivo de uma hash de clientes
void leHashArquivo(Hash *tab);


#endif
