#include <iostream>
#include "../include/hash_map.hpp"

HashMap::HashMap() {}

int HashMap::_hash(int chave)
{
    return chave % TAMANHO_PADRAO;
}

// NÃO TÁ FUNCIONANDO
void HashMap::listar()
{
    for (int i = 0; i < TAMANHO_PADRAO; ++i)
    {
        No<Livro> *atual = map[i];

        while (atual != nullptr)
        {
            std::cout << "ID: " << atual->chave << ", Nome: " << atual->valor->nome
                      << ", Categoria: " << atual->valor->categoria
                      << ", Autor: " << atual->valor->autor << std::endl;

            atual = atual->proximo;
        }
    }
}

// NÃO TÁ FUNCIONANDO
void HashMap::inserir(Livro *livro)
{
    int index = _hash(livro->id);
    No<Livro> *newNode = new No<Livro>{livro->id, livro, nullptr};

    if (map[index] == nullptr)
    {
        map[index] = newNode;
        return;
    }

    No<Livro> *atual = map[index];
    while (atual->proximo != nullptr)
    {
        atual = atual->proximo;
    }

    atual->proximo = newNode;
}

No<Livro> *HashMap::buscar(int chave)
{
    int index = _hash(chave);
    No<Livro> *atual = map[index];

    while (atual != nullptr)
    {
        if (atual->chave == chave)
        {
            return atual;
        }
        atual = atual->proximo;
    }

    return nullptr;
}
