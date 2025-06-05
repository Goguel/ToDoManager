#include "../include/lse.hpp"
#include <cstddef>
#include <ostream>

/// Construtor Padrão.
Lse::Lse()
{
    /// O nó cabeça aponta para o vazio.
    _head = nullptr;
}

/// Construtor.
Lse::Lse(Tarefa tarefa)
{
    /// Alocação dinâmica na criação do nó.
    No<Tarefa> *newHead = new No<Tarefa>();
    newHead->value = tarefa;   

    /// Atribui o endereço do novo nó ao nó cabeça.
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

void Lse::inserirTarefa(Tarefa novaTarefa)
{
    novaTarefa.id = length(_head) + 1;

    No<Tarefa> *nn = new No<Tarefa>();
    nn->value = novaTarefa;
    nn->proximo = nullptr;

    No<Tarefa> *ultimo = _buscarUltimo(_head);

    if (ultimo == nullptr)
    {
        _head = nn;
        return;
        return;
    }

    ultimo->proximo = nn;
}

void Lse::exibirAll()
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

No<Tarefa> *Lse::_buscarAnterior(No<Tarefa> *h, No<Tarefa> *a) 
{
    No<Tarefa> *anterior = h;
    
    while(h != a) 
    {
        anterior = h;
        h = h->proximo;
    }

    return anterior;
}

bool Lse::removerByPrioridade(Prioridade prioridade)
{
    No<Tarefa> *h = _head;
    bool houveRemocao = false;

    if (h == nullptr)
    {
        std::cout << "\nNão há tarefas para serem removidas.\n" << std::endl;
        return false;
    }

    while (h != nullptr) 
    {
        Tarefa t = h->value;

        if (t.prioridade == prioridade) 
        {
            houveRemocao = true;
            No<Tarefa> *a = h;
            No<Tarefa> *anterior = _buscarAnterior(_head, h);

            if (_head->value.descricao == a->value.descricao)
            {
                _head = a->proximo;
            }
            if (a->proximo == nullptr) 
            {
                anterior->proximo = nullptr;
            } 
            else
            {
                anterior->proximo = a->proximo;
            } 
            
            delete a;
        }

        h = h->proximo;
    }

    return houveRemocao? true : false;
}

bool Lse::removerById(int id)
{
    No<Tarefa> *h = _head;
    bool houveRemocao = false;

    if (h == nullptr)
    {
        std::cout << "\nNão existe tarefa para ser removida.\n" << std::endl;
        return false;
    }

    while (h != nullptr) 
    {
        Tarefa t = h->value;

        if (t.id == id) 
        {
            houveRemocao = true;
            No<Tarefa> *a = h;
            No<Tarefa> *anterior = _buscarAnterior(_head, h);

            if (_head->value.descricao == a->value.descricao)
            {
                _head = a->proximo;
            }
            if (a->proximo == nullptr) 
            {
                anterior->proximo = nullptr;
            } 
            else
            {
                anterior->proximo = a->proximo;
            } 
            
            delete a;
            break;
        }

        h = h->proximo;
    }

    return houveRemocao? true : false;
}

void Lse::buscarById(int id)
{
    No<Tarefa> *h = _head;
    bool situacao = false;

    if (h == nullptr)
    {
        std::cout << "\nNão há tarefas a serem buscadas.\n" << std::endl;
        return;
    }

    while (h != nullptr)
    {
        Tarefa t = h->value;

        if (t.id == id)
        {
            situacao = true;
            std::cout << '\n';
            _exibirSeparador();
            std::cout << "Id: " << t.id << std::endl;
            std::cout << "Descricao: " << t.descricao << std::endl;
            std::cout << "Prioridade: " << t.prioridade << std::endl;
            _exibirSeparador();
            std::cout << '\n';
            break;
        }

        h = h->proximo;
    }

    if (!situacao)
    {
        std::cout << "\nNão existe tarefa com esse ID.\n" << std::endl;
    }
}

void Lse::exibirTarefasByPrioridade()
{

    for (int idx{1}; idx < 4; ++idx)
    {
        No<Tarefa> *h = _head;
        while (h != nullptr)
        {
            Tarefa t = h->value;
            if (idx == t.prioridade)
            {
                std::cout << '\n';
                _exibirSeparador();
                std::cout << "Id: " << t.id << std::endl;
                std::cout << "Descricao: " << t.descricao << std::endl;
                std::cout << "Prioridade: " << t.prioridade << std::endl;
                _exibirSeparador();
                std::cout << '\n';
            }

            h = h->proximo;
        }
    }
}
