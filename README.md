# 📅 Schedula - Sistema de Gerenciamento de Rotinas e Compromissos em C

> **Disciplina:** Linguagem e Técnicas de Programação  
> **Professor:** Dacio Machado  
> **Curso:** Engenharia de Software / Análise e Desenvolvimento de Sistemas  

---

## 📌 Sobre o Projeto
O **Schedula** é um sistema desenvolvido em Linguagem C voltado para a organização e otimização da rotina diária e semanal. 

Diferente de agendas convencionais que exigem o cadastro diário de obrigações repetitivas, o Schedula introduz o conceito de **Rotina Recorrente**: atividades fixas associadas aos dias da semana (ex: aulas, academia, reuniões) são mantidas automaticamente na grade semanal, sem a necessidade de reescrevê-las a cada novo dia. Além disso, conta com um módulo robusto de compromissos pontuais e persistência de dados em arquivos binários.

---

## 🎯 Problema e Solução Proposta
* **Problema:** A maioria dos aplicativos de agenda exige que tarefas frequentes sejam cadastradas manualmente dia após dia, gerando retrabalho e desorganização para estudantes e profissionais com rotinas semanais bem definidas.
* **Solução:** O Schedula automatiza a gestão semanal unindo um módulo de atividades recorrentes (por dia da semana) a um módulo de compromissos pontuais atrelados a datas específicas, integrando ambos em uma visualização diária unificada.

---

## 🛠️ Conceitos de C Aplicados
O projeto implementa todos os conceitos fundamentais exigidos na disciplina:
1. **Entrada e Saída Tratadas:** Manipulação de fluxos com `printf`, `scanf` e tratamento de interface via console.
2. **Estruturas de Controle:** Laços de repetição (`do-while`, `while`, `for`) e seleção (`switch-case`, `if-else`) para navegação em menus.
3. **Modularização:** Divisão estrita do código em múltiplos arquivos (`main.c`, módulos `.c` e cabeçalhos `.h`).
4. **Estruturas Heterogêneas (`struct`):** Modelagem de dados para Atividades Recorrentes e Compromissos Eventuais.
5. **Manipulação de Arquivos:** Gravação e leitura binária persistente utilizando `fopen`, `fread`, `fwrite` e `fclose` com tratamento de erros.

---

## 📂 Arquitetura e Estrutura de Arquivos
O projeto está modularizado da seguinte forma:
* `main.c` — Arquivo principal contendo o fluxo de controle e o menu interativo.
* `rotinas.h` / `rotinas.c` — Módulo responsável pela definição das structs, cadastro, listagem e persistência das rotinas recorrentes.
* `compromissos.h` / `compromissos.c` — Módulo responsável pelo gerenciamento de compromissos pontuais e visualização integrada da agenda do dia.

---

## 📝 Descrição das Estruturas de Dados (`Structs`)

### 1. Rotina Recorrente (`RotinaRecorrente`)
Armazena atividades fixas vinculadas a um dia da semana.
* `int diaSemana`: Representa o dia (0 para Domingo até 6 para Sábado).
* `char descricao[100]`: Nome/descrição da atividade.
* `int hora` / `int minuto`: Horário programado.

### 2. Compromisso Pontual (`Compromisso`)
Armazena eventos que ocorrem em uma data específica.
* `int dia`, `int mes`, `int ano`: Data exata do compromisso.
* `int hora` / `int minuto`: Horário do evento.
* `char descricao[100]`: Detalhes do compromisso.

---

## 🚀 Como Compilar e Executar

### Usando o Dev-C++ (Windows):
1. Crie um novo projeto do tipo **Console Application (C Project)**.
2. Adicione os 5 arquivos do repositório (`main.c`, `rotinas.h`, `rotinas.c`, `compromissos.h`, `compromissos.c`) ao projeto.
3. Pressione **F11** para compilar e executar.

### Usando o GCC via Terminal:
```bash
gcc main.c rotinas.c compromissos.c -o schedula.exe
./schedula.exe
