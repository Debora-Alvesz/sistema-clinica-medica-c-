#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "consultas.h"
#include "armazenamento.h"
#include <locale.h>

//Sistema de clinica médica
int main(){
    setlocale(LC_ALL, "Portuguese");

    Lista* pacientes = cria_lista();
    ListaC* consultas = cria_lista();
    Paciente temp;
    Consulta c;

    int opcao;
    char buscaCPF[15];
    char buscacCPF[15];
    char buscaEspecialidade[50];
    int dia, mes, ano;
    CarregarPacientesEmArquivo(pacientes);
    CarregarConsultasEmArquivo(consultas);

    do {
        printf("\n~~~~~~~Menu~~~~~~~\n");
        printf("~~Pacientes~~\n");
        printf(" 1- Cadastrar Paciente no início da lista\n");
        printf(" 2- Listar Pacientes\n");
        printf(" 3- Buscar paciente por CPF\n");
        printf(" 4- Alterar dados do paciente\n");
        printf(" 5- Excluir paciente\n");
        printf("~~Consultas~~\n");
        printf(" 6- Agendar consulta\n");
        printf(" 7- Listar consultas\n");
        printf(" 8- Buscar consulta por cpf\n");
        printf(" 9- Alterar dados da consulta\n");
        printf("10- Excluir consulta\n");
        printf("~~Relatórios~~\n");
        printf("11- Listar consultas por especialidade\n");
        printf("12- Listar consultas por data\n");
        printf("13- Listar pacientes que tem consultas agendadas\n");
        printf(" 0- Para sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite o nome: ");
                scanf(" %[^\n]", temp.nome);
                printf("Digite o CPF (XXX.XXX.XXX-XX): ");
                scanf(" %[^\n]", temp.cpf);
                printf("Digite a data de nascimento (dd/mm/aaaa): ");
                scanf(" %[^\n]", temp.dataNascimento);
                printf("Digite o telefone: ");
                scanf(" %[^\n]", temp.telefone);
                printf("Digite o endereco: ");
                scanf(" %[^\n]", temp.endereco);
                inserirPaciente(pacientes, temp);
                break;
            case 2:
                imprimeLista(pacientes);
                break;
            case 3:
                busca_por_cpf(pacientes);
                break;
            case 4:
                alterar_paciente(pacientes);
                break;
            case 5:
                printf("\nDigite o CPF do paciente que deseja excluir(XXX.XXX.XXX-XX):");
                scanf(" %[^\n]", &buscaCPF);
                if (excluir_paciente(pacientes, buscaCPF))
                    printf("Paciente excluido!\n");
                else
                    printf("Paciente não encontrado!\n");
                break;
            case 6:
                printf("Digite o CPF do paciente(XXX.XXX.XXX-XX): ");
                scanf(" %[^\n]", c.cpfPaciente);
                printf("Digite a data da consulta (DD/MM/AAAA): ");
                printf("Dia:");
                scanf("%d", &c.dataHora.dia);
                printf("Mês: ");
                scanf("%d", &c.dataHora.mes);
                printf("Ano: ");
                scanf("%d", &c.dataHora.ano);
                printf("Digite a hora da consulta (HH:MM): ");
                printf("Hora: ");
                scanf("%d", &c.dataHora.hora);
                printf("Minuto: ");
                scanf("%d", &c.dataHora.minuto);
                printf("Digite a especialidade: ");
                scanf(" %[^\n]", c.especialidade);
                printf("Digite o nome do medico: ");
                scanf(" %[^\n]", c.medico);
                getchar();

                inserirConsulta(consultas, c);
                printf("Consulta cadastrada com sucesso!\n");
                break;
            case 7:
                ordena_lista_consultas(consultas);
                imprimeListaC(consultas);
                break;
            case 8:
                buscarConsultaPorCpf(consultas);
                break;
            case 9:
                alterar_consulta(consultas);
                break;
            case 10:
                printf("\nDigite o CPF do paciente que deseja excluir a consulta(XXX.XXX.XXX-XX):");
                scanf(" %[^\n]", &buscacCPF);
                printf("\nDigite a especialidade da consulta que deseja excluir:");
                scanf(" %[^\n]", &buscaEspecialidade);
                if (excluir_consulta(consultas, buscacCPF, buscaEspecialidade))
                    printf("Consulta excluida!\n");
                     else
                    printf("Consulta não encontrado!\n");
                break;
            case 11:
                printf("\nDigite a especialidade da consulta que deseja buscar:");
                scanf(" %[^\n]", &buscaEspecialidade);
                listarPorEspecilidade(consultas, buscaEspecialidade);
                break;
            case 12:
                printf("\nDigite a data das consultas que deseja buscar (DD/MM/AAAA): ");
                printf("Digite o dia: ");
                scanf("%d", &dia);
                printf("Digite o mês: ");
                scanf("%d", &mes);
                printf("Digite o ano: ");
                scanf("%d", &ano);
                listarPorData(consultas, dia, mes, ano);
                break;
            case 13:
                ordena_lista_consultas(consultas);
                listarPacientesagendados(consultas, pacientes);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                salvarPacientes(pacientes);
                salvarConsultas(consultas);
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (opcao != 0);

liberarListaPacientes(pacientes);
liberarListaConsultas(consultas);
    return 0;
}
