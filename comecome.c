//
//  main.c
//  Curso-C3-Alura
//
//  Created by Gabriel Ferreira on 19/12/16.
//  Copyright © 2016 Gabriel Ferreira. All rights reserved.
//
#include "comecome.h"

MAPA m;
POSICAO heroi;
int tem_pilulas = 0;

int praonde_o_fantasma_vai(int xatual, int yatual, int* xdestino, int* ydestino){
    
    int opcoes[4][2] = {
        {xatual + 1, yatual},
        {xatual - 1, yatual},
        {xatual, yatual + 1},
        {xatual, yatual - 1},
    };
    
    int tentativas = 0;
    srand((int)time(0));
    do {
        int posicao = rand() % 4;
        
        if(pode_andar(&m,FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            
            return 1;
        }
        tentativas++;
    } while (tentativas < 10);
    
    return 0;
}


void fantasmas(){
    MAPA copia;
    
    copia_mapa(&copia, &m);
    
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            
            if(copia.matriz[i][j] == FANTASMA){
                
                int xdestino, ydestino;
                int encontrou = praonde_o_fantasma_vai(i, j, &xdestino, &ydestino);
                
                if (encontrou)
                    anda_no_mapa(&m, i, j, xdestino, ydestino);
                
            }
        }
    }
    libera_mapa(&copia);
}

int acabou(){
    POSICAO pos;
    int fogefogenomapa = encontra_personagem(&m, &pos, HEROI);
    
    return !fogefogenomapa;
}

int eh_direcao(char direcao) {
    return (direcao == ESQUERDA ||
            direcao == BAIXO ||
            direcao == DIREITA ||
            direcao == CIMA);
}

void mover(char direcao){
    
    if(!eh_direcao(direcao))
        return;
    
    int proximox = heroi.x;
    int proximoy = heroi.y;
    
    switch (direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }
    
    if (!pode_andar(&m,HEROI, proximox, proximoy))
        return;
    
    if (eh_personagem(&m, PILULA, proximox, proximoy))
        ++tem_pilulas;
    
    anda_no_mapa(&m, heroi.x, heroi.y, proximox, proximoy);
    
    heroi.x = proximox;
    heroi.y = proximoy;

}

int para_de_explodir(int x, int y, int qtde){
    if (qtde == 0) return 1;
    if (!eh_valida(&m, x, y)) return 1;
    if (eh_parede(&m, x, y)) return 1;
    
    return 0;
}


void explode_pilula(){
    if (!tem_pilulas) return;
    
    direcoes_explosao_pilula(heroi.x,heroi.y,  1,  0, 3);
    direcoes_explosao_pilula(heroi.x,heroi.y, -1,  0, 3);
    direcoes_explosao_pilula(heroi.x,heroi.y,  0,  1, 3);
    direcoes_explosao_pilula(heroi.x,heroi.y,  0, -1, 3);
    
    tem_pilulas--;
}

void direcoes_explosao_pilula(int x, int y, int somax, int somay, int qtde){
    int novox = x + somax;
    int novoy = y + somay;
    
    
    if (para_de_explodir(novox, novoy, qtde)) {
        return;
    }
    
    m.matriz[novox][novoy] = VAZIA;
    direcoes_explosao_pilula(novox, novoy, somax, somay, qtde - 1);
}


int main() {
    
    ler_mapa(&m);
    encontra_personagem(&m, &heroi, HEROI);
    
    do {
        printf("Power: %d\n", tem_pilulas);
        imprime_mapa(&m);
        
        char comando;
        scanf(" %c", &comando);
        mover(comando);
        if (comando == BOMBA)
            explode_pilula();
        
        
        fantasmas();
        
    } while (!acabou());
    
    imprime_mapa(&m);
    libera_mapa(&m);
    printf("*** GAME OVER ***\n\n");
}

//    char key;
//    scanf(" %c", &key);
//    printf("Antes do if ==> key: %c e keycode: %d\n",key, key);
//
//    if (key >= 97 && key <= 122) key -=32;
//    else {
//        printf("Tecla fora do escopo\n");
//        exit(1);
//    }
//
//    printf("Depois do if ==> key: %c e keycode: %d\n",key, key);
//
//Some ASCII values
//A = 65
//a = 97
//B = 66
//b = 98
;
