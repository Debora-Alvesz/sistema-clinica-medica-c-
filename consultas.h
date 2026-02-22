#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;

typedef struct {
    char cpfPaciente[15];
    DataHora dataHora;
    char especialidade[50];
    char medico[100];
} Consulta;

typedef struct elementoConsulta {
    Consulta dados;
    struct elementoConsulta* prox;
} ElementoC;

typedef ElementoC* ListaC;

void inserirConsulta(ListaC* consultas, Consulta c);
void imprimeListaC(ListaC *consultas);
void buscarConsultaPorCpf(ListaC *consultas);
void alterar_consulta(ListaC *consultas);
int excluir_consulta(ListaC *consultas, char buscacCpf[15], char especialidadeBusca[50]);
void listarPorEspecilidade(ListaC *consultas, char buscaEspecialidade[50]);
void listarPorData(ListaC *consultas, int diaBusca, int mesBusca, int anoBusca);
void listarPacientesagendados(ListaC *consultas, Lista *pacientes);
void liberarListaConsultas(ListaC *consultas);

#endif
