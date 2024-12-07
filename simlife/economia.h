#ifndef RANDOM_TRANSITION_H
#define RANDOM_TRANSITION_H

#include <stdlib.h>
#include <time.h>

// Inicializa o gerador de números aleatórios
void inicializar_aleatorio() {
    srand(time(NULL));
}

// Função para gerar um número aleatório dentro de um intervalo
int gerar_numero(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

// Função para determinar o próximo número com base nas regras
int proximo_numero(int atual) {
    int proximo;

    switch (atual) {
        case 1:
            proximo = gerar_numero(1, 2); // Única possibilidade para 1 é 2
            break;
        case 2:
            proximo = gerar_numero(1, 3); // Pode ir para 1, 2 ou 3
            break;
        case 3:
            proximo = gerar_numero(2, 4); // Pode ir para 2, 3 ou 4
            break;
        case 4:
            proximo = gerar_numero(3, 5); // Pode ir para 3, 4 ou 5
            break;
        case 5:
            proximo = gerar_numero(4, 5); // Pode ir para 4 ou 5
            break;
        default:
            proximo = 3; // Caso padrão (não deve ocorrer)
            break;
    }

    return proximo;
}

#endif // RANDOM_TRANSITION_H


