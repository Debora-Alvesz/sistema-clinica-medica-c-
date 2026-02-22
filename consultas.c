#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultas.h"
#include "pacientes.h"
#include "armazenamento.h"

void inserirConsulta(ListaC* consultas, Consulta c) {
    ElementoC* novo = (ElementoC*) malloc(sizeof(ElementoC));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dados = c;
    novo->prox = *consultas;
    *consultas = novo;
}

void imprimeListaC(ListaC *consultas){
    if (consultas == NULL)
        return;

    ElementoC* atual = *consultas;

    printf("\n~Lista de consultas cadastradas~\n");
    while (atual != NULL) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("CPF:%s\n ", atual->dados.cpfPaciente);
    printf("Data: %02d/%02d/%04d\n",
               atual->dados.dataHora.dia,
               atual->dados.dataHora.mes,
               atual->dados.dataHora.ano);
    printf("Hora: %02d:%02d\n ", atual->dados.dataHora.hora, atual->dados.dataHora.minuto);
    printf("Especialidade:%s\n ", atual->dados.especialidade);
    printf("Médico:%s\n ", atual->dados.medico);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    atual = atual->prox;
    }
}

void buscarConsultaPorCpf(ListaC *consultas){
  char buscaCPF[15];
    int encontrado = 0;
    printf("\nDigite o CPF do paciente que deseja buscar (XXX.XXX.XXX-XX):");
    scanf(" %[^\n]", &buscaCPF);

        ElementoC* atual = *consultas;
    while (atual != NULL) {
    if(strcmp(buscaCPF, atual->dados.cpfPaciente) == 0){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Consulta encontrada!\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CPF:%s\n ", atual->dados.cpfPaciente);
            printf("Data: %02d/%02d/%04d\n",
               atual->dados.dataHora.dia,
               atual->dados.dataHora.mes,
               atual->dados.dataHora.ano);
            printf("Hora: %02d:%02d\n ", atual->dados.dataHora.hora, atual->dados.dataHora.minuto);
            printf("Especialidade:%s\n ", atual->dados.especialidade);
            printf("Médico:%s\n ", atual->dados.medico);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Consulta não cadastrado..");
    }
 }



 void alterar_consulta(ListaC *consultas){
  char buscaCPF[15];
    int encontrado = 0;
    printf("\nDigite o CPF do paciente que deseja alterar a consulta(XXX.XXX.XXX-XX):");
    scanf(" %[^\n]", buscaCPF);

        ElementoC* atual = *consultas;
    while (atual != NULL) {
    if(strcmp(buscaCPF, atual->dados.cpfPaciente) == 0){
            printf("Consulta encontrada!\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CPF:%s\n ", atual->dados.cpfPaciente);
            printf("Data: %02d/%02d/%04d\n",
               atual->dados.dataHora.dia,
               atual->dados.dataHora.mes,
               atual->dados.dataHora.ano);
            printf("Hora: %02d:%02d\n ", atual->dados.dataHora.hora, atual->dados.dataHora.minuto);
            printf("Especialidade:%s\n ", atual->dados.especialidade);
            printf("Médico:%s\n ", atual->dados.medico);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

                printf("Digite o novo CPF do paciente(XXX.XXX.XXX-XX): ");
                scanf(" %[^\n]", atual->dados.cpfPaciente);
                printf("Digite a nova data da consulta:\n");
                printf("Dia: ");
                scanf("%d", &atual->dados.dataHora.dia);
                printf("Mês: ");
                scanf("%d", &atual->dados.dataHora.mes);
                printf("Ano: ");
                scanf("%d", &atual->dados.dataHora.ano);
                printf("Digite a nova hora da consulta (HH:MM): ");
                printf("Hora: ");
                scanf("%d", &atual->dados.dataHora.hora);
                printf("Minuto: ");
                scanf("%d", &atual->dados.dataHora.minuto);
                printf("Digite a nova especialidade: ");
                scanf(" %[^\n]", &atual->dados.especialidade);
                printf("Digite o novo nome do medico: ");
                scanf(" %[^\n]", &atual->dados.medico);

            encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Consulta não cadastrada..");
    }
}

int excluir_consulta(ListaC *consultas, char buscacCpf[15], char especialidadeBusca[50]){
    if(consultas == NULL || *consultas == NULL)
        return 0;

    ElementoC* anterior = NULL;
    ElementoC* atual = *consultas;

    while (atual != NULL && strcmp(atual->dados.cpfPaciente, buscacCpf) != 0 ||
            strcmp(atual->dados.especialidade, especialidadeBusca) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    if (anterior == NULL)
        *consultas = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    return 1;
}
void listarPorEspecilidade(ListaC *consultas, char buscaEspecialidade[50]){
     int encontrado = 0;
      ElementoC* atual = *consultas;
     printf("Consultas encontradas:\n");
    while (atual != NULL) {
    if(strcmp(buscaEspecialidade, atual->dados.especialidade) == 0){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CPF:%s\n ", atual->dados.cpfPaciente);
            printf("Data: %02d/%02d/%04d\n",
               atual->dados.dataHora.dia,
               atual->dados.dataHora.mes,
               atual->dados.dataHora.ano);
            printf("Hora: %02d:%02d\n ", atual->dados.dataHora.hora, atual->dados.dataHora.minuto);
            printf("Especialidade:%s\n ", atual->dados.especialidade);
            printf("Médico:%s\n ", atual->dados.medico);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
             encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Nenhuma consulta com essa especialidade cadastrada..");
    }
}
void listarPorData(ListaC *consultas, int diaBusca, int mesBusca, int anoBusca){
int encontrado = 0;
      ElementoC* atual = *consultas;
     printf("Consultas encontradas:\n");
    while (atual != NULL) {
    if (atual->dados.dataHora.dia == diaBusca &&
            atual->dados.dataHora.mes == mesBusca &&
            atual->dados.dataHora.ano == anoBusca){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("CPF:%s\n", atual->dados.cpfPaciente);
            printf("Data: %02d/%02d/%04d\n",
               atual->dados.dataHora.dia,
               atual->dados.dataHora.mes,
               atual->dados.dataHora.ano);
            printf("Hora: %02d:%02d\n ", atual->dados.dataHora.hora, atual->dados.dataHora.minuto);
            printf("Especialidade:%s\n", atual->dados.especialidade);
            printf("Médico:%s\n", atual->dados.medico);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
             encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Nenhuma consulta nessa data cadastrada..");
    }
}
void listarPacientesagendados(ListaC *consultas, Lista *pacientes){
       if (*consultas == NULL){
        printf("Nenhuma consulta cadastrada..");
        return;
       }
    ElementoC* atualConsulta = *consultas;
    Elemento* atualPaciente = *pacientes;
    char cpf[15];

    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Pacientes agendados:\n");
    while (atualConsulta != NULL) {
        strcpy(cpf, atualConsulta->dados.cpfPaciente);

        Elemento* atualPaciente = *pacientes;
        while (atualPaciente != NULL && strcmp(atualPaciente->dados.cpf, cpf) != 0) {
            atualPaciente = atualPaciente->prox;
        }

        if (atualPaciente != NULL) {
            printf("Nome: %s\n", atualPaciente->dados.nome);
            printf("CPF: %s\n", atualPaciente->dados.cpf);
            printf("Data de Nascimento: %s\n", atualPaciente->dados.dataNascimento);
            printf("Telefone: %s\n", atualPaciente->dados.telefone);
            printf("Endereço: %s\n", atualPaciente->dados.endereco);

            printf("Data da consulta: %02d/%02d/%04d\n",
               atualConsulta->dados.dataHora.dia,
               atualConsulta->dados.dataHora.mes,
               atualConsulta->dados.dataHora.ano);
            printf("Hora: %02d:%02d\n ", atualConsulta->dados.dataHora.hora, atualConsulta->dados.dataHora.minuto);
            printf("Especialidade: %s\n", atualConsulta->dados.especialidade);
            printf("Médico: %s\n", atualConsulta->dados.medico);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        atualConsulta = atualConsulta->prox;
    }
}
void liberarListaConsultas(ListaC *consultas) {
    if (consultas == NULL)
        return;

    ElementoC* atual = *consultas;
    while (atual != NULL) {
        ElementoC* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(consultas);
}
int comparaHora(int h1, int m1, int h2, int m2) {
    if (h1 > h2) return 1;
    if (h1 < h2) return -1;
    if (m1 > m2) return 1;
    if (m1 < m2) return -1;
    return 0;
}
void ordena_lista_consultas(ListaC *consultas) {
    if (consultas == NULL || *consultas == NULL) return;

    int trocou;
    ElementoC *no1, *no2;
    Consulta temp;

    do {
        trocou = 0;
        no1 = *consultas;

        while (no1->prox != NULL) {
            no2 = no1->prox;
            if ((no1->dados.dataHora.ano > no2->dados.dataHora.ano) ||
                (no1->dados.dataHora.ano == no2->dados.dataHora.ano && no1->dados.dataHora.mes > no2->dados.dataHora.mes) ||
                (no1->dados.dataHora.ano == no2->dados.dataHora.ano && no1->dados.dataHora.mes == no2->dados.dataHora.mes &&
                 no1->dados.dataHora.dia > no2->dados.dataHora.dia) ||
                (no1->dados.dataHora.ano == no2->dados.dataHora.ano && no1->dados.dataHora.mes == no2->dados.dataHora.mes &&
                 no1->dados.dataHora.dia == no2->dados.dataHora.dia &&
                 comparaHora(no1->dados.dataHora.hora, no1->dados.dataHora.minuto,
                             no2->dados.dataHora.hora, no2->dados.dataHora.minuto) > 0))
            {
                temp = no1->dados;
                no1->dados = no2->dados;
                no2->dados = temp;
                trocou = 1;
            }
            no1 = no1->prox;
        }
    } while (trocou != 0);
}
