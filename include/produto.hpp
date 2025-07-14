#include "categoria.hpp"

#ifndef PRODUTO_HPP
#define PRODUTO_HPP

class Produto : public Categoria
{
private:
    int preco;
    int quantidade;

public:
    Produto(int id, const std::string nome, const std::string categoria, int preco, int quantidade);
};

#endif // PRODUTO_HPP
