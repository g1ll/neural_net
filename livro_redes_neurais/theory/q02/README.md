## Capítulo 2 - Princípios de Neurocomputação:

<hr>

### Anotações:
Representação matemática de um neurônio:

<img src="https://latex.codecogs.com/svg.image?v&space;=&space;\sum_{i=0}^{n}w_{i}x_{i}" title="v = \sum_{i=0}^{n}w_{i}x_{i}" />

Saída da rede:

<img src="https://latex.codecogs.com/svg.image?y_{j}&space;=&space;\phi(v_{j})&plus;b_{j}" title="y_{j}&space;=&space;\phi(v_{j})+b_{j}" />


##### Funções de transferência <img src="https://latex.codecogs.com/svg.image?\phi" title="\phi" />:

1- Função sigmóide:
<img src="https://latex.codecogs.com/svg.image?\phi(v)&space;=&space;\frac{1}{1&plus;e^{-v}}" title="\phi(v) = \frac{1}{1+e^{-v}}" />

2- Função gaussiana:

<img src="https://latex.codecogs.com/svg.image?\phi(v)&space;=&space;e^{-v^{2}}" title="\phi(v) = e^{-v{2}}" />

3- Função tangente hiperbólica:

<img src="https://latex.codecogs.com/svg.image?\phi(v)&space;=&space;tanh(v)" title="\phi(v) = tanh(v)" />

### Questões do Capítulo 2, pag. 18.

#### 2.1 Qual diferença entre um neurônio biológico e um neurônio matemático?

***Resposta:***
A principal diferença está na corrente, um neurônio matemático pode ser simulado através de eletrons en um neurocomputador ou software da rede neural executado geralmente por uma varredura na rede ou usando paralelismo, enquanto que o nurônio biológico utiliza uma rede de ions de sódio e potássio. Os pesos e as ligações entre os neuronios de uma rede neural artificial simbolizam os axionios e os dentritos. No entanto, existem similaridades, pois o neurônio matemático tenta simular as funções do neurônio natural.

#### 2.2 Qual diferença entre o aprendizado supervisionado e o não-supervisioado?

***Resposta:***
A diferença é que o aprendizado supervisionado compara a saída da rede com um valor esperado, e desta forma, corrige os pesos sinápticos para minimizar o erro, como se houvesse um professor. Por outro lado, a rede não-supervisionada não posssui um valor esperado e aprende com a experiência durante o treinamento. Este é o caso característico de redes de classificação onde há uma procura por padrões nos dados.

#### 2.3 O que é retroalimentação?

***Resposta:***
A retroalimentação é quando a saída de um neurônio se liga com um neurônio da camasda anterior ou da sua mesma camada. Essa arquitetura é chamada de feedback e tem um impacto relevante no aprendizado da Rede Neural.