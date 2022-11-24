#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define NONE "\033[0m"

#include <stdbool.h>
#include <stdio.h>

void flush_in() {
  int ch;
  do {
    ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

int main(void) {
  float preco;        // Valor da gasolina
  int tam;            // Tamanho da fila
  float tanque = 200; // Quantidade de litros
  bool rep = true;    // Parametro do laço de repetição do menu principal
  bool rep2 = true;   // Parametro do laço de repetição do menu relatórios

  printf("Autor: João Vitor da Silva\n");
  printf(
      "Esse programa simula um posto de gasolina com uma bomba com capacidade "
      "de 200 litros, ele simula a fila de carros e o abastecimento, também "
      "podendo produzir relatórios dos processos executados\n");

  printf("\nInforme o valor do combustível e também o tamanho da fila que o "
         "estabelecimento suportará:\n");

  do {
    printf("Valor combustível (deve ser maior que 0 e use . no lugar da , para "
           "números decimais):");
    scanf("%f", &preco);
  } while (preco <= 0);

  do {
    printf("Tamanho da fila (deve ser maior que 0 ):");
    scanf("%i", &tam);
  } while (tam <= 0);

  //----------------------------------
  while (rep) {
    printf("\n----- Posto de Gasolina -----\n1 - Adicionar carro\n2 - "
           "Abastecimento\n3 - Exibir carros na fila de espera\n4 - "
           "Relatórios\n5 - Encerrar\n");

    int op = 0; // Variável de OPÇÃO

    scanf("%i", &op);

    switch (op) {
    case 1:
      printf("%sCarro adicionado!%s\n", C_GREEN, NONE);
      break;
    case 2:
      printf("%sCarro abastecido!%s\n", C_GREEN, NONE);
      break;
    case 3:
      printf("%sCarros exibidos!%s\n", C_GREEN, NONE);
      break;
    case 4:
      rep2 = true;

      while (rep2) {
        printf(
            "\n----- Relatórios -----\na - Quantidade de litros vendida\nb - "
            "Valor total arrecadado com as vendas\nc - Quantidade de carros "
            "atendidos\nd - Quantidade de combustível restante no tanque\ne - "
            "Gerar arquivo para impressão (com todas as informações de A, B, C "
            "e D)\nf - Voltar ao menu anterior\n");

        char op2; // Variável de OPÇÃO

        flush_in();
        scanf("%c", &op2);

        switch (op2) {
        case 'a':
          printf("%sQuantidade de litros vendida:%s\n", C_GREEN, NONE);
          break;
        case 'b':
          printf("%sValor total arrecadado com as vendas:%s\n", C_GREEN, NONE);
          break;
        case 'c':
          printf("%sQuantidade de carros atendidos:%s\n", C_GREEN, NONE);
          break;
        case 'd':
          printf("%sQuantidade de combustível restante no tanque:%s\n", C_GREEN,
                 NONE);
          break;
        case 'e':
          printf("%sGerar arquivo de impressão:%s\n", C_GREEN, NONE);
          break;
        case 'f':
          rep2 = false;
          break;
        default:
          printf("%sVocê digitou um valor fora do menu de relatórios%s\n",
                 C_RED, NONE);
        }
      }

      break;
    case 5:
      printf("%sFIM%s\n", C_YELLOW, NONE);
      rep = false;
      break;
    default:
      printf("%sVocê digitou um valor fora do menu%s\n", C_RED, NONE);
    }
  }

  return 0;
}