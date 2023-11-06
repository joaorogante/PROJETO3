#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

void criarTarefa(Tarefa* tarefas, int* numTarefas) {
    if (*numTarefas >= MAX_TAREFAS) {
        printf("Número máximo de tarefas alcançado.\n");
        return;
    }

    Tarefa novaTarefa;

    printf("Digite a prioridade da tarefa (0-10): ");
    scanf("%d", &(novaTarefa.prioridade));

    printf("Digite a descrição da tarefa (até %d letras): ", MAX_DESCRICAO);
    scanf(" %[^\n]", novaTarefa.descricao);

    printf("Digite a categoria da tarefa (até %d letras): ", MAX_CATEGORIA);
    scanf(" %[^\n]", novaTarefa.categoria);

    tarefas[*numTarefas] = novaTarefa;
    (*numTarefas)++;
}
//A função criarTarefa é responsável por criar uma nova tarefa. Ela solicita ao usuário uma prioridade, descrição e categoria, e adiciona a nova tarefa ao array tarefas.

void deletarTarefa(Tarefa* tarefas, int* numTarefas, int posicao) {
    if (posicao < 0 || posicao >= *numTarefas) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = posicao; i < *numTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*numTarefas)--;
}
//A função deletarTarefa recebe a posição de uma tarefa a ser deletada e remove essa tarefa do array tarefas.

void listarTarefas(const Tarefa* tarefas, int numTarefas) {
    if (numTarefas == 0) {
        printf("Não existem tarefas cadastradas.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Descrição: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("------------------------------\n");
    }
}
//A função listarTarefas exibe todas as tarefas cadastradas no array tarefas.

void salvarTarefas(const Tarefa* tarefas, int numTarefas, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(tarefas, sizeof(Tarefa), numTarefas, arquivo);
    fclose(arquivo);

    printf("Tarefas salvas com sucesso no arquivo %s.\n", nomeArquivo);
}

//A função salvarTarefas recebe o nome de um arquivo e salva as tarefas contidas no array tarefas nesse arquivo.

void carregarTarefas(Tarefa* tarefas, int* numTarefas, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para leitura.\n");
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long fileSize = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    int numTarefasArquivo = fileSize / sizeof(Tarefa);
    *numTarefas = numTarefasArquivo;

    fread(tarefas, sizeof(Tarefa), numTarefasArquivo, arquivo);
    fclose(arquivo);

    printf("Tarefas carregadas com sucesso do arquivo %s.\n", nomeArquivo);
}
//A função carregarTarefas recebe o nome de um arquivo e carrega as tarefas desse arquivo para o array tarefas.

//Essas funções são implementadas de acordo com o cabeçalho (Biblioteca.h).

