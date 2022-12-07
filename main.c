#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main(void) {
  float tanq_pad = 200; // Quantidade inicial de gasolina no tanque
  float preco;          // Valor da gasolina
  int tam;              // Tamanho da fila
  float tanque = 200;   // Quantidade de litros
  int fila = 0;         // Número de carros na fila
  bool rep = true;      // Parametro do  laço de repetição do menu principal
  bool rep2 = true; // Parametro do  laço de repetição do menu relatórios
  int atend = 0; // Número de clientes atendidos
  float abast; // Variável de leitura do valor a ser abastecido
  FILE *pont_arq;

  execInicio();

  preco = lerPreco(preco);
  tam = lerTamanho(tam);

  struct Carro *carrosFila; // Fila de carros
  struct Carro *atendidos;  // Registro de carros atendidos

  carrosFila = (struct Carro *)calloc(tam, sizeof(struct Carro));
  if (carrosFila == NULL) {
    printf("Erro ao alocar memória");
    exit(0);
  }

  atendidos = (struct Carro *)malloc(atend * sizeof(struct Carro));
  if (atendidos == NULL) {
    printf("Erro ao alocar memória");
    exit(0);
  }

  while (rep) {
    switch (exibirMenu()) {
    case 1:
      if (fila < tam) {
        informarCarro(carrosFila, fila);
        fila++;
        imp(carrosFila, fila);
        printf("%sCarro adicionado!%s\n", C_GREEN, NONE);
      } else {
        printf("%sFila cheia ;-; -> volte mais tarde%s\n", C_RED, NONE);
      }
      break;
    case 2:
      if (fila > 0) {
        printf("Informe a quantidade de gasolina:");
        scanf("%f", &abast);
        if (abast <= tanque) {
          tanque -= abast;
          atend++;
          atenderCarro(carrosFila, atendidos, fila, atend);
          fila--;
          printf("%sCarro abastecido!%s\n", C_GREEN, NONE);
        } else {
          printf("%sNão há gasolina suficiente%s\n", C_RED, NONE);
        }

      } else {
        printf("%sNão há carros para abastecer%s\n", C_RED, NONE);
      }
      break;
    case 3:
      imp(carrosFila, fila);
      break;
    case 4:
      rep2 = true;

      while (rep2) {

        switch (exibirMenuRelatorios()) {
        case 'a':
          printf("%sQuantidade de litros vendida: %.2f%s\n", C_CYAN,
                 (tanq_pad - tanque), NONE);
          break;
        case 'b':
          printf("%sValor total arrecadado com as vendas: %.2f%s\n", C_CYAN,
                 (tanq_pad - tanque) * preco, NONE);
          break;
        case 'c':
          printf("%sQuantidade de carros atendidos: %i%s\n\n", C_CYAN,
                 atend, NONE);
          imp(atendidos, atend);
          break;
        case 'd':
          printf("%sQuantidade de combustível restante no tanque: %.2f%s\n",
                 C_CYAN, tanque, NONE);
          break;
        case 'e':
          pont_arq = fopen("arquivo.txt", "w");
          if (pont_arq == NULL)
            printf("Erro ao abrir o arquivo.\n");
          else {
            printf("%sArquivo criado com sucesso!%s\n", C_CYAN, NONE);
            fprintf(pont_arq, "Quantidade de litros vendida: %.2f\n",
                    (tanq_pad - tanque));
            fprintf(pont_arq, "Valor total arrecadado com as vendas: %.2f\n",
                    (tanq_pad - tanque) * preco);
            fprintf(pont_arq, "Quantidade de carros atendidos: %i\n",
                    atend);
            fprintf(pont_arq,
                    "Quantidade de combustível restante no tanque: %.2f\n",
                    tanque);
            fclose(pont_arq);
          }

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
      calibrar(carrosFila[0]);
      atend++;
      atenderCarro(carrosFila, atendidos, fila, atend);
      fila--;
      

      break;
    case 6:
      printf("%sFIM%s\n", C_YELLOW, NONE);
      rep = false;
      break;
    default:
      printf("%sVocê digitou um valor fora do menu%s\n", C_RED, NONE);
    }
  }

  return 0;
}


