# 🎲 Projeto WAR - Curso de ADS

Este repositório contém o desenvolvimento do jogo WAR como parte de um trabalho acadêmico do curso de Análise e Desenvolvimento de Sistemas (ADS).  
O projeto foi dividido em três níveis de complexidade, permitindo evolução gradual das funcionalidades e aplicação prática dos conceitos aprendidos em sala.

---

  Objetivo do Trabalho
Aplicar conceitos de programação estruturada em C.  
Exercitar uso de estruturas de dados** (structs, arrays dinâmicos).
 Implementar funções de cadastro, listagem, empréstimo e remoção.
 Trabalhar com alocação dinâmica de memória (malloc, calloc, free).
 Simular a lógica de um jogo de estratégia baseado em conquista de territórios.

---

🏆 Estrutura em Três Níveis

 🔹 Nível 1 – Fundamentos
 Cadastro de jogadores.
 Cadastro de territórios e exércitos.
 Listagem inicial dos dados.
 Uso de arrays estáticos.

 🔹 Nível 2 – Evolução
 Implementação de empréstimos/ataques entre jogadores.
 Controle de disponibilidade de territórios.
 Uso de alocação dinâmica de memória.
 Introdução da struct Emprestimo para armazenar dados.

🔹 Nível 3 – Completo
 Inclusão da funcionalidade de remoção de livros/territórios.
 Verificação automática de objetivos secretos (Missões Estratégicas).
 Melhorias na interface de console (menus e mensagens).
 Liberação correta da memória com free().

🔸 Nível Mestre — Missões Estratégicas (Entrega final)
 Objetivo: Implementar missões estratégicas individuais atribuídas aleatoriamente a cada jogador,
   armazenadas dinamicamente, verificadas silenciosamente ao final de cada turno e que definem condições
   alternativas de vitória.
 Arquivos principais do Nível Mestre (pasta projeto_jogo_war/projeto_jogo_war_mestre`):
   war.h`  : Definições de estruturas e protótipos documentados.
    war.c  : Implementação modular (missões, mapa, ataque, gestão de memória).
    jogo_war_nivel_mestre.c : main que utiliza o módulo e apresenta interface simples.
  Requisitos técnicos:
    Uso de malloc/free para missões e vetores dinâmicos, srand(time(NULL)), validação de entradas.
    Funções obrigatórias: atribuirMissao, verificarMissao, exibirMissao, atacar, exibirMapa, liberarMemoria.
  Compilação (exemplo Windows / MinGW):
     cd projeto_jogo_war\projeto_jogo_war_mestre
     gcc -g jogo_war_nivel_mestre.c war.c -o jogo_war_nivel_mestre.exe
  Também incluí um script compile_mestre.bat na pasta do Nível Mestre para compilar automaticamente
   (compatível com MinGW/MSYS se o gcc estiver no PATH).
  Entrega: há um arquivo jogo_war_mestre_release.zip` contendo a pasta do Nível Mestre pronto para envio.

---

Se desejar, eu posso também gerar um PDF com a documentação do projeto (resumo, instruções e comentários do código).
