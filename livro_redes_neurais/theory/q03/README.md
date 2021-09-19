## Capítulo 3 - O Projeto de uma Rede Neural:

<hr>

### Anotações:

### Questões do Capítulo 3, pag. 25.

#### 3.1 Descreva as fases do projeto de uma rede neural.
***Resposta:***
O projeto de uma rede neural compreende cinco fases bem definidas, sendo elas:
1 - Coleta e seleção de dados;
2 - Configuração da Rede;
3 - Treinamento;
4 - Teste, validação;
5 - Treinamento;

#### 3.2 O que pode gerar custos computacionais?
***Resposta:***
Sendo a quantidade de sinapses da rede proporcional ao tamanho de posições do vetor de entrada de dados, vetores com grandes quantiades de dados geram um enorme esforço computacional. Portanto, a quantidade de dados de entrada está limitada à capacidade computacional disponível.

#### 3.3 Quantas e quais são as etapas de configuração de uma rede neural?
***Resposta:***
A fase de configuração da rede neural é composta por três etapas. Sendo elas:
1 - Escolha do Paradigma, ou seja, qual será o tipo de rede implementado, perceptron, perceptron de múltipla camada, rede de kohonen, etc...

2 - Qual a quantidade de neurônios e camadas a rede deverá possuir;

3 - Determinação do algoritmo de treinamento e função de transferência da rede.

#### 3.4 Em que faze é verificado o desempenho da rede, procando que ela não decorou os dados?
***Resposta:***

É na fase de *Teste* que são apresentados novos dados a rede neural. Estes dados não foram utilizados na fase de treinamento e, desta forma, é possível determinar se a rede consegue generalizar e resolver o problema de interesse.