# Pipeline Gráfico

## Descrição
Esta implementação foi feita com auxílio da biblioteca glm e sua execução ocorrerá nos shaders do OpenGL. Esta atividade também foi realizada a partir de um template de código C++ fornecido pelo professor, que está disponível no [repositório do curso](https://github.com/capagot/icg/tree/master/03_transformations). A atividade consiste em alterar, no template, o conteúdo das matrizes MModel, MView e MProjection para que o programa gere as imagens especificadas em cada exercício.

## Objetivos
O objetivo deste trabalho é familiarizar-se com a estrutura do pipeline gráfico, através da implementação das transformações geométricas (escala, translação, projeção, posição de câmera e transformações livres) que o compõem.

## Desenvolvimento
No contexto da computação gráfica, o pipeline gráfico é um modelo conceitual que descreve quais etapas um sistema gráfico precisa realizar para renderizar uma cena 3D em uma tela 2D. Consiste em uma série de transformações algébricas que são divididas em alguns estágios.

### Transformações Geométricas
Para percorrer o pipeline gráfico, transformações geométricas são feitas de um espaço para outro. A maioria dessas transformações é feita por um operador linear, que neste caso será uma matriz sobre os vetores que compõem um objeto, transformando-os de um espaço vetorial para outro. As principais transformações que são abordadas neste atividade são:

- Escala;
- Translação;
- Projeção;
- Rotação.

### Cena
A cena é composta por dois triângulos (vermelho e azul), sendo que em relação à câmera, o triângulo vermelho está ligeiramente à frente do triângulo azul. A configuração geométrica da cena renderizada pode ser visualizada nas Figuras abaixo.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100792839-042f9580-33fa-11eb-9f9d-0ef69053feff.png" alt="Sublime's custom image"/>
    <img src="https://user-images.githubusercontent.com/54148100/100792892-1ad5ec80-33fa-11eb-8b01-808605b32e8a.png" alt="Sublime's custom image"/>
    <img src="https://user-images.githubusercontent.com/54148100/100792946-350fca80-33fa-11eb-801e-fcc59c9e52c2.png" alt="Sublime's custom image"/>
  </p>

Na primeira figura o plano XY (eixo Z negativo p/ dentro do plano). A figura ao meio representa a visualização dos eixos XYZ, já a terceira figura, o plano ZY (eixo X negativo p/ dentro do plano).

- ### Escala
Neste exercício, é necessário modificar a matriz Model com os seguintes fatores de escala:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100805234-1666ff00-340d-11eb-82a2-3569d3997f43.png" alt="Sublime's custom image"/>
  </p>
  A escala afeta as dimensões de um objeto, de forma que cada coordenada de um vetor A é multiplicada por seus escalares. Portanto, essa transformação pode alterar o comprimento e até mesmo a direção de um vetor.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100805312-34346400-340d-11eb-9c7c-d3a651e70ee3.png" alt="Sublime's custom image"/>
  </p>
Então, substituindo os valores escalares pelos solicitados no exercício, temos:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100805388-57f7aa00-340d-11eb-9461-d107c2a72cb0.png" alt="Sublime's custom image"/>
  </p>
No código temos a seguinte mudanção na matriz Model:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100782737-9aa88a80-33eb-11eb-86c0-2d2fb7978896.png" alt="Sublime's custom image"/>
  </p>
Com o seguinte resultado visual na cena:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100783162-36d29180-33ec-11eb-9ae7-19ef087835dc.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 1: Resultado do 1° exercício.
  </p>
  
- ### Translação
Neste exercício, é necessário modificar a matriz Model com a seguinte translação:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100806215-d43ebd00-340e-11eb-907b-5474692d5523.png" alt="Sublime's custom image"/>
  </p>
A translação é uma transformação afim, então é necessário modificar a coordenada homogênea, de tal forma:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100806426-33043680-340f-11eb-8e65-68699a6a1612.png" alt="Sublime's custom image"/>
  </p>
Então, modificando a matriz Model com os valores especificados no exercício, temos:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100806644-95f5cd80-340f-11eb-8190-5492a7026b93.png" alt="Sublime's custom image"/>
  </p>
No código temos a seguinte mudanção na matriz Model:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100784757-6edad400-33ee-11eb-8a98-13ff32ee5cae.png" alt="Sublime's custom image"/>
  </p>
E o resultado na cena é:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100784847-916ced00-33ee-11eb-99ee-94f81e0810fc.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 2: Resultado do 2° exercício.
  </p>
  
- ### Projeção Perspectiva
Para este exercício, foi necessário modificar a matriz de projeção para que ela considere a câmera na origem de seu sistema de coordenadas, em que d é a distância do centro de projeção à origem do sistema de coordenadas da câmera e seu valor é de 0,5.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100807835-c474a800-3411-11eb-89d6-046eb0d37cc3.png" alt="Sublime's custom image"/>
  </p>
Modificando a matriz de projeção no template, temos:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100783722-e60f6880-33ec-11eb-87a2-fc79d53ebbcd.png" alt="Sublime's custom image"/>
  </p>
E o resultado na cena é:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100783842-13f4ad00-33ed-11eb-911e-2c34ca4f9ed4.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 3: Resultado do 3° exercício.
  </p>

- ### Posição da câmera
Neste exercício, foi necessário manter as modificações feitas na matriz projeção no exercício anterior e modificar a matriz View.

Para definir uma câmera que irá capturar a cena que desejas, é necessário definir seus eixos através das informações que são necessárias para gerá-la. Isso é:
- Posição da câmera: o ponto relativo à sua posição;

- Alvo da câmera: o ponto para onde está olhando;

- Direção: a distância entre o alvo e a posição;

- Vetor UP: um vetor que representa o que seria "pesquisar" no Espaço Universo, que, neste caso, é considerado igual ao vetor unitário que representa o eixo y do Universo.

  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100809923-0dc6f680-3416-11eb-95bb-b7c93f9bc06f.png" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 4: Criando os eixos do sistema de coordenadas da câmera.
  </p>
Após este procedimento, é necessário construir as matrizes que formarão a View.

- Matriz B: Representa os pontos do sistema de coordenadas do Universo no novo sistema relacionado ao Espaço da Câmera.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100810147-8b8b0200-3416-11eb-98c5-2bb90a3e8703.png" alt="Sublime's custom image"/>
  </p>
- Matrix T: Usado para traduzir todos os vértices com o ponto de posição para posicionar a câmera na origem.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100810183-a3fb1c80-3416-11eb-8a0d-f54aec75c742.png" alt="Sublime's custom image"/>
  </p>
- Visualização Matrix: Para combinar tais matrizes e gerar a visualização Matrix, basta multiplicar uma pela outra.
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/100810203-aeb5b180-3416-11eb-9925-41af69e2618e.png" alt="Sublime's custom image"/>
  </p>
  
As modificações, assim como códigos adicionais incluídos neste exercício podem ser vistos com mais detalhes [aqui](https://github.com/WellyngtonMS/Computer-Graphics/blob/0e577d58c0d658e9bff765510e497fecb0b4c83f/Atividade%2003/Exerc%C3%ADcio%2004/main.cpp#L76-L98).

- ### Transformação livre

## Dificuldades

## Referências
- [Pipeline Gráfico - Wikipédia](https://en.wikipedia.org/wiki/Graphics_pipeline)
- [Blog Matheus](http://matheuspraxedescg.blogspot.com/2016/10/pipeline-grafico.html)
- Notas de aula Profº. Christian
