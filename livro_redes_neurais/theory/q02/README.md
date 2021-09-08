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

#### 2.4 Qual o pricípio de funcionamento dos neurônios, de acordo com Hebb?

***Resposta:***
O princípio de funcionamento de Hebb diz que "Quando um axiônio da célula A está perto o suficiente para excitar uma célula B e participa do seu disparo repetidamente, então algum processo de crescimento ou modificação metabólica acontece em uma das células ou em ambas, de tal forma que a eficiência de A como uma das células que dispara B é aumentada".

#### 2.5 Qual os algoritmos aplicados ao treinamento das redes neurais?

***Resposta:***
Existem diversos algoritmos de aprendizagem para ajustar os pesos sinápticos e os valores dos ***bias***. Alguns dests algoritmos de aprendizagem utilizados são:
 1- Aprendizagem por correção  de erros (regra delata);
 2 - Aprendizagem competitiva (regra de kohonen);
 3 - Aprendizagem baseda em memória;
 4 - Aprendizagem hebbiana;

### 2.6 O que é, e para que serve um ***bias*** ?

***Resposta:***
Um bias é um parametro adicional somado aos pesos sinápticos de modo a trazer uma maior possibilidade de ajuste e adaptação do modelo neural ao problema de interesse. Outra contribuição relevante to parametro **bias*** é permitir que mesmo com entrdas nulas a saída do neurônio não seja nulo. Por exmplo, se usássemos a função de transferencia  da tangente hiperbólica para entradas nulas a ativação ***v*** seria nula também nula. Com o ***bias*** evitamos que x = [0 0]t seja nulo e podemos relacionar com y = 1, como no problema '~not~' da lógica.