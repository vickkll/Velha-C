#include <stdio.h>

char Jogo[3][3];

void limpa_entrada(void) {
    while (getchar() != '\n');
}

void limpa_tabela(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            Jogo[i][j] = '1' + j + 3 * i;
    }
}

void escreve_tabela(void) {
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c\n", Jogo[i][0], Jogo[i][1], Jogo[i][2]);
        if(i < 2){
            printf("-----------\n");
        }
    }
}

int verifica_tabela(char jogador) {
    // Verifica as colunas e linhas
    for (int i = 0; i < 3; i++) {
        if (Jogo[i][0] == jogador && Jogo[i][1] == jogador && Jogo[i][2] == jogador)
            return 1;
        if (Jogo[0][i] == jogador && Jogo[1][i] == jogador && Jogo[2][i] == jogador)
            return 1;
    }

    // Verifica as diagonais
    return (Jogo[0][0] == jogador && Jogo[2][2] == jogador  ||
            Jogo[0][2] == jogador && Jogo[2][0] == jogador) &&
            Jogo[1][1] == jogador;
}

char le_jogada(char jogador) {
    int jogada;
    int x, y;

    do {
        printf("Turno do %c: ", jogador);
        scanf(" %d", &jogada);
        limpa_entrada();
        x = (jogada - 1) / 3;
        y = (jogada - 1) % 3;
    } while (jogada < 1 || jogada > 9 || Jogo[x][y] == 'x' || Jogo[x][y] == 'o');

    return jogada - 1;
}

void jogo_principal(void) {
    int contagem = 0;

    while(1) {
        escreve_tabela();

        // Jogada X
        int jogada = le_jogada('x');
        Jogo[jogada / 3][jogada % 3] = 'x';
        contagem++;
        
        if (verifica_tabela('x')) {
            escreve_tabela();
            printf("Jogador X ganhou o jogo!\n");
            break;
        }

        if (contagem == 9) {
            escreve_tabela();
            printf("Deu velha!\n");
            break;
        }
                  
        escreve_tabela();

        // Jogada O
        jogada = le_jogada('o');
        Jogo[jogada / 3][jogada % 3] = 'o';
        contagem++;

        if (verifica_tabela('o')) {
            escreve_tabela();
            printf("Jogador O ganhou o jogo!\n");
            break;
        }
    }
}

int main(void) {
    while (1) {
        printf("===================================\n");
        printf("Bem vindo(a) ao jogo da velha ASCII\n");
        printf("===================================\n");
        // Construcao da matriz
        limpa_tabela();
        jogo_principal();

    }
    
    return 0;
}

