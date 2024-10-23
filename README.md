# Determinant Calculator

## Introdução

Esta é a documentação do projeto **Determinant Calculator**, cujo objetivo é calcular o determinante de uma matriz data de maneira genérica para qualquer matriz quadrada de ordem n.

## Implementação

Basicamente o projeto consiste em um `Parser`(responsável por validar e converter um .txt em dados na memória) e uma `Calculator` que é reponsável por fazer os cálculos que chegam no determinante.

## Explicação

O **determinante** de uma matriz quadrada é um número escalar associado a essa matriz, que fornece informações importantes sobre suas propriedades. Por exemplo, o determinante pode indicar se uma matriz é invertível (não singular) ou não (singular). Se o determinante for zero, a matriz não tem inversa; se for diferente de zero, a matriz é invertível.
Uma das formas de calcular o determinante de uma matriz **A** é através da soma de produtos elementares. Esse método, baseado na **Regra de Laplace**, expande o determinante em termos dos cofatores da matriz.

## Uso

Para fazer uso do projeto siga as intruções abaixo:

### Pré-requisitos
- Cmake
- Git
- (Por conta do uso de scripts, preferencialmente um sistema de base Unix)

### Passo-a-Passo

1. Clone [este](https://github.com/gabrieloak123/determinant-calculator) repositório.
```
git clone https://github.com/gabrieloak123/determinant-calculator.git
```
2. Insira o .txt que contém a matriz que será usada na operação na pasta `files`
3. Rode o arquivo `run.sh` (Talvez seja necessário dar permissão)
```
chmod +x run.sh
./run.sh
```
