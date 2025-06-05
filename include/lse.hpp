#pragma once

#include "no.hpp"
#include "prioridade.hpp"
#include "tarefa.hpp"

class Lse
{
private:
    No<Tarefa> *_head;      ///< Representa a cabeça do nó da lista encadeada.

    
    No<Tarefa> *_buscarUltimo(No<Tarefa> *h);


    void _exibirSeparador();
    No<Tarefa> *_buscarAnterior(No<Tarefa> *h, No<Tarefa> *a);

public:

    /**
     * @brief Construtor padrão que inicializa uma lista vazia.
     * @details Não haverá nenhum nó e o nó cabeça aponta para o 'vazio'.
     */
    Lse();

    /**
     * @brief Construtor que inicializa a lista com um nó.
     * @param tarefa Dado a ser inserido no nó 
     */
    Lse(Tarefa tarefa);

    static int length(No<Tarefa> *h);

    void inserir(Tarefa novaTarefa);
    bool removerId(int id);
    bool removerPrioridade(Prioridade prioridade);
    void buscar(int id);
    void exibir();
    void exibirTarefasPrioridade();
};
