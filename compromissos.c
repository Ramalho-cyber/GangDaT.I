#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "rotinas.h"

/* ---------- Cadastro ---------- */

void cadastrarCompromisso() {
    Compromisso c;

    limparTela();
    puts("--- Cadastro de Compromisso Eventual ---");

    printf("Data (DD MM AAAA): ");
    scanf("%d %d %d", &c.dia, &c.mes, &c.ano);

    printf("Horário (HH MM): ");
    scanf("%d %d", &c.hora, &c.minuto);

    printf("Descrição do compromisso: ");
    scanf("%s", c.descricao);

    salvarCompromissoNoArquivo(c);
}

void salvarCompromissoNoArquivo(Compromisso c) {
    FILE *file = fopen(ARQ_COMPROMISSOS, "ab");

    if (!file) {
        puts("\n[Erro crítico] Não foi possível abrir o arquivo de compromissos para gravação!");
        pausar();
        return;
    }

    fwrite(&c, sizeof(Compromisso), 1, file);
    fclose(file);

    puts("\n[Sucesso] Compromisso pontual salvo com sucesso!");
    pausar();
}

/* ---------- Listagem ---------- */

void listarCompromissos() {
    limparTela();

    FILE *file = fopen(ARQ_COMPROMISSOS, "rb");
    if (!file) {
        puts("\n[Aviso] Nenhum compromisso eventual cadastrado.");
        pausar();
        return;
    }

    Compromisso c;
    int encontrados = 0;

    imprimirSeparador();
    puts("      COMPROMISSOS PONTUAIS CADASTRADOS ");
    imprimirSeparador();

    for (; fread(&c, sizeof(Compromisso), 1, file) == 1; encontrados++) {
        printf("Data: %02d/%02d/%d às %02d:%02d -> %s\n",
               c.dia, c.mes, c.ano, c.hora, c.minuto, c.descricao);
    }
    fclose(file);

    if (!encontrados) {
        puts("Nenhum compromisso cadastrado.");
    }

    printf("\n");
    pausar();
}

/* ---------- Agenda do dia ---------- */

void visualizarAgendaDia() {
    int d, m, a, diaSemanaFiltro;

    limparTela();
    puts("--- Visualizar Agenda do Dia ---");

    printf("Informe a data desejada (DD MM AAAA): ");
    scanf("%d %d %d", &d, &m, &a);

    printf("Informe o dia da semana correspondente (0-Domingo a 6-Sábado): ");
    scanf("%d", &diaSemanaFiltro);

    limparTela();
    imprimirSeparador();
    printf(" AGENDA PARA %02d/%02d/%d (%s)\n", d, m, a, diasSemanaStr[diaSemanaFiltro]);
    imprimirSeparador();

    /* Rotinas recorrentes do dia da semana */
    puts("\n[ ROTINAS RECORRENTES ]");
    FILE *fileR = fopen(ARQ_ROTINAS, "rb");
    if (!fileR) {
        puts(" Nenhuma rotina cadastrada.");
    } else {
        RotinaRecorrente r;
        int countR = 0;

        for (; fread(&r, sizeof(RotinaRecorrente), 1, fileR) == 1; ) {
            if (r.diaSemana != diaSemanaFiltro) continue;
            printf(" - %02d:%02d -> %s\n", r.hora, r.minuto, r.descricao);
            countR++;
        }
        fclose(fileR);

        if (!countR) puts(" Nenhuma rotina fixa para este dia.");
    }

    /* Compromissos eventuais da data exata */
    puts("\n[ COMPROMISSOS PONTUAIS ]");
    FILE *fileC = fopen(ARQ_COMPROMISSOS, "rb");
    if (!fileC) {
        puts(" Nenhum compromisso cadastrado.");
    } else {
        Compromisso c;
        int countC = 0;

        for (; fread(&c, sizeof(Compromisso), 1, fileC) == 1; ) {
            if (c.dia != d || c.mes != m || c.ano != a) continue;
            printf(" - %02d:%02d -> %s\n", c.hora, c.minuto, c.descricao);
            countC++;
        }
        fclose(fileC);

        if (!countC) puts(" Nenhum compromisso pontual nesta data.");
    }

    imprimirSeparador();
    printf("\n");
    pausar();
}
