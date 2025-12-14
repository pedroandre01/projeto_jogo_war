//===========================================================================================
// Implementação do nível aventureiro do jogo WAR.
// O usuário define o número de territórios a cadastrar.
// O programa lê os territórios, exibe os cadastrados e simula uma batalha simples.
//===========================================================================================

#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf, fgets)
#include <stdlib.h>  // Biblioteca para funções de alocação dinâmica (malloc, calloc, free)
#include <string.h>  // Biblioteca para manipulação de strings (strcpy, strcmp, strcspn)
#include <time.h>    // Biblioteca para trabalhar com tempo (usada para srand(time(NULL)))

// Estrutura que representa um território no jogo
typedef struct {
    char nome[30];   // Nome do território (até 29 caracteres + '\0')
    char cor[10];    // Cor do exército que controla o território
    int tropas;      // Número de tropas posicionadas no território
} Territorio;

// Função para limpar o buffer de entrada
// Isso evita que o '\n' deixado pelo scanf atrapalhe a leitura com fgets
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar os territórios
// Recebe um ponteiro para o vetor de territórios e o total de territórios
void cadastrarTerritorios(Territorio* mapa, int total) {
    for (int i = 0; i < total; i++) {
        printf("\nWAR - Cadastro de Territorios %d\n", i + 1 );
        

        // Leitura do nome do território
        printf("Digite o nome do territorio: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // remove o '\n'

        // Leitura da cor do território
        printf("Digite a cor do territorio: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0'; // remove o '\n'

        // Leitura do número de tropas
        printf("Digite o numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBuffer(); // limpa o buffer após scanf
    }
}

// Função para exibir todos os territórios cadastrados
void exibirTerritorios(Territorio* mapa, int total) {
    printf("\n--- Territorios cadastrados ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d - Nome: %s     | Cor: %s     | Tropas: %d\n",i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função que simula um ataque entre dois territórios
// Recebe ponteiros para o território atacante e defensor
void atacar(Territorio* atacante, Territorio* defensor) {
    // Rolagem de dados (valores entre 1 e 6)
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    // Poder total = tropas + valor do dado
    int poderAtacante = atacante->tropas + dadoAtacante;
    int poderDefensor = defensor->tropas + dadoDefensor;

    // Exibe os resultados da batalha
    printf("\nResultado da batalha:\n");
    printf("Atacante (%s - %s): Tropas=%d + Dado(%d) = %d\n", atacante->nome, atacante->cor, atacante->tropas, dadoAtacante, poderAtacante);
    printf("Defensor (%s - %s): Tropas=%d + Dado(%d) = %d\n", defensor->nome, defensor->cor, defensor->tropas, dadoDefensor, poderDefensor);

    // Determina o vencedor
    if (poderAtacante > poderDefensor) {
        // Se atacante vence, defensor muda de cor e recebe metade das tropas do atacante
        printf("O atacante venceu! O territorio %s agora pertence a cor %s.\n",defensor->nome, atacante->cor);
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else if (poderDefensor > poderAtacante) {
        // Se defensor vence, atacante perde uma tropa
        printf("O defensor resistiu! O atacante perde uma tropa.\n");
        if (atacante->tropas > 0) atacante->tropas--;
    } else {
        // Empate
        printf("Empate! Nenhuma mudança ocorreu.\n");
    }
}

// Função para liberar a memória alocada dinamicamente
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// Função principal
int main() {
    srand(time(NULL)); // inicializa o gerador de números aleatórios

    int totalTerritorios;
    printf("\n=== JOGO WAR - NIVEL AVENTUREIRO ===\n");
    printf("Digite o numero de territorios a cadastrar: ");
    scanf("%d", &totalTerritorios);
    limparBuffer();

    // Validação do número de territórios
    if (totalTerritorios <= 0) {
        printf("Numero invalido de territorios.\n");
        return 1;
    }

    // Alocação dinâmica do vetor de territórios
    Territorio* mapa = (Territorio*) calloc(totalTerritorios, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Cadastro e exibição inicial dos territórios
    cadastrarTerritorios(mapa, totalTerritorios);
    exibirTerritorios(mapa, totalTerritorios);

    // Escolha dos territórios para batalha
    int idxAtacante, idxDefensor;
    printf("\nEscolha o territorio atacante (1 a %d): ", totalTerritorios);
    scanf("%d", &idxAtacante);
    printf("Escolha o territorio defensor (1 a %d): ", totalTerritorios);
    scanf("%d", &idxDefensor);

    // Ajusta índices para começar em 0
    idxAtacante--;
    idxDefensor--;

    // Validação das escolhas
    if (idxAtacante < 0 || idxAtacante >= totalTerritorios ||
        idxDefensor < 0 || idxDefensor >= totalTerritorios ||
        idxAtacante == idxDefensor) {
        printf("Territorios invalidos.\n");
        liberarMemoria(mapa);
        return 1;
    }

    // Verifica se não está atacando território da mesma cor
    if (strcmp(mapa[idxAtacante].cor, mapa[idxDefensor].cor) == 0) {
        printf("Nao pode atacar um territorio da mesma cor!\n");
    } else {
        atacar(&mapa[idxAtacante], &mapa[idxDefensor]);
    }

    // Exibe territórios atualizados após a batalha
    exibirTerritorios(mapa, totalTerritorios);

    // Libera memória antes de encerrar
    liberarMemoria(mapa);
    return 0;
}
