#include "../include/lse.hpp"
#include <iostream>

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

            removerPrioridade = static_cast<Prioridade>(prioridade);
            lista.remover(removerPrioridade);

            //std::cout << "Tarefas com prioridade "<< prioridade << " foram removidas com sucesso" << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Em desenvolvimento." << std::endl;
            break;
        }
        case 5:
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
    std::cout << "3. Remover uma tarefa por prioridade" << std::endl;
    std::cout << "4. Buscar uma tarefa" << std::endl;
    std::cout << "5. Sair" << std::endl;
}
