#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "hash_table.h"

// Função que imprime os detalhes de um concurso específico
// Recebe um ponteiro para a estrutura Concurso
void print_concurso(Concurso* concurso) {
    if (concurso) { // Verifica se o concurso existe
        // Imprime o número do concurso
        printf("Número do Concurso: %d\n", concurso->numero);
        // Imprime a data do concurso
        printf("Data: %s\n", concurso->data);
        // Imprime os números sorteados
        printf("Números sorteados: ");
        for (int i = 0; i < 6; i++) {
            printf("%d ", concurso->bolas[i]);
        }
        printf("\n");
    } else {
        // Mensagem de erro se o concurso não for encontrado
        printf("Concurso não encontrado.\n");
    }
}

// Função principal do menu que exibe as opções disponíveis e processa a escolha do usuário
// Recebe um ponteiro para a tabela hash que armazena os concursos
void menu(HashTable* table) {
    int option; // Variável para armazenar a escolha do usuário
    do {
        // Exibe as opções do menu principal
        printf("Menu:\n");
        printf("1. Inserir Concurso\n");
        printf("2. Buscar Concurso\n");
        printf("3. Remover Concurso\n");
        printf("4. Visualizar Todos os Concursos\n");
        printf("5. Carregar Concursos de um Arquivo\n");
        printf("6. Apresentar Estatísticas\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option); // Lê a escolha do usuário

        int numero_concurso; // Variável para armazenar o número do concurso
        Concurso concurso; // Estrutura para armazenar os dados de um concurso

        // Processa a escolha do usuário
        switch (option) {
            case 1:
                // Insere um novo concurso na tabela
                printf("Número do Concurso: ");
                scanf("%d", &concurso.numero); // Lê o número do concurso
                printf("Data (dd-mm-yyyy): ");
                scanf("%s", concurso.data); // Lê a data do concurso
                printf("Digite os 6 números sorteados: ");
                for (int i = 0; i < 6; i++) {
                    scanf("%d", &concurso.bolas[i]); // Lê os números sorteados
                }
                insert(table, concurso); // Insere o concurso na tabela hash
                break;
            case 2:
                // Busca um concurso na tabela e exibe seus detalhes
                printf("Número do Concurso: ");
                scanf("%d", &numero_concurso); // Lê o número do concurso a ser buscado
                Concurso* encontrado = search(table, numero_concurso); // Busca o concurso na tabela
                print_concurso(encontrado); // Imprime os detalhes do concurso encontrado
                break;
            case 3:
                // Remove um concurso da tabela
                printf("Número do Concurso: ");
                scanf("%d", &numero_concurso); // Lê o número do concurso a ser removido
                remove_concurso(table, numero_concurso); // Remove o concurso da tabela
                break;
            case 4:
                // Exibe todos os concursos armazenados na tabela
                print_all(table);
                break;
            case 5:
                // Carrega concursos a partir de um arquivo
                printf("Nome do arquivo: ");
                char filename[100];
                scanf("%s", filename); // Lê o nome do arquivo
                filename[strcspn(filename, "\n")] = 0; // Remove o newline no final da string, se houver
                load_from_file(table, filename); // Carrega os concursos do arquivo para a tabela
                break;
            case 6:
                // Apresenta as estatísticas dos concursos
                apresentar_estatisticas(table);
                break;
            case 7:
                // Sai do programa
                printf("Saindo...\n");
                break;
            default:
                // Mensagem de erro para opções inválidas
                printf("Opção inválida!\n");
        }
    } while (option != 7); // Continua exibindo o menu até o usuário escolher sair

    printf("Menu encerrado.\n"); // Mensagem final ao encerrar o menu
}

// Função que exibe o menu de estatísticas e processa a escolha do usuário
// Recebe um ponteiro para a tabela hash que armazena os concursos
void apresentar_estatisticas(HashTable* table) {
    int sub_option; // Variável para armazenar a escolha do usuário no menu de estatísticas
    do {
        // Exibe as opções do menu de estatísticas
        printf("Estatísticas:\n");
        printf("1. Quantidade de sorteios de um número\n");
        printf("2. Dez Números Mais Sorteados\n");
        printf("3. Dez Números Menos Sorteados\n");
        printf("4. Quantidade de concursos em um determinado ano\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &sub_option); // Lê a escolha do usuário

        // Processa a escolha do usuário no menu de estatísticas
        switch (sub_option) {
            case 1:
                // Chama a função que conta a quantidade de sorteios de um número específico
                quantidade_sorteios_numero(table);
                break;
            case 2:
                // Chama a função que mostra os dez números mais sorteados
                dez_numeros_mais_sorteados(table);
                break;
            case 3:
                // Chama a função que mostra os dez números menos sorteados
                dez_numeros_menos_sorteados(table);
                break;
            case 4:
                // Chama a função que mostra a quantidade de concursos de um ano específico
                quantidade_concursos_ano(table);
                break;
            case 5:
                // Retorna ao menu principal
                printf("Retornando ao Menu Principal...\n");
                break;
            default:
                // Mensagem de erro para opções inválidas
                printf("Opção inválida!\n");
        }
    } while (sub_option != 5); // Continua exibindo o menu de estatísticas até o usuário escolher voltar
}
