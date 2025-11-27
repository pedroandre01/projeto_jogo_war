#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5

struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar o buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct territorio mapa[MAX_TERRITORIOS];
    int totalTerritorios = 0;

    printf("==============================\n");
    printf(" JOGO WAR - NIVEL AVENTUREIRO \n");
    printf("==============================\n");

    // Cadastro de 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("\nCadastro do territorio %d\n", i + 1);

        printf("Digite o nome do territorio: ");
        fgets(mapa[totalTerritorios].nome, sizeof(mapa[totalTerritorios].nome), stdin);
        mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0'; // remove \n

        printf("Digite a cor do territorio: ");
        fgets(mapa[totalTerritorios].cor, sizeof(mapa[totalTerritorios].cor), stdin);
        mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = '\0'; // remove \n

        printf("Digite o numero de tropas no territorio: ");
        scanf("%d", &mapa[totalTerritorios].tropas);
        limparBuffer(); // limpa o \n deixado pelo scanf

        printf("Territorio %d cadastrado com sucesso!\n", i + 1);
        totalTerritorios++;
    }

    // Exibir os territórios cadastrados
    printf("\n--- Territorios cadastrados ---\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("Territorio %d: nome=%s, cor=%s, tropas=%d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}
    

