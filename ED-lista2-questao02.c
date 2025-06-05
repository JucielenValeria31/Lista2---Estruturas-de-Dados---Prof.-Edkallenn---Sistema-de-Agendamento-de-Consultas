/* 
**    Função : Implementação das funções do Sistema de Agendamento de Consultas
**    Autor : Juciélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Implementação das funções declaradas no .h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ED-lista2-questao02.h"

// Fila Estática
void inicializarFilaEstatica(FilaEstatica *f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaEstaticaCheia(FilaEstatica *f) {
    return f->fim == TAM;
}

int filaEstaticaVazia(FilaEstatica *f) {
    return f->inicio == f->fim;
}

void inserirFilaEstatica(FilaEstatica *f, Paciente p) {
    if(filaEstaticaCheia(f)) {
        printf("Fila de Médico cheia!\n");
    } else {
        f->fila[f->fim++] = p;
    }
}

void exibirFilaEstatica(FilaEstatica *f) {
    printf("Fila de Médico:\n");
    for(int i = f->inicio; i < f->fim; i++) {
        printf("%s, %d anos\n", f->fila[i].nome, f->fila[i].idade);
    }
}

// Fila Dinâmica
void inicializarFilaDinamica(FilaDinamica *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserirFilaDinamica(FilaDinamica *f, Paciente p) {
    No *novo = (No*) malloc(sizeof(No));
    novo->paciente = p;
    novo->prox = NULL;
    if(f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void exibirFilaDinamica(FilaDinamica *f) {
    No* aux = f->inicio;
    printf("Fila de Enfermagem:\n");
    while(aux != NULL) {
        printf("%s, %d anos\n", aux->paciente.nome, aux->paciente.idade);
        aux = aux->prox;
    }
}
