#include <iostream>
#include <string>
#include "../include/hash_map.hpp"

HashMap::HashMap()
{
     proximo_id = 1; // ID começa em 1
    for (int i = 0; i < TAMANHO_PADRAO; ++i)
    {
        map[i] = nullptr;
    }
}

// Destrutor: Libera toda a memória alocada
HashMap::~HashMap() {
    std::cout << "\nLimpando memoria..." << std::endl;
    for (int i = 0; i < TAMANHO_PADRAO; ++i) {
        No<Livro> *atual = map[i];
        while (atual != nullptr) {
            No<Livro> *proximo = atual->proximo;
            delete atual->valor; // Deleta o objeto Livro
            delete atual;        // Deleta o nó da lista
            atual = proximo;
        }
        map[i] = nullptr;
    }
}

int HashMap::_hash(int chave)
{
    return chave % TAMANHO_PADRAO;
}

void HashMap::listar()
{
    std::cout << "\n--- LISTA DE LIVROS ---" << std::endl;
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

// Inserir agora atribui o ID automaticamente
void HashMap::inserir(Livro *livro) {
    livro->id = this->proximo_id; // Atribui ID
    this->proximo_id++;          // Incrementa para o próximo

    int index = _hash(livro->id);
    No<Livro> *newNode = new No<Livro>{livro->id, livro, nullptr};

    if (map[index] == nullptr) {
        map[index] = newNode;
    } else {
        No<Livro> *atual = map[index];
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = newNode;
    }
    std::cout << "\nLivro '" << livro->nome << "' inserido com sucesso! ID gerado: " << livro->id << std::endl << std::endl;
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

// Editar com busca e atualização no mesmo lugar
void HashMap::editar(int chave) {
    No<Livro> *no = buscar(chave);

    if (no != nullptr) {
        std::cout << "Editando livro: " << no->valor->nome << " (ID: " << chave << ")" << std::endl;
        
        std::string novo_nome;
        std::string novo_autor;

        std::cout << "Digite o novo nome do livro: ";
        std::getline(std::cin, novo_nome);

        std::cout << "Digite o novo autor do livro: ";
        std::getline(std::cin, novo_autor);

        no->valor->nome = novo_nome;
        no->valor->autor = novo_autor;

        std::cout << "\nLivro editado com sucesso!" << std::endl << std::endl;

    } else {
        std::cout << "\nLivro com ID " << chave << " nao encontrado." << std::endl << std::endl;
    }
}