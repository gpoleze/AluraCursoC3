//
//  mapa.c
//  Curso-C3-Alura
//
//  Created by Gabriel Ferreira on 21/12/16.
//  Copyright © 2016 Gabriel Ferreira. All rights reserved.
//

#include "mapa.h"

void copia_mapa(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    
    aloca_mapa(destino);
    for (int i = 0 ; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int eh_parede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_VERTICAL ||
    m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int eh_personagem(MAPA* m, char personagem, int x, int y){
    return m->matriz[x][y] == personagem;
}

int pode_andar(MAPA* m, char personagem, int x, int y){
    return eh_valida(m, x, y) &&
            !eh_parede(m, x, y) &&
             !eh_personagem(m, personagem, x, y);
}

int encontra_personagem(MAPA* m, POSICAO* p, char c){
    for (int i = 0 ; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if (m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

void ler_mapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Seus mapa não pôde ser carregado");
        exit(1);
    } //Mensagem erro na leitura do arquivo mapas.txt
    
    //leio o tamanho do mapa
    fscanf(f, "%d %d", &m->linhas, &m->colunas);
    printf("linhas:%d colunas:%d\n",m->linhas, m->colunas);
    
    aloca_mapa(m);
    
    //leio os valores da matriz
    for (int i = 0; i < m->linhas; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    
    //fecho o arquivo
    fclose(f);
    
}

void aloca_mapa(MAPA* m){
    //reservo a memória necessária para a minha matriz
    m->matriz = malloc(sizeof(char*) * m->linhas); //como mapa já foi definido não preciso de mais nada além de atribuir um valor (neste caso o ponteiro indicando a memmória)
    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void libera_mapa(MAPA* m){
    //libero a memória
    for (int i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

int eh_valida(MAPA* m, int x, int y){
    
    if (x >= m->linhas)
        return 0;
    if (y >= m->colunas)
        return 0;
    
    return 1;
}

int eh_vazia(MAPA* m, int x, int y){

    if (m->matriz[x][y] != VAZIA)
        return 0;
    
    return 1;
}

void anda_no_mapa(MAPA* m, int xorigen, int yorigen, int xdestino,int ydestino) {
    
    char personagem = m->matriz[xorigen][yorigen];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigen][yorigen] = VAZIA;
}

