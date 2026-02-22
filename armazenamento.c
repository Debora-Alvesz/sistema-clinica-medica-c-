#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "consultas.h"
#include "armazenamento.h"

void salvarPacientes(Lista *pacientes){
    FILE *arquivoP = fopen("pacientes.txt", "w");
    if (arquivoP == NULL){
        printf("\nErro ao abrir o arquivo..\n");
        return;
    }
     if (pacientes == NULL)
        return;
    Elemento* atual = *pacientes;

    while (atual != NULL) {
        fprintf(arquivoP, "%s;%s;%s;%s;%s\n",
             atual->dados.nome,
             atual->dados.cpf,
             atual->dados.dataNascimento,
             atual->dados.telefone,
             atual->dados.endereco);

             atual = atual->prox;
    }
    fclose(arquivoP);
}

void CarregarPacientesEmArquivo(Lista *pacientes) {
    FILE *arquivoP = fopen("pacientes.txt", "r");
    if (arquivoP == NULL) {
        printf("Nenhum arquivo encontrado, começando lista vazia.\n");
        return;
    }
    Paciente aux;
    while (fscanf(arquivoP, " %[^;];%[^;];%[^;];%[^;];%[^\n]",
                  aux.nome,
                  aux.cpf,
                  aux.dataNascimento,
                  aux.telefone,
                  aux.endereco) == 5) {
    inserirPaciente(pacientes, aux);
    }

    fclose(arquivoP);
    printf("Pacientes carregados com sucesso!\n");
}

void salvarConsultas(ListaC *consultas){
    FILE *arquivoC = fopen("consultas.txt", "w");
    if (arquivoC == NULL){
        printf("\nErro ao abrir o arquivo..\n");
        return;
    }
     if (consultas == NULL)
        return;
    ElementoC* atual = *consultas;

    while (atual != NULL) {
        fprintf(arquivoC, "%s;%02d/%02d/%04d;%s;%02d:%02d;%s\n",
        atual->dados.cpfPaciente,
        atual->dados.dataHora.dia,
        atual->dados.dataHora.mes,
        atual->dados.dataHora.ano,
        atual->dados.especialidade,
        atual->dados.dataHora.hora,
        atual->dados.dataHora.minuto,
        atual->dados.medico);

             atual = atual->prox;
    }
    fclose(arquivoC);
}

void CarregarConsultasEmArquivo(ListaC *consultas) {
    FILE *arquivoC = fopen("consultas.txt", "r");
    if (arquivoC == NULL) {
        printf("Nenhum arquivo encontrado, começando lista vazia.\n");
        return;
    }
    Consulta aux;
            while (fscanf(arquivoC, " %[^;];%d/%d/%d;%[^;];%d:%d;%[^\n]",
              aux.cpfPaciente,
              &aux.dataHora.dia,
              &aux.dataHora.mes,
              &aux.dataHora.ano,
              aux.especialidade,
              &aux.dataHora.hora,
              &aux.dataHora.minuto,
              aux.medico) == 8) {
    inserirConsulta(consultas, aux);
        }

    fclose(arquivoC);
    printf("Consultas carregadas com sucesso!\n");
}
