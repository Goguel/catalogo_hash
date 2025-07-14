#include <string>
#include "categoria.hpp"

#ifndef LIVRO_HPP
#define LIVRO_HPP

class Livro : public Categoria
{
private:
    std::string autor;

public:
    Livro(int id, std::string nome, std::string categoria, std::string autor);
};

#endif // LIVRO_HPP
