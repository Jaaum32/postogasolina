#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_CYAN "\033[36m"
#define NONE "\033[0m"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Carro {
  char marca[30];
  char modelo[30];
  int ano;
  int portas;
  char placa[10];
  int rodas;
};

void delay(unsigned int secs);
void flush_in();
void execInicio();
void calibrar(struct Carro c);
void imp(struct Carro c[], int tam);
void informarCarro(struct Carro carrosFila[], int fila);
char exibirMenuRelatorios();
int exibirMenu();
float lerPreco(float preco);
int lerTamanho(int tam);