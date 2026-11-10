#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "rotinas.h"
#include "compromissos.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        system("cls"); // Limpa a tela ao retornar ao menu principal
        printf("========================================\n");
        printf("       📅 SCHEDULA - AGENDA INTELIGENTE   \n");
        printf("========================================\n");
        printf("1. Cadastrar Atividade Recorrente\n");
        printf("2. Listar Rotinas Recorrentes\n");
        printf("3. Cadastrar Compromisso Pontual\n");
        printf("4. Listar Compromissos Pontuais\n");
        printf("5. Visualizar Agenda Integrada do Dia\n");
        printf("0. Sair\n");
        printf("----------------------------------------\n");
        printf("Escolha sua opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\n[Erro] Entrada inválida! Digite um número.\n");
            system("pause");
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarRotina();
                break;
            case 2:
                listarRotinas();
                break;
            case 3:
                cadastrarCompromisso();
                break;
            case 4:
                listarCompromissos();
                break;
            case 5:
                visualizarAgendaDia();
                break;
            case 0:
                system("cls");
                printf("\nEncerrando o Schedula. Até logo!\n");
                break;
            default:
                printf("\n[Erro] Opção inválida! Tente novamente.\n");
                system("pause");
        }
    } while (opcao != 0);

    return 0;
}
