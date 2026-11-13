#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotinas.h"

const char *diasSemanaStr[] = {
    "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira",
    "Quinta-feira", "Sexta-feira", "Sábado"
};

/* Funções auxiliares internas (static: visíveis só neste arquivo,
   não conflitam com nada do código principal) */
static void rotinasLimparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void rotinasMensagemPausa(const char *msg) {
    printf("\n%s\n", msg);
    system("pause");
}

void cadastrarRotina() {
    system("cls");
    RotinaRecorrente r;
    memset(&r, 0, sizeof(r)); /* evita lixo de memória gravado no arquivo */

    printf("--- Cadastro de Rotina Recorrente ---\n");
    printf("Dias da semana:\n");
    printf("0 - Domingo\n1 - Segunda\n2 - Terça\n3 - Quarta\n4 - Quinta\n5 - Sexta\n6 - Sábado\n");
    printf("Digite o número correspondente ao dia: ");

    if (scanf("%d", &r.diaSemana) != 1 || r.diaSemana < 0 || r.diaSemana > 6) {
        rotinasLimparEntrada();
        rotinasMensagemPausa("[Erro] Dia da semana inválido!");
        return;
    }
    rotinasLimparEntrada(); /* descarta o '\n' antes de ler o texto */

    printf("Descrição da atividade (ex: Aula de C, Academia): ");
    if (fgets(r.descricao, sizeof(r.descricao), stdin) == NULL) {
        rotinasMensagemPausa("[Erro] Falha ao ler a descrição!");
        return;
    }

    size_t len = strcspn(r.descricao, "\n");
    if (r.descricao[len] == '\n') {
        r.descricao[len] = '\0';      /* remove o '\n' do fgets */
    } else {
        rotinasLimparEntrada();       /* texto maior que o campo: descarta o excesso */
    }

    if (len == 0) {
        rotinasMensagemPausa("[Erro] A descrição não pode ficar vazia!");
        return;
    }

    printf("Horário (HH MM): ");
    if (scanf("%d %d", &r.hora, &r.minuto) != 2 ||
        r.hora < 0 || r.hora > 23 || r.minuto < 0 || r.minuto > 59) {
        rotinasLimparEntrada();
        rotinasMensagemPausa("[Erro] Horário inválido!");
        return;
    }
    rotinasLimparEntrada();

    salvarRotinasNoArquivo(r);
}

void salvarRotinasNoArquivo(RotinaRecorrente r) {
    FILE *file = fopen(ARQ_ROTINAS, "ab");
    if (file == NULL) {
        rotinasMensagemPausa("[Erro crítico] Não foi possível abrir o arquivo de rotinas para gravação!");
        return;
    }

    size_t gravados = fwrite(&r, sizeof(RotinaRecorrente), 1, file);
    fclose(file);

    if (gravados != 1) {
        rotinasMensagemPausa("[Erro] Falha ao gravar a rotina no arquivo!");
        return;
    }
    rotinasMensagemPausa("[Sucesso] Rotina recorrente cadastrada e salva com sucesso!");
}

void listarRotinas() {
    system("cls");
    FILE *file = fopen(ARQ_ROTINAS, "rb");
    if (file == NULL) {
        rotinasMensagemPausa("[Aviso] Nenhuma rotina cadastrada ainda.");
        return;
    }

    RotinaRecorrente r;
    int encontradas = 0;

    printf("========================================\n");
    printf("       LISTA DE ROTINAS RECORRENTES     \n");
    printf("========================================\n");

    while (fread(&r, sizeof(RotinaRecorrente), 1, file) == 1) {
        /* protege contra registro corrompido (índice fora do vetor) */
        const char *dia = (r.diaSemana >= 0 && r.diaSemana <= 6)
                              ? diasSemanaStr[r.diaSemana]
                              : "Dia inválido";

        r.descricao[sizeof(r.descricao) - 1] = '\0'; /* garante fim da string */

        printf("[%s] às %02d:%02d -> %s\n", dia, r.hora, r.minuto, r.descricao);
        encontradas++;
    }
    fclose(file);

    if (encontradas == 0) {
        printf("Nenhuma rotina encontrada no arquivo.\n");
    }
    printf("\n");
    system("pause");
}
