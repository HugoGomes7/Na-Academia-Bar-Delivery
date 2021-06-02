
#include <stdio.h> // Include para entrada e saída e manipulação de arquivos
#include <stdlib.h> // Include para alocação

#include "outras_funcoes.h" // Include da TAD de outras funções
#include "clientes.h" // Include para importar a TAD dos clientes
#include "menus.h" // Include da TAD dos menus
#include "produtos.h" // Include para importar a TAD dos produtos

// Menu principal resposável por gerenciar o projeto
void menu(){
    while(1) {
        int escolha=0;
        limpar();
        printf("-----------------------------------------------\n");
        printf("      NaAcademia Bar - Delivery                \n");
        printf("-----------------------------------------------\n");
        printf("   1 - Para inicializar o atendimento.         \n");
        printf("   2 - Para finalizar o programa.              \n");
        printf("-----------------------------------------------\n");
        printf("Escolha: ");
        scanf("%i", &escolha);
        if (escolha == 1) atendimentoPrincipal();
        else if(escolha == 2) break;
        else {
            puts("escolha um numero valido!");
            delay(2);
        }
    }
}

// Função da interface do menu de opções de cadastros e pedidos
void atendimentoPrincipal(){
  Hash* tab = hash_cria();
  long int cpf;
    while(1){
        int escolha;
        limpar();
        printf("---------------------------------------------------\n");
        printf("       Bem vindo ao NaAcademia Bar                 \n");
        printf("---------------------------------------------------\n");
        printf("   1 - Para fazer cadastro do cliente.             \n");
        printf("   2 - Para fazer o pedido.                        \n");
        printf("   3 - Para remover clientes cadastrados.          \n");
        printf("   4 - Para exibir os clientes em ordem alfabética.\n");
        printf("   5 - Retornar ao menu.                           \n");
        printf("---------------------------------------------------\n");
        printf("Digite: ");

        scanf("%d", &escolha);

        if(escolha == 1) {
          Cliente* cliente = cadastro();
          hash_insere(tab, cliente);
          salvaClientes("Clientes/tabela.txt", tab);
          delay(2);
        }
        else if (escolha == 2) {
          if(hash_estaVazia(tab) == 0){
            printf("\nBase de usuarios vazia, primeiro crie um usuario.\n");
            delay(1);
          }
          else{
          hash_imprime(tab);
          printf("Digite o CPF do cliente para realizar o pedido: ");
          scanf("%ld", &cpf);
          Cliente* c = hash_busca(tab, cpf);
          delay(2);
            if(c){
              cardapio(c);
            }
            else {
              printf("\n\tPrimeiro cadastre um cliente ou insira um cpf um valido.\n");
              delay(3);
            }
          }
        }
        else if (escolha == 3) {
            if(hash_estaVazia(tab) == 0){
                printf("\nBase de usuarios vazia, primeiro crie um usuario.\n");
                delay(1);
            }
            else{
                limpar();
                hash_imprime(tab);
                printf("Digite o CPF do cliente que deseja remover da tabela: ");
                scanf("%li", &cpf);
                hash_removecliente(tab, cpf);
                salvaClientes("Clientes/tabela.txt", tab);
                delay(1);
            }
        }
        else if(escolha == 4){
          if(hash_estaVazia(tab) == 0){
            printf("\nBase de usuarios vazia, primeiro crie um usuario.\n");
            delay(1);
          }
          else {
            hash_imprimeOrdenado(tab);
            salvaClientes("Clientes/tabela.txt", tab);
            delay(5);
          }
        }
        else if (escolha == 5) break;
        else {
            puts("Entrada invalida!");
            delay(3);
        }
    }
    hash_libera(tab);

}

// Função da interface central de cardapios de pedidos
void cardapio(Cliente* cliente){
    TabelaDeProdutos *produtos = criaTabelaDeProdutos();
    while(1){
        int escolha=0;
        limpar();
        printf("-----------------------------------------------\n");
        printf("                   CARDAPIO                    \n");
        printf("-----------------------------------------------\n");
        printf("   1 - Petiscos                                \n");
        printf("   2 - Cervejas.                               \n");
        printf("   3 - Destilados.                             \n");
        printf("   4 - Cachacas.                               \n");
        printf("   5 - Bebidas nao alcoolicas.                 \n");
        printf("   6 - Concluir pedido.                        \n");
        printf("-----------------------------------------------\n");
        printf("\nEscolha: ");
        scanf("%d", &escolha);
        if(escolha == 1) petiscos(produtos);
        else if(escolha == 2) cervejas(produtos);
        else if(escolha == 3) destilados(produtos);
        else if(escolha == 4) cachacas(produtos);
        else if(escolha == 5) bebnalc(produtos);
        else if(escolha == 6) {
          printf("\n\t********* Pedido concluido com sucesso! *********\n");
          delay(3);
          printf("\n  ********* A nota fiscal do seu pedido foi gerada em um arquivo txt *********\n");
          delay(3);
          printf("\n\t\tRetornando ao menu de atendimento\n");
          delay(2);
          break;
        }
        else {
            puts("entrada invalida!");
            delay(2);
        }
    }

    imprimeNotaFiscal(cliente, produtos);
    liberaTabelaDeProdutos(produtos);
}

