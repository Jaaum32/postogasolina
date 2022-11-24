#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_CYAN "\033[36m"
#define NONE "\033[0m"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct Carro {
  char marca[30];
  char modelo[30];
  int ano;
  int portas;
  char placa[10];
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

void calibrar() {
  int pressao;

  printf("Digite o valor da pressao desejada no pneu:");
  scanf("%i", &pressao);

  printf("%sTodos os pneus foram calibrados!%s\n", C_GREEN, NONE);
}

void impFila(struct Carro carrosFila[]) {
  for (int i = 0; i <= sizeof(carrosFila) / sizeof(int); i++) {
    if (strcmp(carrosFila[i].marca, "") != 0) {
      printf("Carro %i\n", i + 1);
      printf("Marca: %s\n", carrosFila[i].marca);
      printf("Modelo: %s\n", carrosFila[i].modelo);
      printf("Ano: %i\n", carrosFila[i].ano);
      printf("Portas: %i\n", carrosFila[i].portas);
      printf("Placa: %s\n\n", carrosFila[i].placa);
    }
  }
}

void impAtend(struct Carro atendidos[]){
  for (int i = 0; i <= sizeof(atendidos) / sizeof(int); i++) {
    if (strcmp(atendidos[i].marca, "") != 0) {
      printf("Carro %i\n", i + 1);
      printf("Marca: %s\n", atendidos[i].marca);
      printf("Modelo: %s\n", atendidos[i].modelo);
      printf("Ano: %i\n", atendidos[i].ano);
      printf("Portas: %i\n", atendidos[i].portas);
      printf("Placa: %s\n\n", atendidos[i].placa);
    }
  }
}

void limparFila(struct Carro c[], struct Carro none) {
  for (int i = 0; i <= sizeof(c) / sizeof(int); i++) {
    c[i] = none;
  }
}

void informarCarro(struct Carro carrosFila[], int fila) {
  struct Carro c;

  printf("Informe os dados do seu carro\nMarca: ");
  scanf("%s", &c.marca);
  printf("Modelo: ");
  scanf("%s", &c.modelo);
  printf("Ano: ");
  scanf("%i", &c.ano);
  printf("Portas: ");
  scanf("%i", &c.portas);
  printf("Placa: ");
  scanf("%s", &c.placa);
  printf("\n");

  carrosFila[fila] = c;
}

void atenderCarro(struct Carro carrosFila[], struct Carro atendidos[], int fila,
                  int atend) {
  struct Carro n = {"", "", 0, 0, ""}; 
  atendidos[atend] = carrosFila[0];

  for (int i = 0; i <= sizeof(carrosFila) / sizeof(int); i++) {
    if (i != fila - 1) {
      carrosFila[i] = carrosFila[i + 1];
    } else {
      carrosFila[i] = n;
    }
  }
}

int main(void) {
  float tanq_pad = 200; // Quantidade inicial de gasolina no tanque
  float preco;          // Valor da gasolina
  int tam;              // Tamanho da fila
  float tanque = 200;   // Quantidade de litros
  int fila = 0;         // Número de carros na fila
  bool rep = true;      // Parametro do  laço de repetição do menu principal
  bool rep2 = true; // Parametro do  laço de repetição do menu relatórios
  int atend = 0;    // Número de clientes atendidos
  float abast;      // Variável de leitura do valor a ser abastecido

  execInicio();

  preco = lerPreco(preco);

  tam = lerTamanho(tam);

  struct Carro none = {"", "", 0, 0, ""}; // Carro nulo
  struct Carro carrosFila[tam];           // Fila de carros
  struct Carro atendidos[100];             // Registro de carros atendidos

  limparFila(carrosFila, none);
  limparFila(atendidos, none);

  while (rep) {
    switch (exibirMenu()) {
    case 1:
      if (fila < tam) {
        informarCarro(carrosFila, fila);
        impFila(carrosFila);
        printf("%sCarro adicionado!%s\n", C_GREEN, NONE);
        fila++;
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
          atenderCarro(carrosFila, atendidos, fila, atend);
          fila--;
          atend++;
          printf("%sCarro abastecido!%s\n", C_GREEN, NONE);
        } else {
          printf("%sNão há gasolina suficiente%s\n", C_RED, NONE);
        }

      } else {
        printf("%sNão há carros para abastecer%s\n", C_RED, NONE);
      }
      break;
    case 3:
      impFila(carrosFila);
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
          printf("%sQuantidade de carros atendidos: %i%s\n\n", C_CYAN, atend,
                 NONE);
          impFila(atendidos);
          break;
        case 'd':
          printf("%sQuantidade de combustível restante no tanque: %.2f%s\n",
                 C_CYAN, tanque, NONE);
          break;
        case 'e':
          printf("%sGerar arquivo de impressão%s\n", C_CYAN, NONE);
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
      atenderCarro(carrosFila, atendidos, fila, atend);
      fila--;
      atend++;
      calibrar();
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