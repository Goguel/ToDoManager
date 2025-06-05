#pragma once

#include <iostream>
/**
 * @brief Estrutura que representa uma tarefa.
 * @details Essa struct será usada como dado do nó da lista encadeada.
 */
struct Tarefa
{
    int id;                 ///< O id representa o índice de cada tarefa.
    std::string descricao;  ///< Variável para armazenar a descrição inserida.
    int prioridade;         ///< Prioridades atribuídas: alta, média e baixa.
};
