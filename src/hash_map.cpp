#include <iostream>
#include "../include/hash_map.hpp"

HashMap::HashMap()
{
    for (int i = 0; i < TAMANHO_PADRAO; ++i)
    {
        map[i] = nullptr;
    }
}

int HashMap::_hash(int chave)
{
    return chave % TAMANHO_PADRAO;
}

void HashMap::listar()
{
    bool temInformacao = false;

    for (int i = 0; i < TAMANHO_PADRAO; ++i)
    {
        No<Livro> *atual = map[i];

        while (atual != nullptr)
        {
            temInformacao = true;
            Livro *livroAtual = atual->valor;

            std::cout << "ID: " << livroAtual->id << ", Nome: " << livroAtual->nome
                      << ", Categoria: " << livroAtual->categoria
                      << ", Autor: " << livroAtual->autor << std::endl;

            atual = atual->proximo;
        }
    }

    if (!temInformacao)
    {
        std::cout << "\nNão há livros cadastrados"
                  << std::endl
                  << std::endl;
    }
}

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

void HashMap::remover(int chave)
{
    int index = _hash(chave);
    No<Livro> *atual = map[index];
    No<Livro> *anterior = nullptr;

    while (atual != nullptr)
    {
        if (atual->chave == chave)
        {
            if (anterior == nullptr)
            {
                map[index] = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            delete atual->valor;
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void HashMap::editar(int chave, Livro *livro)
{
    No<Livro> *no = buscar(chave);
    if (no != nullptr)
    {
        no->valor->nome = livro->nome;
        no->valor->autor = livro->autor;
    }
    else
    {
        std::cout << "Livro com ID " << chave << " não encontrado." << std::endl;
    }
}
