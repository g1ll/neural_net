## Capítulo 1 - Introdução:

<hr>

### Anotações:

Rede neural Perceptron não resolve problema XOR.

<img src="https://latex.codecogs.com/gif.latex?%20XOR%20\iff%20(A%20\lor%20B)%20\land%20\neg(A%20\land%20B)"/> 

*XOR* Table: 

A|B|S 
-|-|-
0|0|0
0|1|1
1|0|1
1|1|0

<hr>

### Questões do Capítulo 1, pag. 8.

#### 1.1 O que quer dizer Inteligência Artificial?

***Resposta:***

O termo Inteligência Artificial (IA) descreve a habilidade de máquinas resolverem problemas não lineares, substituindo o ser humano em diversas atividades um exemplo de IA são as Rede Neuras Artificiais.

#### 1.2 Quais as habilidade que uma máquina inteligente deve apresentar?

***Resposta:***

Uma máquina inteligente deve ter a capacidade de aprender a partir de dados de entrada, com ou sem uma supervisão, ou professor. A máquina com IA é capaz de resolver problemas realizando inferência sobre os dados de entrada. A IA também está relacionada a capacidade de planejamento, acumular e manipular conhecimento, compreeder linguagem natural e interpretar estímulos sensoriais.

#### 1.3 Faça um resumo dos elementos fundamentais de um sistema inteligente.

***Resposta***

Um sistema inteligente consiste em três sitemas fundamentais: Representação do conhecimento, Racioncínio e Aprendizagem. O conhecimento poder ser representado de duas formas: Declaratica e Procedimental. A forma declarativa compreende uma coleção de fatos e relações entre estes fatos, assim como, um motor de inferência sobre estes fatos. O Racionínio está ligado a resolução de problemas, que na maioria das vezes representa uma busca por soluções viáveis, como um problema de otimização. Ou seja, a pesquisa em um espaço de busca de estados possíveis da melhor solução. O Aprendizado é a característica da máquina intelitente aprender com situações passadas, de modo a não repitilas, caso estas sejam inadeguadas, ou repitilas quando adequadas à solução do problema.

#### 1.4 O que é aprendizado?
***Resposta***

Segundo a psicologia, aprendizado é o fato de uma pessoa mudar de comportamento diante de uma situação para evitar um resultado não indesejado, sendo essa mudança relacionada à uma tendência inata, reposta temporária ou maturação (Hilgard, 1975). No entanto, para uma máquina aprender são necessárias habilidades como a capacidade de generalizar, de induzir, de fazer analogias e de receber instruções.

#### 1.5 Descreva as vantagens e limitações das redes neurais.
***Resposta***

Redes neuras possuem as vantagens de generalização, adaptação a universos não-estacionários, e tolerância a falhas. A generalização é a capacidade da rede responder a entradas que não estavam nos dados de treinamento, diferente de algoritmos convencionais que respondem apenas para os dados aos quais foram projetados. Uma rede neural também pode ser projetada para adaptar-se, ou seja, ajustar seus pesos sinápticos de acordo com as mudanças nas estatísticas com o tempo. A outra vantagem estaria na natureza distributiva de processamento, uma rede física, por exemplo, não pararia de funcionar caso um neurônio apresentasse defeito, a rede continuaria a gerar uma resposta global. Neste caso, existiria apenas uma perda da qualidade, sendo, portanto, tolerante a falhas. A principal desvantagem de uma rede neural é a "caixa preta" que o modelo representa, pois não é possível gerar uma prova formal para os resultados obtidos, nem estabelecer relação entre um peso sináptico com uma determinada resposta da rede ou significado físico.

#### 1.6 O que é o problema XOR?

O problema XOR é um problema simples representado pela operação lógica OU Exclusivo. Nesta operação, dadas duas entradas, a resposta será verdadeira apenas se uma das entradas forem verdadeiras. Os pesquisadores Minsky e Seymour provaram que o percepton de uma camada, criado pelo cientista Frank Rosenblatt, não é capaz de resolver o problema simples do XOR.