#ifndef ROTINAS_H
#define ROTINAS_H

#define MAX_DESC 100
#define ARQ_ROTINAS "rotinas.dat"

typedef struct {
    int diaSemana; // 0: Domingo até 6: Sábado
    char descricao[MAX_DESC];
    int hora;
    int minuto;
} RotinaRecorrente;

extern const char *diasSemanaStr[];

void cadastrarRotina();
void listarRotinas();
void salvarRotinasNoArquivo(RotinaRecorrente r);

#endif
