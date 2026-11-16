#ifndef ROTINAS_H                
#define ROTINAS_H                 

#define MAX_DESC 100               /* Tamanho máximo (em caracteres) da descrição de uma rotina */
#define ARQ_ROTINAS "rotinas.dat"  /* Nome do arquivo onde as rotinas são gravadas */

typedef struct {                  /* Define uma estrutura para representar uma rotina recorrente */
    int diaSemana;                /* 0: Domingo até 6: Sábado */
    char descricao[MAX_DESC];     /* Texto que descreve a rotina (ex.: "Academia") */
    int hora;                     /* 0 a 23 */
    int minuto;                   /* 0 a 59 */
} RotinaRecorrente;               

extern const char *diasSemanaStr[]; /* Vetor de strings com os nomes dos dias da semana (definido em outro arquivo .c) */

void cadastrarRotina();                          /* Pede os dados ao usuário e cadastra uma nova rotina */
void listarRotinas();                            /* Lê o arquivo e exibe todas as rotinas cadastradas*/
void salvarRotinasNoArquivo(RotinaRecorrente r); /* Grava uma rotina no arquivo ARQ_ROTINAS */

#endif    
