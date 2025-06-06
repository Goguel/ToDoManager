#pragma once

#include "no.hpp"
#include "prioridade.hpp"
#include "tarefa.hpp"

class Lse
{
private:
    No<Tarefa> *_head;
    No<Tarefa> *_buscarUltimo(No<Tarefa> *h);
    No<Tarefa> *_buscarAnterior(No<Tarefa> *h, No<Tarefa> *a);
    void _exibirSeparador();

public:
    Lse();

    Lse(Tarefa tarefa);

    static int length(No<Tarefa> *h);
    
    void inserirTarefa(Tarefa novaTarefa);

    void buscarById(int id);

    
    void exibirAll();
    void exibirTarefasByPrioridade();
    bool removerById(int id);
    bool removerByPrioridade(Prioridade prioridade);
};
