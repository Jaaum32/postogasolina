#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_CYAN "\033[36m"
#define NONE "\033[0m"

struct Carro {
  char marca[30];
  char modelo[30];
  int ano;
  int portas;
  char placa[10];
  int rodas;
};

void flush_in() {
  int ch;
  do {
    ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

void execInicio() {
  printf("Autor: João Vitor da Silva\n");
  printf(
      "Esse programa simula um posto de gasolina com uma bomba com capacidade "
      "de 200 litros, ele simula a fila de carros e o abastecimento, também "
      "podendo produzir relatórios dos processos executados\n");

  printf("\nInforme o valor do combustível e também o tamanho da fila que o "
         "estabelecimento suportará:\n");
}

float lerPreco(float preco) {
  do {
    printf("Valor combustível (deve ser maior que 0 e use . no lugar da , para "
           "números decimais):");
    scanf("%f", &preco);
  } while (preco <= 0);

  return preco;
}

int lerTamanho(int tam) {
  do {
    printf("Tamanho da fila (deve ser maior que 0 ):");
    scanf("%i", &tam);
  } while (tam <= 0);

  return tam;
}

int exibirMenu() {
  printf("\n----- Posto de Gasolina -----\n1 - Adicionar carro\n2 - "
         "Abastecimento\n3 - Exibir carros na fila de espera\n4 - "
         "Relatórios\n5 - Calibrar\n6 - Encerrar\n");

  int op = 0; // Variável de OPÇÃO

  scanf("%i", &op);

  system("clear");

  return op;
}

char exibirMenuRelatorios() {
  printf("\n----- Relatórios -----\na - Quantidade de litros vendida\nb - "
         "Valor total arrecadado com as vendas\nc - Quantidade de carros "
         "atendidos\nd - Quantidade de combustível restante no tanque\ne - "
         "Gerar arquivo para impressão (com todas as informações de A, B, C "
         "e D)\nf - Voltar ao menu anterior\n");

  char op2; // Variável de OPÇÃO

  flush_in();
  scanf("%c", &op2);

  system("clear");

  return op2;
}

void delay(unsigned int secs) {
  unsigned int end = time(0) + secs;
  while (time(0) < end)
    ;
}

void calibrar(struct Carro c) {
  int pressao;

  printf("Digite o valor da pressao desejada nos pneus: ");
  scanf("%i", &pressao);
  printf("\n");

  int vet[c.rodas / 2][2];

  for (int i = 0; i < c.rodas / 2; i++) {
    for (int j = 0; j < 2; j++) {
      vet[i][j] = pressao - (rand() % 10);
    }
  }

  printf("\n");
  for (int i = 0; i < c.rodas / 2; i++) {
    for (int j = 0; j < 2; j++) {
      while (vet[i][j] != pressao) {
        for (int i = 0; i < c.rodas / 2; i++) {
          for (int j = 0; j < 2; j++) {
            if (vet[i][j] == pressao) {
              printf("%s %i %s", C_GREEN, vet[i][j], NONE);
            } else {
              printf(" %i ", vet[i][j]);
            }
          }
          printf("\n\n");
        }
        delay(1);
        system("clear");
        vet[i][j]++;
      }
    }
  }

  for (int i = 0; i < c.rodas / 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (vet[i][j] == pressao) {
        printf("%s %i %s", C_GREEN, vet[i][j], NONE);
      } else {
        printf(" %i ", vet[i][j]);
      }
    }
    printf("\n\n");
  }

  printf("%sTodos os pneus foram calibrados!%s\n", C_GREEN, NONE);
}

void imp(struct Carro c[], int tam) {
  for (int i = 0; i <= tam; i++) {
    if (strcmp(c[i].marca, "") != 0) {
      printf("Carro %i\n", i + 1);
      printf("Marca: %s", c[i].marca);
      printf("Modelo: %s", c[i].modelo);
      printf("Ano: %i\n", c[i].ano);
      printf("Portas: %i\n", c[i].portas);
      printf("Placa: %s", c[i].placa);
      printf("Rodas: %i\n\n", c[i].rodas);
    }
  }
}

void informarCarro(struct Carro carrosFila[], int fila) {
  struct Carro c;

  flush_in();
  printf("Informe os dados do seu carro\nMarca: ");
  fgets(c.marca, 30, stdin);

  printf("Modelo: ");
  fgets(c.modelo, 30, stdin);

  printf("Ano: ");
  scanf("%i", &c.ano);

  printf("Portas: ");
  scanf("%i", &c.portas);

  flush_in();
  printf("Placa: ");
  fgets(c.placa, 10, stdin);

  printf("Número de rodas: ");
  scanf("%i", &c.rodas);

  printf("\n");

  carrosFila[fila] = c;
}

void atenderCarro(struct Carro carrosFila[], struct Carro *atendidos, int fila, int atend) {
  struct Carro n = {"", "", 0, 0, ""};

  atendidos[atend - 1].portas = carrosFila[0].portas;
  atendidos[atend - 1].ano = carrosFila[0].ano;
  strcpy(atendidos[atend - 1].marca, carrosFila[0].marca);
  strcpy(atendidos[atend - 1].modelo, carrosFila[0].modelo);
  strcpy(atendidos[atend - 1].placa, carrosFila[0].placa);
  atendidos[atend - 1].rodas = carrosFila[0].rodas;

  for (int i = 0; i <= fila; i++) {
    if (i != fila - 1) {
      carrosFila[i] = carrosFila[i + 1];
    } else {
      carrosFila[i] = n;
    }
  }

  atendidos =
      (struct Carro *)realloc(atendidos, (atend + 1) * sizeof(struct Carro));
}