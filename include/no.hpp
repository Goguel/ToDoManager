#pragma once

/**
 * @brief Representa um nó de uma lista encadeada simples.
 * @tparam T Tipo do valor armazenado no nó.
 */
template <class T>
struct No
{
    T value;        ///< Valor armazenado no nó.
    No *proximo;    ///< Ponteiro para o próximo nó.
};
