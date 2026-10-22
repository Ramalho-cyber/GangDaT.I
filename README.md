# 📅 Schedula - Sistema de Gerenciamento de Rotinas e Compromissos em C

> **Disciplina:** Linguagem e Técnicas de Programação  
> **Professor:** Dacio Machado  
> **Curso:** Engenharia de Software 

---

## 📌 Sobre o Projeto

O **Schedula** é um sistema desenvolvido em **Linguagem C** voltado para a organização e otimização da rotina diária e semanal. 

Diferente de agendas convencionais que exigem o cadastro diário de obrigações repetitivas, o **Schedula** introduz o conceito de **Rotina Recorrente**: atividades fixas associadas aos dias da semana (ex: faculdade, academia, reuniões semanais) são mantidas automaticamente na grade semanal, sem a necessidade de reescrevê-las a cada novo dia.

Além da gestão de rotinas fixas, a aplicação oferece recursos completos de agenda tradicional, como visualização de calendário, cadastro de novos compromissos eventuais e persistência de dados em arquivo.

---

---

## 🛠️ Conceitos da Linguagem C Aplicados

O projeto foi construído cobrindo os conceitos fundamentais ministrados na disciplina:

1. **Entrada e Saída Tratadas:** Manipulação de fluxos com `printf`, `scanf` e tratamento de buffers (`fgets`/`getchar`).
2. **Estruturas de Controle:** Laços de repetição (`while`, `for`) e estruturas condicionais (`if`, `switch-case`) para menus e fluxos de navegação.
3. **Modularização (Funções):** Código totalmente dividido em módulos específicos com papéis bem definidos.
4. **Estruturas Homogêneas:** Uso de matrizes e vetores para manipulação de textos e listas.
5. **Estruturas Heterogêneas (`struct`):** Modelagem de dados para Atividades, Compromissos e Horários.
6. **Manipulação de Arquivos:** Gravação e leitura persistente com `fopen`, `fprintf`, `fscanf`/`fread`, `fwrite` e fechamento correto de ponteiros (`fclose`)[cite: 1].
7. **Organização em Múltiplos Arquivos:** Separação entre arquivos de cabeçalho (`.h`), implementação (`.c`) e o ponto de entrada principal (`main.c`)[cite: 1].
