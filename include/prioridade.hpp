#pragma once

/**
 * @brief Estabelece as prioridades que se pode atribuir em cada tarefa.
 * @details Cada prioridade: alta, média e baixa; é utilizada como critério de
 *          remoção de tarefas e para exibir as tarefas de forma ordenada
            considerando as prioridades.
 */
enum Prioridade
{
    ALTA = 1,
    MEDIA,
    BAIXA,
};
