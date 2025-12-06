#include <stdio.h>

#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void inicializarTabuleiro(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = EMPTY;
        }
    }
}

void exibirTabuleiro(char tab[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tab[i][0], tab[i][1], tab[i][2]);
        if (i < 2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int jogadaValida(char tab[3][3], int linha, int coluna) {
    return linha >= 0 && linha < 3 &&
           coluna >= 0 && coluna < 3 &&
           tab[linha][coluna] == EMPTY;
}

int verificarVitoria(char tab[3][3], char jogador) {
    // Linhas
    for (int i = 0; i < 3; i++)
        if (tab[i][0] == jogador && tab[i][1] == jogador && tab[i][2] == jogador)
            return 1;

    // Colunas
    for (int j = 0; j < 3; j++)
        if (tab[0][j] == jogador && tab[1][j] == jogador && tab[2][j] == jogador)
            return 1;

    // Diagonal principal
    if (tab[0][0] == jogador && tab[1][1] == jogador && tab[2][2] == jogador)
        return 1;

    // Diagonal secundária
    if (tab[0][2] == jogador && tab[1][1] == jogador && tab[2][0] == jogador)
        return 1;

    return 0;
}

int verificarEmpate(char tab[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tab[i][j] == EMPTY)
                return 0;
    return 1;
}

int main() {
    char tab[3][3];
    char jogadorAtual = PLAYER_X;
    int linha, coluna;

    inicializarTabuleiro(tab);

    while (1) {
        exibirTabuleiro(tab);
        printf("Jogador %c, escolha linha e coluna (0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (!jogadaValida(tab, linha, coluna)) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tab[linha][coluna] = jogadorAtual;

        if (verificarVitoria(tab, jogadorAtual)) {
            exibirTabuleiro(tab);
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate(tab)) {
            exibirTabuleiro(tab);
            printf("Empate!\n");
            break;
        }

        jogadorAtual = (jogadorAtual == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}
