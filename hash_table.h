#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Define o tamanho da tabela hash
#define TABLE_SIZE 100

// Estrutura que representa um concurso
typedef struct Concurso {
    int numero;           // Número do concurso
    char data[11];        // Data do concurso no formato dd-mm-yyyy + terminador nulo
    int bolas[6];         // Números sorteados no concurso
    struct Concurso* next; // Ponteiro para o próximo concurso na lista encadeada (usado para tratamento de colisões)
} Concurso;

// Estrutura que representa a tabela hash
typedef struct HashTable {
    Concurso* table[TABLE_SIZE]; // Array de ponteiros para concursos. Cada índice da tabela pode ter uma lista encadeada de concursos.
} HashTable;

// Função para inicializar a tabela hash
void init_hash_table(HashTable* table);

// Função para inserir um novo concurso na tabela hash
void insert(HashTable* table, Concurso concurso);

// Função para buscar um concurso específico pelo número
Concurso* search(HashTable* table, int numero);

// Função para remover um concurso da tabela hash
void remove_concurso(HashTable* table, int numero);

// Função para imprimir todos os concursos armazenados na tabela hash
void print_all(HashTable* table);

// Função para carregar concursos de um arquivo e inseri-los na tabela hash
void load_from_file(HashTable* table, const char* filename);

// Função para limpar a tabela hash, liberando toda a memória alocada
void clear_table(HashTable* table);

// Função para contar quantas vezes um número específico foi sorteado em todos os concursos
void quantidade_sorteios_numero(HashTable* table);

// Função para encontrar e imprimir os dez números mais sorteados
void dez_numeros_mais_sorteados(HashTable* table);

// Função para encontrar e imprimir os dez números menos sorteados
void dez_numeros_menos_sorteados(HashTable* table);

// Função para contar e listar os concursos realizados em um determinado ano
void quantidade_concursos_ano(HashTable* table);

#endif // HASH_TABLE_H
