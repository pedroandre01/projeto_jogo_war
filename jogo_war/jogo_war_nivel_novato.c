// esse ea primeira camada do jogo war, onde o jogador ja tem acesso a todas as funcionalidades basicas do jogo
// como cadastro de jogadores, cadastro de territorios, distribuicao de exercitos, ataques e movimentacoes
#include<stdio.h>// para printf, scanf, fgets
#include<stdlib.h>// para system("cls") ou system("clear")
#include<string.h> // para strcspn()

// --- constantes globais ---
#define MAX_JOGADORES 5 // numero maximo de jogadores
struct territorio{// estrutura do territorio
    char nome[30];// nome do territorio
    char cor[10];// cor do territorio
    int tropas;// numero de tropas no territorio
};
// --- funções para limpar o buffer de entrada ---
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// --- função principal (main)---
int main() {
    struct territorio mapa[42];// array de territorios
    int totalTerritorios = 0;// total de territorios cadastrados
    int opcao;

    //--- laço principal do Menu ---
    do {
        // Exibir o Menu de opções
        printf("==============================\n");
        printf(" JOGO WAR - NIVEL AVENTUREIRO \n");
        printf("==============================\n");
        printf("cadastro do territorio 1\n");
        printf("digite o nome do territorio: ");
        scanf("%s", mapa[totalTerritorios].nome);
        printf("digite a cor do territorio: ");
        scanf("%s", mapa[totalTerritorios].cor);
        printf("digite o numero de tropas no territorio: ");
        scanf("%d", &mapa[totalTerritorios].tropas);
        printf("territorio cadastrado com sucesso!\n");
        printf("cadastro do territorio 2\n");
        printf("digite o nome do territorio 2: ");
        scanf("%s", mapa[totalTerritorios+1].nome);
        printf("digite a cor do territorio 2: ");
        scanf("%s", mapa[totalTerritorios+1].cor);
        printf("digite o numero de tropas no territorio 2: ");
        scanf("%d", &mapa[totalTerritorios+1].tropas);
        printf("territorio 2 cadastrado com sucesso!\n");
        printf("cadastro do territorio 3\n");
        printf("digite o nome do territorio 3: ");
        scanf("%s", mapa[totalTerritorios+2].nome);
        printf("digite a cor do territorio 3: ");
        scanf("%s", mapa[totalTerritorios+2].cor);
        printf("digite o numero de tropas no territorio 3: ");
        scanf("%d", &mapa[totalTerritorios+2].tropas);
        printf("territorio 3 cadastrado com sucesso!\n");
        printf("cadastro do territorio 4\n");
        printf("digite o nome do territorio 4: ");  
        scanf("%s", mapa[totalTerritorios+3].nome);
        printf("digite a cor do territorio 4: ");
        scanf("%s", mapa[totalTerritorios+3].cor);
        printf("digite o numero de tropas no territorio 4: ");
        scanf("%d", &mapa[totalTerritorios+3].tropas);
        printf("territorio 4 cadastrado com sucesso!\n");
        printf("cadastro do territorio 5\n");
        printf("digite o nome do territorio 5: ");
        scanf("%s", mapa[totalTerritorios+4].nome);
        printf("digite a cor do territorio 5: ");
        scanf("%s", mapa[totalTerritorios+4].cor);
        printf("digite o numero de tropas no territorio 5: ");
        scanf("%d", &mapa[totalTerritorios+4].tropas);
        printf("territorio 5 cadastrado com sucesso!\n");


        limparBuffer(); // limpar o '\n' deixado pelo scanf.
        totalTerritorios += 5;// atualiza o total de territorios cadastrados
        // Exibir os territorios cadastrados
        printf("\n--- territorios cadastrados ---\n");  
        for (int i = 0; i < totalTerritorios; i++) {
            printf("territorio %d: nome=%s, cor=%s, tropas=%d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
        }
        // Sair do laço após um ciclo de cadastro e exibição
        opcao = 0;
    } while (opcao != 0);
    printf
    r