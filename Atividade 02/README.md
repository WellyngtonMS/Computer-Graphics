# Rasterização

## Descrição
A atividade 02 consiste em implementar funções muito conhecidas na computação gráfica e que utilizam conceitos e algoritmos de rasterização de linhas e pontos. Conceitos estes aprendidos durante as aulas e que serão melhores abordados adiante.
A rasterização é feita simulando o acesso direto a memória de vídeo.

## Objetivo
O objetivo é aplicar os conceitos mencionados na descrição da atividade a partir da implementação de algoritmos de rasterização e de 3 (três) funções chamadas PutPixel (colocar pixel), DrawLine (desenhar linha) e DrawTriangle (desenhar triângulo). 

## Desenvolvimento
Uma imagem digital é composta de pixels, com quantidades finitas e discretas de representação numérica para sua intensidade, além disso contém um número fixo de linhas e colunas de pixels, normalmente armazenados na memória do computador como uma imagem raster, uma matriz bidimensional de pequenos inteiros, cada um representando uma cor associada a um pixel específico.

Atualmente existem diversos tipos de sistemas que representam cores, porém a mais importante e que foi utilizada na implementação é o sistema padrão de representação de cores em imagens digitais, mais conhecido pela sigla RGBA (Red, Green, Blue e Alpha). Este modelo é muito utilizado na maioria dos equipamentos de obtenção e visualização de imagens. No padrão RGB, cada pixel consiste em três canais, cada um representando uma cor (R para vermelho, G para verde e B para azul). Normalmente, 8 bits são reservados para cada componente (canal), o que se diferencia em 256 níveis de intensidade diferentes para cada cor. Além disso, o canal A (alfa) pode ser usado para transparência.

-  ### TAD (Tipos abstratos de dados)
Como visto, uma imagem raster é composta por um espaço bidimensional, embora a memória seja representada de forma linear. Portanto, é necessário calcular o deslocamento para que cada pixel (dada sua posição X e Y), ocupe um único espaço na memória. Além disso é necessário o armazenamento do valor de cada banda RGBA respectivamente. A seguir é apresentado uma especificação do conjunto de dados e operações construídas para a implementação das funções mencionadas no objetivo.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96197364-39eeec80-0f28-11eb-92cf-67cbd446e665.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 1: Tipos abstratos de dados.
  </p>

Para a rasterização de primitivas foi feita uma simulação de acesso direto à memória de vídeo. Os sistemas operacionais atuais protegem a memória do acesso direto, por isso um [framework](https://github.com/capagot/icg/tree/master/02_mygl_framework), fornecido pelo professor, foi utilizado para efetuar com sucesso tal simulação.

-  ### PutPixel
O número de pixels na tela é equivalente ao número de linhas multiplicado pelo número de colunas, logo a memória deve ter esse mesmo número de posições para representar a tela por completo, linearmente. Portanto, conforme cálculo utilizado na função da figura a seguir, o algoritmo decide a posição de cada pixel e de cada canal de um pixel na memória, considerando a largura em pixels da tela. Definido as informações do pixel ele está pronto para ser impresso na janela.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96198354-fc3f9300-0f2a-11eb-9a5f-86c1e16917d7.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 2: Implementação da função PutPixel.
  </p>

-  ### DrawLine
A função basicamente rasteriza uma linha na tela, recebendo como parâmetros as coordenadas dos seus vértices inicial e final (representados respectivamente pelas tuplas (x1,y1) e (x2,y2)) e as cores (no formato RGBA) de cada vértice. Existem alguns algoritmos para a rasterização de linha, nesta atividade foi implementado e utilizado o algoritmo de Bresenham.
 
O algoritmo de Bresenham (também chamado de algoritmo do Ponto Médio) baseia-se no argumento de que um segmento de reta, ao ser plotado, deve ser contínuo, ou melhor, os pixels que compõem um segmento de reta devem ser vizinhos. É conhecido também por ser um método muito eficiente para desenhar linhas porque usa apenas adição de inteiros. A seguir um exemplo de passo-a-passo da execução do algoritmo:
  ````
    Parâmetros de entrada: (x1,y1) e (x2,y2).
    1. Calcula-se dx=x2-x1 e dy=y2-y1.
    2. Calculam-se as variáveis auxiliares: 2dy e 2dy-2dx.
    3. Coloca-se nas variáveis de trabalho o ponto inicial: x <- x1 e y <- y1.
    4. Plota-se o ponto (x,y).
    5. Calcula-se o parâmetro de decisão: p = 2dy – dx.
    6. Se p for negativo, então x <- x+1, p <- p+2dy e vai para o passo 8.
    7. Se p for positivo ou zero, então: x <- x+1, y <- y+1 e p <- p+2dy – 2dx.
    8. Repetem-se os passos 6 a 7 até que o ponto (x2, y2) seja alcançado.
  ````
Para uma melhor organização do código e decisões a se tomar, foi criado duas funções auxiliares à função DrawLine. Ambas são apresentadas a seguir, assim como a função principal:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96197923-b209e200-0f29-11eb-83f2-2636c1f0fa7a.png" alt="Sublime's custom image"/>
    <img src="https://user-images.githubusercontent.com/54148100/96199274-7f61e880-0f2d-11eb-9712-e637de57adee.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 3: Implementação das funções lineX e lineY.
  </p>
  
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96201218-6a3b8880-0f32-11eb-9679-2aa2348f312b.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 4: Implementação da função DrawLine
  </p>
  
As cores dos pixels ao longo da linha rasterizada foram obtidas por meio de interpolação linear das cores dos vértices.

-  ### Interpolação Linear das cores
O Algoritmo de Interpolação Linear de Cores consiste em interpolar as cores entre o ponto inicial e final da linha de forma linear, ou seja, deve-se ter um degradê suave entre os dois pontos da linha. Realiza-se a diferença de cores entre os pontos final e inicial da linha, obtendo uma variação de cor.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96202971-0ff0f680-0f37-11eb-93dd-bcd32ab9e9a5.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 5: Implementação da função que realiza a interpolação linear das cores.
  </p>
 
-  ### DrawTriangle
Com o algoritmo de Bresenham implementado e a interpolação linear também, para rasterizar um triângulo agora basta rasterizar 3 linhas entre os seus vértices, utilizando então a função DrawLine.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/96205855-f7380f00-0f3d-11eb-8a77-1372dc853ee4.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 6: Implementação da função DrawTriangle.
  </p>

## Resultados

## Dificuldades

## Referências
- [Imagem Digital - Wikipédia](https://pt.wikipedia.org/wiki/Imagem_digital)
- [RGBA](https://pt.wikipedia.org/wiki/RGBA)
- Notas de aula Profº. Christian
