//
//  mapa.h
//  Curso-C3-Alura
//
//  Created by Gabriel Ferreira on 21/12/16.
//  Copyright © 2016 Gabriel Ferreira. All rights reserved.
//

#ifndef mapa_h
#define mapa_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define VAZIA '.'

#define HEROI '@'
#define FANTASMA 'F'
#define PILULA 'P'

struct mapa{
    char** matriz; // estou falando para o sistema que terei um ponteiro de ponteiros, que é um array de arrays, ou seja uma matriz
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao{
    int x;
    int y;
};
typedef struct posicao POSICAO;

void ler_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void libera_mapa(MAPA* m);
void anda_no_mapa(MAPA* m, int xorigen, int yorigen, int xdestino,int ydestino);
void copia_mapa(MAPA* destino, MAPA* origem);

int encontra_personagem(MAPA* m, POSICAO* p, char c);
int eh_valida(MAPA* m, int x, int y);
int eh_vazia(MAPA* m, int x, int y);
int pode_andar(MAPA* m, char personagem, int x, int y);
int eh_parede(MAPA* m, int x, int y);
int eh_personagem(MAPA* m, char personagem, int x, int y);

#endif /* mapa_h */
