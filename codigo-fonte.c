#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

char jogoDaVelha[3][3], jogador1[24], jogador2[24], op;
int l, c, player = 0, linha, coluna, vitoria = 0;

void apresentar(){
    printf("\n\t---------------------------------\n");
    printf("\t---------------------------------\n");
    printf("\t--------  JOGO DA VELHA  --------\n");
    printf("\t---------------------------------\n");
    printf("\t---------------------------------\n");

    printf("\n\tEscolha uma das opções abaixo!\n\n");
    printf("\t1 - Jogar\n");
    printf("\t2 - Créditos\n");
    printf("\t3 - Sair: ");
    scanf("%s", &op);
    system("cls");
};

void receberUsuarios(){
    printf("\n\n\n\tPlayer 1 digite seu nome: ");
    scanf("%s", jogador1);
    printf("\n\tPlayer 2 digite seu nome: ");
    scanf("%s", jogador2);
    system("cls");
};

void tab(){
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            jogoDaVelha[l][c] = ' ';
        }
    }
};

void printarTab(){
    printf("\n");
    printf("\t0     1      2\n\n");
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            printf("\t%c", jogoDaVelha[l][c]);
            if(c < 2){
                printf(" |");
            }
            if(c == 2){
                printf("   %d", l);
            }
        }
        if(l < 2){
            printf("\n     --------------------\n");
        }
    }
};

void jogar(){
    printf("\n\n\tPlayer 1: X  //  Player 2: O\n");

    do{
        if(player == 0){
            printf("\n\n\tJogador X digite a linha da sua jogada: ");
            scanf("%d", &linha);
            printf("\n\tJogador X digite a coluna da sua jogada: ");
            scanf("%d", &coluna);
            system("cls");
            if(jogoDaVelha[linha][coluna] != ' ' || linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
                printf("\n\tJogada Inválida! Jogue Novamente\n");
                printarTab();
            }
        }
        else{
            printf("\n\n\tJogador O digite a linha da sua jogada: ");
            scanf("%d", &linha);
            printf("\n\tJogador O digite a coluna da sua jogada: ");
            scanf("%d", &coluna);
            system("cls");
            if(jogoDaVelha[linha][coluna] != ' ' || linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
                printf("\n\tJogada Inválida! Jogue Novamente\n");
                printarTab();
            }
        }
    }while(jogoDaVelha[linha][coluna] != ' ' || linha < 0 || linha > 2 || coluna < 0 || coluna > 2);

    if(player == 0){
        jogoDaVelha[linha][coluna] = 'X';
        player++;
    }
    else{
        jogoDaVelha[linha][coluna] = 'O';
        player = 0;
    }
};

void checarVitoria(){
    if(jogoDaVelha[0][0] == 'X' && jogoDaVelha[0][1] == 'X' && jogoDaVelha[0][2] == 'X' ||
       jogoDaVelha[1][0] == 'X' && jogoDaVelha[1][1] == 'X' && jogoDaVelha[1][2] == 'X' ||
       jogoDaVelha[2][0] == 'X' && jogoDaVelha[2][1] == 'X' && jogoDaVelha[2][2] == 'X'){
