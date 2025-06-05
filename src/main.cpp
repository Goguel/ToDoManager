#include "../include/lse.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>

/**
 * @brief 
 */
void exibirOpcoes();

int main()
{
    Lse lista = Lse();
    int opcao;

    std::cout << "Bem vindo ao gerenciador de tarefas!" << std::endl;

    while (true)
    {
        exibirOpcoes();
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            lista.exibir();
            break;
        case 2:
        {
            Tarefa novaTarefa;
            std::cout << "Digite a descricao da tarefa: ";
            std::cin.ignore();

            std::getline(std::cin, novaTarefa.descricao);
            std::cout << "Digite a prioridade da tarefa (1-3): ";
            int prioridade;
            std::cin >> prioridade;
            novaTarefa.prioridade = static_cast<Prioridade>(prioridade);

            lista.inserir(novaTarefa);
            break;
        }
        case 3:
        {
            std::cout << "Digite a prioridade a ser removida: ";
            int prioridade;
            Prioridade removerPrioridade;
            std::cin >> prioridade;

            if (prioridade < Prioridade::ALTA ||  prioridade > Prioridade::BAIXA)
            {
                std::cout << "\nEssa prioridade inserida não existe.\n" << std::endl;
                break;
            }
            removerPrioridade = static_cast<Prioridade>(prioridade);
            bool situacao = lista.removerPrioridade(removerPrioridade);

            if (situacao)
            {
                std::cout << "\nTarefas com prioridade "<< prioridade << " foram removidas com sucesso.\n" << std::endl;
            }
            break;
        }
        case 4:
        {
            std::cout << "Digite o id da tarefa a ser removida: ";
            int id;
            std::cin >> id;

            bool situacao = lista.removerId(id);
            if (situacao)
            {
                std::cout << "\nTarefa com id " << id << " foi removida com sucesso.\n" << std::endl;
            }
            break;
        }
        case 5:
        {
            std::cout << "Digite o id da tarefa a ser buscado: ";
            int id;
            std::cin >> id;
            lista.buscar(id);
            break;
        }
        case 6:
        {
            lista.exibirTarefasPrioridade();
            break;
        }
        case 7:
        {
            std::cout << "Saindo do gerenciador de tarefas. Até logo!" << std::endl;
            return 0;
        }

        default:
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}

void exibirOpcoes()
{
    std::cout << "O que deseja fazer?" << std::endl;
    std::cout << "1. Visualizar suas tarefas" << std::endl;
    std::cout << "2. Adicionar uma nova tarefa" << std::endl;
    std::cout << "3. Remover tarefas por prioridade" << std::endl;
    std::cout << "4. Remover uma tarefa por id" << std::endl;
    std::cout << "5. Buscar uma tarefa" << std::endl;
    std::cout << "6. Exibir todas as tarefas ordenadas por prioridade" << std::endl;
    std::cout << "7. Sair" << std::endl;
}
