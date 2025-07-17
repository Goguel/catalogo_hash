#pragma once

template <typename T>
struct No
{
    int chave;
    T *valor;
    No *proximo;
};
