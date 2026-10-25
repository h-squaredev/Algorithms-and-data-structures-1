/*
 nosso personagem quer carregar a comida coletada para casa, mas o encontro com um fantasma, 
 ao invés de terminar o jogo, faz com que toda a comida coletada seja roubada.
 Neste problema os fantasmas não se movem, e o jogador sempre faz o Pacman percorrer o seguinte caminho:

O Pacman começa no canto superior esquerdo do tabuleiro.
O Pacman percorre toda a linha, da esquerda para direita, até chegar ao lado direito do tabuleiro.
O jogador desce uma posição, e percorre toda a linha, desta vez da direita para a esquerda.
As etapas 2 e 3 se repetem até que todo o tabuleiro tenha sido percorrido.
Infelizmente, Pacman não pode ignorar os comandos do usuário para fugir dos fantasmas ou pegar mais comida, mas ele pode, a qualquer momento, se aproveitar de um bug de implementação e interromper o jogo, levando consigo toda a comida que estiver carregando.

Você deve escrever um programa que determine a maior quantidade de comida que o Pacman pode levar, se escolher a melhor hora possível para sair. Note que o jogador também tem a opção de não sair antes do final do jogo.

A primeira linha contém um inteiro N (2 ≤ N ≤ 100), o tamanho do tabuleiro do jogo, que é quadrado. Cada uma das N linhas seguintes contém N caracteres, que podem ser (aspas para melhor clareza):

‘.’ um espaço vazio;
‘o’ uma comida;
‘A’ um fantasma.
Não há um fantasma e uma comida na mesma posição.

Não há fantasma nem comida na posição inicial do Pacman (ou seja, o primeiro caractere da primeira linha do tabuleiro é ‘.’).
*/

#include <stdio.h>

int main(){
    int N, contador_comida = 0, comida_max = 0;

    // entrada de dados do tamanho do tabuleiro ao quadrado
    scanf("%d", &N);

    // N + 1 para tamanho de linhas por causa do \0 que é o critério de parada de cada linha
    char tabuleiro[N + 1][N+ 1];

    // A partir de uma string, vaia tribuir os caracteres do usuario a cada linha
    for(int i = 0; i < N; i++){
        scanf("%s", tabuleiro[i]);
        //printf("Elemento [%d][%d] = %d\n", i, j, tabuleiro[i][j]);
    }   

    // Simulacao do movimento do pacman em zigue zag
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            for(int j = 0; j < N; j++){
                if(tabuleiro[i][j] == 'o'){
                    contador_comida++;
                    if(contador_comida > comida_max){
                        comida_max = contador_comida;
                    }
                }else if(tabuleiro[i][j] == 'A'){
                        contador_comida = 0;
                }else continue;
            }
        }else{
            for(int j = N - 1; j >= 0; j--){
                if(tabuleiro[i][j] == 'o'){
                    contador_comida++;
                    if(contador_comida > comida_max){
                        comida_max = contador_comida;
                    }
                }else if(tabuleiro[i][j] == 'A'){
                        contador_comida = 0;
                }else continue;
            }
        }   
    }

    printf("%d\n", comida_max);
    return 0;
}