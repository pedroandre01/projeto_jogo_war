
// Esse é o cadastro do jogo WAR de territórios (versão nível novato....)
// O código abaixo lê 5 territórios do usuário e exibe os cadastrados.

#include <stdio.h>   // funções de entrada/saída (printf, scanf, fgets, getchar)
#include <stdlib.h>  // utilidades padrão (não usado diretamente aqui, mas incluído)
#include <string.h>  // funções de manipulação de strings (strcspn)

#define MAX_TERRITORIOS 5  // número máximo de territórios a cadastrar

// Estrutura que representa um território do jogo
struct territorio {
    char nome[30];  // nome do território (até 29 caracteres + '\0')
    char cor[10];   // cor associada ao território (até 9 caracteres + '\0')
    int tropas;     // número de tropas posicionadas no território
};

// Função para limpar o buffer de entrada (consome caracteres até '\n')
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // descarta até o fim da linha
}

int main() {
    struct territorio mapa[MAX_TERRITORIOS]; // vetor que guarda os territórios
    int totalTerritorios = 0; // contador de territórios cadastrados

    // Cabeçalho do programa
    printf("==============================\n");
    printf(" JOGO WAR - NIVEL AVENTUREIRO \n");
    printf("==============================\n");

    // Loop para cadastrar exatamente 5 territórios (conforme MAX_TERRITORIOS)
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\nCadastro do territorio %d\n", i + 1);

        // Leitura do nome usando fgets para evitar overflow de buffer
        printf("Digite o nome do territorio: ");
        fgets(mapa[totalTerritorios].nome, sizeof(mapa[totalTerritorios].nome), stdin);
        // Remove o '\n' deixado pelo fgets substituindo-o por '\0'
        mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0';

        // Leitura da cor do território (também com fgets)
        printf("Digite a cor do territorio: ");
        fgets(mapa[totalTerritorios].cor, sizeof(mapa[totalTerritorios].cor), stdin);
        // Remove o '\n' deixado pelo fgets
        mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = '\0';

        // Leitura do número de tropas com scanf (inteiro)
        printf("Digite o numero de tropas no territorio: ");
        scanf("%d", &mapa[totalTerritorios].tropas);
        limparBuffer(); // limpa o '\n' remanescente no buffer após o scanf

        printf("Territorio %d cadastrado com sucesso!\n", i + 1);
        totalTerritorios++; // incrementa o total de territórios cadastrados
    }

    // Exibe a lista de territórios cadastrados
    printf("\n--- Territorios cadastrados ---\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("Territorio %d: nome=%s, cor=%s, tropas=%d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0; // encerra o programa com sucesso
}
// ...existing code...
