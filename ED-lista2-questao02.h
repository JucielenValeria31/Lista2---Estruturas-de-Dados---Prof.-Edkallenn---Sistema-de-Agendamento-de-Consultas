/* 
**    Função : Arquivo de cabeçalho para Sistema de Agendamento de Consultas
**    Autor : Jucieélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Definição das estruturas e protótipos das funções
*/

#ifndef AGENDA_H
#define AGENDA_H

#define TAM 5

typedef struct {
    char nome[50];
    int idade;
    char especialidade[30]; // Médico ou Enfermagem
} Paciente;

// Fila Estática
typedef struct {
    Paciente fila[TAM];
    int inicio, fim;
} FilaEstatica;

// Fila Dinâmica
typedef struct No {
    Paciente paciente;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} FilaDinamica;

// Funções Fila Estática
void inicializarFilaEstatica(FilaEstatica *f);
int filaEstaticaCheia(FilaEstatica *f);
int filaEstaticaVazia(FilaEstatica *f);
void inserirFilaEstatica(FilaEstatica *f, Paciente p);
void exibirFilaEstatica(FilaEstatica *f);

// Funções Fila Dinâmica
void inicializarFilaDinamica(FilaDinamica *f);
void inserirFilaDinamica(FilaDinamica *f, Paciente p);
void exibirFilaDinamica(FilaDinamica *f);

#endif
