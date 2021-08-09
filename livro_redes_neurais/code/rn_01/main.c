/* 
 * File:   main.c
 * Author: echoes
 * Teste Rede Neural Artificial Percepton Simples
 * Created on 21 de Novembro de 2013, 00:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define entrada 3
#define saida 2
#define in 4


/*
 * 
 */
int main(int argc, char** argv) {
    
    float w[entrada][saida], // Pesos Wij
            erro, // Valor esperado para o erro
            err[saida], // Erro na saída da RNA
            ni[saida],// ??
            errom,bias, eta, entradas[in][saida], saidas[in][saida],
            phi[saida];
            
    
    
    erro = 1.5;
    printf("\nerro: %.2f\n",erro);
    
    return (EXIT_SUCCESS);
}

