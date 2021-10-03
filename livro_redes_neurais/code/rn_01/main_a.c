/* 
 * File:   main.c
 * Author: echoes
 * Teste Rede Neural Artificial Percepton Simples
 * Livro Pag 42-43
 * Created on 02 de Outubro de 2021, 15:19
 * Alteração do exemplo original do livro para epocas automáticas
 * até atingir o erro médio geral definido
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define entrada 3
#define saida 2
#define in 4

int main(int argc, char **argv)
{
    float w[entrada][saida], err, erro[saida], ni[saida], errom,
        bias, eta, entradas[in][saida], saidas[in][saida],
        phi[saida];
    int x, cont, contt, contin = 0, epocas=0, testeerro = 0, funcao;
    char continua = 's';
    for (x = 0; x < entrada; x++)
        for (cont = 0; cont < saida; cont++)
            w[x][cont] = 0;

    system("clear");
    printf("Entre com o valor do bias: ");
    scanf("%f", &bias);
    printf("Entre com o valor da taxa de aprendizagem: ");
    scanf("%f", &eta);
    printf("Entre com o valor do erro esperado: ");
    scanf("%f", &err);
    printf("Entre com a função desejada [(1) Degrau, (2) Sigmoide]: ");
    scanf("%d", &funcao);

    printf("Entre com os dados de entrada e de saída para o treinamento:\n");

    for (x = 0; x < in; x++)
        for (cont = 0; cont < saida; cont++){
            printf("Entrada %d, Neuronio %d: ", x + 1, cont + 1);
            scanf("%f", &entradas[x][cont]);
        }

    for (x = 0; x < in; x++)
        for (cont = 0; cont < saida; cont++){
            printf("Saida %d, Neuronio %d: ", x + 1, cont + 1);
            scanf("%f", &saidas[x][cont]);
        }

    printf("Todos os pesos iniciais são zero.\n");
    printf("Iniciando processo iterativo...\n");
    cont = 0;
    while (!testeerro)
    {
        //system("clear");
        cont++;
        printf("\nIteração %d:\n", cont);
        printf("\nContador Entradas: %d:\n", contin);
        for (x = 0; x < entrada - 1; x++)
            printf("Entradas: %f\n", entradas[contin][x]);
        for (x = 0; x < saida; x++){
            ni[x] = w[0][x] * bias;
            for (contt = 0; contt < entrada - 1; contt++)
                ni[x] = ni[x] + w[contt + 1][x] + entradas[contin][contt];
            switch (funcao)
            {
            case 1:
                if (ni[x] > 0) phi[x] = 1;
                else phi[x] = 0;
                break;
            case 2:
                phi[x] = 1 / (1 + exp(-ni[x]));
                break;
            }
            erro[x] = saidas[contin][x] - phi[x];
            printf("Saída esperada: %f\n", saidas[contin][x]);
            printf("Saída da rede: %f\n", phi[x]);
        }
        errom = 0;
        for (x = 0; x < saida; x++)
            errom = errom + erro[x] / saida;
        printf("Erro médio geral: %f\n", errom);
        for (x = 0; x < saida; x++)
            if (abs(errom) < err) testeerro = 1;
            else testeerro = 0;
       
        printf("Corrigindo pesos...\n");
        for (x = 0; x < entrada; x++)
            for (contt = 0; contt < saida; contt++)
                if (x == 0)
                    w[x][contt] = w[x][contt] + eta * erro[contt] * bias;
                else
                    w[x][contt] = w[x][contt] + eta * erro[contt] * entradas[contin][x - 1];
        
        for (x = 0; x < entrada; x++)
            for (contt = 0; contt < saida; contt++)
                printf("w[%d][%d] = %.2f\n", x, contt, w[x][contt]);

        contin++;
        if (contin > entrada) contin = 0;
        epocas++
    }
    printf("Finalizado!\n");
    printf("Iterações: %d", epocas);
    return EXIT_SUCCESS;
}