## Questão 01

Algoritmo para encontrar o maior palíndromo (trecho que lido da esquerda pra direita e vice-versa mantem a mesma sequência em ambos os lados).

A sequência deve ser lido a partir do arquivo de texto *strings_01*.

O código deve apresentar a quantidade de letras do maior palíndromo dentro de cada string e zero caso não encontre.

## Questão 02

Desenvolver um programa que receba via teclado um número romano, converta o mesmo em número decimal e apresente em tela o resultado.

Considerar como números validos: I = 1, V = 5 , X = 10, L = 50, C = 100, D = 500, M = 1000

Exemplos de referência de saída : IV = 4 , VI = 6 , XII = 12 , IX =9 , VIII = 8, MDCDLXXIV = 1974.

## Questão 03

Considerando que o espaço de cor RGB pode ser representada por um uint32, onde os 8 primeiros bits menos significantes representam o canal azul,
seguidos por 8 bits que representam a claridade de verde, que por sua vez são seguidos de 8 bits que nos dizem a intensidade do vermelho. Os 8 bits mais significantes são interpretados como o canal Alpha, ou seja, a transparência.

Podemos, portanto, representar cada canal de cor por um par hexadecimal, de 00 a FF. Conseguimos definir então que:

- 0x0 é equivalente a preto, já que a luminosidade de todos os canais está em 0; 
- 0xFF (255) nos daria o azul mais brilhante;
- 0xFF00 (65280) nos daria o máximo de verde possivel;
- 0xFF0000 (16711680) nos daria o vermelho mais vivo;

Crie com base nisto uma função que gradativamente mude e printe a cor vermelha de r_inicial para r_final em um certo numero de passos;

Referência de saída:

```bash
cor_inicial = 0x00001A; 
cor_final = 0xFF001A; 
steps = 3;
```

Este programa também recebe cores como argumentos em linha de comando
por exemplo:

```bash
./a.out 0x00001A 0xFF001A 3
```

```
output_esperado:
    0x55001A\n
    0xAA001A\n 
    0XFF001A\n
```

## Questão 04

Dada uma array de k , lista lincada “listas”, cada lista esta em ordem ascendente. Mergear as listas lincadas em uma única lista em ordem ascendente.

Input: 

```
listas = [[1,3,8],[1,3,6],[8,9]] 
```

Output: 

``` 1 1 3 3 6 8 8 9```


## Questão 05

O código deverá fazer um sorteio e a comparação com o “premio”. Se houver match , deverá ser exibida a saída da string “ganhou”.

</br>
</br>
<p align=left> <b>Minhas informações de contato 📬</b></p>
<p align=left>
<a href="https://github.com/andersonhsporto" target="_blank"><img src="https://img.shields.io/badge/Github-181717?logo=Github&logoColor=white"/></a>  
<a href="mailto:anderson.higo2@gmail.com" target="_blank"><img src="https://img.shields.io/badge/Gmail-EA4335?logo=Gmail&logoColor=white"/></a>
<a href= "https://www.linkedin.com/in/andersonhsporto/"target="_blank"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?logo=linkedin&logoColor=white"/></a>