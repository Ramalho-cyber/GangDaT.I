#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotinas.h"

const char *diasSemanaStr[] = {
    "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", 
    "Quinta-feira", "Sexta-feira", "Sábado"
};

void cadastrarRotina() {
    system("cls");
    RotinaRecorrente r;

    printf("--- Cadastro de Rotina Recorrente ---\n");
    printf("Dias da semana:\n");
    printf("0 - Domingo\n1 - Segunda\n2 - Terça\n3 - Quarta\n4 - Quinta\n5 - Sexta\n6 - Sábado\n");
    printf("Digite o número correspondente ao dia: ");
    scanf("%d", &r.diaSemana);

    if (r.diaSemana < 0 || r.diaSemana > 6) {
        printf("\n[Erro] Dia da semana inválido!\n");
        system("pause");
        return;
    }

    printf("Descrição da atividade (ex: Aula de C, Academia): ");
    scanf("%s", r.descricao);

    printf("Horário (HH MM): ");
    scanf("%d %d", &r.hora, &r.minuto);

    if (r.hora < 0 || r.hora > 23 || r.minuto < 0 || r.minuto > 59) {
        printf("\n[Erro] Horário inválido!\n");
        system("pause");
        return;
    }

    salvarRotinasNoArquivo(r);
}

void salvarRotinasNoArquivo(RotinaRecorrente r) {
    FILE *file = fopen(ARQ_ROTINAS, "ab");
    if (file == NULL) {
        printf("\n[Erro crítico] Não foi possível abrir o arquivo de rotinas para gravação!\n");
        system("pause");
        return;
    }
    fwrite(&r, sizeof(RotinaRecorrente), 1, file);
    fclose(file);
    printf("\n[Sucesso] Rotina recorrente cadastrada e salva com sucesso!\n");
    system("pause");
}

void listarRotinas() {
    system("cls");
    FILE *file = fopen(ARQ_ROTINAS, "rb");
    if (file == NULL) {
        printf("\n[Aviso] Nenhuma rotina cadastrada ainda.\n");
        system("pause");
        return;
    }

    RotinaRecorrente r;
    printf("========================================\n");
    printf("       LISTA DE ROTINAS RECORRENTES     \n");
    printf("========================================\n");
    
    int encontradas = 0;
    while (fread(&r, sizeof(RotinaRecorrente), 1, file) == 1) {
        printf("[%s] às %02d:%02d -> %s\n", diasSemanaStr[r.diaSemana], r.hora, r.minuto, r.descricao);
        encontradas++;
    }
    fclose(file);

    if (encontradas == 0) {
        printf("Nenhuma rotina encontrada no arquivo.\n");
    }
    printf("\n");
    system("pause");
}
