/* 
 * File:   main.c
 * Author: echoes
 * Teste Rede Neural Artificial Percepton Simples
 * Livro Pag 42-43
 * Created on 21 de Novembro de 2013, 00:49
 * Update on 2021/0815
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define entrada 3
#define saida 2
#define in 4

int main(int argc, char **argv)
{

    float w[entrada][saida], // Pesos Wij
        err,                 // Valor esperado para o erro
        erro[saida],         // Erro na saída da RNA
        ni[saida],           // ??
        errom, bias, eta, entradas[in][saida], saidas[in][saida],
        phi[saida];

    int x, cont, contt, contin = 0, epocas, testeerro = 0;
    funcao;
    char continua = 's';

    for (x = 0; x < entrada; x++)
        for (cont = 0; cont < saida; cont++)
            w[x][cont] = 0;

    system('clear');
    printf("Entre com o valor do bias: ");
    scanf("%f", &bias);
    printf("Entre com o valor da taxa de aprendizagem: ");
    scanf("%f", &eta);
    printf("Entre com o número de iterações: ");
    scanf("%d", &epocas);
    printf("Entre com a função desejada [(1) Degrau, (2) Sigmoide]");
    scanf("%d", &funcao);

    printf("Entre com os dados de entrada e de saída para o treinamento:\n");

    for (x = 0; x < in; x++)
        for (cont = 0; cont < saida; cont++)
        {
            printf("Entrada %d, Neuronio %d: ", x + 1, cont + 1);
            scanf("%f", &entradas[x][cont]);
        }

    for (x = 0; x < in; x++)
        for (cont = 0; cont < saida; cont++)
        {
            printf("Saida %d, Neuronio %d: ", x + 1, cont + 1);
            scanf("%f", &saidas[x][cont]);
        }

    printf("Todos os pesos iniciais são zero.\n");
    printf("Iniciando processo iterativo...\n");

    cont = 0;

    while ((cont < epocas) && !testeerro && (continua != 'n'))
    {
        system('clear');
        cont++;
        printf("Iteração %d:\n", cont);
        for (x = 0; x < entrada - 1; x++)
            printf("Entradas: %f", entradas[contin][x]);
        for (x = 0; x < saida; x++)
        {
            ni[x] = w[0][x] * bias;
            for (cont = 0; cont < entrada - 1; cont++)
                ni[x] = ni[x] + w[cont + 1][x] + entradas[contin][contt];
            switch (funcao)
            {
            case 1:
                if (ni[x] > 0)
                    phi[x] = 1;
                else
                    phi[x] = 0;
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
            if (abs(errom) < err)
                testerro = 1;
            else
                testeerro = 0;
        printf("Corrigindo pesos...\n");
        for (x = 0; x < entrada; x++)
            for (contt = 0; contt < saida; contt++)
                if (x == 0)
                    w[x][contt] = w[x][contt] + eta * erro[contt] * bias;
                else
                    w[x][contt] = w[x][contt] + eta * erro[contt] * entradas[contin][x - 1];
        for (x = 0; x < entrada; x++)
            for (contt = 0; contt < saida; contt++)
                printf("w[%d][%d] = %f\n", x, contt, w[x][contt]);

        printf("Continua?");
        scanf("%c", &continua);
        contin++;
        if (contin > entrada)
            contin = 0;
    }
    printf("Finalizado!\n")
}

return (EXIT_SUCCESS);
}
