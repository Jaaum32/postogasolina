#include <stdio.h>

void flush_in() {
  int ch;
  do {
    ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

int main(void) {
  float preco; // Valor da gasolina
  int tam;     // Tamanho da fila

  printf("Autor: João Vitor da Silva\n");
  printf("Esse programa simula um posto de gasolina com uma bomba com capacidade de 200 litros, ele simula a fila de carros e o abastecimento, também podendo produzir relatórios dos processos executados\n");

  printf("\nInforme o valor do combustível e também o tamanho da fila que o "
         "estabelecimento suportará:\n");
  
  do {
    printf("Valor combustível:");
    scanf("%f", &preco);
  } while (preco <= 0);

  do {
    printf("Tamanho da fila:");
    scanf("%i", &tam);
  } while (tam <= 0);

  //----------------------------------

  printf("\n----- Posto de Gasolina -----\n1 - Adicionar carro\n2 - "
         "Abastecimento\n3 - Exibir carros na fila de espera\n4 - "
         "Relatórios\n5 - Encerrar\n");

  int op = 0; // Variável de OPÇÃO

  scanf("%i", &op);

  switch (op) {
  case 1:
    printf("Carro adicionado!");
    break;
  case 2:
    printf("Carro abastecido!");
    break;
  case 3:
    printf("Carros exibidos!");
    break;
  case 4:
    printf("\n----- Relatórios -----\na - Quantidade de litros vendida\nb - "
           "Valor total arrecadado com as vendas\nc - Quantidade de carros "
           "atendidos\nd - Quantidade de combustível restante no tanque\ne - "
           "Gerar arquivo para impressão (com todas as informações de A, B, C "
           "e D)\nf - Voltar ao menu anterior\n");

    char op2; // Variável de OPÇÃO

    flush_in();
    scanf("%c", &op2);

    switch (op2) {
    case 'a':
      printf("Quantidade de litros vendida");
      break;
    case 'b':
      printf("Valor total arrecadado com as vendas");
      break;
    case 'c':
      printf("Quantidade de carros atendidos");
      break;
    case 'd':
      printf("Quantidade de combustível restante no tanque");
      break;
    case 'e':
      printf("Gerar arquivo de impressão");
      break;
    case 'f':
      printf("Menu anterior");
      break;
    }
    break;
  case 5:
    printf("FIM");
    break;
  }

  return 0;
}