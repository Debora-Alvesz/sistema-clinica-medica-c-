#ifndef ARMAZENAMENTO_H
#define ARMAZENAMENTO_H

#include "pacientes.h"
#include "consultas.h"

void salvarPacientes(Lista *pacientes);
void CarregarPacientesEmArquivo(Lista *pacientes);
void salvarConsultas(ListaC *consultas);
void CarregarConsultasEmArquivo(ListaC *consultas);
#endif
