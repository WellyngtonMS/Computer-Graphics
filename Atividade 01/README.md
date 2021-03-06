# Compilando e Executando um Programa OpenGL Moderno

## Descrição
A atividade 1 consiste em apenas executar um programa, que utiliza shaders para desenhar um triângulo colorido na tela, verificando então a integrida da instalação do modern OpenGL de maneira correta.

## Objetivo
Os objetivos deste trabalho são:
-  Verificar se o ambiente de desenvolvimento em OpenGL 3.3 está corretamente configurado no computador;
-  Familizarizar-se com a estrutura de um programa OpenGL moderno.

## Desenvolvimento
Para a realização deste trabalho, inicialmente deve-se fazer download do material OpenGL disponível no repositório da disciplina [capagot/ICG](https://github.com/capagot/icg).
Após o download, deverá compilar e executar este programa da seguinte maneira:
##### Ubuntu 20.04 LTS

-  Modern
  ````
$ make
$ ./moderngl_hello_world 
  ````
-  Old
  ````
$ make
$ ./old_hello_world 
  ````
  Durante a compilação alguns warnings poderão aparecer na tela.
  
## Resultados
Uma vez compilado, ao ser executado, o programa apresentará uma janela contendo um triângulo colorido, como ilustrado a seguir:
  <p align="center">
    <img src="https://user-images.githubusercontent.com/54148100/94626457-846a3b00-0291-11eb-8ba8-579bbbb48592.jpg" alt="Sublime's custom image"/>
  </p>
  <p align="center">
    Figura 1: Janela OpenGL criada durante a execução do programa.
  </p>

![Alt text](https://user-images.githubusercontent.com/54148100/94623221-11a99180-028a-11eb-8274-3c2bf81e4bdd.gif)
  
## Dificuldades
As maiores dificuldades encontradas na primeira atividade, foram relacionadas a instalação do ambiente de desenvolvimento e das bibliotecas necessárias para a compilação e a execução dos códigos da atividade.
Inicialmente foram executados os seguintes comandos:
````
$ sudo apt-get update
$ sudo apt-get install libgll-mesa-dev
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
````
Porém alguns erros relacionados aos arquivos .glsl como o seguinte, apareceram:
````
ERROR::SHADER::VERTEX::COMPILATION_FAILED
0:1(10): error: GLSL 3.30 is not supported. Supported version are: 1.10, 1.20, 1,30, 1.00 ES, and 3.00 ES
````
Facilmente resolvidos com as linhas de comando:
````
$ sudo apt-get install build-essential libgl1-mesa-dev
$ sudo apt-get install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev
````
