/* 
**    Função : Arquivo de teste do Sistema de Agendamento de Consultas
**    Autor : Jucieélen Valéria Souza - Turma P2 A
**    Data  : 05/06/2025
**    Observações: Programa principal com menu de interação
*/

#include <stdio.h>
#include <string.h>
#include "ED-lista2-questao02.h"

int main() {
    FilaEstatica filaMedico;
    FilaDinamica filaEnfermagem;
    Paciente p;
    int op;

    inicializarFilaEstatica(&filaMedico);
    inicializarFilaDinamica(&filaEnfermagem);

    do {
        printf("\n1 - Agendar Médico\n2 - Agendar Enfermagem\n3 - Exibir Filas\n0 - Sair\n");
        scanf("%d", &op);
        getchar(); // Limpar buffer

        switch(op) {
            case 1:
                printf("Nome: ");
                fgets(p.nome, 50, stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &p.idade);
                strcpy(p.especialidade, "Médico");
                inserirFilaEstatica(&filaMedico, p);
                break;

            case 2:
                printf("Nome: ");
                fgets(p.nome, 50, stdin);
                p.nome[strcspn(p.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &p.idade);
                strcpy(p.especialidade, "Enfermagem");
                inserirFilaDinamica(&filaEnfermagem, p);
                break;

            case 3:
                exibirFilaEstatica(&filaMedico);
                exibirFilaDinamica(&filaEnfermagem);
                break;
        }
    } while(op != 0);

    return 0;
}
