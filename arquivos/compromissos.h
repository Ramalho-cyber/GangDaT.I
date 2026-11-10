#ifndef COMPROMISSOS_H
#define COMPROMISSOS_H

#define MAX_DESC 100
#define ARQ_COMPROMISSOS "compromissos.dat"

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    char descricao[MAX_DESC];
} Compromisso;

void cadastrarCompromisso();
void listarCompromissos();
void salvarCompromissoNoArquivo(Compromisso c);
void visualizarAgendaDia();

#endif
