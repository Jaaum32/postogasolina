#include <stdio.h>

int main(void) {
  float preco; // Valor da gasolina
  int tam;     // Tamanho da fila

  printf("Autor: João Vitor da Silva\n");
  printf("Esse programa simula um posto de gasolina com uma bomba com capacidade de 200 litros, ele simula a fila de carros e o abastecimento, também podendo produzir relatórios dos processos executados\n");

  printf("\nInforme o valor do combustível e também o tamanho da fila que o "
         "estabelecimento suportará:\nValor combustível:");
  scanf("%f", &preco);
  printf("Tamanho da fila:");
  scanf("%i", &tam);
  return 0;
}