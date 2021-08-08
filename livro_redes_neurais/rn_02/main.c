/*
 * File:   main.c
 * Author: echoes
 *
 * Created on 28 de Novembro de 2013, 10:36
 * Rede Neural Artificial
 * - Percepton de Multiplas Camadas
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>


/**************************************
 * Funções
 */


/**
 * Função de Transferência - Sigmoid
 * f(x)=1/1-exp(v)
 *  - v : valor da função de ativação
 * @param v
 *      Valor da função de ativação V
 * @return float
 */
float ft_sigmoid(float v);

/**
 * Derivada da Função de Transferência - Sigmoid
 * f(x)=exp(-v)/(1+exp(-v))^2
 *  - v : valor da função de ativação
 * @param v
 *      Valor da função de ativação V
 * @return float
 */
float diff_ft_sigmoid(float v);

int main(int argc, char** argv) {
   

    int x, y, i, j, k, // Variáveis auxiliares
            ne = 1, // Número de iterações para geração de valores desejados
            n = 3, // Número de neurônios
            epocas = 100000, // Número de iterações de treinamento
            cdebug = 0, //flag para habilitar debug geral
            cdebugerror = 1; //falg para habilitar apenas o erro

    float wd[2][2], // Pesos desejados
            w[2][2], // Pesos para iterações
            wa[2][2], //Pesos aleatórios
            deltaw[2][2], //Ajuste dos pesos
            bias[3], // Valor de bias
            del_bias[3], //Variação do bias
            vn[n], // Valores da função de ativação
            sn[n], // Valores da função de transferência
            gln[n], // Valor do gradiente local de cada neurônio
            saidasd[ne], // Valores da primeira saída, valores desejados
            saidas[ne], // Valores das saídas de treinamento
            erros, //erro
            z,ta = 0.9, // Taxa de aprendizajem
            deuc;  //Distancia euclidiana

    srand48(time(NULL));

    bias[0] = 1;
    bias[1] = 1;
    bias[2] = 1;
    

    printf("\nREDE NEURAL MLP PRÉ-MAPEADA\n");

    printf("\n\t£-Gerando pesos mapeados... \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
           wd[i][j] = floor(drand48()*10)/10;
            //wd[i][j] = drand48()/100;
            printf("\n\t  w[%d%d] » %.3f", i, j, wd[i][j]);
        }
    }

    printf("\n\t£-Calculando valores desejados...\n");

    for (k = 0, z = k+1; k < ne; k++, z++) {
        //printf("\n\t z = %d", z);
        for (i = 0; i < n - 1; i++) {
            vn[i] = wd[0][i] * z + bias[i];
            //printf("\n\t v[%d] = %f.3", i + 1, vn[i]);
            sn[i] = ft_sigmoid(-vn[i]);
            //printf("\n\t ft[%d] = %f.3", i + 1, sn[i]);
        }
        vn[n - 1] = wd[1][0] * sn[0] + wd[1][1] * sn[1] + bias[2];
        //printf("\n\t v[%d] = %f.3", n, vn[n - 1]);
        sn[i] = ft_sigmoid(vn[n - 1]);
        //printf("\n\t ft[%d] = %f.3", n, sn[n - 1]);
        saidasd[k] = sn[n - 1];
        //printf("\n\t%.3f", saidasd[k]);
        //printf("\n\t---------------");
    }

    for (k = 1; k <= ne; k++) {
        printf("\n\t x=%d | f(x)=%.3f ", k, saidasd[k - 1]);
    }
    printf("\n──────────────────────────────────────────────────");

    printf("\n\n¬ INICIO DO TREINAMENTO:̣\n");
    printf("\n\t§-Épocas de treinamento: %d", epocas);
    printf("\n\t§-Taxa de aprendizagem: %.3f", ta);

    //GERANDO PESOS ALEATÓRIOS
    printf("\n\t§-Gereando pesos aleatórios...\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            w[i][j] = floor(drand48()*10)/10;
            //w[i][j] = drand48()/100;
            wa[i][j] = w[i][j];
            printf("\t| %.3f", w[i][j]);
        }
    }

    //LOOP PARA ÉPOCAS DE TREINAMENTOS
    for (k = 0; k < epocas; k++) {
        if(cdebug==1)printf("\n\n\t§-Época » %d", k);

        //LOOP PARA ENTRAR COM VALORES NA REDE
        for (j = 0,x=j+1; j < ne; j++,x++) {

            //CALCULANDO SAIDAS
            // printf("\n\t\t x = %d", x);
            for (i = 0; i < n - 1; i++) {
                vn[i] = w[0][i] * x + bias[i];
                //   printf("\n\t\t v[%d] = %f.3", i + 1, vn[i]);
                sn[i] = ft_sigmoid(-vn[i]);
                // printf("\n\t\t ft[%d] = %f.3", i + 1, sn[i]);
            }
            vn[n - 1] = w[1][0] * sn[0] + w[1][1] * sn[1] + bias[2];
            //printf("\n\t\t v[%d] = %f.3", n, vn[n - 1]);
            sn[i] = ft_sigmoid(vn[n - 1]);
            //printf("\n\t\t ft[%d] = %f.3", n, sn[n - 1]);
            saidas[j] = sn[n - 1];
            //printf("\n\t\t%.3f", saidas[j]);
            //printf("\n---------------");
        }

        //AJUSTES DA CAMADA DE SAÍDA PARA CADA ENTRADA
        for (j = 0,x=j+1; j < ne; j++,x++) {

        x = 0; //sinal de entreda, treinar primeiro sinal
        //CÁLCULO DO ERRO
        if(cdebug==1)printf("\n\t\tø Cálculo do erro para saída ..");
        erros = saidasd[j] - saidas[j];
        if(cdebugerror==1 || cdebug==1) printf("\n\t\t epoca %d | erro »» %f | saída %d",k, erros,j);
        //CÁLCULO DO GRADIENTE LOCAL NEURÔNIO DE SAÍDA N3
        if(cdebug==1)printf("\n\t\tø Cálculo do gradiente local do neurônio de saída");
        if(cdebug==1)printf("\n\t\t\tvn[2] »» %.3f", vn[2]);
        gln[2] = -erros * diff_ft_sigmoid(vn[2]);
        if(cdebug==1)printf("\n\t\t\tð[2] »» %.3f", gln[2]);

        //AJUSTE DO PESO W10
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do peso W10");
        w[1][0] += ta * gln[2] * sn[0]; //PESO MENOS A VARIAÇÃO
        if(cdebug==1)printf("\n\t\t\tw[1][0] »» %.3f", w[1][0]);

        //AJUSTE DO PESO W11
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do peso W11");
        w[1][1] += ta * gln[2] * sn[1];
        if(cdebug==1)printf("\n\t\t\tw[1][1] »» %.3f", w[1][1]);

        //AJUSTE DO BIAS B2
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do Bias B2");
        //del_bias[2] = ta * gln[2] * x;
        del_bias[2] = -ta * gln[2];// errata -t*del(n)
        bias[2] += del_bias[2];
        if(cdebug==1)printf("\n\t\t\tbias[2] »» %.3f", bias[2]);

        //AJUSTES DA CAMADA OCULTA
        if(cdebug==1)printf("\n\t\tø Ajustes da camada oculta...");

        //CÁLCULO DO GRADIENTE LOCAL DO NEURÔNIO DA CAMADA OCULTA N1
        if(cdebug==1)printf("\n\t\tø Cálculo do gradiente local do neurônio n[1]");
        gln[1] = diff_ft_sigmoid(vn[1]) * gln[2] * w[1][1];
        if(cdebug==1)printf("\n\t\t\tvn[1] »» %.3f", vn[1]);
        if(cdebug==1)printf("\n\t\t\tð[1] »» %.3f", gln[1]);

        //AJUSTE DO PESO W01
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do peso W01");
        w[0][1] += ta * gln[1] * x;
        if(cdebug==1)printf("\n\t\t\tw[0][1] »» %.3f", w[0][1]);

        //AJUSTEDO BIAS B1
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do Bias B1");
        //bias[1] += -ta * gln[1] * x; //bias menos a variação
        bias[1] += - ta * gln[1]; //bias menos a variação
        if(cdebug==1)printf("\n\t\t\tbias[1] »» %.3f", bias[1]);

        //CÁLCULO DO GRADIENTE LOCAL DO NEURÔNIO DA CAMADA OCULTA N0
        if(cdebug==1)printf("\n\t\tø Cálculo do gradiente local do neurônio n[0]");
        if(cdebug==1)printf("\n\t\t\tvn[0] »» %.3f", vn[0]);
        gln[0] = diff_ft_sigmoid(vn[0]) * gln[2] * w[1][0];
        if(cdebug==1)printf("\n\t\t\tð[0] »» %.3f", gln[0]);

        //AJUSTE DO PESO W00
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do peso W01");
        w[0][0] += ta * gln[0] * x;
        if(cdebug==1)printf("\n\t\t\tw[0][1] »» %.3f", w[0][0]);

        //AJUSTEDO BIAS B0
        if(cdebug==1)printf("\n\t\tø Cálculo do ajuste do Bias B1");
        //bias[0] += -ta * gln[0] * x; //bias menos a variação
        bias[0] += -ta * gln[0]; //bias menos a variação
        if(cdebug==1)printf("\n\t\t\tbias[1] »» %.3f", bias[0]);

        }//fim do treinamento das saidas


                //IMPRIMINDO SAIDAS GERADAS
                if(cdebug==1)printf("\n\t\tø Saída gerada | saida desejada...");
                for (j = 0,z=0; j < ne; j++) {
                      if(cdebug==1)printf("\n\t\t\t x=%d | f(x)=%.6f | f(x)=%.6f | saída %d", j + 1, saidas[j], saidasd[j],j);
                    //teste de convergência
                    if(saidas[j]==saidasd[j]){
                        z++;//conta quantas saidas convergem
                    }
                }
                 //SE TODAS SAIDAS CONVERGEM SAI DO LOOP DE TREINAMENTO
                if(z==ne){
                     if(cdebugerror==1)printf("\n\n\t\t TODAS SAIDAS CONVERGIRAM EM %d epocas", k);
                     k=epocas;
                }




        if(cdebug==1)printf("\n\t---------------------------------------------");


    }
    printf("\n\n¬ FIM DO TREINAMENTO:̣\n");

    //SAIDAS APÓS TREINAMENTOS
    printf("\n\t¬RESULTADOS APÓS TREINAMENTOS");
    printf("\n\t§-Épocas de treinamento: %d", epocas);
    printf("\n\t§-Taxa de aprendizagem: %.3f", ta);
    //IMPRIMINDO SAIDAS GERADAS
    printf("\n\t\tø Saída gerada | saida desejada...");
    for (j = 0; j < ne; j++) {
        printf("\n\t\t x=%d | f(x)=%.3f | f(x)=%.3f", j + 1, saidas[j], saidasd[j]);
    }

    //PESOS ORIGINAIS
    printf("\n\t§-Pesos originais...\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("\t| %.3f", wd[i][j]);
        }
    }

    //PESOS ALEATÓRIOS
    printf("\n\t§-Pesos aleatórios...\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("\t| %.3f", wa[i][j]);
        }
    }


    //PESOS TREINADOS
    printf("\n\t§-Pesos treinados...\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("\t| %.3f", w[i][j]);
        }
    }

    //DISTANCIA EUCLIDIANA DOS PESOS
    deuc = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            deuc += pow(wd[i][j] - w[i][j],2);
        }
    }
    deuc = sqrt(deuc);;
    printf("\n\t§-Distância euclidiana : %f", deuc);


    printf("\n");
    return (EXIT_SUCCESS);
}

float ft_sigmoid(float v) {
    return 1 / (1 - exp(-v));
}

float diff_ft_sigmoid(float v) {
    return exp(-v) / pow((1 + exp(-v)), 2);
}
