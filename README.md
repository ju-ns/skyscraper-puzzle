# Skyscraper Puzzle Solver

Um solucionador do quebra-cabeça **Skyscraper Puzzle** 4x4 implementado em linguagem C, utilizando técnicas de backtracking e validações para garantir que as regras do jogo sejam respeitadas.

---

## Sobre o Projeto

O Skyscraper Puzzle é um jogo de lógica onde o objetivo é preencher uma grade (4x4 neste projeto) com números representando alturas de prédios, obedecendo dicas de visibilidade fornecidas nas bordas da grade. Essas dicas indicam quantos prédios são visíveis de cada direção (norte, sul, leste e oeste), considerando que prédios mais altos bloqueiam a visão dos prédios menores atrás deles.

Este projeto implementa:

- Validação da entrada do usuário com contagem e verificação dos números;
- Representação das dicas de visibilidade para as quatro direções;
- Algoritmo de backtracking para tentar todas as combinações possíveis;
- Verificação de duplicatas nas linhas e colunas;
- Cálculo da visibilidade dos prédios para validar a solução;
- Impressão da solução no console.

---

## Como Usar

1. Compile o projeto com um compilador C (exemplo usando gcc):

   ```bash
   gcc -Wall -Wextra -Werror *.c -o skyscraper_solver

2. Execute o programa passando as dicas como entrada (ou adapte para receber via linha de comando conforme seu código):

    ./skyscraper_solver "2 1 3 2 2 3 1 2 1 2 2 3 3 2 1 2"

3. O programa irá resolver o quebra-cabeça e imprimir a solução no console, ou indicar se não foi possível encontrar uma solução válida.

## Estrutura do Código

- **rush01.h** — Cabeçalho com definições, protótipos e a estrutura das dicas.
- **input.c** — Funções para validação, extração e parseamento das dicas de entrada.
- **solve.c** — Algoritmo de backtracking e validações durante a resolução.
- **validation.c** — Funções para verificar duplicatas e completar a grade.
- **visibility.c** — Funções para contar prédios visíveis nas quatro direções.
- **out.put.c** — Funções para imprimir a solução no terminal.

## Tecnologias e Conceitos

- **Linguagem:** C
- **Paradigma:** Programação estruturada
- **Técnicas aplicadas:**
  - Backtracking para resolução do puzzle
  - Validação de regras do jogo (visibilidade, duplicatas)
  - Manipulação de arrays multidimensionais
  - Estrutura de dados simples para organização das dicas

## Autor

Julia Anísio Nogueira Nunes

   
