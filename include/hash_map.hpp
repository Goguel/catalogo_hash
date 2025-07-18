#include "no.hpp"
#include "livro.hpp"

#pragma once

#define TAMANHO_PADRAO 20

class HashMap
{
private:
    No<Livro> *map[TAMANHO_PADRAO];
    int _hash(int chave);
    int proximo_id;

public:
    HashMap();
    ~HashMap();

    void listar();
    void inserir(Livro *livro);
    No<Livro> *buscar(int chave);
    void remover(int chave);
    void editar(int chave);
};