// Função com o cardapio de petiscos
void petiscos(TabelaDeProdutos* tabelaDeProdutos) {
    limpar();
    int entrada = 0;
    while (1){
        limpar();
        printf("\n_____________________________________________________________\n");
        printf("|_______Petiscos______||______Preco______||______Codigo_____|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--File-com-fritas----||---R$ 20,00------||--------1--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Calafritas---------||---R$ 15,00------||--------2--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Frango-com-fritas--||---R$ 18,00------||--------3--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Camarao-com-fritas-||---R$ 25,00------||--------4--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|_____________________||_________________||_________________|\n");
        printf("Informe o codigo (0 para voltar): ");
        scanf("%d", &entrada);
        if (entrada == 0) break;
        if (entrada > 0 && entrada < 5){
            adicionaProduto(tabelaDeProdutos, criaProduto(entrada));
            printf("\n********* Pedido realizado com sucesso! *********\n");
            delay(2);

        }
        else {
            printf("\nCodigo invalido para essa secao, tente novamente.\n");
            delay(2);
        }
    }
}

// Função com o cardapio de cervejas
void cervejas(TabelaDeProdutos* tabelaDeProdutos) {
    limpar();
    int entrada = 0;
    while (1) {
        limpar();
        printf("\n_____________________________________________________________\n");
        printf("|_______Cervejas______||______Preco______||______Codigo_____|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Heineken-----------||---R$ 6,00-------||--------5--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Corona-------------||---R$ 5,00-------||--------6--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Stella-------------||---R$ 5,00-------||--------7--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Budweiser----------||---R$ 6,00-------||--------8--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Petra--------------||---R$ 3,00-------||--------9--------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Itaipava-----------||---R$ 2,50-------||--------10-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Brahma-------------||---R$ 3,00-------||--------11-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Bohemia------------||---R$ 3,00-------||--------12-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Amstel-------------||---R$ 5,00-------||--------13-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Eisenbahn----------||---R$ 5,00-------||--------14-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|_____________________||_________________||_________________|\n");
        printf("Informe o codigo (0 para voltar): ");
        scanf("%d", &entrada);
        if (entrada == 0) break;
        if (entrada > 4 && entrada < 15) {
          adicionaProduto(tabelaDeProdutos, criaProduto(entrada));
          printf("\n********* Pedido realizado com sucesso! *********\n");
          delay(2);
        }
        else {
            printf("\nCodigo invalido para essa secao, tente novamente.\n");
            delay(2);
        }
    }
}

// Função com o cardapio de destilados
void destilados(TabelaDeProdutos* tabelaDeProdutos) {
    limpar();
    int entrada = 0;
    while (1) {
        limpar();
        printf("\n_____________________________________________________________\n");
        printf("|______Destilados_____||______Preco______||______Codigo_____|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Vodka-Smirnoff-----||---R$ 33,90------||--------15-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Vodka-Absolut------||---R$ 85,72------||--------16-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Vodka-Skyy---------||---R$ 43,90------||--------17-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Montila------------||---R$ 17,90------||--------18-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Whishky-Old-Parr---||---R$ 127,84-----||--------19-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Whishky-JackDaniels||---R$ 159,99-----||--------20-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Whishky-Red-Label--||---R$ 89,90------||--------21-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Whishky-Ballantines||---R$ 91,30------||--------22-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|_____________________||_________________||_________________|\n");
        printf("Informe o codigo (0 para voltar): ");
        scanf("%d", &entrada);
        if (entrada == 0) break;
        else if (entrada > 14 && entrada < 23) {
          adicionaProduto(tabelaDeProdutos, criaProduto(entrada));
          printf("\n********* Pedido realizado com sucesso! *********\n");
          delay(2);
        }
        else {
            printf("\nCodigo invalido para essa secao, tente novamente.\n");
            delay(2);
        }
    }
}

// Função com o cardapio de cachaças
void cachacas(TabelaDeProdutos* tabelaDeProdutos) {
    limpar();
    int entrada = 0;
    while (1) {
        limpar();
        printf("\n_____________________________________________________________\n");
        printf("|_______Cachacas______||______Preco______||______Codigo_____|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Cachaca-Cabare-----||---R$ 38,90------||--------23-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Cachaca-51---------||---R$ 8,99-------||--------24-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Cachaca-Ypioca-----||---R$ 14,90------||--------25-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Ypioca 965ml-------||---R$ 14,90------||--------26-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Ypioca-Lata--------||---R$ 5,00-------||--------27-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|_____________________||_________________||_________________|\n");
        printf("Informe o codigo (0 para voltar): ");
        scanf("%d", &entrada);
        if (entrada == 0) break;
        if (entrada > 22 && entrada < 28) {
          adicionaProduto(tabelaDeProdutos, criaProduto(entrada));
          printf("\n********* Pedido realizado com sucesso! *********\n");
          delay(2);
        }
        else {
            printf("\nCodigo invalido para essa secao, tente novamente.\n");
            delay(2);
        }
    }
}

// Função com o cardapio de bebidas não alcoólicas
void bebnalc(TabelaDeProdutos* tabelaDeProdutos) {
    limpar();
    int entrada = 0;
    while (1) {
        limpar();
        printf("\n_____________________________________________________________\n");
        printf("|_______Bebidas_______||______Preco______||______Codigo_____|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Energetico-Fusion--||---R$ 12,00------||--------28-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Energetico-Red-Bull||---R$ 11,00------||--------29-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Energetico-TNT-----||---R$ 5,00-------||--------30-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Agua-de-Coco-------||---R$ 4,00-------||--------31-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|--Agua-com-Gas-------||---R$ 2,50-------||--------32-------|\n");
        printf("|---------------------||-----------------||-----------------|\n");
        printf("|_____________________||_________________||_________________|\n");
        printf("Informe o codigo (0 para voltar): ");
        scanf("%d", &entrada);
        if (entrada == 0) break;
        if (entrada > 27 && entrada < 33) {
          adicionaProduto(tabelaDeProdutos, criaProduto(entrada));
          printf("\n********* Pedido realizado com sucesso! *********\n");
          delay(2);
        }
        else {
            printf("\nCodigo invalido para essa secao, tente novamente.\n");
            delay(2);
        }
    }
}
