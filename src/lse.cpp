#include "../include/lse.hpp"

Lse::Lse()
{
    _head = nullptr;
}

Lse::Lse(Tarefa tarefa)
{
    No<Tarefa> *newHead = new No<Tarefa>();
    newHead->value = tarefa;

    _head = newHead;
}

int Lse::length(No<Tarefa> *h)
{
    if (h == nullptr)
    {
        return 0;
    }

    return 1 + length(h->proximo);
}

No<Tarefa> *Lse::_buscarUltimo(No<Tarefa> *h)
{
    No<Tarefa> *anterior = h;

    while (h != nullptr)
    {
        anterior = h;
        h = h->proximo;
    }

    return anterior;
}

void Lse::inserir(Tarefa novaTarefa)
{
    novaTarefa.id = length(_head) + 1;

    No<Tarefa> *nn = new No<Tarefa>();
    nn->value = novaTarefa;
    nn->proximo = nullptr;

    // A partir da inserção da segunda tarefa:
    if (_buscarUltimo(_head) != nullptr) {
        _buscarUltimo(_head)->proximo = nn;
    }
}

void Lse::exibir()
{
    No<Tarefa> *h = _head;

    if (h == nullptr)
    {
        std::cout << "Não há tarefas a serem feitas." << std::endl;
        return;
    }

    _exibirSeparador();

    while (h != nullptr)
    {
        Tarefa t = h->value;

        std::cout << "Id: " << t.id << std::endl;
        std::cout << "Descricao: " << t.descricao << std::endl;
        std::cout << "Prioridade: " << t.prioridade << std::endl;
        _exibirSeparador();

        h = h->proximo;
    }
}

void Lse::_exibirSeparador()
{
    std::cout << "----------------------------------------" << std::endl;
}
