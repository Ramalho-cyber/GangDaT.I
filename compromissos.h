#ifndef COMPROMISSOS_H
#define COMPROMISSOS_H

#define MAX_DESC 100                         /* tamanho máximo da descrição (inclui o '\0') */
#define ARQ_COMPROMISSOS "compromissos.dat"  /* arquivo binário onde os compromissos são salvos */

/* Compromisso com data e horário específicos.
   Atenção: não altere a ordem nem o tamanho dos campos,
   senão o arquivo compromissos.dat já existente deixa de ser lido corretamente. */
typedef struct {
    int dia;                   /* 1 a 31 */
    int mes;                   /* 1 a 12 */
    int ano;                   /* ex: 2026 */
    int hora;                  /* 0 a 23 */
    int minuto;                /* 0 a 59 */
    char descricao[MAX_DESC];  /* texto do compromisso */
} Compromisso;

void cadastrarCompromisso();                /* lê os dados do usuário e salva */
void listarCompromissos();                  /* mostra todos os compromissos salvos */
void salvarCompromissoNoArquivo(Compromisso c); /* grava um compromisso no final do arquivo */
void visualizarAgendaDia();                 /* mostra os compromissos de uma data */

#endif
