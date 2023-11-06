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
void alterarTarefa(Tarefa* tarefas, int posicao) {
    if (posicao < 0 || posicao >= MAX_TAREFAS) {
        printf("Posição inválida.\n");
        return;
    }

    printf("Digite a prioridade da tarefa (0-10): ");
    scanf("%d", &(tarefas[posicao].prioridade));

    printf("Digite a descrição da tarefa (até %d letras): ", MAX_DESCRICAO);
    scanf(" %[^\n]", tarefas[posicao].descricao);

    printf("Digite a categoria da tarefa (até %d letras): ", MAX_CATEGORIA);
    scanf(" %[^\n]", tarefas[posicao].categoria);
}
//Altera os dados de uma tarefa.

void filtrarTarefasPorPrioridade(const Tarefa* tarefas, int numTarefas) {
    int prioridadeEscolhida;
    printf("Digite a prioridade que deseja filtrar (0-10): ");
    scanf("%d", &prioridadeEscolhida);

    printf("Tarefas com prioridade %d:\n", prioridadeEscolhida);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeEscolhida) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("------------------------------\n");
        }
    }
}
//Exibe as tarefas com a prioridade feita pelo usuario.
void filtrarTarefasPorEstado(const Tarefa* tarefas, int numTarefas) {
    char estadoEscolhido[MAX_ESTADO];
    printf("Digite o estado que deseja filtrar: ");
    scanf(" %[^\n]", estadoEscolhido);

    printf("Tarefas no estado %s:\n", estadoEscolhido);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].estado, estadoEscolhido) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("------------------------------\n");
        }
    }
}
//Exibe as tarefas com o estado escolhido pelo usuário.
void filtrarTarefasPorCategoria(Tarefa* tarefas, int numTarefas) {
    char categoriaEscolhida[MAX_CATEGORIA];
    printf("Digite a categoria que deseja filtrar: ");
    scanf(" %[^\n]", categoriaEscolhida);

    
    for (int i = 0; i < numTarefas - 1; i++) {
        for (int j = i + 1; j < numTarefas; j++) {
            if (tarefas[i].prioridade < tarefas[j].prioridade) {
                Tarefa aux = tarefas[i];
                tarefas[i] = tarefas[j];
                tarefas[j] = aux;
            }
        }
    }

    printf("Tarefas da categoria %s:\n", categoriaEscolhida);
    printf("------------------------------\n");

    
    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaEscolhida) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("------------------------------\n");
        }
    }
}
// Exibe as tarefas da categoria escolhida pelo usuário.
void filtrarTarefasPorPrioridadeECategoria(Tarefa* tarefas, int numTarefas) {
    int prioridadeEscolhida;
    char categoriaEscolhida[MAX_CATEGORIA];

    printf("Digite a prioridade que deseja filtrar (0-10): ");
    scanf("%d", &prioridadeEscolhida);

    printf("Digite a categoria que deseja filtrar: ");
    scanf(" %[^\n]", categoriaEscolhida);

    printf("Tarefas com prioridade %d e da categoria %s:\n", prioridadeEscolhida, categoriaEscolhida);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeEscolhida && strcmp(tarefas[i].categoria, categoriaEscolhida) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("------------------------------\n");
        }
    }
}
//Filtra tarefas por prioridade e categoria.
void exportarTarefasPorPrioridade(const Tarefa* tarefa, int numTarefa, int prioridade, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");

    for(int i = 0; i < numTarefa; i++) {
        if(tarefa[i].prioridade == prioridade) {
           fprintf(arquivo, "%d,%s,%s,%s\n", tarefa[i].prioridade,
                   tarefa[i].categoria,
                   tarefa[i].estado,
                   tarefa[i].descricao);
       }
    }

    fclose(arquivo);
}
// Exporta as tarefas com a prioridade escolhida

