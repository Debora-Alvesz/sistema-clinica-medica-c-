#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "armazenamento.h"

Lista* cria_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL) {
        *lista = NULL;
    }
    return lista;
}

void inserirPaciente(Lista *pacientes, Paciente p) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dados = p;
    novo->prox = *pacientes;
    *pacientes = novo;
}

void imprimeLista(Lista *pacientes){
    if (pacientes == NULL)
        return;

    Elemento* atual = *pacientes;

    printf("\n~Lista de pacientes cadastrados~\n");
    while (atual != NULL) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Nome:%s\n ", atual->dados.nome);
    printf("CPF:%s\n ", atual->dados.cpf);
    printf("Data de nascimento (dd/mm/aaaa):%s\n ", atual->dados.dataNascimento);
    printf("Telefone:%s\n ", atual->dados.telefone);
    printf("Endereço:%s\n ", atual->dados.endereco);
      printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
    atual = atual->prox;
    }
}

void busca_por_cpf(Lista *pacientes){
    char buscaCPF[15];
    int encontrado = 0;
    printf("\nDigite o CPF do paciente que deseja buscar (XXX.XXX.XXX-XX):");
    scanf(" %[^\n]", &buscaCPF);

        Elemento* atual = *pacientes;
    while (atual != NULL) {
    if(strcmp(buscaCPF, atual->dados.cpf) == 0){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Paciente encontrado!\n");
            printf("Nome:%s\n ", atual->dados.nome);
            printf("CPF:%s\n ", atual->dados.cpf);
            printf("Data de nascimento (dd/mm/aaaa):%s\n ", atual->dados.dataNascimento);
            printf("Telefone:%s\n ", atual->dados.telefone);
            printf("Endereço:%s\n ", atual->dados.endereco);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Paciente não cadastrado..");
    }
 }

 void alterar_paciente(Lista *pacientes){
  char buscaCPF[15];
    int encontrado = 0;
    printf("\nDigite o CPF do paciente que deseja buscar (XXX.XXX.XXX-XX):");
    scanf(" %[^\n]", &buscaCPF);

        Elemento* atual = *pacientes;
    while (atual != NULL) {
    if(strcmp(buscaCPF, atual->dados.cpf) == 0){
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Paciente encontrado!\n");
            printf("Nome:%s\n ", atual->dados.nome);
            printf("CPF:%s\n ", atual->dados.cpf);
            printf("Data de nascimento (dd/mm/aaaa):%s\n ", atual->dados.dataNascimento);
            printf("Telefone:%s\n ", atual->dados.telefone);
            printf("Endereço:%s\n ", atual->dados.endereco);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

            printf("Digite o novo nome: ");
            scanf(" %[^\n]", atual->dados.nome);
            printf("Digite o novo CPF (XXX.XXX.XXX-XX): ");
            scanf(" %[^\n]", atual->dados.cpf);
            printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
            scanf(" %[^\n]", atual->dados.dataNascimento);
            printf("Digite o novo telefone: ");
            scanf(" %[^\n]", atual->dados.telefone);
            printf("Digite o novo endereco: ");
            scanf(" %[^\n]", atual->dados.endereco);

            encontrado++;
         }
            atual = atual->prox;
    }
    if(encontrado == 0){
        printf("Paciente não cadastrado..");
    }
}

int excluir_paciente(Lista *pacientes, char buscaCpf[15]){
    if(pacientes == NULL || *pacientes == NULL)
        return 0;

    Elemento* anterior = NULL;
    Elemento* atual = *pacientes;

    while (atual != NULL && strcmp(atual->dados.cpf, buscaCpf) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    if (anterior == NULL)
        *pacientes = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    return 1;
}

void liberarListaPacientes(Lista *pacientes) {
    if (pacientes == NULL)
        return;

    Elemento* atual = *pacientes;
    while (atual != NULL) {
        Elemento* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pacientes);
}
