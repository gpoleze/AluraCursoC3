//
//  header.h
//  Curso-C3-Alura
//
//  Created by Gabriel Ferreira on 19/12/16.
//  Copyright © 2016 Gabriel Ferreira. All rights reserved.
//

#ifndef _COMECOME_H_
#define _COMECOME_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"
#include "ui.h"

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

void mover(char direcao);
void fantasmas();
void explode_pilula();
void direcoes_explosao_pilula(int x, int y, int somax, int somay, int qtde);

int acabou();
int eh_direcao(char direcao);
int praonde_o_fantasma_vai(int xatual, int yatual, int* xdestino, int* ydestino);

#endif
