#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_DESCRICAO 300
#define MAX_CATEGORIA 100
#define MAX_TAREFAS 100

typedef struct {
    int prioridade;
    char descricao[MAX_DESCRICAO];
    char categoria[MAX_CATEGORIA];
} Tarefa;

void criarTarefa(Tarefa* tarefas, int* numTarefas);
void deletarTarefa(Tarefa* tarefas, int* numTarefas, int posicao);
void listarTarefas(const Tarefa* tarefas, int numTarefas);
void salvarTarefas(const Tarefa* tarefas, int numTarefas, const char* nomeArquivo);
void carregarTarefas(Tarefa* tarefas, int* numTarefas, const char* nomeArquivo);
void alterarTarefa(Tarefa* tarefas, int posicao);
void filtrarTarefasPorPrioridade(const Tarefa* tarefas, int numTarefas); 
void filtrarTarefasPorEstado(const Tarefa* tarefas, int numTarefas); 
void filtrarTarefasPorCategoria(Tarefa* tarefas, int numTarefas); 
void filtrarTarefasPorPrioridadeECategoria(Tarefa* tarefas, int numTarefas);
void exportarTarefasPorPrioridade(const Tarefa* tarefas, int numTarefas, int prioridade, const char* nomeArquivo); 
void exportarTarefasPorCategoria(Tarefa* tarefa, int numTarefa, const char* categoria, const char* nomeArquivo); 
void exportarTarefasPorPrioridadeECategoria(Tarefa* tarefas, int numTarefas, int prioridade, const char* categoria, const char* nomeArquivo);

#endif

// Gerencia tarefas de acordo com critérios e exporta tarefas.
