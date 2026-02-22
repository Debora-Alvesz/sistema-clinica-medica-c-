#ifndef PACIENTES_H
#define PACIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cpf[15];
    char dataNascimento[11];
    char telefone[20];
    char endereco[200];
} Paciente;

typedef struct elemento {
    Paciente dados;
    struct elemento* prox;
} Elemento;

typedef Elemento* Lista;

Lista* cria_lista();
void inserir_Paciente(Lista *pacientes, Paciente temp);
void imprime_Lista(Lista *pacientes);
void busca_por_cpf(Lista *pacientes);
void alterar_paciente(Lista *pacientes);
int excluir_paciente(Lista *pacientes, char buscaCpf[15]);
void liberarListaPacientes(Lista *pacientes);
#endif
