#ifndef MENU_H
#define MENU_H

#include "hash_table.h" // Inclui o cabeçalho que define a estrutura e as funções da tabela hash

// Função principal do menu. Exibe as opções disponíveis e processa as escolhas do usuário.
// O parâmetro 'table' é um ponteiro para a tabela hash que armazena os concursos.
void menu(HashTable* table);

// Função auxiliar que imprime os detalhes de um concurso específico.
// O parâmetro 'concurso' é um ponteiro para a estrutura Concurso que será impressa.
void print_concurso(Concurso* concurso);

// Função que apresenta as estatísticas solicitadas pelo usuário.
// O parâmetro 'table' é um ponteiro para a tabela hash onde os concursos estão armazenados.
void apresentar_estatisticas(HashTable* table);

#endif // MENU_H
