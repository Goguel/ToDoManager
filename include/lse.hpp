#pragma once

#include "no.hpp"
#include "prioridade.hpp"
#include "tarefa.hpp"

class Lse
{
private:
    No<Tarefa> *_head;
    No<Tarefa> *_buscarUltimo(No<Tarefa> *h);
    // void _ordenar();
    void _exibirSeparador();
    No<Tarefa> *_buscarAnterior(No<Tarefa> *h, No<Tarefa> *a);

public:
    Lse();
    Lse(Tarefa tarefa);

    static int length(No<Tarefa> *h);

    void inserir(Tarefa novaTarefa);
    // void remover(int id);
    void remover(Prioridade prioridade);
    // void buscar(int id);
    void exibir();
};
