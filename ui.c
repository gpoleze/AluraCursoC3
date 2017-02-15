//
//  ui.c
//  Curso-C3-Alura
//
//  Created by Gabriel P Ferreira on 2017-02-14.
//  Copyright © 2017 Gabriel Ferreira. All rights reserved.
//

#include "ui.h"

//Desenhos Prsonagens
char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprime_parte(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}


void imprime_mapa(MAPA* m){
    //imprimo em tela a matriz
    for (int i = 0; i < m->linhas; i++) {
        
        for (int parte = 0 ; parte < 4; parte ++) {
        
            for (int j = 0; j < m->colunas; j++) {
                
                switch (m->matriz[i][j]) {
                    case FANTASMA:
                        imprime_parte(desenhofantasma, parte);
                        break;
                        
                    case HEROI:
                        imprime_parte(desenhoheroi, parte);
                        break;
                        
                    case PILULA:
                        imprime_parte(desenhopilula, parte);
                        break;
                        
                    case PAREDE_VERTICAL:
                    case PAREDE_HORIZONTAL:
                        imprime_parte(desenhoparede, parte);
                        break;
                        
                    case VAZIA:
                        imprime_parte(desenhovazio, parte);
                        break;
                }
            }
            printf("\n");
        }
    }
}


