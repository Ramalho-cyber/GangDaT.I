#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "rotinas.h"

void cadastrarCompromisso() {
    system("cls");
    Compromisso c;

    printf("--- Cadastro de Compromisso Eventual ---\n");
    printf("Data (DD MM AAAA): ");
    scanf("%d %d %d", &c.dia, &c.mes, &c.ano);

    printf("Horario (HH MM): ");
    scanf("%d %d", &c.hora, &c.minuto);

    printf("Descricao do compromisso: ");
    scanf("%s", c.descricao);

    salvarCompromissoNoArquivo(c);
}

void salvarCompromissoNoArquivo(Compromisso c) {
    FILE *file = fopen(ARQ_COMPROMISSOS, "ab");
    if (file == NULL) {
        printf("\n[Erro critico] Nao foi possível abrir o arquivo de compromissos para gravacao!\n");
        system("pause");
        return;
    }
    fwrite(&c, sizeof(Compromisso), 1, file);
    fclose(file);
    printf("\n[Sucesso] Compromisso pontual salvo com sucesso!\n");
    system("pause");
}

void listarCompromissos() {
    system("cls");
    FILE *file = fopen(ARQ_COMPROMISSOS, "rb");
    if (file == NULL) {
        printf("\n[Aviso] Nenhum compromisso eventual cadastrado.\n");
        system("pause");
        return;
    }

    Compromisso c;
    printf("========================================\n");
    printf("      COMPROMISSOS PONTUAIS CADASTRADOS \n");
    printf("========================================\n");

    int encontrados = 0; // Variável declarada corretamente aqui
    while (fread(&c, sizeof(Compromisso), 1, file) == 1) {
        printf("Data: %02d/%02d/%d as %02d:%02d -> %s\n", c.dia, c.mes, c.ano, c.hora, c.minuto, c.descricao);
        encontrados++;
    }
    fclose(file);

    if (encontrados == 0) {
        printf("Nenhum compromisso cadastrado.\n");
    }
    printf("\n");
    system("pause");
}

void visualizarAgendaDia() {
    system("cls");
    int d, m, a, diaSemanaFiltro;

    printf("--- Visualizar Agenda do Dia ---\n");
    printf("Informe a data desejada (DD MM AAAA): ");
    scanf("%d %d %d", &d, &m, &a);

    printf("Informe o dia da semana correspondente (0-Domingo a 6-Sábado): ");
    scanf("%d", &diaSemanaFiltro);

    system("cls");
    printf("========================================\n");
    printf(" AGENDA PARA %02d/%02d/%d (%s)\n", d, m, a, diasSemanaStr[diaSemanaFiltro]);
    printf("========================================\n");

    // Exibir Rotinas Recorrentes para este dia da semana
    printf("\n[ ROTINAS RECORRENTES ]\n");
    FILE *fileR = fopen(ARQ_ROTINAS, "rb");
    if (fileR != NULL) {
        RotinaRecorrente r;
        int countR = 0;
        while (fread(&r, sizeof(RotinaRecorrente), 1, fileR) == 1) {
            if (r.diaSemana == diaSemanaFiltro) {
                printf(" - %02d:%02d -> %s\n", r.hora, r.minuto, r.descricao);
                countR++;
            }
        }
        fclose(fileR);
        if (countR == 0) printf(" Nenhuma rotina fixa para este dia.\n");
    } else {
        printf(" Nenhuma rotina cadastrada.\n");
    }

    // Exibir Compromissos Eventuais para esta data exata
    printf("\n[ COMPROMISSOS PONTUAIS ]\n");
    FILE *fileC = fopen(ARQ_COMPROMISSOS, "rb");
    if (fileC != NULL) {
        Compromisso c;
        int countC = 0;
        while (fread(&c, sizeof(Compromisso), 1, fileC) == 1) {
            if (c.dia == d && c.mes == m && c.ano == a) {
                printf(" - %02d:%02d -> %s\n", c.hora, c.minuto, c.descricao);
                countC++;
            }
        }
        fclose(fileC);
        if (countC == 0) printf(" Nenhum compromisso pontual nesta data.\n");
    } else {
        printf(" Nenhum compromisso cadastrado.\n");
    }
    printf("========================================\n\n");
    system("pause");
}
